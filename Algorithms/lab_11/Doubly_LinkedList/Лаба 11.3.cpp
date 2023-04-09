#define _CRT_SECURE_NO_WARNINGS //чтобы не жаловался
#include <iostream>
#include <stdio.h> //для работы с файлами
#include <windows.h> //для русского ввода-вывода штучки

using namespace std;
const int MAXLINE = 255; //макс длина строки

struct Point
{
	Point* prev = nullptr; //предыдущий элемент списка
	char data[MAXLINE]; //строка, название и тд элемента списка
	Point* next = nullptr; //следующий элемент списка 
};
Point* head = nullptr;
void add_objs(int index, int k);
void push_back(Point* obj, int k);
void push_front(Point* obj, int k);


Point* get_obj(int index) //получение обьекта списка по индексу
{
	Point* top = head;	
	int k = 0;
	while (top != nullptr)
	{
		if (k == index)
			return top;
		top = (*top).next;
		++k;
	}
	return nullptr;
}
Point* get_obj(char* str) //получение обьекта списка по ключу
{
	Point* top = head;
	while (top != nullptr)
	{
		if (strcmp((*top).data, str) == 0)
			return top;
		top = (*top).next;
	}
	return nullptr;
}
void create_list(Point*& head) //создание списка
{
	unsigned int n; //кол-во элементов в списке
	cout << "Введите кол-во элементов в списке (если 0 - пустой): ";
	cin >> n;
	if (n > 0)
	{
		head = new Point;
		cin.get();
		cin.getline(head->data, MAXLINE);
		push_back(head, n - 1); //n-1, т.к. создали указатель на первый.
	}
}
void add_objs(int index, int k) //добавление элементов
{
	if (k == 0) return;
	Point* obj;
	obj = get_obj(index);
	if (obj == nullptr) { cout << "Такого индекса не существует! " << endl; return; }
	cout << "Добавление элементов!" << endl;
	cout << "*****************************" << endl;
	cout << "Введите " << k*2 << " элементов: " << endl;
	cin.get();
	push_front(obj, k);
	push_back(obj, k);
	cout << "*****************************" << endl;
}
void push_back(Point* obj, int k) //добавление после заданного объекта
{
	if (k == 0) return;
	Point* next = new Point;
	cin.getline(next->data, MAXLINE);
	next->prev = obj;
	next->next = obj->next;
	obj->next = next;
	if (next->next != nullptr) next->next->prev = next;
	push_back(next, --k);
}
void push_front(Point* obj, int k) //добавление перед заданным объектом
{
	if (k == 0) return;
	Point* prev = new Point;
	cin.getline(prev->data, MAXLINE);
	prev->next = obj;
	prev->prev = obj->prev;	
	obj->prev = prev;
	if (prev->prev == nullptr) head = prev;
	else prev->prev->next = prev;
	push_front(obj, --k);
}
void remove_obj(char* str) //удаление обьекта списка по ключу
{
	Point* obj = get_obj(str);
	if (obj == nullptr) { cout << "Такого элемента нет!" << endl; return; }
	cout << "*****************************" << endl;
	cout << "Удаление элемента с ключом " << str << endl;
	if (obj->next != nullptr) obj->next->prev = obj->prev;
	if (obj->prev != nullptr) obj->prev->next = obj->next;
	if (head == obj) head = obj->next;
	delete obj;
	cout << "Элемент удален!" << endl;
	cout << "*****************************" << endl;
}
void show_list() //показать список
{
	if (head == nullptr) { cout << "Список пуст!" << endl;  return; }
	else cout << "Вывод!!! " << endl;
	Point* temp = head;
	int i = 0;
	while (temp != nullptr)
	{
		cout << i << " " << (*temp).data << endl;
		++i;
		temp = (*temp).next;
	}
}
void remove_list() //удаление списка
{
	Point* temp;
	cout << "Удаление списка!" << endl;
	while (head != nullptr)
	{
		temp = (*head).next;
		delete head;
		head = temp;
	}
	cout << "Список удален!" << endl;
}
void toFile(char* filename) //загрузить в файл ключи списка
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(2);
	}
	cout << "Заносим данные в файл..." << endl;
	Point* top = head;
	while (top != nullptr)
	{
		fputs((*top).data, file);
		fputs("\n", file);
		top = (*top).next;
	}
	cout << "Данные успешно занесены!" << endl;
	fclose(file);
}
void fromFile(char* filename) //выгрузить из файла ключи списка
{
	FILE* file;
	char row[MAXLINE];
	if ((file = fopen(filename, "rb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(2);
	}
	cout << "Считываем данные из файла..." << endl;
	Point* top, * next;
	top = new Point;
	(*top).prev = nullptr;
	head = top;
	int i = 0;
	while (!feof(file) && fgets(row, MAXLINE, file))
	{
		row[strlen(row) - 1] = '\0'; //заносили с \n, нужно его убрать.
		strcpy((*top).data, row);
		next = new Point;
		(*top).next = next;
		(*next).prev = top;
		top = next;
		++i;
	}
	fclose(file);
	if (i == 0) { head = nullptr; delete top; cout << "В файле ничего нет." << endl; }
	else {
		if ((*top).prev != nullptr)
			(*(*top).prev).next = nullptr;
		delete top;
	}
	cout << "Данные успешно считаны!" << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, N, K;
	char str[MAXLINE];
	char filename[] = "file.txt";
	do
	{
		system("pause");
		system("cls");
		cout << "\tМеню\t" << endl;
		cout << "0. Выход из меню;" << endl;
		cout << "1. Создание двунаправленного списка;" << endl;
		cout << "2. Вывод ключей объектов списка;" << endl;
		cout << "3. Добавление K объектов около объекта с позицией N;" << endl;
		cout << "4. Удаление объекта с заданным ключом;" << endl;
		cout << "5. Удаление списка;" << endl;
		cout << "6. Сохранить данные списка в файл;" << endl;
		cout << "7. Считать данные из файла;" << endl;
		cin >> n;
		switch (n)
		{
		case 0: {
			cout << "Выход из меню!" << endl;
			break;
		}
		case 1: {create_list(head); break; }
		case 2: {show_list(); break; }
		case 3: {
			cout << "Введите кол-во объетов K и позицию N: " << endl;
			cin >> K >> N;
			add_objs(N, K);
			break;
		}
		case 4: {
			cout << "Введите ключ объекта, который хотите удалить: " << endl;
			cin.get();
			cin.getline(str, MAXLINE);
			remove_obj(str);
			break;
		}
		case 5: {remove_list(); break; }
		case 6: {toFile(filename); break; }
		case 7: {fromFile(filename); break; }
		default: { cout << "Такой команды нет!" << endl; break; }
		}
	} while (n != 0);
	return 0;
}
