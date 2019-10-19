#ifndef MY_SYMBOL_H1
#define MY_SYMBOL_H1
#include <vector>
#include "mylinalg.h"
#include <math.h>
#include <QObject>
using namespace MyLinearAlgebra;

namespace iii {

	const double g = 9.80665;
	const double nu = 132712.43994e6;
	const double Re = 6371.3;

    class TModel: public QObject {
         Q_OBJECT
	protected:
		TMatrix Result;
		double T0;
		double T1;
		double H0;
		TVector X0;
    public:
        virtual TVector GetX(){return TVector();}
        virtual void addResult(const TVector& rvalue, double lvalue) {}
        virtual TVector getInitialConditions() { return X0; }
        TMatrix getResult() const { return this->Result; }
        virtual TVector getRight( TVector& rvalue, double lvalue) { return TVector(); }
        double getSamplingIncrement() { return SamplingIncrement; }
        virtual int getLengthVecSost() { int a=0; return a; }
        int getkolfunc() { return X0.size(); }
        double getT0() { return T0; }
        double getT1() { return T1; }
        double getH0() { return H0; }
        void setT0(double t0) { T0 = t0; }
        void setT1(double t1) { T1 = t1; }
        void setInitialConditions(TVector& vec) { X0.resize(vec.length()) ; X0 = vec; }
        void setH0(double h0) { H0 = h0; }
		double SamplingIncrement;
	};

	class TComposite : public TModel
	{
        Q_OBJECT
	protected:
		bool work=false;
		int getLengthVecSost();
        TVector getInitialConditions() { return X0; }
        TVector getRightItems(const TVector & rvalue, double lvalue);
        void addResultItems (const TVector & rvalue, double lvalue);
        TVector GetX();
	public:
        TVector getXlast();
        std::vector <TComposite*> Items;
        virtual double getM() { return double(); }
        virtual void SetInitionalCondition(const TVector& aX0, double aPsiTarget, double aBetaTarget) {};
        void getStop() { work = false; }
        void getStart() { work = true; }
	    bool getWork() { return work; }
    signals:
        void getPsi(TVector rvalue);
        void BOOM();
    public slots:
        virtual void setPsi(TVector rvalue) {}
	};

	class TScene : public TComposite
	{ 
	protected:
		double countAircraft, countMissle;
	public:
		TScene() ;

		TVector getRight( TVector& rvalue, double lvalue);
		void addResult(const TVector& rvalue, double lvalue) ;
	};

	class TDynamicObject : public TComposite
	{ protected:
        double PsiTarget=0;
        double BetaTarget=0;
        double Dtarget=1000000;
		bool stop=false;
		double m0,dmt, mt, m;
		double getM() { return m; }
	};

	class TAircraft : public TDynamicObject
{
	};


    class TAircraft1 : public TAircraft
    {
        Q_OBJECT
    protected:
        bool lapel=false;
    public:
        TAircraft1(TVector aX);
        TVector getRight(TVector& rvalue, double lvalue);
        void addResult(const TVector& rvalue, double lvalue);
    public slots:
        void setPsi(TVector rvalue);
    };


    class TAircraft2 : public TAircraft
    {
        Q_OBJECT
    public:
        TAircraft2(TVector aX);
        TVector getRight(TVector& rvalue, double lvalue);
        void addResult(const TVector& rvalue, double lvalue);
    public slots:
        void Crash();
    };

	class TMissle : public TDynamicObject
    {
        Q_OBJECT
    public:
		TMissle();
        void SetInitionalCondition(const TVector& aX0, double aPsiTarget, double aBetaTarget);
        TVector getRight( TVector& rvalue, double lvalue);
        void addResult(const TVector& rvalue, double lvalue);
    public slots:
        void setPsi(TVector rvalue);
	};

}
#endif //MY_SYMBOL_H1

