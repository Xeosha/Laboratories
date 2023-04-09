#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object
{
public:
	Object();
	~Object();
	virtual void Show() = 0;
};

