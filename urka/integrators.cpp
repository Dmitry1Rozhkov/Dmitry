#include "integrators.h"
double iii::TIntegrator::u() const {
	double v = 1;
	double u;
	while (1 + v > 1) {
		u = v;
		v = v / 2;
	};
	return u;
};

void iii::TEylerMod::run(TModel & Mod)
{
	if (h == 0) h = u();

	double t = Mod.getT0();


	while ((t < Mod.getT1()) && (!StopIntg))
	{
        int kolfunc = Mod.getLengthVecSost();
        TVector y(kolfunc);
        y = Mod.GetX();
        TVector y_forecast(kolfunc);

		y_forecast = y + Mod.getRight(y, t)*h;
        y = y + Mod.getRight(y, t)*(h / 2.) + Mod.getRight(y_forecast, t + h) * h * 0.5;
		Mod.addResult(y, t);
            t += h;
	};

}


iii::TDormandPriceIntegrator::TDormandPriceIntegrator()
{
	a[0][0] = 0;                 a[0][1] = 0;                  a[0][2] = 0;                  a[0][3] = 0;                a[0][4] = 0;                   a[0][5] = 0;
	a[1][0] = 1.0/5.0;           a[1][1] = 0;                  a[1][2] = 0;                  a[1][3] = 0;                a[1][4] = 0;                   a[1][5] = 0;
	a[2][0] = 3.0/40.0;          a[2][1] = 9.0 / 40.0;         a[2][2] = 0;                  a[2][3] = 0;                a[2][4] = 0;                   a[2][5] = 0;
	a[3][0] = 44.0 / 45.0;       a[3][1] = -56.0 / 15.0;       a[3][2] = 32.0 / 9.0;         a[3][3] = 0;                a[3][4] = 0;                   a[3][5] = 0;
	a[4][0] = 19372.0 / 6561.0;  a[4][1] = -25360.0 / 2187.0;  a[4][2] = 64448.0 / 6561.0;   a[4][3] = -212.0 / 729.0;   a[4][4] = 0;                   a[4][5] = 0;
	a[5][0] = 9017.0 / 3168.0;   a[5][1] = -355.0 / 33.0;      a[5][2] = 46732.0 / 5247.0;   a[5][3] = 49.0 / 176.0;     a[5][4] = -5103.0 / 18656.0;   a[5][5] = 0;
	a[6][0] = 35.0 / 384.0;      a[6][1] = 0;                  a[6][2] = 500.0 / 1113.0;     a[6][3] = 125.0 / 192.0;    a[6][4] = -2187.0 / 6784.0;    a[6][5] = 11.0 / 84.0;

	b1[0] = 5179.0 / 57600.0;       b[0] = 35.0 / 384.0;          c[0] = 0;
	b1[1] = 0;                      b[1] = 0;                     c[1] = 1.0 / 5.0;
	b1[2] = 7571.0 / 16695.0;       b[2] = 500.0 / 1113.0;        c[2] = 3.0 / 10.0;
	b1[3] = 393.0 / 640.0;          b[3] = 125.0 / 192.0;         c[3] = 4.0 / 5.0;
	b1[4] = -92097.0 / 339200.0;    b[4] = -2187.0 / 6784.0;      c[4] = 8.0 / 9.0;
	b1[5] = 187.0 / 2100.0;         b[5] = 11.0 / 84.0;           c[5] = 1.0;
	b1[6] = 1.0 / 40.0;             b[6] = 0;                     c[6] = 1.0;
	epsmax = 1e-10;
	zero = u();
}
void iii::TDormandPriceIntegrator::run(TModel & Mod)
{
	double h;
	double	h_new =Mod.SamplingIncrement;
	double teta;
	TVector beta(6);
    TVector x0 = Mod.GetX();;
    TVector y4(Mod.getLengthVecSost());
    TVector y5(Mod.getLengthVecSost());
    TVector y6(Mod.getLengthVecSost());
	double t = Mod.getT0();
	double t_out = t;
	double eps = 0;
	double epssumm=0;
	TVector sum;
	while (t < Mod.getT1()) {
		h = h_new;
		sum = x0;
		k[0] = Mod.getRight(sum, t);
		sum = x0 + k[0] * (h*a[1][0]);
		k[1] = Mod.getRight(sum, t + h * c[1]);
		sum = x0 + (k[0] * a[2][0] + k[1] * a[2][1])*h;
		k[2] = Mod.getRight(sum, t + h * c[2]);
		sum = x0 + (k[0] * a[3][0] + k[1] * a[3][1] + k[2] * a[3][2])*h;
		k[3] = Mod.getRight(sum, t + h * c[3]);
		sum = x0 + (k[0] * a[4][0] + k[1] * a[4][1] + k[2] * a[4][2] + k[3] * a[4][3])*h;
		k[4] = Mod.getRight(sum, t + h * c[4]);
		sum = x0 + (k[0] * a[5][0] + k[1] * a[5][1] + k[2] * a[5][2] + k[3] * a[5][3] + k[4] * a[5][4])*h;
		k[5] = Mod.getRight(sum, t + h * c[5]);
		sum = x0 + (k[0] * a[6][0] + k[1] * a[6][1] + k[2] * a[6][2] + k[3] * a[6][3] + k[4] * a[6][4] + k[5] * a[6][5])*h;
		k[6] = Mod.getRight(sum, t + h * c[6]);
		y4 = x0 + (k[0] * b[0] + k[1] * b[1] + k[2] * b[2] + k[3] * b[3] + k[4] * b[4] + k[5] * b[5] + k[6] * b[6])*h;
		y5 = x0 + (k[0] * b1[0] + k[1] * b1[1] + k[2] * b1[2] + k[3] * b1[3] + k[4] * b1[4] + k[5] * b1[5] + k[6] * b1[6])*h;
		epssumm = 0;
		h_new = h / (max(0.1, min(5.0, pow((eps / epsmax), 0.2) / 0.9)));
        for (int j = 0; j < Mod.getLengthVecSost(); j++) {
			epssumm += pow((h*(y4[j] - y5[j])) / (max(max(pow(10.0, -5.0), abs(y4[j])), max(abs(x0[j]), 2.0 * u() / epsmax))), 2.0);
		}
        eps = pow((epssumm / Mod.getLengthVecSost()), 0.5);
		if (epsmax < eps)
			continue;
		while ((t_out < (t + h)) && (t_out <= Mod.getT1())) {
			teta = (t_out - t) / h;
			beta[0] = teta * (1.0 + teta * (-1337.0 / 480.0 + teta * (1039.0 / 360.0 + teta * (-1163.0 / 1152.0))));
			beta[1] = 0;
			beta[2] = 100.0 * pow(teta, 2.0)*(1054.0 / 9275.0 + teta * (-4682.0 / 27825.0 + teta * (379.0 / 5565.0))) / 3.0;
			beta[3] = -5 * pow(teta, 2)*(27.0 / 40.0 + teta * (-9.0 / 5.0 + teta * (83.0 / 96.0))) / 2.0;
			beta[4] = 18225 * pow(teta, 2)*(-3.0 / 250.0 + teta * (22.0 / 375.0 + teta * (-37.0 / 600.0))) / 848.0;
			beta[5] = -22 * pow(teta, 2)*(-3.0 / 10.0 + teta * (29.0 / 30.0 + teta * (-17.0 / 24.0))) / 7.0;
			y6 = x0;
			for (int j = 0; j < 6; j++)
				y6 = y6 + k[j] * beta[j]* h;
			Mod.addResult(y6, t_out);
			t_out += Mod.SamplingIncrement;
		}
		//system("pause");
		t += h;
		x0 = y4;
	}
}

