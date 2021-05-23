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
	worker = new Staff(1, "张三", 1);
	worker->showperson();
	delete worker;
	worker = new Manager(2, "李四", 1);
	worker->showperson();
	delete worker;
	worker = new Boss(2, "李四", 1);
	worker->showperson();
	delete worker;*/
	

	int choice = 0;
	while (true)
	{
		wm.Show_menu();
		cout << "请输入你的choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加成员
			wm.AddEmp();
			break;
		case 2://显示职员
			wm.show_Emp();
			break;
		case 3://删除职员
			wm.Del_Emp();
			break;
		case 4://修改职员
			wm.Mod_Emp();
			break;
		case 5://查找职员信息
			wm.findmater_Emp();
			break;
		case 6://编号排序
			wm.line_Emp();
			break;
		case 7://清空
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