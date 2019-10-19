#define _USE_MATH_DEFINES 1;
#include "model.h"
#include <Windows.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#define PI 3.14159265


using namespace std;
using namespace iii;

iii::TScene::TScene()
{ 
	work = true;
	Result.resize(0, 0);
    X0.resize(0);

    T0=0;
    T1=300;
    SamplingIncrement=1;

	TVector X1Air(6); 
    X1Air[0] = 0;
    X1Air[1] = 3000;
    X1Air[2] = 0;
    X1Air[3] = 0;
    X1Air[4] = 0;
    X1Air[5] = 800;
	

	TVector X2Air(6);
    X2Air[0] = 0000;
    X2Air[1] = 3200;
    X2Air[2] = 1500;
    X2Air[3] = 00;
    X2Air[4] = 0;
    X2Air[5] = 400;
	Items.resize(2);

    Items.at(0) = new TAircraft1(X1Air);
    Items.at(1) = new TAircraft2(X2Air);
	Items[0]->getStart();
	Items[1]->getStart();

   QObject::connect(Items[1], SIGNAL(getPsi(TVector)), Items[0], SLOT(setPsi(TVector)));
   QObject::connect(Items[1], SIGNAL(getPsi(TVector)), Items[0]->Items[0], SLOT(setPsi(TVector)));
   QObject::connect(Items[0]->Items[0], SIGNAL(BOOM()), Items[1], SLOT(Crash()));

}

TVector iii::TScene::getRight( TVector& rvalue, double lvalue)
{
	TVector res(rvalue.size());
	res=getRightItems(rvalue, lvalue);
	return res;
}

void iii::TScene::addResult(const TVector & rvalue, double lvalue)
{
addResultItems(rvalue, lvalue);
}

iii::TAircraft1::TAircraft1(TVector aX)
{
    X0.resize(aX.size());
    X0 = aX;

    Result.resize(1, getkolfunc()+1);
    for (int i = 0; i < getkolfunc(); i++)
        Result(0, i+1) = X0[i];

    m0 = 10900;
    mt = 3000;
    dmt = 0.27;

    Items.resize(6);
    for (int i = 0; i < 6; i++)
        Items.at(i) = new TMissle();
    double summM = 0;
    for (int i = 0; i < 6; i++)
        summM=Items[i]->getM();

    m = m0 + mt + summM;
}

iii::TAircraft2::TAircraft2(TVector aX)
{
    X0.resize(aX.size());
    X0 = aX;

    Result.resize(1, getkolfunc()+1);
    for (int i = 0; i < getkolfunc(); i++)
        Result(0, i+1) = X0[i];

    m0 = 10900;
    mt = 3000;
    dmt = 0.27;
    m = m0 + mt;
}

void iii::TAircraft1::addResult(const TVector & rvalue, double lvalue)
{
    int RC = Result.rowCount();
        Result.resize(RC + 1, rvalue.size()+1);
        Result(RC, 0) = lvalue;
        for (int i = 0; i < rvalue.size(); i++)
        {
            Result(RC, i + 1) = rvalue[i];
        }
        if (Items[0]->getWork())
            addResultItems(rvalue, lvalue);
       if ((!Items[0]->getWork()) && (Dtarget<2000)){
  Items[0]->SetInitionalCondition(rvalue, PsiTarget, BetaTarget);
  Items[0]->getStart();
       lapel=true;}
}

void iii::TAircraft2::addResult(const TVector & rvalue, double lvalue)
{
    int RC = Result.rowCount();
        Result.resize(RC + 1, rvalue.size()+1);
        Result(RC, 0) = lvalue;
        for (int i = 0; i < rvalue.size(); i++)
        {
            Result(RC, i + 1) = rvalue[i];
        }
    emit getPsi(rvalue);
}

void iii::TAircraft1::setPsi(TVector rvalue)
{
TVector ax=getXlast();
BetaTarget = atan2((rvalue[1]-ax[1]),sqrt(pow(rvalue[0]-ax[0],2)+pow(rvalue[2]-ax[2],2)));
PsiTarget = atan2((rvalue[2]-ax[2]),(rvalue[0]-ax[0]));
Dtarget = sqrt(pow(rvalue[0]-ax[0],2)+pow(rvalue[1]-ax[1],2)+pow(rvalue[2]-ax[2],2));
}



TVector iii::TAircraft1::getRight( TVector& rvalue, double lvalue)
{
    TVector res(rvalue.size());
    res=getRightItems(rvalue, lvalue);
    if (!lapel)
    {
  /*  res[0] = 100*cos(PsiTarget);
    res[1] = 100*sin(BetaTarget);
    res[2] = 100*sin(PsiTarget);
    res[3] = 0;
    res[4] = 0;
    res[5] = 0;}*/
        res[0] = rvalue[3];
        res[1] = rvalue[4];
        res[2] = rvalue[5];
            res[3] = 0*cos(PsiTarget);
            res[4] = 0*sin(BetaTarget);
            res[5] = 0*sin(PsiTarget);}
    else {
        res[0] = rvalue[3];
        res[1] = rvalue[4];
        res[2] = rvalue[5];
        res[3] = 0*cos(PI/2);
        res[4] = 0*sin(0);
        res[5] = 0*sin(PI/2);
    }
    return res;
}

