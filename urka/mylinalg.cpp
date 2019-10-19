#include "mylinalg.h"
using namespace MyLinearAlgebra;
const double eps = 10e-16;
// �������

TVector::TVector() : n(0), data(NULL) {}

TVector::TVector(int n) : n(0), data(NULL) {resize(n);}
TVector::TVector(const TVector& rvalue) : n(0), data(NULL) {(*this) = rvalue;}

TVector& TVector::operator = (const TVector& rvalue) {
	// ���� ����� ������� �� ��������� � ������
	if (this != &rvalue) {
		// ���� ������ ������ �������� �� ��������� � ������, �� ������ ���������� ������
		if (n != rvalue.n) {
			// ���� ������ ��� ���� ��������, ������� �
			if (data) { delete[] data; }
			// ��������� ����� ������
			data = new double[rvalue.n];
			// ���������� ������ �������
			n = rvalue.n;
		}
		// ������� ������ �� ������� �������� � �����
		memcpy(data, rvalue.data, sizeof(double) * n);
	}

	// ������� ������ �� ����� ������� ��� ����������� ������� ������������
	return *this;
}


TVector::~TVector() {
	// ���� ���� ������ ����� ��� ���������������, ������� ���
	if (data) {
		delete[] data;
		n = 0;
		data = NULL;	}
}

// ������� ������� ���-�� ��������� �������

void TVector::resize(int n) {
#ifdef _DEBUG
	if (n < 0)
		throw 1;
#endif
	// ���� ����� ������ ��������� �� ������ - �������
	if (n == this->n) return;
	// ����� ���� ������
	double *newData = new double[n];
	// ���� ���� ������ ����� ��� ���������������...
	if (data) {
		// ����������� �� ������� � ������ ������� �����
		int min_n = (this->n < n) ? this->n : n;
		// ������� ������ �� ������� ����� � �����
		memcpy(newData, data, sizeof(double)*min_n);
		// �������� ������� �����
		delete[] data;
	}
	// ������������ ������ ����� � ������� �������
	data = newData;
	// ���������� ������ �������
	this->n = n;
}

// �������� �������� ��������

TVector MyLinearAlgebra::TVector::operator-() 
{
	TVector V(n);
	for (int i = 0; i < n; i++)
		V[i] -= data[i] ;
	return V;
}

TVector MyLinearAlgebra::TVector::operator-(const TVector & arg) 
{
#ifdef _DEBUG
	if (n != arg.n)
		throw 1;
#endif
	TVector V(n);
	for (int i = 0; i < n; i++)
		V[i] = data[i] - arg[i];
	return V;
}

TVector TVector::operator + (const TVector& arg)  {
#ifdef _DEBUG
	if (n != arg.n)
		throw 1;
#endif
	TVector V(n);
	for (int i = 0; i < n; i++)
		V[i] = data[i] + arg[i];
	return V;
}

TVector MyLinearAlgebra::TVector::operator*(const double & arg) {
	TVector V(n);
	for (int i = 0; i < n; i++)
		V[i] = data[i] *arg;
	return V;
}

double MyLinearAlgebra::TVector::operator*(const TVector & arg) 
{
#ifdef _DEBUG
	if (n != arg.n)
		throw 1;
#endif
	double V=0;
	for (int i = 0; i < n; i++)
		V += data[i] * arg[i];
	return V;
}

TVector MyLinearAlgebra::TVector::operator^(const TVector & arg) const
{
#ifdef _DEBUG
	if (n != arg.n)
		throw 1;
#endif
	TVector V(n);
	V[0] = data[1] * arg[2] - data[2] * arg[1];
	V[1] = data[2] * arg[0] - data[0] * arg[2];
	V[2] = data[0] * arg[1] - data[1] * arg[0];
	return V;
}

double MyLinearAlgebra::TVector::length() const
{
    double V=0;
	for (int i = 0; i < n; i++)
		V += pow(data[i],2);
	return pow(V,0.5);
}


// �������

TMatrix::TMatrix() : n(0), m(0), data(NULL) {}
TMatrix::TMatrix(int n, int m) : n(0), m(0), data(NULL) { resize(n, m); }
// ����������� �����
TMatrix::TMatrix(const TMatrix& rvalue) : n(0), m(0), data(NULL) { (*this) = rvalue; }

TMatrix& TMatrix::operator = (const TMatrix& rvalue) {
	// ���� ����� ������� �� ��������� � ������
	if (this != &rvalue) {
		// �������� ����� ���������� ������
		this->~TMatrix();
		// ��������� ����� ������ �� �������� ������� ��������
		resize(rvalue.n, rvalue.m);
		// ������� ������ �� ������� �������� � ����� ���������
		for (int i = 0; i < n; i++)
			memcpy(data[i], rvalue.data[i], sizeof(double)*m);
	}
	// ������� ������ �� ����� ������� ��� ����������� ������� ������������
	return (*this);
}

// ���������� ������� �������

TMatrix::~TMatrix() {
	if (data) {
		for (int i = 0; i < n; i++)
			delete[] data[i];
		delete[] data;
		data = NULL;
		n = m = 0;	}
}

// ������� ������� ����������� �������

