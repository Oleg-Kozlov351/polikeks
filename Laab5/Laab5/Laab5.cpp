#include "pch.h"
#include <iostream>
#include <string>


using namespace std;

// 1.СИНТАКСИС ОБЪЯВЛЕНИЯ КЛАССА
// class Имя_класса
// {
//     int hp; //число хп
//     double speed; // скорость персонажа
//     void heal(); // восстановление хп
//     void move(); // проигрывание анимации движения
// }

// определение класса и объекта
// СВОЙСТВО (PROPERTY) - ПЕРЕМЕННАЯ В СОСТАВЕ КЛАССА
// МЕТОД (METHOD) - функция в составе класса
// ИНКАПСУЛЯЦИЯ - ФАКТИЧЕСКИ, ОБЪЕДИНЕНИЕ ДАННЫХ И МЕТОДОВ, ОБЪЕДИНЕННЫХ
// единым смыслом, в одну конструкцию языка
// НАСЛЕДОВАНИЕ - СОЗДАНИЕ ПРОИЗВОДНЫХ КЛАССОВ ОТ РОДИТЕЛЬСКОГО И ЗАИМСТВОВАНИЕ
// ЕГО СВОЙСТВ И МЕТОДОВ
// ПОЛИМОРФИЗМ простыми словами: экземпляры одного класса ведут себя по-разному
// инкапсуляуции, наследствие и полиморфизм - три основные идеи
class vehicle // игровое транспортное средство
{
private:
public:
	double speed; // скорость
	char regnumber[6] = { 0 }; // госномер
	unsigned char capacity; // число пассажиров

	bool check_regnumber() // если зарегестрирован - true
	{
		// если метод небольшой то определение пишется прямо в классе

		// если номер K370AO - возвращает true
		const char * true_number = "K370AO";
		bool result = true;

	}
	// void add_passanger(int passangers);
	// void accelerate(double delta_velocity);
};
void array_equalization(char * first_array, char * second_array) {
	int lenght = strlen(first_array);
	for (int i = 0; i < lenght; i++) {
		second_array[i] = first_array[i];
	}
}
void print_array_chr(char * arr) {
	int lenght = strlen(arr);
	for (int i = 0; i < lenght; i++) {
		std::cout << arr[i];
	}
}
class user_data
{
private:
	char first_name[255];
	char second_name[255];
	char str_passport[10];
	char str_birthdate[10];
public:
	user_data(); //конструктор
	~user_data(); //деструктор;

	user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10]);

	user_data(char * p_first_name, char * p_second_name);

	bool set_first_name(char p__first_name[255])
	{
		for (int i = 0; i < 10; i++)
		{
			if (p__first_name[i] > '64' || p__first_name[i] < '91') {}
			else
				return false;
			p__first_name[i] = p__first_name[i];

		}
		return true;
		//проверять на отстутствие цифр, точек и других знаком препинания кроме "-"


		//проверять на отсутствие точек, цифр и других знаков препинания кроме тире

	};
	bool set_secondname(char * p_secondname) {
		int lenght = strlen(p_secondname);
		for (int i = 0; i < lenght; i++) {
			if (p_secondname[i] < 'A' || (p_secondname[i] > 'Z' &&
				p_secondname[i] < 'a') || p_secondname[i] > 'z') {
				if (p_secondname[i] == '-') {
					continue;
				}
				return false;
			}
		}
		array_equalization(p_secondname, second_name);
		return true;
		//проверять на отсутствие цифр, точек и других знаков препинания кроме "-"
	};
	bool set_birthdate(char p_birthdate[10])
	{
		for (int i = 0; i < 2; i++) {
			if (p_birthdate[i] < '0' || p_birthdate[i] > '9') {
				return false;
			}
		}
		return true;
		//должно соответствовать формату "00.00.0000"

	};

	bool set_passport(char p_passport[10])
	{
		for (int i = 0; i < 10; i++) {
			if (p_passport[i] < '0' || p_passport[i] > '9') {
				return false;
			}
		}
		return true;
		//должно соответствовать формату "0000000000"

	};
	void print_user_data() {
		//print_array_chr(first_name);
		//print_array_chr(second_name);
		print_array_chr(str_passport);
		print_array_chr(str_birthdate);

	}
};
user_data::user_data() {
};// конструктор
user_data::~user_data() {
}; // деструктор
user_data::user_data(char * p_first_name, char * p_second_name, char * p_str_passport, char * p_str_birthdate) {
	//first_name = p_first_name;
	if (set_first_name(p_first_name)) {
		std::cout << "Firstname is fine\n";
	}
	if (set_secondname(p_second_name)) {
		std::cout << "Secondname is fine\n";
	}
	if (set_passport(p_str_passport)) {
		std::cout << "Passport is fine\n";
	}
	if (set_birthdate(p_str_birthdate)) {
		std::cout << "Birthdate is fine\n";
	}
};
user_data::user_data(char * p_first_name, char * p_second_name) {
	//first_name = p_first_name;
	set_first_name(p_first_name);
	set_secondname(p_second_name);
};





	/*2.СИНТАКСИС ОБЪЯВЛЕНИЯ ОБЪЕКТА И ОБРАЩЕНИЯ К СВОЙСТВАМ И МЕТОДАМ
	Имя_класса объект1;
	vehicle car;
	car.speed = 123;
	объект1.свойство1 = 1;
	объект1.метод3();
	*/

	/*
	3. СПЕЦИФИКАТОРЫ ДОСТУПА
	к полям (свойствам и методам), объявленным в разделе public:
	можно обращаться везде( и из методов класса и снаружи

	*/

	
int main()
{

	user_data birthdate;
	char birthdate_array[11] = "29.01.2001";
	char secondname_array[255] = "Kozlov";
	char firstname_array[255] = "Oleg";
	char passport_array[11] = "1111385612";
	if (birthdate.set_first_name(firstname_array)) {
		std::cout << "All right\n";
             
	}
	else {
		std::cout << "Error";
	}
	user_data user1;
	user_data user2(firstname_array, secondname_array, passport_array, birthdate_array);
}