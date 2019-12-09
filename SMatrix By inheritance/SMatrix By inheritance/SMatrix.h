#ifndef SMATRIX_H
#define SMATRIX_H
#include"Matrix.h"

class SMatrix:public Matrix
{
public:
	int order;
public:
	SMatrix(int o=1);
	SMatrix& operator=(const Matrix & ref);
	SMatrix(const Matrix & ref);
	SMatrix(const SMatrix & ref);
	int getOrder();
};

#endif
