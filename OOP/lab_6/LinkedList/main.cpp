#include "LinkedList.h"
int main()
{
	setlocale(0, ".1251");
	LinkedList list;
	cout << "Заполнение четными числами\n";
	for (int i = 2; i <= 10; i += 2) list.push(i);
	cout << "Вывод элементов списка: ";
	cout << list << endl;
	cout << "\nРазмер списка: ";
	cout << list() << endl;
	cout << "list[0]: ";
	cout << list[0] << endl;
	cout << "Создаем итератор, выводим через итератор: ";
	Iterator i = list.first();
	for (; i != list.last(); i++)
		cout << *i << " ";
	cout << endl;
	cout << "Удаляем 1-ый элемент\n";
	list.pop();
	i = list.first();
	cout << "i+=4\n";
	i = i + 4;
	cout << "*i: ";
	cout << *i << endl;
	cout << "Заполнение списка нечетными числами\n";
	LinkedList list2;
	for (int i = 1; i < 10; i += 2) list2.push(i);
	cout << endl;
	cout << "Вывод list1 and list2 \n";
	cout << list << endl << endl;
	cout << list2 << endl << endl;
	cout << "list3 = list * list2\n";
	LinkedList list3 = list * list2;
	cout << list3 << endl;
	list3.push_before(3, 1);
	cout << endl << list3 << endl;
	return 0;
}