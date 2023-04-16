#include "LinkedList.h"

int main()
{
	setlocale(0, ".1251");
	Pair pair(1, 1.5);
	LinkedList <Pair> list1(5, pair);
	list1.push(pair);
	cout << list1 << endl;
	Pair pair2(2, 10);
	LinkedList <Pair> list2(5, pair2);
	cout << list2 << endl;
	LinkedList <Pair> list = list1 * list2;
	cout << list << endl;
	Iterator<Pair> it = list.first();
	for (; it != list.last(); it++)
	{
		cout << *it << " ";
	}
	cout << *it << endl;
	cout << "\n\n" << endl;
	LinkedList <double> list3(5, 4.5);
	list3.push(6);
	cout << list3 << endl;
	LinkedList <double> list4(5, 10);
	cout << list4 << endl;
	LinkedList <double> list34 = list3 * list4;
	cout << list34 << endl;
	Iterator<double> it2 = list34.first();
	for (; it2 != list34.last(); it2++)
	{
		cout << *it2 << " ";
	}
	cout << *it2;
	return 0;
}
