#include<iostream>
using namespace std;
#include"SMatrix.h"

int main()
{
	SMatrix m(2);
	SMatrix n(2);
	m.at(0, 0) = 0;
	m.at(0, 1) = 1;
	m.at(1, 0) = 2;
	m.at(1, 1) = 3;
	n.at(0, 0) = 0;
	n.at(0, 1) = 1;
	n.at(1, 0) = 2;
	n.at(1, 1) = 3;
	SMatrix o=m+n;
	SMatrix b(o);
	b.display();
	cout << b.order;
	//m.Transpose().getOrder();
	cout << "\n\n\n\n\n\n\n";
	return 0;
}