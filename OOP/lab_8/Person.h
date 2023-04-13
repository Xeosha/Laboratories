#pragma once
#include "Object.h"


class Person :
	public Object
{
protected:
	string name;
	int age;
	friend istream& operator>>(istream& in, Person& p);			// ввод
	friend ostream& operator<<(ostream& out, const Person& p);	// вывод
public:
	void set_name(string name);									// сеттер имени
	void set_age(int age);										// сеттер возраста
	string get_name();											// геттер имени
	int get_age();												// геттер возраста
	Person();													// конструктор без параметров
	Person(string name, int age);								// конструктор с параметрами
	Person(const Person& p);									// конструктор копирования
	~Person();													// деструктор
	void Show();
	void HandleEvent(const TEvent& e);
	int AvgAge() { return age;  }

};
