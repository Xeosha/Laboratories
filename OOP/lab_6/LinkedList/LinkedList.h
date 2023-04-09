#pragma once
#include <iostream>
#include <algorithm>			// для min/max
using namespace std;


//-------------------------------------------------------------------//
//	Если ф-ия имеет параметр с const, тогда и все связанные 
//	с ней ф-ии должны иметь тот же модификатор!
//	110(LinkedList.cpp) - конструктор копирования: имеет const list, 
//	работает с индексами через оператор [] => перегрузка
//	оператора [] должна иметь в конце const!! 90(LinkedList.cpp)
//  Тоже самое с 65, 71, 77 (77 имеет const)
//-------------------------------------------------------------------//


//-------------------------//
//	связь списка
//-------------------------//
struct Point
{			
	int num = 0;				// просто число
	Point* next = nullptr;		// указатель на следующий элемент списка
};
//-------------------------//
//	итератор списка
//-------------------------//
class Iterator
{
	friend class LinkedList;	// доступ к приватным атрбутам списка
private:
	Point* elem = nullptr;		// указатель на связь
public:
	Iterator() { elem = nullptr; }									
	Iterator(const Iterator& it) { elem = it.elem; };
	bool operator == (const Iterator& it) { return elem == it.elem; }
	bool operator != (const Iterator& it) { return elem != it.elem; }
	void operator ++ () { elem = elem->next; };			// ++i - смещение вправо на 1
	void operator ++ (int) { elem = elem->next; };		// i++ - смещение вправо на 1
	//---------// i+n - смещение вправо на n
	Iterator& operator + (int n)
	{
		for (int i = 0; i < n && elem->next != nullptr; i++)
			elem = elem->next;
		return *this;
	}
	int operator * () const { return elem->num; };      // разыменование итератора (вывод)
};

//-------------------------//
//	связанный список
//-------------------------//
class LinkedList
{
	Iterator beg, end;									// укзаатели итератора на начальный и конечный элемент
	size_t size = 0;									// размер списка
	Point* head = nullptr;								// указатель на первый элемент
	Point* top = nullptr;								// указатель на ласт элемент
	//-------------------------------вывод----------------------------------------//
	friend ostream& operator<<(ostream& out, const LinkedList& list);	
	friend istream& operator>>(istream& in, LinkedList& list);			 
	void output(Point* obj) const;
public:
	void show() const;		
	//---------------------------------------------------------------------------//
private:
	Point* get_obj(int num);							// получение объекта с заданным номером
	void push_before_obj(int k, int num, Point* obj);	// добавление обьекта перед заданным рекурсивно
public:
	LinkedList();										// конструктор
	LinkedList(size_t s, int k);						// констуктор: s - размер, k - значение по умолчанию
	~LinkedList();										// деструктор
	LinkedList(const LinkedList& list);					// конструктор копирования
	int& operator [](int index) const;					// доступ по индексу
	LinkedList& operator =(const LinkedList& list);		// оператор присваивания
	LinkedList operator * (LinkedList& list);			// умножение списка на список
	int operator ()() { return size; };					// возвращение длины списка
	void push(int k);									// добавление в конец списка
	int pop();											// удаление первого элемента
	Iterator first() { return beg; }					// возвращает указатель на первый элемент
	Iterator last() { return end; }						// вовзращает указаетль на последний элемент
	void push_before(int k, int num);					// добавление K объектов перед заданным номером

};



