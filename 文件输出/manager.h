#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<string>

class Manager :public worker
{
public:
	Manager(int ID, string name, int dID);
	 void showperson();
	 string getperson();
};