#include"worker.h"
#pragma once

class Staff :public worker
{
public:
	Staff(int ID, string name, int dID);

	void showperson();
	
	string getperson();

	
};