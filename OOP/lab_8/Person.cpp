#include "Person.h"

Person::Person()
{
	this->name = "";
	this->age = 0;
}
Person::Person(string name, int age)
{
	this->name = name;
	this->age = age;
}
Person::Person(const Person& p)
{
	age = p.age;
	name = p.name;
}
Person::~Person()
{
	cout << "Вызван деструктор для объекта класса Person!" << endl;
}
istream& operator>>(istream& in, Person& p)
{
	cout << "(string)name: ";
	in >> p.name;
	cout << "(int)age: ";
	in >> p.age;
	return in;
}
ostream& operator<<(ostream& out, const Person& p)
{

	return (out << p.name << " : " << p.age);
}
void Person::set_name(string name)
{
	this->name = name;
}
void Person::set_age(int age)
{
	this->age = age;
}
string Person::get_name()
{
	return name;
}
int Person::get_age() {
	return age;
}
void Person::Show()
{
	cout << name << ": " << age << endl;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << *this; break;
		}
	}
}
