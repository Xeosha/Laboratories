#define _CRT_SECURE_NO_WARNINGS //чтобы не жаловался
#include <iostream>
#include <stdio.h> //для работы с файлами
#include <windows.h> //для русского ввода-вывода штучки

using namespace std;
const int MAXLINE = 255; //макс длина строки

struct Point
{
	char data[MAXLINE]; //строка, название и тд элемента стека
	Point* next = nullptr; //следующий элемент списка стека
};

struct Stack
{
	Point* head = nullptr; //указатель на последний входящий элемент стека
	size_t stack_size = 0;
};

bool stack_is_empty(Stack& stack); //проверка на пустой стек
void output(Point* obj); //рекурсивная функция для обратного вывода 3 2 1 -> 1 2 3 (ввод был 1 2 3)
void show_stack(Stack& stack); //вывод стека
void push(Stack& stack, char* str); //добавить новый элемент сверху
Stack* create_stack(int size); //создание стека из n элементов
void remove_obj(Stack& stack, char* str); //удалить объект с заданным ключом
void push_before(Stack& stack, unsigned index, unsigned k); //вставить перед элементом
void remove_stack(Stack& stack); //удаление списка
void toFile_obj(Point* obj, FILE* file); //рекурсия ф-ия для обратного порядка заноса в файл
void toFile(Stack& stack, char* filename); //загрузить в файл ключи стека
void fromFile(Stack& stack, char* filename); //выгрузить из файла ключи стека
void show_menu(); //показать пункты менюшки
void menu(); //сама менюшка

bool stack_is_empty(Stack& stack) //проверка на пустой стек
{
	return stack.head == nullptr; //stack_size = 0;
}
void output(Point* obj) //рекурсивная функция для обратного вывода 3 2 1 -> 1 2 3 (ввод был 1 2 3)
{
	if (obj == nullptr) return;
	output(obj->next);
	cout << obj->data << endl;
}
void show_stack(Stack& stack) //вывод стека
{
	if (stack_is_empty(stack)) cout << "Стек пуст" << endl;
	else output(stack.head);
}
void push(Stack& stack, char* str) //добавить новый элемент сверху
{
	stack.stack_size++;
	Point* obj = new Point;
	strcpy(obj->data, str);
	obj->next = stack.head;
	stack.head = obj;
}
void pop(Stack& stack)
{
	if (stack.head != nullptr)
	{
		Point* temp = stack.head;
		stack.head = stack.head->next;
		delete temp;
		stack.stack_size--;
	}
}
Stack* create_stack(int size) //создание стека из n элементов
{
	Stack* stack = new Stack;
	if (size > 0 && stack_is_empty(*stack))
	{
		char str[MAXLINE];
		cout << "Введите ключи " << size << " элементов стека: " << endl;
		cin.get();
		for(int i = 1; i <= size; i++)
		{
			cout << i << ". ";
			gets_s(str, MAXLINE);
			push(*stack, str);
		}
	}
	return stack;
}
void push_before(Stack& stack, unsigned index, unsigned k)
{
	int new_index = stack.stack_size - index + 1;
	if (new_index < 0 || stack_is_empty(stack)) cout << "Введен неверный индекс/стек пуст" << endl;
	else
	{
		char str[MAXLINE];
		Stack* stack2 = new Stack;
		for (int i = 1; i <= new_index; i++)
		{
			push(*stack2, stack.head->data);
			pop(stack);
		}
		cout << "Введите " << k << " элементов: " << endl;
		cin.get();
		for (int i = 1; i <= k; i++)
		{
			cin.getline(str, MAXLINE);
			push(stack, str);
		}
		for (int i = 0; i < new_index; i++)
		{
			push(stack, stack2->head->data);
			pop(*stack2);
		}

	}
} 
void remove_obj(Stack& stack, char* str)
{
	int stack_size = stack.stack_size;
	Stack* stack2 = create_stack(0);
	for (int i = 1; i <= stack_size; i++)
	{
		if (strcmp(stack.head->data, str) != 0)
		{
			push(*stack2, stack.head->data);
		}
		pop(stack);
	}
	cout << endl;
	int stack_size2 = stack2->stack_size;
	for (int i = 1; i <= stack_size2; i++)
	{
		push(stack, stack2->head->data);
		pop(*stack2);
	}
}
void remove_stack(Stack& stack) //удаление списка
{
	Point* temp;
	while (stack.head != nullptr)
	{
		temp = stack.head->next;
		delete stack.head;
		stack.head = temp;
	}
	stack.stack_size = 0;
	cout << "Список удален!" << endl;
}
void toFile_obj(Point* obj, FILE* file)
{
	if (obj == nullptr) return;
	toFile_obj(obj->next, file);
	fputs(obj->data, file);
	fputs("\n", file);
}
void toFile(Stack& stack, char* filename) //загрузить в файл ключи стека
{
	FILE* file;
	if ((file = fopen(filename, "wb")) == NULL) //ошибка открытия файла 
	{
		cout << "Ошибка открытия файла" << endl;
		exit(1);
	}
	cout << "Заносим данные в файл..." << endl;
	toFile_obj(stack.head, file);
	cout << "Данные успешно занесены!" << endl;
	fclose(file);
}
void fromFile(Stack& stack, char* filename) //выгрузить из файла ключи списка
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
		push(stack, row);
	}
	fclose(file);
	cout << "Данные успешно считаны!" << endl;
}
void show_menu()
{
	cout << "\tМеню\t" << endl;
	cout << "0. Выход из меню;" << endl;
	cout << "1. Создание стека;" << endl;
	cout << "2. Вывод ключей объектов стека;" << endl;
	cout << "3. Добавление K объектов перед объектом с позицией N;" << endl;
	cout << "4. Удаление объекта с заданным ключом;" << endl;
	cout << "5. Удаление стека;" << endl;
	cout << "6. Сохранить данные стека в файл;" << endl;
	cout << "7. Считать данные из файла в стек;" << endl;
}
void menu()
{
	Stack* stack = new Stack;
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
			stack = create_stack(size);
			break; }
		case 2: {
			show_stack(*stack);
			break; }
		case 3: {
			cout << "Введите кол-во объетов K и позицию N: " << endl;
			cin >> K >> N;
			push_before(*stack, N, K);
			break;
		}
		case 4: {
			cout << "Введите ключ объекта, который хотите удалить: " << endl;
			cin.get();
			cin.getline(str, MAXLINE);
			remove_obj(*stack, str);
			break;
		}
		case 5: {remove_stack(*stack); break; }
		case 6: {toFile(*stack, filename); break; }
		case 7: {fromFile(*stack, filename); break; }
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
