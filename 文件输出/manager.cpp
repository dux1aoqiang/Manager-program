#include"manager.h"
Manager::Manager(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->dID = dID;
}
void Manager::showperson()
{
	cout << "ְ���ı��:  " << this->m_ID
		<< "\tְ��������:  " << this->m_Name
		<< "\tְ����ְ��:  " << this->getperson()
		<< "\t��ϸ�Ĳ��������ϰ彻�������񣬲��·���Ա��" << endl;
 }
string Manager::getperson()
{
	return string("����");
 }