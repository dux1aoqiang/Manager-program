#include<iostream>
using namespace std;
#include"WorkerManager.h"

#include"worker.h"
#include"staff.h"
#include"manager.h"
#include"boss.h"

int main()
{
	WorkerManager wm;

	/*worker* worker = NULL;
	worker = new Staff(1, "����", 1);
	worker->showperson();
	delete worker;
	worker = new Manager(2, "����", 1);
	worker->showperson();
	delete worker;
	worker = new Boss(2, "����", 1);
	worker->showperson();
	delete worker;*/
	

	int choice = 0;
	while (true)
	{
		wm.Show_menu();
		cout << "���������choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://��ӳ�Ա
			wm.AddEmp();
			break;
		case 2://��ʾְԱ
			wm.show_Emp();
			break;
		case 3://ɾ��ְԱ
			wm.Del_Emp();
			break;
		case 4://�޸�ְԱ
			wm.Mod_Emp();
			break;
		case 5://����ְԱ��Ϣ
			wm.findmater_Emp();
			break;
		case 6://�������
			wm.line_Emp();
			break;
		case 7://���
			wm.clean_all();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}