TVector iii::TAircraft2::getRight( TVector& rvalue, double lvalue)
{
    TVector res(rvalue.size());
    res[0] = rvalue[3];
    res[1] = rvalue[4];
    res[2] = rvalue[5];
    res[3] = 0*cos(PI/2);
    res[4] = 0*sin(0);
    res[5] = 0*sin(PI/2);
    return res;
}

void iii::TAircraft2::Crash()
{
    getStop();
}

void iii::TMissle::SetInitionalCondition(const TVector& aX0, double aPsiTarget, double aBetaTarget)
{
    X0.resize(aX0.size());
    X0 = aX0;
    PsiTarget=aPsiTarget;
    BetaTarget=aBetaTarget;
    Result.resize(1, getkolfunc()+1);
    for (int i = 0; i < getkolfunc(); i++)
        Result(0, i+1) = X0[i];
}

iii::TMissle::TMissle()
{ // m0, dmt, mt
	m0 = 200;
	mt = 50;
    dmt = 5;
	m = m0 + mt;  
}

void iii::TMissle::setPsi(TVector rvalue)
{
    if (getWork()){
TVector ax=getXlast();
BetaTarget = atan2((rvalue[1]-ax[1]),sqrt(pow(rvalue[0]-ax[0],2)+pow(rvalue[2]-ax[2],2)));
PsiTarget = atan2((rvalue[2]-ax[2]),(rvalue[0]-ax[0]));
Dtarget = sqrt(pow(rvalue[0]-ax[0],2)+pow(rvalue[1]-ax[1],2)+pow(rvalue[2]-ax[2],2));
    }
}

void iii::TMissle::addResult(const TVector & rvalue, double lvalue)
{
    int RC = Result.rowCount();

        Result.resize(RC + 1, rvalue.size()+1);
        Result(RC, 0) = lvalue;
        for (int i = 0; i < rvalue.size(); i++)
        {
            Result(RC, i + 1) = rvalue[i];
        }

        if (Dtarget<150)
        {
            BOOM();
            getStop();
        }
}

TVector iii::TMissle::getRight( TVector& rvalue, double lvalue)
{
    TVector res(rvalue.size());
    res[0] = rvalue[3];
    res[1] = rvalue[4];
    res[2] = rvalue[5];
    res[3] = 5*cos(PsiTarget);
    res[4] = 35*sin(BetaTarget);
    res[5] = 0*sin(PsiTarget);
    return res;
}




int iii::TComposite::getLengthVecSost()
{
	int length = getkolfunc();
        if (!Items.empty())
	for (int i=0; i < Items.size(); i++)
	{
		if (Items[i]->getWork())
		length += Items[i]->getLengthVecSost();
    };
	return length;
}

TVector iii::TComposite::getXlast()
{
	TVector res(getkolfunc());
    for (int i = 1; i <= getkolfunc(); i++)
        res[i-1] = Result(Result.rowCount()-1, i);
	return res;
}


void iii::TComposite::addResultItems(const TVector &rvalue, double lvalue)
{
    TVector Res(rvalue.size());
    TVector ItemResult;
    int numberNow = getkolfunc();
    int lengthX = 0;

    for (int i = 0; i < Items.size(); i++)
    {
        if (!Items[i]->getWork())
            continue;

        lengthX = Items[i]->getLengthVecSost();
        ItemResult.resize(lengthX);

        for (int j = numberNow; j < numberNow + lengthX; j++)
            ItemResult[j - numberNow] = rvalue[j];
        numberNow+=lengthX;
        Items[i]->addResult(ItemResult,lvalue);
    }
}


TVector iii::TComposite::getRightItems(const TVector& rvalue, double lvalue)
{

	if (Items.empty())
		return rvalue;
	TVector Res(rvalue.size());
	TVector ResItem;
	TVector ItemRvalue;

    int numberNow = getkolfunc();
	int lengthX = 0;

    for (int i = 0; i < getkolfunc(); i++)
        Res[i] = rvalue[i];

	for (int i = 0; i < Items.size(); i++)
	{
        if (Items[i]->getWork()==false)
            continue;

		lengthX = Items[i]->getLengthVecSost();
		
		ItemRvalue.resize(lengthX);
		ResItem.resize(lengthX);
		
		for (int j = numberNow; j < numberNow + lengthX; j++)
			ItemRvalue[j - numberNow] = rvalue[j];
		
		ResItem=Items[i]->getRight(ItemRvalue,lvalue);

		for (int j = numberNow; j < numberNow + lengthX; j++)
			Res[j] = ResItem[j- numberNow];
		numberNow += lengthX;
	}
	return Res;
}

TVector iii::TComposite::GetX()
{
	TVector res(getLengthVecSost());
    int numberNow=getkolfunc();
	if (Items.empty())
	res = getXlast();
	else
    {
        TVector xlast(getkolfunc());
        xlast = getXlast();
        for (int i = 0; i < getkolfunc(); i++)
            res[i] = xlast[i];

		for (int i = 0; i < Items.size(); i++)
		{
            if (Items[i]->getWork())
            {
				TVector ItemX(Items[i]->getLengthVecSost());
				ItemX = Items[i]->GetX();
				for (int j = 0; j < ItemX.size(); j++)
                    res[numberNow + j] = ItemX[j];
                numberNow += ItemX.size();
			}
		}	
	}
	return res;
}

