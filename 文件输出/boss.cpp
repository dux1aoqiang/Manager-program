#include"boss.h"
Boss::Boss(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->dID = dID;
}
void Boss::showperson()
{
	cout << "职工的编号:  " << this->m_ID
		<< "\t职工的姓名:  " << this->m_Name
		<< "\t职工的职务:  " << this->getperson()
		<< "\t详细的操作：下发给经理任务" << endl;
}
string Boss::getperson()
{
	return string("老板");
}