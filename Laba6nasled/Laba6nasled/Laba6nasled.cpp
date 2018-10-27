// Laba6nasled.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int i = -15;
	double d = 1000.5e03; 
	float result1;
	long long result2;
	result1 = i + d;
	result2 = i / d;
	char  ch1[255] = "123.4";
	char  ch2[255] = "456.7";

	std::cout << "First: ";
	std::cin >> ch1;
	std::cout << std::endl;

	std::cout << "Second: ";
	std::cin >> ch2;
	std::cout << std::endl;

	i = atoi(ch1);
	d = atof(ch2);
	d += i;
	std::cout << d << std::endl;
}

/* Наследование - свойств и методов родительского класса в производном классе.
синтаксис
class имя_произв_класса : [тип наследования] имя_родительского_класса1
						  [тип наследования] имя_родительского_класса2
{
...
}
В род.			В загаловке при наследовании
классе			public:			protected:		private:
public:			public:			protected:		private:
protected:		protected:		private:		protected:
privat:			not inherited   not inherited   not inherited
где "тип_наследования" - тоже public, protected и privat, но указывать не обязательно
2. Метод, переопределённый в дочернем классе полностью заменит унаследованный родительский метод
Чтобы при запуске нового дочернего метода также выполнять и родительский необходимо указать это явно
в родительском классе void weapon::reload() {};
в дочернем классе void rifle::reload():weapon::reload(),...{};
3. Если объявить метод со словом virtual, в данном классе можно не приводить реализацию метода, и определеить его (привести реализацию)
только в дочерних классах
4. void fnc1 (const тип1 параметр1, тип2 параметр2)
{
параметр1 = 10;
}
объявление константного метода класса запрещает ему изменять какое-либо из свойств объекта
													\/
 void fnc1 (const тип1 параметр1, тип2 параметр2) const
{
параметр1 = 10;
}
*/


