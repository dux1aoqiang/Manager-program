#include"manager.h"
Manager::Manager(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->dID = dID;
}
void Manager::showperson()
{
	cout << "职工的编号:  " << this->m_ID
		<< "\t职工的姓名:  " << this->m_Name
		<< "\t职工的职务:  " << this->getperson()
		<< "\t详细的操作：做老板交代的任务，并下发给员工" << endl;
 }
string Manager::getperson()
{
	return string("经理");
 }