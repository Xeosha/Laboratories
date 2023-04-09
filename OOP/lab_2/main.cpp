#include "Point.h";
#include <iostream>

void print(Point& t)
{
	t.show();
}

Point set_obj(std::string FIO, double salary, int award)
{
	Point s(FIO, salary, award);
	return s;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	Point p1;
	p1.show();
	p1.FIO = "Danil";
	p1.set_award(15170.7);
	p1.set_salary(1000);
	p1.show();
	Point p2("Mihail", 9251, 500);
	print(p2);
	std::cout << p2.get_salary() << " " << p2.get_award() << std::endl;
	Point p3 = set_obj("Sasha", 1251.4, 200);
	p3.show();
	return 0;

}
