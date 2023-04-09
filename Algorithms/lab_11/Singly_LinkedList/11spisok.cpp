#define _CRT_SECURE_NO_WARNINGS //чтобы не жаловался
#include <iostream> // cout - cin
#include <stdio.h> // для работы с файлами
#include <windows.h> // для русского ввода-вывода штучки

using namespace std;
const int MAXLINE = 255; // макс длина строки

struct Point
{
	char data[MAXLINE];	    // строка, название и тд элемента списка
	Point* next = nullptr;  // следующий элемент списка
};
struct List
{
	size_t size = 0;	    // размер списка 
	Point* head = nullptr;  // указатель на первый элемент (голова)
	Point* tail = nullptr;  // указатель на последний элемент (хвост)
};

void show_menu(); // визуал меню
void menu(); // меню из switch
void show_list(List* list); //вывод списка, проверка на пустой список
void output(Point* obj, int i); //рекурсивная функция для обратного вывода 3 2 1 -> 1 2 3 (ввод был 1 2 3)
List* create_list(int size); // создание списка из size элементов
bool list_is_empty(List* list); // проверка на пустоту списка
void push_back(List* list, char* str); // добавление элемента в конец списка
void push_front(List* list, char* str); // добавление элемента в начало списка
void push_before(List* list, int k, int num); // добавление K объектов перед заданным номером
void push_before_obj(List* list, int k, int num, Point* obj); //  добавление обьекта перед заданным рекурсивно
Point* get_obj(List* list, int num); // получение объекта с заданным номером
void remove_obj(List* list, char* str); // удаление объекта с заданным ключом

