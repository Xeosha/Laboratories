#pragma once
#include <string>;

class Point
{
public:
	std::string FIO;								   // публичный атрибут ФИО
	Point();										   // конструктор без параметров
	Point(std::string name, double salary, int award); // конструктор с параметрами
	Point(const Point& obj);						   // конструктор копирования
	~Point();										   // деконструктор
	double get_salary();						       // геттер зарплаты
	void set_salary(double salary);					   // сеттер зарплаты
	int get_award();								   // геттер премии
	void set_award(int award);						   // сеттер премии
	void show();									   // вывод локальных атрибутов объекта
private:
	double salary;									   // зарплата
	int award;										   // премия
};	
