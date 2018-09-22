// Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "pch.h"
#include <iostream>


int main()
{
	//создать челочисленные переменные a = 300
	// b = 560
	// вывести на экран a*a*b*b
	//              b/a
	//              символ_A + a
	long long a = 300;
	long long b = 560;
	std::cout << "a * a * b * b = " << a * a * b * b << std::endl;
	std::cout << "/n";
	std::cout << "b / a = " << b / a << std::endl;
	std::cout << "SizeOfInt = " << sizeof(int);
	int max_int = 0b0111111111111111;
	std::cout << "SizeOfInt = " << sizeof(int) << std::endl;
	std::cout << "MaxInt = " << max_int << std::endl;
	/*вывести таблицу
	тип данных - занимаемый размер - мин значение - максимальное значение
	bool
	char
	int
	long
	long long
	double*/
	std::cout << "bool " << "SizeOfBool = " << sizeof(bool) << " MinBool = 0" << "\t" << "MaxBool = 255 " << "\t" << std::endl;
	std::cout << "char" << "SizeOfChar = " << sizeof(char) << "MinChar = " << CHAR_MIN << "\t" << "MaxChar = " << CHAR_MAX << std::endl;
	std::cout << "int" << "SizeOfInt = " << sizeof(int) << "MinInt = " << INT32_MIN << "\t" << "MaxInt = " << INT32_MAX << std::endl;
	std::cout << "long" << "SizeOfLong = " << sizeof(long) << "MinLong = " << LONG_MIN << "\t" << "MaxLong = " << LONG_MAX << std::endl;
	std::cout << "llong" << "SizeOfLlong = " << sizeof(long long) << "MinLlong = " << LLONG_MIN << "\t" << "MaxLlong = " << LLONG_MAX << std::endl;
	std::cout << "double" << "SizeOfDouble = " << sizeof(double) << "MinDouble = " << DBL_MIN << "\t" << "MaxDouble = " << DBL_MAX << std::endl;


	










		return 0;
}