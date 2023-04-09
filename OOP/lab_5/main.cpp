#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"

int main()
{
	setlocale(0, ".1251");
	Vector v(5);
	Person p;
	cin >> p;
	Student s;
	cin >> s;
	s.is_norm();
	Object* o = &p;
	v.Add(o);
	cout << v << endl;
	v.Add(&s);
	cout << v << endl;
	return 0;
}