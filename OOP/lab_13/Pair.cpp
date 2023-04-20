#include "Pair.h"


Pair::Pair(int a, double b)
{
	this->a = a;		
	this->b = b;
}
istream& operator>>(istream& in, Pair& p)
{
	cout << "(int)a : ";
	in >> p.a; 
	cout << "(double)b :";
	in >> p.b;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)	
{

	return (out << p.a << " : " << p.b);
}
Pair::Pair()
{
	a = 0;			
	b = 0;
}
Pair::~Pair()
{
}
Pair::Pair(const Pair& p)
{
	a = p.a;
	b = p.b;
}
Pair& Pair::operator=(const Pair& p)
{
	if (&p==this) return *this; 
	a = p.a;
	b = p.b;
	return *this;
}
Pair Pair::operator-(const Pair& p)
{
	Pair res(a - p.a, b - p.b);
	return res;

}
Pair& Pair::operator+(int a)
{
	this->a += a;
	return *this;
}
Pair& Pair::operator+(double b)
{
	this->b += b;
	return *this;
}

Pair& Pair::operator++()
{
	++a; ++b;
	return *this;
}

Pair Pair::operator ++(int)
{
	Pair temp = *this;
	this->a++; this->b++;
	return temp;
}	

Pair Pair::operator+(const Pair& p)
{
	this->a += p.a;
	this->b += p.b;
	return *this;
}
