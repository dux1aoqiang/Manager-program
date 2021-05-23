#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<string>

class Boss :public worker
{
public:
	Boss(int ID, string name, int dID);
	virtual void showperson();
	virtual string getperson();
};