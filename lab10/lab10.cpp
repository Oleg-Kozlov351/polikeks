#include "pch.h"
#include <iostream>
#include "..\Lab10_static_lib\matrix.h"
int main()
{
	dynamic_matrix_with_operators matr1, matr2, matr3;
	hello();
	matr1.input();
	matr1.print();
	matr2.input();
	matr3 = matr1 + matr2;
	std::cout << matr3 << std::endl;
	matr3 = matr1 * matr2;
	//std::cout << matr3 << std::endl;
	//matr1.multMatrix(matr2);
	//matr1.summMatrix(matr2);
	//matr1.transpMatrix();
	//matr1.print();
	//matr1.clear();
	//matr2.clear();
}