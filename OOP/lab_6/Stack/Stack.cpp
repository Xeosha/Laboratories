#include "Stack.h"

void Stack::push_op(Point* obj)
{
	if (obj == nullptr) return;
	push_op(obj->next);
	this->push(obj->data);
}

Stack& Stack::operator=(const Stack& stack)
{
	while (this->pop() != "");
	Point temp = *stack.head;
	push_op(&temp);

	return *this;
}
Stack::Stack(const Stack& stack)
{
	Point temp = *stack.head;
	push_op(&temp);
}
Stack::Stack(int n) : Stack()
{

	if (n > 0)
	{
		string str;
		cout << "Введите ключи " << n << " элементов:\n";
		for (int i = 1; i <= n; i++)
		{
			cout << i << ". ";
			getline(cin, str);
			push(str);
		}
	}
}

Stack::~Stack()
{
	while (pop() != "");
}

void Stack::push(string str)
{
	size++;
	Point* obj = new Point;
	obj->data = str;
	obj->next = head;
	head = obj;
}
string Stack::pop()
{
	string result = "";
	if (!stack_is_empty())
	{
		result = head->data;
		Point* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	return result;
}

void Stack::output(Point* obj) 
{
	if (obj == nullptr) return;
	output(obj->next);
	cout << obj->data << endl;
}
void Stack::show()
{
	if (stack_is_empty()) cout << "Стек пуст" << endl;
	else output(head);
}

