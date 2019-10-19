#ifndef MY_SYMBOL_H
#define MY_SYMBOL_H
#include <iostream>
#include <math.h>
namespace MyLinearAlgebra {
	class TMatrix;
	class TVector {
	protected:
		int n;
		double *data;
	public:
		TVector();
		TVector(int n);
		TVector(const TVector& rvalue);
		TVector& operator = (const TVector& rvalue);
		virtual ~TVector();
		inline int size() const { return n; }
		inline int high() const { return n - 1; }
		void resize(int n);
		// �������� ������� � ��������� �������
		inline double& operator[](int i) { return data[i]; }
		// �������� ������������ ������� � ��������� �������
		inline const double& operator[](int i) const { return data[i]; }
		// �������� - ������� �����
		TVector operator - () ;
		TVector operator - (const TVector& arg) ;
		TVector operator + (const TVector& arg) ;
		TVector operator * (const double & arg) ;
		// �������� ���������� ��������� ��������
		double operator * (const TVector& arg) ;
		// �������� ��������� ������� �� �������
		//TVector operator * (const TMatrix& arg) const;

		// �������� ���������� ��������� ��������
		TVector operator ^ (const TVector& arg) const;
		// ������������� ������� - �������� ��������� ����� �� ������
		friend TVector operator * (double lvalue, const TVector& rvalue);
		// ������� ��������� ������ �������
		double length() const;
		// ������� ������������ �������
		TVector& norm();
	};


	class TMatrix {

	protected:
		int n, m;
		double **data;
	public:

		TMatrix();
		TMatrix(int n, int m);
		TMatrix(const TMatrix& rvalue);
		TMatrix& operator = (const TMatrix& rvalue);
		virtual ~TMatrix();
		inline int rowCount() const  { return n; }
		inline int colCount() const { return m; }
		inline int rowHigh() const { return n - 1; }
		inline int colHigh() const { return m - 1; }
		void resize(int n, int m);
		inline double& operator()(int i, int j) { return data[i][j]; }

		// �������� ������������ ������� � ��������� �������

		inline const double& operator()(int i, int j) const { return data[i][j]; }

		TMatrix operator - () const;
		TMatrix operator - (const TMatrix& arg) const;
		TMatrix operator + (const TMatrix& arg) const;
		TMatrix operator * (double arg) const;
		TMatrix operator * (const TMatrix& arg) const;

//	/ �������� ��������� ������� �� ������

		TVector operator * (const TVector& arg) const;

		// ������������� ������� - �������� ��������� ����� �� �������

		//friend TMatrix operator * (double lvalue, const TMatrix& rvalue);
		
		// �������� ��������� ������ (����� ������)

		TMatrix operator ! () const ;
		
		// ���������

		TMatrix Hol() const;

		// ������� ���������� ������������

		double det() const;

		// ������� ����������������

		TMatrix t() const;

		// ������� ������������ ��������� �������

		static TMatrix E(int n);
		// ������� ������������ �����

		//TMatrix& swapRows(int i, int j);

	};
}
#endif //MY_SYMBOL_H