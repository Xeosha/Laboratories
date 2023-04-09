#include "Person.h"
#include "Student.h"

void f1(Person& p)
{
	p.set_age(0);
}

Student f2()
{
	Student s("����", 21, "�����������", 5);
	return s;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	cout << "������� ��� ������� ������ Person, ���� ��� ����������, ������ �: " << endl;
	Person p1;
	Person p2("�����", 18);
	cout << p1 << endl << p2 << endl;
	cout << "���������� �����������: p1 = p2" << endl;
	p1 = p2;
	cout << p1 << endl;
	cout << "�������� ������� ������ Student, ���� � �����������, ������ ���: " << endl;
	Student s1;
	cout << s1 << endl;
	Student s2("������", 17, "����������", 5);
	cout << s2 << endl;
	cout << "��������� ����� ������� ������ Student" << endl;
	cin >> s1;
	cout << s1 << endl;
	cout << "�������� ������� ������ Student ����� �-�� f1" << endl;
	Student s3 = f2();
	cout << s3 << endl;
	cout << "��������� �������� ������� ������ Person ����� f2" << endl;
	f1(p1);
	cout << p1.get_age() << endl;
	cout << "����������� ������� print() ��� Person* p3 = &s3: " << endl;
	Person* p3 = &s3;
	p3->print();
	return 0;
}