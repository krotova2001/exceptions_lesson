#include <iostream>
#include <exception>
#include "Der.h"
using namespace std;

class MyEx:public exception
{
	int lvl;
public:
	MyEx(const char* p, int v) : exception(p), lvl{v} {};
	int Getlvl()const // присваевание уровня ошибки, дложен быть константным
	{
		return lvl;
	}
};


double division(int a, int b)
{
	if (!b)
		throw MyEx("Can't div by zero", 3);
	return a / b;
}

int main()
{
	cout << "Start programm\n";
	try // выполняется до первой исключительной ситуации
	{
		//Der T;
		division(1, 0);
	}
	//выполняется первый catch
	catch (const exception& er) // пользовательские исключения на сонове класса
	{
		cout << er.what() <<"\n";
	}


	catch (MyEx& er) // пользовательские исключения на сонове класса
	{
		cout << "lvl: " << er.Getlvl() << " - " << er.what() << "\n";
	}



	catch (...)
	{
		cout << "Error\n";
	}
	cout << "End programm\n";

}