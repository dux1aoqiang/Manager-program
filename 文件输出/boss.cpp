#include"boss.h"
Boss::Boss(int ID, string name, int dID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->dID = dID;
}
void Boss::showperson()
{
	cout << "ְ���ı��:  " << this->m_ID
		<< "\tְ��������:  " << this->m_Name
		<< "\tְ����ְ��:  " << this->getperson()
		<< "\t��ϸ�Ĳ������·�����������" << endl;
}
string Boss::getperson()
{
	return string("�ϰ�");
}