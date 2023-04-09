#include "Object.h"
#include <iostream>

Object::~Object()
{
	std::cout << "Вызван деструктор объекта базового класса Object" << std::endl;
}

Object::Object()
{
	std::cout << "Вызван конструктор объекта базового класса Object" << std::endl;
}
