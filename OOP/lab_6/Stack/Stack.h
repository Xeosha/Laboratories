#pragma once
#include <iostream>
#include <string>
using namespace std;


class Stack
{
	struct Point
	{
		string data = "";
		Point* next = nullptr;
	};

	Point* head;								// указатель на последний элемент стека
	size_t size;								// размер стека
	bool stack_is_empty()					
	{ return size == 0;}						// проверка на пустой стек
	void output(Point* obj);					// рекурсивная функция для обратного вывода 3 2 1 -> 1 2 3 (ввод был 1 2 3)
	void push_op(Point* obj);					// для перегрузки оператора присваивания и конструктора копированимя

public:
	Stack() : head(nullptr), size(0) {}
	Stack(int n);
	Stack(const Stack& stack);
	Stack& operator=(const Stack& stack);		// оператор присваивания
	~Stack();
	string top() const { return head->data; }	// вывод головы
	void show();								// вывод стека
	void push(string str);						// добавить новый элемент сверху
	string pop();								// удаление вершины

};

