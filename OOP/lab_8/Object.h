#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Event.h"

class Object
{
public:
	Object();
	~Object();
	virtual void Show() = 0;
	virtual void HandleEvent(const TEvent& e) = 0;
	virtual int AvgAge() = 0;
};

