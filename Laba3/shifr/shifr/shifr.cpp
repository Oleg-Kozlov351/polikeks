// shifr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
 
int main()
{
	using std::cin;
	char a[50] = { 0 };
	std::cin >> a;
	for (int i = 0; i < strlen(a); i++) {
		a[i] += 3;
		if (((a[i] > 'Z') && (a[i] < 'a')) || (a[i] > 'z'))
			a[i] = a[i] - 26;
	}
	std::cout << a;
}