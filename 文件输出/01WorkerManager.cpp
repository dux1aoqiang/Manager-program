#include"WorkerManager.h"
#include"staff.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"


using namespace std;
WorkerManager::WorkerManager()
{
	//1 文件未创建的时候 读
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;


		//记录职工人数
		this->m_EmpNum = 0;
		//文件是为空
		this->FileIsEmpty = true;
		//职工数组指针  数值后面利于多次开发 **前面一个是父类指针的类型后面一个是指针的对象
		this->m_EmpArray = NULL;
		
		ifs.close();
		return;
	}
	
	//2  文件存在  但是数据为空  先表示字符 然后读字符的末尾 就为空的表示
	char ch;
	ifs >> ch;//左移运算符 表示读取
	if (ifs.eof())
	{
		//测试代码  cout << "文件为空" << endl;

		//记录职工人数
		this->m_EmpNum = 0;
		//文件是为空
		this->FileIsEmpty = true;
		//职工数组指针  数值后面利于多次开发 **前面一个是父类指针的类型后面一个是指针的对象
		this->m_EmpArray = NULL;

		ifs.close();
		return;
	}
	//3  文件里储存了数据了读取数值
	int num = this->get_EmpNum();
	//测试代码  cout << "现在文件中有： " << num << "个人" << endl;
	this->m_EmpNum = num;
	 
	//开辟新空间堆区容量 并且调用init_emp
	this->m_EmpArray = new worker * [this->m_EmpNum];

	this->init_Emp();

	//测试代码  
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工的ID：" << this->m_EmpArray[i]->m_ID
			<< "  职工的姓名:" << this->m_EmpArray[i]->m_Name
			<< "  职工的职责:" << this->m_EmpArray[i]->dID<<endl;
	}*/

}

void WorkerManager::AddEmp()
{
	cout << "请输入添加职工的数量" << endl;
	int addnum = 0;//保存用户输入类型
	cin >> addnum;
	if (addnum > 0)
	{
		//添加
		//计算新添加的内存大小 从而实现覆盖
		
		int Newsize = this->m_EmpNum + addnum;

		//开辟新空间动态数组 后面new 父类*开辟数组  前面指针对应
		worker ** Newspace = new worker * [Newsize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum; i++)
			{
				Newspace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据  不能在上面if语句中执行 会没有结果 无法运行
		for (int i = 0; i < addnum; i++)
		{
			int ID;
			string name;
			int select;
			cout << "请输入第 " << i + 1 << "的编号" << endl;
			cin >> ID;
			cout << "请输入第 " << i + 1 << "的姓名" << endl;
			cin >> name;
			cout << "请选择岗位" << endl;
			cout << "1 ：普通职工     2 ：经理     3：老板" << endl;
			cin >> select;
			worker* worker = NULL;
			switch (select)
			{
			case 1:
			{
				worker = new Staff(ID, name, 1);
				break;
			}
			case 2:
			{
				worker = new Manager(ID, name, 2);
				break;
			}
			case 3:
			{
				worker = new Boss(ID, name, 3);
				break;
			}

			default:
				break;
			}

			//将创建的职工保存在新数组中去
			Newspace[this->m_EmpNum + i] = worker;

		}
		//释放原有空间数组   前面加【】 制定类型为数组
		delete[] this->m_EmpArray;

		//更改空间指向  将space的数组覆给Array 形成新的空间指向
		this->m_EmpArray = Newspace;

		//更新职工人数
		this->m_EmpNum = Newsize;       //Newsize=addnum + this->m_EmpNum

		//应为添加人员了  所以更新文件不为空
		this->FileIsEmpty = false;
		//提示
		cout << "成功添加了：   " << addnum << "   人员进入" << endl;

		this->save();

	}//
	else
	{
		cout << "输入的数据有误" << endl;
	}
}
void WorkerManager::Show_menu()  //要调用头文件里的东西从而实现维护 并面向对象
{
	cout << "欢迎使用杜哥哥打的职工管理系统" << endl;
	cout << "0：退出管理系统" << endl;
	cout << "1：增加职工信息" << endl;
	cout << "2：显示职工信息" << endl;
	cout << "3：删除离职成员" << endl;
	cout << "4：修改成员信息" << endl;
	cout << "5：查找职工信息" << endl;
	cout << "6：按照编号排序" << endl;
	cout << "7：清空所有文档" << endl;
	cout << endl;
}
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//开辟保存空间
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件 ————写文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << "  " << this->m_EmpArray[i]->m_Name << "  " << this->m_EmpArray[i]->dID << " " << endl;
		}//左移运算符为写入符号   右移运算符为读取 eof（）为文件的末尾
	ofs.close();
}

int WorkerManager ::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
		int id;
		string name;
		int did;
		int num=0;
		while (ifs>>id,ifs>>name,ifs>>did)
		{
			num++;
		}
		return num;
}

