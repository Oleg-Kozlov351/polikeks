#include "pch.h"
#include <iostream>
#include <string>

class vehicle // скорость
{
private: //спецификатор класса можно обратиться через метод класса
public:
	double speed; //скорость

	char regnumber[6] = { 0 };//госномер
	unsigned char capacity;//число пассажиров

	bool check_regnumber() //если зарегестрирован - true
	{

	};
	//void add_passenger(int passsengers);
	//void accelerate(double delta_velocity);
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
class user_data {
private:
	char first_name[255];
	char second_name[255];
	char str_passport[10];
	char str_birthdate[10];
public:
	user_data();// конструктор
	~user_data(); // деструктор
	user_data(char * p_first_name, char * p_second_name, char * p_str_passport, char * p_str_birhtdate);
	user_data(char * p_first_name, char * p_second_name);
	bool set_firstname(char * p_firstname) {
		int lenght = strlen(p_firstname);
		for (int i = 0; i < lenght; i++) {
			if ((p_firstname[i] < 'A') || (p_firstname[i] > 'Z' &&
				p_firstname[i] < 'a') || (p_firstname[i] > 'z')) {
				if (p_firstname[i] == '-') {
					continue;
				}
				return false;
			}
		}
		array_equalization(p_firstname, first_name);
		return true;
		//проверять на отсутствие цифр, точек и других знаков препинания кроме "-"
	}
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
	}
	bool set_birthdate(char * p_birthdate) {
		for (int i = 0; i < 10; i++) {
			if (i == 2 || i == 5) {
				if (p_birthdate[i] != '.') {
					return false;
				}
			}
			else if (p_birthdate[i] < '0' || p_birthdate[i] > '9') {
				return false;
			}
		}
		//должно соответствовать формату 00.00.0000
		array_equalization(p_birthdate, str_birthdate);
		return true;
	};
	bool set_passport(char * p_passport) {
		for (int i = 0; i < 10; i++) {
			if (p_passport[i] < '0' || p_passport[i] > '9') {
				return false;
			}
		}
		//строка должна содержать 10 цифр
		array_equalization(p_passport, str_passport);
		return true;
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
	if (set_firstname(p_first_name)) {
		std::cout << "Firstname Okey.\n";
	}
	if (set_secondname(p_second_name)) {
		std::cout << "Secondname Okey.\n";
	}
	if (set_passport(p_str_passport)) {
		std::cout << "Passport Okey.\n";
	}
	if (set_birthdate(p_str_birthdate)) {
		std::cout << "Birthdate Okey.\n";
	}
};
user_data::user_data(char * p_first_name, char * p_second_name) {
	//first_name = p_first_name;
	set_firstname(p_first_name);
	set_secondname(p_second_name);
};
int main()
{
	user_data birthdate;
	char birthdate_array[11] = "25.09.2000";
	char firstname_array[255] = "Ivanov";
	char secondname_array[255] = "Ivan";
	char passport_array[11] = "1234567890";
	if (birthdate.set_firstname(firstname_array)) {
		std::cout << "All is fine.";
	}
	else {
		std::cout << "Error";
	}
	user_data user1;
	user_data user2(firstname_array, secondname_array, passport_array, birthdate_array);
	user_data user3(firstname_array, secondname_array);
}