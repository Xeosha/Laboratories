#include "Person.h"
#include "Student.h"

void f1(Person& p)
{
	p.set_age(0);
}

Student f2()
{
	Student s("Егор", 21, "информатика", 5);
	return s;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	cout << "Создаем два объекта класса Person, один без параметров, другой с: " << endl;
	Person p1;
	Person p2("Данил", 18);
	cout << p1 << endl << p2 << endl;
	cout << "Констуктор копирования: p1 = p2" << endl;
	p1 = p2;
	cout << p1 << endl;
	cout << "Создание объекта класса Student, один с параметрами, другой без: " << endl;
	Student s1;
	cout << s1 << endl;
	Student s2("Михаил", 17, "математика", 5);
	cout << s2 << endl;
	cout << "Изменение полей объекта класса Student" << endl;
	cin >> s1;
	cout << s1 << endl;
	cout << "Создание объекта класса Student через ф-ию f1" << endl;
	Student s3 = f2();
	cout << s3 << endl;
	cout << "Изменение атрибута объекта класса Person через f2" << endl;
	f1(p1);
	cout << p1.get_age() << endl;
	cout << "Виртуальная функция print() для Person* p3 = &s3: " << endl;
	Person* p3 = &s3;
	p3->print();
	return 0;
}