void output(Point* obj, int i = 1) 
{
	if (obj == nullptr) return;
	cout << i << ". " << obj->data << endl;
	output(obj->next, ++i);
}
void show_list(List* list)
{
	if (list_is_empty(list)) cout << "Список пуст" << endl;
	else output(list->head);
}
bool list_is_empty(List* list) //проверка на пустой список
{
	return list == nullptr || list->size == 0;
}
List* create_list(int size)
{
	List* list = new List;
	char str[MAXLINE];
	if (size > 0)
	{
		cout << "Введите ключи " << size << " элементов списка: " << endl;
		cin.get();
		for (int i = 1; i <= size; i++)
		{
			cout << i << ". ";
			gets_s(str, MAXLINE);
			push_back(list, str);
		}
	}
	return list;
}	
void push_back(List* list, char* str) // добавить новый элемент сверху
{
	Point* new_point = new Point;	  // cоздаем новый узел
	strcpy(new_point->data, str);     // записываем данные в узел
	if (list_is_empty(list))		  // если список пуст, то tail == head
	{
		list->head = new_point;
		list->tail = new_point;
	} else {
		list->tail->next = new_point; // иначе добавляем связь и перемещаем tail
		list->tail = new_point;
	}
	list->size++;					  // увеличиваем размер списка
}
void push_front(List* list, char* str)
{
	Point* new_point = new Point;
	strcpy(new_point->data, str);
	if (list_is_empty(list))
	{
		list->head = new_point;
		list->tail = new_point;
	}
	else
	{
		new_point->next = list->head;
		list->head = new_point;
	}
	list->size++;
}
Point* get_obj(List* list, int num)
{
	Point* obj = list->head;
	for (int i = 1; i < num; ++i)
	{
		obj = obj->next;
	}
	return obj;
}
void remove_obj(List* list, char* str)
{
	if (list_is_empty(list)) cout << "Список пуст, нечего удалять!" << endl;
	else
	{
		Point* temp = list->head;
		if (list->head == list->tail && strcmp(str, list->head->data) == 0)
		{
			delete list->head;
			list->head = nullptr;
			list->tail = nullptr;
			list->size--;
		}
		else if (strcmp(str, list->head->data) == 0)
		{
			temp = list->head;
			list->head = list->head->next;
			delete temp;
			list->size--;
		}
		else
		{
			while (temp->next != nullptr)
			{
				if (strcmp((temp->next)->data, str) == 0)
				{
					if (temp->next == list->tail)
					{
						delete list->tail;
						list->tail = temp;
						list->tail->next = nullptr;
					}
					else
					{
						Point* temp2 = (temp->next)->next;
						delete temp->next;
						temp->next = temp2;
					}
					list->size--;
					return;
				}
				temp = temp->next;
			}
			cout << "Элемент не найден!" << endl;
		}

	}
}
void remove_list(List* list)
{
	Point* temp;
	while (list->head != nullptr)
	{
		temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	list->size = 0;
	list->tail = nullptr;
	cout << "Список удален!" << endl;
}
void push_before_obj(List* list, int k, int num, Point* obj)
{
	if (k == 0) return;
	Point* new_obj = new Point;
	cin.getline(new_obj->data, MAXLINE);
	if (num == 1)
	{
		new_obj->next = list->head;
		list->head = new_obj;
	}
	else {
		new_obj->next = obj->next;
		obj->next = new_obj;
	}
	list->size++;
	push_before_obj(list, k - 1, num, obj);
}
void push_before(List* list, int k, int num)
{
	if (!list_is_empty(list) && num >= 1 && num <= list->size)
	{
		if (k == 0) return;
		Point* obj = get_obj(list, num - 1);
		cout << "Введите " << k << " ключей: " << endl;
		cin.get();
		push_before_obj(list, k, num, obj);
	}
	else cout << "Список пуст или введен неверный индекс" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	fputs(obj->data, file);
	fputs("\n", file);
	toFile_obj(obj->next, file);
}
void toFile(List* list, char* filename) //загрузить в файл ключи стека
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(1);
	}
	cout << "Заносим данные в файл..." << endl;
	toFile_obj(list->head, file);
	cout << "Данные успешно занесены!" << endl;
	fclose(file);
}
void fromFile(List* list, char* filename) //выгрузить из файла ключи списка
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
		push_back(list, row);
	}
	fclose(file);
	cout << "Данные успешно считаны!" << endl;
}
void show_menu()
{
	cout << "\tМеню\t" << endl;
	cout << "0. Выход из меню;" << endl;
	cout << "1. Создание списка;" << endl;
	cout << "2. Вывод ключей объектов cписка;" << endl;
	cout << "3. Добавление объекта в начало списка;" << endl;
	cout << "4. Добавление объекта в конец списка;" << endl;
	cout << "5. Добавление K объектов перед объектом с позицией N;" << endl;
	cout << "6. Удаление объекта с заданным ключом;" << endl;
	cout << "7. Удаление списка;" << endl;
	cout << "8. Сохранить данные списка в файл;" << endl;
	cout << "9. Считать данные из файла в список;" << endl;
}
void menu()
{
	List* list = new List;
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
			remove_list(list);
			delete list;
			list = create_list(size);
			break; }
		case 2: {
			show_list(list);
			break; }
		case 3: {
			cout << "Введите ключ head элемента:" << endl;
			cin.get();
			gets_s(str, MAXLINE);
			push_front(list, str);
			break;
		}
		case 4: {
			cout << "Введите ключ tail элемента:" << endl;
			cin.get();
			gets_s(str, MAXLINE);
			push_back(list, str);
			break;
		}

		case 5: {
			cout << "Введите кол-во объетов K и позицию N: " << endl;
			cin >> K >> N;
			push_before(list, K, N);
			break;
		}		
		case 6: {
			cout << "Введите ключ объекта, который хотите удалить: " << endl;
			cin.get();
			cin.getline(str, MAXLINE);
			remove_obj(list, str);
			break;
		}
		case 7: {remove_list(list); break; } 
		case 8: {toFile(list, filename); break; }
		case 9: {fromFile(list, filename); break; }
		default: { cout << "Такой команды нет!" << endl; break; }
		}
	} while (n != 0);
	remove_list(list);
	delete list;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	return 0;
}
