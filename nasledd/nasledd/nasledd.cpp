#include "pch.h"
#include <iostream>
using namespace std;
//стековая память ограничена
//int *ptr_int = new int; пример
//в нераспределенной памяти создается блок размером с int
//и указатель на него возвращается в переменную ptr_int

//нельзя переполнять память,особождаем память с помощью оператора delete
//delete b; удалить блок памяти пока не потерян указатель на нее
//в динамической памяти может выделятся только одномерный массив
//тип * имя_указателя = new тип[длина];
//удаляются delete[] имя_указателя

//двумерный динамический массив
//int ** dynamic2Darray = new int *[11];
//затем выделяется блок памяти под каждую строчку
//for (int i = 0; i < 11; i++) {
//	dynamic2Darray[i] = new int[12];
//	for (int j = 0; j < 12; j++) {
//		dynamic2Darray[i][j] = j;
//	}
//}

/*Для выделения двумерного массива сначала создаётся одномерный массив
содержащий указатели на другие массивы(строки)
int ** dynamic2Darray = new int[l1]
затем выделяется блок памяти под каждую строку и указатель на неё
возвращается в созданный массив указателей
for (int i = 0; i < l1; i++) {
	dynamic2darray[i] = new int[l2];
	for (int j = 0; j < l2; j++) {
		dynamic2Darray[i][j] = j;
	}
}
Чтобы удалить двумерный массив
for (int i = 0; i < l1; i++) {
	delete[] dynemic2Darray[i];
}
delete[] dynamic2Darray; */


class matrix
{
protected:
	int * matr = new int[rows*columns];
	int rows, columns;
	int *res = new int[rows*columns];
public:
	matrix();
	~matrix();

	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);

	int getElem(int row, int col);
	int getRows() { return rows; }
	int getColumns() { return columns; }

	bool input();
	void transp();

	void printM()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i*columns + j] << "\t";
			}
			cout << endl;
		}
	};

};

class  vector :public matrix
{
private:
	//int *vec = new int[n];
	//int n;
public:
	vector();
	//~vector();
	int getN() { return getColumns(); }
	int getEl(int i);
	bool enter();
	void kvec(int k)
	{
		for (int i = 0; i < columns; i++)
		{
			matr[i] *= k;
			cout << matr[i] << ' ';
		}
	};
	bool multvec(vector vec2);
};

vector::vector() { rows = 1; }
//vector::~vector() {}



int main()
{
	matrix matrA, matrB;
	vector vec1, vec2;
	//matrA.input();
	//matrB.input();
	//matrA.printM();
	//matrA.transp();
	//matrA.summMatrix(matrB);
	//matrA.multMatrix(matrB);
	vec1.enter();
	vec2.enter();
	vec1.multvec(vec2);
	vec1.printM();
	vec2.printM();
	return 0;
}

matrix::matrix() {}
matrix::~matrix() { /*delete [] matr;*/ }

bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns + j] += matr2.getElem(i, j);
			}
		}
		printM();
		return true;
	}
	else
	{
		cout << "columns and rows are not equal";
		return false;
	}
}

void matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j * columns + i] << " ";
		}
		cout << endl;
	}

}

bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < columns; k++) {
					sum += matr[i*columns + k] * matr2.getElem(k, j);
				}
				res[i*matr2.getColumns() + j] = sum;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i*matr2.getColumns() + j] << "\t";
			}
			cout << endl;
		}
		return true;
	}
	else
	{
		cout << "col1 != row2";
		return false;
	}
}

int matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
	{
		return matr[row*columns + col];
	}
	else
	{
		cout << "error";
		return -1;
	}
}

bool matrix::input()
{
	cout << "rows=";
	cin >> rows;
	cout << "columns=";
	cin >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matr[i*columns + j];
		}
		cout << endl;
	}
	return true;
}

bool vector::multvec(vector vec2)
{
	int scal = 0;
	if (columns == vec2.getN())
	{
		for (int i = 0; i <columns; i++)
		{
			scal += matr[i] * vec2.getEl(i);
		}
		cout << scal;
		//delete[]matr;
		return true;
	}
	else { return false; }
}

bool vector::enter()
{
	cout << "columns=";
	cin >> columns;
	for (int j = 0; j < columns; j++)
	{
		cout << "matr[" << j << "]=";
		cin >> matr[j];
	}
	return true;
}

int vector::getEl(int i)
{
	if (i > -1 && i < columns) { return matr[i]; }
	else
	{
		cout << "error!";
		return -1;
	}
}