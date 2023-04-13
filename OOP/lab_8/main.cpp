#include "Dialog.h"
#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "МЕНЮШЕЧКА: " << endl << endl;
	cout << "-----------------------------------" << endl;
	cout << endl << "1. Создать вектор: (m6, где 6-размер)\n2. Добавить элемент: +\n3. Удалить элемент: -\n4. Вывод полей элементов: s\n5. Средний возраст: z\n6. Выход: q\n\n";
	cout << "-----------------------------------" << endl;
	cout << endl;
	Dialog D;
	D.Execute();
	return 0;


}