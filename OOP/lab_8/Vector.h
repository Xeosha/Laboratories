#pragma once
#include "Student.h"
using namespace std;
class Vector
{
public:
	Vector();
	Vector(int);
	~Vector();
	void Add(Object*);
	void Add();
	void Del();
	void Show();
	int operator()();
	void AvgAge();
	friend ostream& operator<<(ostream& out, const Vector& v);
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};

