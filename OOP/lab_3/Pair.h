#pragma once
#include <iostream>
using namespace std;
class Pair
{
	int a;														
	double b;

	
public:
	friend istream& operator>>(istream& in, Pair& p);			// ввод
	friend ostream& operator<<(ostream& out, const Pair& p);	// вывод

	Pair(int a, double b);										// конструктор с параметрами
	Pair();														// конструктор без параметров 
	Pair(const Pair& p);										// конструктор копирования
	~Pair();													// деструктор
	Pair& operator=(const Pair& p);								// присваивание
	Pair operator-(const Pair& p);								// вычитание двух объектов
	Pair& operator+(int a);										// прибавление int числа
	Pair& operator+(double b);									// прибавление double числа
	Pair& operator++();											// префиксный инкремент
	Pair operator++(int);										// постфиксный инкремент
};

