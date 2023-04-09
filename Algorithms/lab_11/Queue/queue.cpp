#define _CRT_SECURE_NO_WARNINGS //чтобы не жаловался
#include <iostream>
#include <stdio.h> //для работы с файлами
#include <windows.h> //для русского ввода-вывода штучки

using namespace std;
const int MAXLINE = 255; //макс длина строки

struct Point
{
	char data[MAXLINE]; //строка, название и тд элемента очереди
	Point* next = nullptr; //следующий элемент очереди
};
Point* head = nullptr; //указатель на первый элемент очереди
Point* top = nullptr; //указатель на последний элемент очереди
size_t size_queue = 0;

void push(char* str); //добавить новый элемент сверху
bool queue_is_empty(); //проверка на пустой стек

void create_queue(int size)
{
	if (size > 0 && queue_is_empty())
	{
		char str[MAXLINE];
		cout << "Введите ключи " << size << " элементов очереди: " << endl;
		cin.get();
		for (int i = 1; i <= size; i++)
		{
			cout << i << ". ";
			gets_s(str, MAXLINE);
			push(str);
		}
	}
}
void push(char* str) //добавить новый элемент сверху
{
	if (queue_is_empty())
	{
		head = new Point;
		strcpy(head->data, str);
		top = head;
	}
	else
	{
		Point* obj = new Point;
		strcpy(obj->data, str);
		top->next = obj;
		top = obj;
	}
	size_queue++;

}
void pop()
{
	Point* temp = head;
	head = head->next;
	size_queue--;
	delete temp;
}
bool queue_is_empty() //проверка на пустой стек
{
	return size_queue == 0;
}
void push_before(int index, int k)
{
	if (!queue_is_empty() && index >= 1 && index <= size_queue && k > 0)
	{
		int i = 1;
		while (i < index)
		{
			push(head->data);
			pop();
			i++;
		}
		char str[MAXLINE];
		cout << "Введите элементы для вставки: " << endl;
		cin.get();
		for (int j = 1; j <= k; j++)
		{
			cin.getline(str, MAXLINE);
			push(str);
		}
		for (i; i <= size_queue - k; i++)
		{
			push(head->data);
			pop();
		}
	}
	else cout << "Очередь пуста или введен неверный индекс" << endl;
}
void output(Point* obj) 
{
	cout << obj->data << endl;
	if (obj == top) return;
	output(obj->next);
}
void show_queue() //вывод стека
{
	if (queue_is_empty()) cout << "Очередь пуста" << endl;
	else output(head);
}
void remove_obj(char* str)
{
	if (queue_is_empty()) cout << "Очередь пуста, нечего удалять!" << endl;
	int i = 1;
	while (i <= size_queue)
	{
		if (strcmp(head->data, str) == 0)
		{
			pop();
		}
		else
		{
			push(head->data);
			pop();
			i++;
		}
	}
}
void remove_queue()
{
	while (head != nullptr)
	{
		pop();
	}
	cout << size_queue << " Очередь удалена!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	fputs(obj->data, file);
	fputs("\n", file);
	toFile_obj(obj->next, file);
}
void toFile(char* filename) //загрузить в файл ключи стека
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(1);
	}
	cout << "Заносим данные в файл..." << endl;
	toFile_obj(head, file);
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
	while (!feof(file) && fgets(row, MAXLINE, file))
	{
		row[strlen(row) - 1] = '\0'; //заносили с \n, нужно его убрать.
		push(row);
	}
	fclose(file);
	cout << "Данные успешно считаны!" << endl;
}
void show_menu()
{
	cout << "\tМеню\t" << endl;
	cout << "0. Выход из меню;" << endl;
	cout << "1. Создание очереди;" << endl;
	cout << "2. Вывод ключей объектов очереди;" << endl;
	cout << "3. Добавление K объектов перед объектом с позицией N;" << endl;
	cout << "4. Удаление объекта с заданным ключом;" << endl;
	cout << "5. Удаление очереди;" << endl;
	cout << "6. Сохранить данные очереди в файл;" << endl;
	cout << "7. Считать данные из файла в очередь;" << endl;
}
void menu()
{
	int n, N, K;
	int size;
	char str[MAXLINE];
	char filename[] = "file.txt";
	do
	{
		system("pause");
		system("cls");
		show_menu();
		cin >> n;
		cout << "---" << endl;
		switch (n)
		{
		case 0: {
			cout << "Выход из меню!" << endl;
			break;
		}
		case 1: {
			cout << "Введите кол-во элементов: ";
			cin >> size;
			create_queue(size);
			break; }
		case 2: {
			show_queue();
			break; }

		case 3: {
			cout << "Введите кол-во объетов K и позицию N: " << endl;
			cin >> K >> N;
			push_before(N, K);
			break;
		}
		case 4: {
			cout << "Введите ключ объекта, который хотите удалить: " << endl;
			cin.get();
			cin.getline(str, MAXLINE);
			remove_obj(str);
			break;
		}

		case 5: {remove_queue(); break; }
		case 6: {toFile(filename); break; }
		case 7: {fromFile(filename); break; }
		default: { cout << "Такой команды нет!" << endl; break; }
		}
	} while (n != 0);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu();

	return 0;
}
