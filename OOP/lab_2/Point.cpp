#pragma once
#include "Point.h"
#include <iostream>

// Конструктор без параметров
Point::Point()
{
	FIO = "";
	this->salary = 0;
	this->award = 0;
}
// Коструктор с парвметрами
Point::Point(std::string name, double salary, int award)
{
	FIO = name;
	this->salary = salary;
	this->award = award;
}
// Конструктор копированимя 
Point::Point(const Point& obj)
{
	this->FIO = obj.FIO;
	this->salary = obj.salary;
	this->award = obj.award;
}
// Деконструктор
Point::~Point()
{
	std::cout << "Удаление объекта: " << this << std::endl;
}
// Геттер зарплаты
double Point::get_salary()
{
	return salary;
}
// Сеттер зарплаты
void Point::set_salary(double salary)
{
	this->salary = salary;
}
// Геттер премии
int Point::get_award()
{
	return award;
}
// Сеттер премии
void Point::set_award(int award)
{
	this->award = award;
}
// Вывод локальных атрибутов объекта класса Point;
void Point::show()
{
	std::cout << "FIO: " << FIO << std::endl << "salary: " << salary << std::endl << "award: " << award << std::endl;
} 