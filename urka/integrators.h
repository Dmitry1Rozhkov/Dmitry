#ifndef MY_SYMBOL_H2
#define MY_SYMBOL_H2
#include "model.h"
namespace iii {
class TIntegrator {
protected:
	bool StopIntg = false;
	double epsmax;
	double zero;
public:
	//TIntegrator() {};
    virtual void run(TModel& Mod) {}
    double u() const;
    double max(double a1, double a2) { if (a1 > a2) return a1; else return a2; }
    double min(double a1, double a2) { if (a1 < a2) return a1; else return a2; }
    void stop() { StopIntg = true; }
};

class TEylerMod : public TIntegrator {
protected:
	double h = 0; //шаг интегрирования
public:
    void seth(double& ah) { h = ah; }
    TEylerMod() {}
	void run(TModel& Mod);
};



class TDormandPriceIntegrator : public TIntegrator {
protected:
	
	double a[7][6];
	double b[7];
	double b1[7];
	double c[7];
	TVector k[7];
public:
	TDormandPriceIntegrator();
	void run(TModel& Mod);
};
};
#endif //MY_SYMBOL_H2
