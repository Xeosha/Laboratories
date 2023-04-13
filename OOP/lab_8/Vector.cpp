#include "Vector.h"
using namespace std;

Vector::Vector()
{
	beg = 0;
	size = 0;
	cur = 0;
}
Vector::~Vector()
{
	if (beg != 0) delete[] beg;
	beg = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Add(Object* p) {
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty" << endl;
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}

void Vector::Add()
{
	if (cur == size) return;
	Object* o;
	cout << "Кого добавить: \n1. Person\n2. Student\n";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		Person* p = new Person();
		cin >> *p;
		o = p;
		Add(o);
		break;
	}
	case 2:
	{
		Student* s = new Student();
		cin >> *s;
		o = s;
		Add(o);
		break;
	}
	default:
	{
		cout << ":C";
		break;
	}
	}
}

void Vector::Show()
{
	cout << *this;
}

void Vector::Del()
{
	if (cur == 0)
		return;//пустой 
	cur--;
}

int Vector::operator ()()
{
	return size;
}
void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//вызов метода (позднее связывание) 
			p++;//передвигаем указатель на следующий объект
		}
	}
}

void Vector::AvgAge()
{
	int a = 0;
	if (cur == 0)
	{
		cout << "Вектор пуст!";
		return;
	}
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		a += (*p)->AvgAge();
		p++;
	}
	cout << "Средний возраст людей в списке: " << a / cur << '\n';
}

