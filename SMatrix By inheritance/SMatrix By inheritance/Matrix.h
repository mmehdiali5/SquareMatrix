#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
	int rows, cols;
	double**data;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix &);
	Matrix& operator=(const Matrix &);
	~Matrix();
	double &at(int, int);
	const double&at(int, int)const;
	double& operator()(int a, int b);
	int getRows()const;
	int getColumns()const;
	void display()const;
	Matrix Transpose()const;
	Matrix add(const Matrix &)const;
	Matrix operator+(const Matrix &)const;
	Matrix multiply(const Matrix &)const;
	void reSize(int, int);
};

#endif 



