#include "Student.h"
Student::Student()
{
	name = "";
	subject = "";
	age = 0;
	mark = 0;
}
Student::Student(string name, int age, string subject, int mark)
{
	this->name = name;
	this->age = age;
	this->subject = subject;
	this->mark = mark;
}
Student::~Student()
{
	cout << "Деструктор объекта класса Student" << endl;
}
Student::Student(const Student& s)
{
	name = s.name;
	age = s.age;
	subject = s.subject;
	mark = s.mark;
}
istream& operator>>(istream& in, Student& s)
{
	cout << "(string)name: ";
	in >> s.name;
	cout << "(int)age: ";
	in >> s.age;
	cout << "(string)subject: ";
	in >> s.subject;
	cout << "(int)mark: ";
	in >> s.mark;
	return in;
}
ostream& operator<<(ostream& out, const Student& s)
{
	return (out << s.name << " : " << s.age << " | " << s.subject << " : " << s.mark);
}   
