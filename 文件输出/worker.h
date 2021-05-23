#pragma once
#include<iostream>
using namespace std;
#include<string>

class worker
{
public:
virtual void showperson()=0;
virtual string getperson()=0;//¸ÚÎ»


int m_ID;
string m_Name;
int dID;
};