void TMatrix::resize(int n, int m) {
	// ���-�� �����, ������� ����� ��������� � ����� ����� ������
	int min_n = this->n < n ? this->n : n;
	// ���� ���-�� �������� �� ���������
	if (this->m != m) {
		// ���-�� ��������, ������� ����� ��������� � ����� ����� ������
		int min_m = this->m < m ? this->m : m;
		// ���� ����������� �������� ������ � ����� �����
		for (int i = 0; i < min_n; i++) {
			// �������� ������ �����-������
			double *newDataRow = new double[m];
			// ������� ������ � ����� ����-������
			memcpy(newDataRow, data[i], sizeof(double)*min_m);
			// �������� ������� ����� ������ �� ���� �����
			delete[] data[i];
			// ������������ ������ �����-������ �� ������ �����
			data[i] = newDataRow;		}
		// ���������� ������ �������
		this->m = m;
	}
	// ���� ���-�� ����� �� ���������
	if (this->n != n) {
		// �������� ������ �����-����������
		double **newData = new double*[n];
		// ������� ����������� ������� ���������� � �����
		memcpy(newData, data, sizeof(double*)*min_n);
		// �������� ������ ����� �� ������� ����������
		for (int i = n; i < this->n; i++) { delete[] data[i]; }
		// �������� ������� ����������
		if (data) { delete[] data; }
		// �������� ����������� ����� � ����� ����������
		for (int i = this->n; i < n; i++) { newData[i] = new double[m]; }
		// �������� ������� ���������� � ������
		data = newData;
		this->n = n;	}
}


TMatrix MyLinearAlgebra::TMatrix::operator-() const
{
	TMatrix M(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M(i, j) =-1*data[i][j] ;
	return M;
}

TMatrix MyLinearAlgebra::TMatrix::operator-(const TMatrix & arg) const
{
#ifdef _DEBUG
	if ((n != arg.n) || (m != arg.m))
		throw 1;
#endif
	TMatrix M(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M(i, j) = data[i][j] - arg(i, j);
	return M;
}
TMatrix TMatrix::operator + (const TMatrix& arg) const {
#ifdef _DEBUG
	if ((n != arg.n) || (m != arg.m))
		throw 1;
#endif
	TMatrix M(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M(i, j) = data[i][j] + arg(i, j);
	return M;
}

TMatrix MyLinearAlgebra::TMatrix::operator*(double arg) const
{

	TMatrix M(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M(i, j) = arg*data[i][j];
	return M;
}

TMatrix MyLinearAlgebra::TMatrix::operator*(const TMatrix & arg) const
{
#ifdef _DEBUG
	if ((n != arg.m) || (n != arg.m))
		throw 1;
#endif
	TMatrix M(n, arg.m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < arg.m; j++)
			M(i, j) = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < arg.m; j++)
			for (int l = 0;  l < arg.n ; l++)
			M(i, j) += arg(l, j)*data[i][l] ;
	return M;
}

TVector MyLinearAlgebra::TMatrix::operator*(const TVector & arg) const
{
	TVector res(3); res[0] = 0; res[1] = 0; res[2] = 0;
	for (int i = 0; i < this->rowCount(); i++)
		for (int j = 0; j < this->colCount(); j++)
			res[i] += data[i][j] * arg[j];

	return res;
}


TMatrix MyLinearAlgebra::TMatrix::operator!() const {
	double b;
	TMatrix M(n, n), N(n,n);
	M=M.E(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			N(i, j) = data[i][j];
	
	
	for (int i = 0; i < n; i++)
	{
		if (N(i, i) == 0)
		{
			double Buffer = 0;
			int t = 0;
			int y = 1;
			while (t == 0) {
				if (!(N(y, i) == 0)) {
					for (int j = 0; j < n; j++) {
						Buffer = N(i, j);
						N(i, j) = N(y, j);
						N(y, j) = Buffer;
						Buffer = M(i, j);
						M(i, j) = M(y, j);
						M(y, j) = Buffer;
					}
					t = 1;
				}
				y += 1;
			}
		}
		b = N(i, i);
		for (int j = 0; j < n; j++) {
			M(i, j) = M(i, j) / b;
			N(i,j) = N(i, j) / b;
		}
		for (int l = 0; l < n; l++)
			if (!(l == i)) {
				b = N(l, i);
				for (int j = 0; j < n; j++)
				{
					N(l, j) = N(l, j) - b * N(i, j);
					M(l, j) = M(l, j) - M(i, j) * b;
				}
			}
	}
	
	return M;
}

TMatrix MyLinearAlgebra::TMatrix::Hol() const
{
	TMatrix A(n, n), L(n, n), X(n, n);
	double Summ=0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			L(i, j) = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			X(i, j) = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A(i, j) = data[i][j];

	L(0, 0) = sqrt(A(0, 0));
	for (int i = 1; i < n; i++)
		L(i, 0) = A(i, 0) / L(0, 0);

	for (int j = 1; j < n; j++)
	{
		Summ = 0;
		for (int p = 0; p <= j - 1; p++)
			Summ += pow(L(j, p),2);
			L(j, j) = sqrt(A(j, j) - Summ);

			for (int i = j + 1; i < n; i++) {
				Summ = 0;
			for (int p = 0; p <= i - 1; p++)
				Summ += L(j, p)*L(i, p);
			L(i, j) = (A(i, j) - Summ) / L(j, j);
		}
	}
	for (int i = n-1 ; i >= 0; i--)
		for (int j = i; j >= 0; j--)
		{
			if (i == j) {
				Summ = 0;
				for (int k = i+1; k <n; k++)
					Summ +=L(k,i)*X(k,i);
				X(i, i) = (1 / L(i, i) - Summ)/ L(i, i);
			}
			else
			{
				Summ = 0;
				for (int k = j + 1; k <n; k++)
					Summ += L(k, j)*X(k, i);
				X(i, j) = Summ*(-1 / L(j, j));
				X(j, i) = Summ*(-1 / L(j, j));
			}
		}

	return X;
}



TMatrix MyLinearAlgebra::TMatrix::t() const
{
	double K;
	TMatrix M(m, n);
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
	{
		K = data[j][i];
		    M(i,j)=data[j][i] ;
		}
	return M;
}

TMatrix TMatrix::E(int n) {
	TMatrix E(n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				E(i, j) = 1;
			else E(i, j) = 0;
		return E;
	}

