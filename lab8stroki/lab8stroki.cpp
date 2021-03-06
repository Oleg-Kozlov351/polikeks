// lab8_stroki_i_files.cpp : Строки и файлы
//

#include "pch.h"
#include <iostream>
using namespace std;
/*
СТРОКИ И ФАЙЛЫ
1. СТРОКИ СТАРОГО С-ТИПА
представляют из себя всего лишь массив символов с нуливым окончанием.
По нулю определяется конец строки. В случае, если пользователь забыл поставить \0
или он по тем или иным причинам стёрся, функции С будут пытаться считывать
символы до тех пор, пока встретят \0 или не вызовут ошибку
char cstr1[] = "CD-style string1"; \\ '0' в конце дописывается автоматически
char cstr2[] = { 'C', '-', 's', 't', 'y'. 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '2', '\0' }
char cstr3[] = { '\67', '\45', '\115', 't', 'y', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '3', '\0' }
*/

//2. ФУНКЦИИ ДЛЯ РАБОТЫ С C-СТРОКАМИ
// вывод на печать printf(char*, , , ) или printf_s(char*, , , ) - print formatted
// пример: printf("базовая %s строка %f", параметр1, параметр2)
// знаком % помечаются места вставки параметров

// %f - параметр подставляется на место %f, оформленное в виде числа с плавающей точкой
// %s - параметр подставляется на место %s как строка
// %d - параметр подставляется на место %d как целое число
// %e - параметр подставляется на место %e как число в экспоненциальном виде

// 3. ПРОЧИЕ СТРОКОВЫЕ ФУНКЦИИ
// объединение (конкатенация) строк strcat(*char, *char)
// копирование из одной строки в другую strcpy(*char, *char)
// сравнение strcmp(*char, *char), если строки идентичны, возвращает 0, иначе - позицию первого различного символа
// длина строки strlen(*char)
// чтение строки с консоли scanf(*char, параметр)
// вставка строки в строку производится в несколько действий
// иногда надо будет добавлять _s, e.g. strlen_s(*char)

/*
4. СТРОКА С++
в стандартной библиотеке С++ массив символов инкапсулирован в КЛАСС std::string
в который также собраны самые часто используемые методы обработки
(конкатенация, подсчёт длины, вставка, удаление, поиск и тд)
и для которого  перегружены операторы + (конкатенация), ввод, вывод и т.д.
ещё одно отличие от строк C - длина строки теперь задаётся отедельным числом,
хранящимся в классе, а не нулевым окончанием
Примеры:
std::string cppstr1 = "C++ - style string 1";
std::string cppstr2 = "";
5. РАБОТА С ФАЙЛАМИ В С++
Класс fstream - поток ввода/вывода
аналагичен cin и cout, но не на консоль, а в файл
необходим #include <fstream>
цкл работы с файлом:
1) указать имя открыть для чтения/записи/чтение и записи
2) перейти на нужную позицию
3) прочитать или записать
4) закрыть файл
*/


int main()
{
	printf(cstr1);
	// в функцию передаётся массив char (а имя массива являяется УКАЗАТЕЛЕМ на самый ... либо указатель *char
	printf(cstr3); //автоматический перенос строки не делается
	printf("Parameter1 = %2.2f, parameter2 = %d, parameter3 = %s\n\n, 1.5, 100, "\"some string\"");
	//2.2 - первая 2 - свободное место перед целым числом, а вторая 2 - количество цифр после точки

	char place_to_copy[255];
	char place_from_copy[] = "abcdefghijklmnop";
	strcpy(place_to_copy, 255, place_from_copy);
	printf("Result = %s", place_to_copy);

	int i = strcmp(cstr1, cstr2);
	printf("Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, 1);

	int lnght = strlen(cstr1);
	printf("Result of strlen(%s) = %d\n", cstr1, lngth);

	char cstr3[255];
	strcpy("Result of strcpy(%s, %s)\n", cstr3, cstr2);

	//объединение строк
	strcat(cstr3, 255, cstr1);
	cout << "Result of strcat(cstr2, cstr1) = " << cstr3 << endl;
	cout << "Instead of strcat() use operator +:\t" << (cppstr1 + cppstr2) << endl << endl; //для конкетенации перегружен "+"

	//что есть в классе (смотрим через IntelliSense)
	string strl = "";
	strl.append(); //-добавить подстроку в конец
	strl.at(i) //- аналог квадратных строк strl[i]
		strl.c_str() //- преобразование строк С++ в строку С(возвр. char*)
		//например, для prntf("%s", str1.c_str())
		//или strcpy(place_to_copy, 255, str1.c_str())
		//str1.clear() - сбросить строку
		//str1.length() - длина строки
		//и много чего ещё полезного

		fstream fs;
	fs.open("example_textfile.mylife", //путь к файлу и имя
		ios::in | ios::out | ios::trunc); //режим работы с файлом (комбинация чтения и записи)
	fs << "100500" << endl;
	fs << "some_string" << endl;
	fs << "123456.789123" << endl;

	fs.seekg(0); //переход обратно в начало
	int int1;
	fs >> int1; cout << "Первая запись в файле" << int1 << endl;
	char buffer[255];
	fs >> buffer; cout << "Вторая запись в файле" << buffer << endl;
	double dbl1;
	fs >> dbl1; cout << "Третья запись в файле" << dbl1 << endl;
	fs.close();

	getchar();
	return 0;
}