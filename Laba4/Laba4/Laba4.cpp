// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "pch.h"
#include <iostream>
// 1.СИНТАКСИС
// синтаксис объявления указателей "тип_данных * имя_указателя;"
// фактически, указатель - это unsigned int или unsigned long long с адресом,
// так как дробных или отрицательных адресов нет
int * ptr_int;
int * ptr_dbl;
int * arr;
int arr1D[10] = { 1, 50, 11, 12, 101 };
int


// 2. РАЗМЕР УКАЗАТЕЛЯ
// ВСЕ указатели всегда одной и той же разрядности
// каким бы ни был огромным тип данных (строка, объект, массив)
// указатель на него всегда будет занимать 4\8 байт, что и является основным
// преимуществом указателей std::cout << "int pointer size = "
;
using namespace std;
int main()
{
	int * ptr_int;
	double * ptr_dbl;

	cout << "int pointer size =" << sizeof(ptr_int) << endl;
	cout << "double pointer size =" << sizeof(ptr_dbl) << endl;
	cout << "char pointer size =" << sizeof(char *) << endl;
	cout << "long long pointer size =" << sizeof(long long *) << endl;
	cout << "bool pointer size =" << sizeof(bool *) << endl;

	int arr1D[5] = { 1, 2, 3, 4, 5 };
	cout << "arr = " << arr1D << endl;
	cout << "*arr = arr[0] = " << *arr1D << endl;
	cout << "*(arr+4) = arr[4] = " << *(arr1D + 4) << endl;

}

// 3. СОДЕРЖИМОЕ УКАЗАТЕЛЯ