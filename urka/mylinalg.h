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
		// Оператор доступа к элементам вектора
		inline double& operator[](int i) { return data[i]; }
		// Оператор константного доступа к элементам вектора
		inline const double& operator[](int i) const { return data[i]; }
		// Оператор - унарный минус
		TVector operator - () ;
		TVector operator - (const TVector& arg) ;
		TVector operator + (const TVector& arg) ;
		TVector operator * (const double & arg) ;
		// Оператор скалярного умножения векторов
		double operator * (const TVector& arg) ;
		// Оператор умножения вектора на матрицу
		//TVector operator * (const TMatrix& arg) const;

		// Оператор векторного умножения векторов
		TVector operator ^ (const TVector& arg) const;
		// Дружественная функция - оператор умножения числа на вектор
		friend TVector operator * (double lvalue, const TVector& rvalue);
		// Функция получения модуля вектора
		double length() const;
		// Функция нормирования вектора
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

		// Оператор константного доступа к элементам вектора

		inline const double& operator()(int i, int j) const { return data[i][j]; }

		TMatrix operator - () const;
		TMatrix operator - (const TMatrix& arg) const;
		TMatrix operator + (const TMatrix& arg) const;
		TMatrix operator * (double arg) const;
		TMatrix operator * (const TMatrix& arg) const;

//	/ Оператор умножения матрицы на вектор

		TVector operator * (const TVector& arg) const;

		// Дружественная функция - оператор умножения числа на матрицу

		//friend TMatrix operator * (double lvalue, const TMatrix& rvalue);
		
		// Оператор обращения матриц (метод Гаусса)

		TMatrix operator ! () const ;
		
		// Холецкого

		TMatrix Hol() const;

		// Функция вычисления детерминанта

		double det() const;

		// Функция транспонирования

		TMatrix t() const;

		// Функция формирования единичной матрицы

		static TMatrix E(int n);
		// Функция перестановки строк

		//TMatrix& swapRows(int i, int j);

	};
}
#endif //MY_SYMBOL_H