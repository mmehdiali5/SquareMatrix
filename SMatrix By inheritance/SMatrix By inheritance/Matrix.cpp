#include<iostream>
using namespace std;
#include"Matrix.h"

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	data = nullptr;
}

Matrix::Matrix(int r, int c)
{
	rows = r;
	cols = c;
	data = new double*[rows];
	for (int i = 0; i < rows; i = i + 1)
	{
		data[i] = new double[cols];
	}
}

Matrix::~Matrix()
{
	rows = 0;
	cols = 0;
	if (!data)
	{
		return;
	}
	for (int i = 0; i < rows; i = i + 1)
	{
		delete[]data[i];
	}
	delete[]data;
	data = nullptr;
}

Matrix::Matrix(const Matrix & ref)
{
	if (!ref.data)
	{
		data = nullptr;
		rows = 0;
		cols = 0;
	}
	cols = ref.cols;
	rows = ref.rows;
	data = new double*[rows];
	for (int i = 0; i < rows; i = i + 1)
	{
		data[i] = new double[cols];
	}
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			data[i][j] = ref.data[i][j];
		}
	}
}

Matrix& Matrix::operator=(const Matrix & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	if (!ref.data)
	{
		data = nullptr;
		rows = 0;
		cols = 0;
	}
	cols = ref.cols;
	rows = ref.rows;
	data = new double*[rows];
	for (int i = 0; i < rows; i = i + 1)
	{
		data[i] = new double[cols];
	}
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			data[i][j] = ref.data[i][j];
		}
	}
	return *this;
}

double& Matrix::at(int r, int c)
{
	if (r >= 0 && r < rows && c >= 0 && c < cols)
	{
		return data[r][c];
	}
	exit(0);
}

double& Matrix::operator()(int r, int c)
{
	if (r >= 0 && r < rows && c >= 0 && c < cols)
	{
		return data[r][c];
	}
	exit(0);
}

const double& Matrix::at(int r, int c)const
{
	if (r >= 0 && r < rows && c >= 0 && c < cols)
	{
		return data[r][c];
	}
	exit(0);
}

int Matrix::getRows()const
{
	return rows;
}

int Matrix::getColumns()const
{
	return cols;
}

void Matrix::display()const
{
	int i, j;
	for (i = 0; i < rows; i = i + 1)
	{
		for (j = 0; j < cols; j = j + 1)
		{
			cout << data[i][j] << "    ";
		}
		cout << '\n';
	}
	cout << '\n';
}

Matrix Matrix::Transpose()const
{
	Matrix tr(cols, rows);
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			tr.data[j][i] = data[i][j];
		}
	}
	return tr;
}

Matrix Matrix::add(const Matrix & b)const
{
	Matrix add1(rows, cols);
	if (b.rows != rows || b.cols != cols)
	{
		exit(0);
	}
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			add1.data[i][j] = data[i][j] + b.data[i][j];
		}
	}
	return add1;
}

Matrix Matrix::operator+(const Matrix & b)const
{
	Matrix add1(rows, cols);
	if (b.rows != rows || b.cols != cols)
	{
		exit(0);
	}
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < cols; j = j + 1)
		{
			add1.data[i][j] = data[i][j] + b.data[i][j];
		}
	}
	return add1;
}

Matrix Matrix::multiply(const Matrix & b)const
{
	if (cols != b.rows)
	{
		exit(0);
	}
	Matrix multi(rows, b.cols);
	for (int i = 0; i < multi.rows; i = i + 1)
	{
		for (int j = 0; j < multi.cols; j = j + 1)
		{
			multi.data[i][j] = 0;
			for (int k = 0; k < cols; k = k + 1)
			{
				multi.data[i][j] = multi.data[i][j] + (data[i][k] * b.data[k][j]);
			}
		}
	}
	return multi;
}

void Matrix::reSize(int newRow, int newCol)
{
	Matrix newMat(newRow, newCol);
	int tempRow, tempCol;
	if (newRow <= rows)
	{
		tempRow = newRow;
	}
	else
	{
		tempRow = rows;
	}
	if (newCol <= cols)
	{
		tempCol = newCol;
	}
	else
	{
		tempCol = cols;
	}
	for (int i = 0; i < tempRow; i = i + 1)
	{
		for (int j = 0; j < tempCol; j = j + 1)
		{
			newMat.data[i][j] = data[i][j];
		}
	}
	this->~Matrix();
	data = newMat.data;
}
