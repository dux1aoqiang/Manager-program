#include"staff.h"


Staff::Staff(int ID,string name,int dID ) 
{
	this->m_ID = ID;
	this->m_Name = name;
	this->dID = dID;
}

void Staff::showperson()
{
	cout << "ְ���ı��:  " << this->m_ID
		<< "\tְ��������:  " << this->m_Name
		<< "\tְ����ְ��:  " << this->getperson()
		<<"\t��ϸ�Ĳ�������������������" << endl;
}

string Staff::getperson()
{
	return string("ְԱ");
}




