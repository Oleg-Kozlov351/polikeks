#include "pch.h"
#include <iostream>
#include <Windows.h>
struct pair
{
	double x;
	double y;
};
extern "C" __declspec(dllimport) double dicr(double a, double b, double c);
extern "C" __declspec(dllimport) pair quadratic_equation(double a, double b, double c);
//typedef double (CALLBACK* DISCR)(double, double, double);
//typedef pair (CALLBACK* QUADRATIC)(double, double, double);
int main()
{
	/*HINSTANCE hDLL;
	hDLL = LoadLibrary(L"C:/Users/antos/OneDrive/Рабочий стол/GitHubReposytory/x64/Debug/Dynamic_lib.dll");
	std::cout << hDLL << std::endl;
	DISCR discr = (DISCR)GetProcAddress(hDLL, "dicr");
	std::cout << discr;
	QUADRATIC qudr_eq = (QUADRATIC)GetProcAddress(hDLL, "quadratic_equation");*/
	double a, b, c;
	double x1 = 0;
	double x2 = 0;
	pair result;
	std::cin >> a >> b >> c;
	//result = qudr_eq(a, b, c);
	result = quadratic_equation(a, b, c);
	x1 = result.x;
	x2 = result.y;
	std::cout << x1 << " " << x2;
}