//从文件中直接读取数据并且初始化
void  WorkerManager::init_Emp() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int temp = 0;
	while (ifs >> id&& ifs >> name&& ifs >> did)
	{
		worker* worker=NULL;
		if (did == 1)
		{
			worker = new Staff(id, name, did);
		}

		if (did == 2)
		{
			worker = new Manager(id, name, did);
		}

		if (did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[temp] = worker;
		temp++;
	}
	ifs.close();

}

	//显示所有成员信息
void WorkerManager::show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "你输入的文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showperson();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}


//先查找是否有此人  如果没有此人返回-1 有此人=1
int WorkerManager::IsExist(int id)
{
	int idex = -1;
	
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)

		{
			idex = i;
			break;
		}
	}
	
	return idex;
}

//删除成员
void WorkerManager::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空" << endl;
	}
	else
	{
		int id=0;
		cout << "请输入你需要删除的ID" << endl;
		cin >> id;
		int idex = this->IsExist(id);
		
		if (idex != -1)
		{
			for (int i = idex; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				
			}
			this->m_EmpNum--;//跟新数组
			this->save();//保存在文件中去
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到此职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入需要查找并修改职工编号" << endl;
		int id = 0;
		cin >> id;
		int idex =this->IsExist(id);
		if (idex != -1)
		{
			delete this->m_EmpArray[idex];
			int newid=0;
			string newname;
			int newselect;
			cout << "查到"<<id<<"号职工，准备删除此职工" << endl;

			cout << "请输入修改后的新职工号" << endl;
			cin >> newid;
		

			cout << "请输入新的职工姓名" << endl;
			cin >> newname;

			cout << "请输入新的职工职位" << endl;
			cout << "1 ：普通职工     2 ：经理     3：老板" << endl;
			cin >> newselect;
			worker* worker = NULL;
			switch (newselect)
			{
			case 1:
				worker = new Staff(newid, newname, newselect);
				break;
			case 2:
				worker = new Manager(newid, newname, newselect);
				break;
			case 3:
				worker = new Boss(newid, newname, newselect);
				break;
			default:
				break;
			}
			this->m_EmpArray[idex] = worker;
			cout << "保存成功" << endl;
			this->save();

		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//选择查找方式
void WorkerManager::findmater_Emp()
{
	if(this->FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
	}

	else
	{
		int select = 0;
		cout << "请选择查找方式" << endl;
		cout << "1 按姓名查找" << endl;
		cout << "2 按编号查找" << endl;
		cin >> select;
		if (select == 1)
		{
			string name;
			cout << "请输入姓名->查找的具体的人" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					//姓名可能有重复 但编号不会
					cout << "查到此人  编号为"<<this->m_EmpArray[i]->m_ID<<"--此人信息如下" << endl;
					flag = true;
					//显示信息接口
					this->m_EmpArray[i]->showperson();
				}
			}
			if (flag == false)
			{
				cout << "查无此人或输入姓名有错" << endl;
			}
		}
		if (select == 2)
		{
			int id = 0;
			cout << "请输入编号->查找的具体的人" << endl;
			cin >> id;
			int idex=this->IsExist(id);
			if (idex != -1)
			{
				cout << "查到此人" << endl;
				this->m_EmpArray[idex]->showperson();
			}
			else
			{
				cout << "查找失败 查无此人"<<endl;
			}
			
		}
	}
	system("pause");
	system("cls");
}

//编号顺序
void WorkerManager::line_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空 或文件不存在" << endl;
		system("pause");
		system("cls");
	}

	else 
	{
		//升 或 降 排列
		cout << "请选择你需要的排列方式" << endl;
		cout << "1  升序   2  降序  " << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int maxORmin = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					//升序  定义一个最大 然后往后走
					if (this->m_EmpArray[i]->m_ID > this->m_EmpArray[j]->m_ID)

					{
						maxORmin = j;
					}
				}
				else
				{
					if(this->m_EmpArray[i]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						maxORmin = j;
					}
				}
			}
				//判断 定义的最大最小值 是否是算法里面的最大或最小的值
			if (i != maxORmin)
			{
				worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[maxORmin];
				this->m_EmpArray[maxORmin] = temp;
			}
		}
		cout << "排序成功  排序后的结果如下" << endl;
		this->save();
		this->show_Emp();
	}	
}

//清空所有
void WorkerManager::clean_all()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空 不需要清空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "确定是否清空" << endl;
		cout << "1 :确定  2: 否" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//清空
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);//意思为删除原有文件并重新创建
			ofs.close();
			if (this->m_EmpArray != NULL)
			{
				//删除数组中每个值  和数组指针并置为空 然后人数定于为0 定义文件为空；
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->FileIsEmpty = true;
			}
		}

	}
}

//析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != 0)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != 0)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
