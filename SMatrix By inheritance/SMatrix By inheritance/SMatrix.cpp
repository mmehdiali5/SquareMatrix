#include<iostream>
using namespace std;
#include"SMatrix.h"

SMatrix::SMatrix(int o):Matrix(o,o)
{}

int SMatrix::getOrder()
{
	return order;
}

SMatrix & SMatrix::operator=(const Matrix & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	Matrix::operator=(ref);
	order = ref.getRows();
	return *this;
}

SMatrix::SMatrix(const SMatrix & ref):Matrix(ref)
{
	order = ref.order;
}

SMatrix::SMatrix(const Matrix & ref) : Matrix(ref)
{
	order = ref.getRows();
}