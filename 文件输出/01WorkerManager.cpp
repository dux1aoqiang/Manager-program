#include"WorkerManager.h"
#include"staff.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"


using namespace std;
WorkerManager::WorkerManager()
{
	//1 �ļ�δ������ʱ�� ��
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;


		//��¼ְ������
		this->m_EmpNum = 0;
		//�ļ���Ϊ��
		this->FileIsEmpty = true;
		//ְ������ָ��  ��ֵ�������ڶ�ο��� **ǰ��һ���Ǹ���ָ������ͺ���һ����ָ��Ķ���
		this->m_EmpArray = NULL;
		
		ifs.close();
		return;
	}
	
	//2  �ļ�����  ��������Ϊ��  �ȱ�ʾ�ַ� Ȼ����ַ���ĩβ ��Ϊ�յı�ʾ
	char ch;
	ifs >> ch;//��������� ��ʾ��ȡ
	if (ifs.eof())
	{
		//���Դ���  cout << "�ļ�Ϊ��" << endl;

		//��¼ְ������
		this->m_EmpNum = 0;
		//�ļ���Ϊ��
		this->FileIsEmpty = true;
		//ְ������ָ��  ��ֵ�������ڶ�ο��� **ǰ��һ���Ǹ���ָ������ͺ���һ����ָ��Ķ���
		this->m_EmpArray = NULL;

		ifs.close();
		return;
	}
	//3  �ļ��ﴢ���������˶�ȡ��ֵ
	int num = this->get_EmpNum();
	//���Դ���  cout << "�����ļ����У� " << num << "����" << endl;
	this->m_EmpNum = num;
	 
	//�����¿ռ�������� ���ҵ���init_emp
	this->m_EmpArray = new worker * [this->m_EmpNum];

	this->init_Emp();

	//���Դ���  
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ID��" << this->m_EmpArray[i]->m_ID
			<< "  ְ��������:" << this->m_EmpArray[i]->m_Name
			<< "  ְ����ְ��:" << this->m_EmpArray[i]->dID<<endl;
	}*/

}

void WorkerManager::AddEmp()
{
	cout << "���������ְ��������" << endl;
	int addnum = 0;//�����û���������
	cin >> addnum;
	if (addnum > 0)
	{
		//���
		//��������ӵ��ڴ��С �Ӷ�ʵ�ָ���
		
		int Newsize = this->m_EmpNum + addnum;

		//�����¿ռ䶯̬���� ����new ����*��������  ǰ��ָ���Ӧ
		worker ** Newspace = new worker * [Newsize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum; i++)
			{
				Newspace[i] = this->m_EmpArray[i];
			}
		}
		//���������  ����������if�����ִ�� ��û�н�� �޷�����
		for (int i = 0; i < addnum; i++)
		{
			int ID;
			string name;
			int select;
			cout << "������� " << i + 1 << "�ı��" << endl;
			cin >> ID;
			cout << "������� " << i + 1 << "������" << endl;
			cin >> name;
			cout << "��ѡ���λ" << endl;
			cout << "1 ����ְͨ��     2 ������     3���ϰ�" << endl;
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

			//��������ְ����������������ȥ
			Newspace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�пռ�����   ǰ��ӡ��� �ƶ�����Ϊ����
		delete[] this->m_EmpArray;

		//���Ŀռ�ָ��  ��space�����鸲��Array �γ��µĿռ�ָ��
		this->m_EmpArray = Newspace;

		//����ְ������
		this->m_EmpNum = Newsize;       //Newsize=addnum + this->m_EmpNum

		//ӦΪ�����Ա��  ���Ը����ļ���Ϊ��
		this->FileIsEmpty = false;
		//��ʾ
		cout << "�ɹ�����ˣ�   " << addnum << "   ��Ա����" << endl;

		this->save();

	}//
	else
	{
		cout << "�������������" << endl;
	}
}
void WorkerManager::Show_menu()  //Ҫ����ͷ�ļ���Ķ����Ӷ�ʵ��ά�� ���������
{
	cout << "��ӭʹ�öŸ����ְ������ϵͳ" << endl;
	cout << "0���˳�����ϵͳ" << endl;
	cout << "1������ְ����Ϣ" << endl;
	cout << "2����ʾְ����Ϣ" << endl;
	cout << "3��ɾ����ְ��Ա" << endl;
	cout << "4���޸ĳ�Ա��Ϣ" << endl;
	cout << "5������ְ����Ϣ" << endl;
	cout << "6�����ձ������" << endl;
	cout << "7����������ĵ�" << endl;
	cout << endl;
}
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ٱ���ռ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ� ��������д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << "  " << this->m_EmpArray[i]->m_Name << "  " << this->m_EmpArray[i]->dID << " " << endl;
		}//���������Ϊд�����   ���������Ϊ��ȡ eof����Ϊ�ļ���ĩβ
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

//���ļ���ֱ�Ӷ�ȡ���ݲ��ҳ�ʼ��
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

	//��ʾ���г�Ա��Ϣ
void WorkerManager::show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "��������ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showperson();
		}
	}
	//�����������
	system("pause");
	system("cls");
}


//�Ȳ����Ƿ��д���  ���û�д��˷���-1 �д���=1
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

//ɾ����Ա
void WorkerManager::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ��" << endl;
	}
	else
	{
		int id=0;
		cout << "����������Ҫɾ����ID" << endl;
		cin >> id;
		int idex = this->IsExist(id);
		
		if (idex != -1)
		{
			for (int i = idex; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				
			}
			this->m_EmpNum--;//��������
			this->save();//�������ļ���ȥ
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ���Ҳ��޸�ְ�����" << endl;
		int id = 0;
		cin >> id;
		int idex =this->IsExist(id);
		if (idex != -1)
		{
			delete this->m_EmpArray[idex];
			int newid=0;
			string newname;
			int newselect;
			cout << "�鵽"<<id<<"��ְ����׼��ɾ����ְ��" << endl;

			cout << "�������޸ĺ����ְ����" << endl;
			cin >> newid;
		

			cout << "�������µ�ְ������" << endl;
			cin >> newname;

			cout << "�������µ�ְ��ְλ" << endl;
			cout << "1 ����ְͨ��     2 ������     3���ϰ�" << endl;
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
			cout << "����ɹ�" << endl;
			this->save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//ѡ����ҷ�ʽ
void WorkerManager::findmater_Emp()
{
	if(this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}

	else
	{
		int select = 0;
		cout << "��ѡ����ҷ�ʽ" << endl;
		cout << "1 ����������" << endl;
		cout << "2 ����Ų���" << endl;
		cin >> select;
		if (select == 1)
		{
			string name;
			cout << "����������->���ҵľ������" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					//�����������ظ� ����Ų���
					cout << "�鵽����  ���Ϊ"<<this->m_EmpArray[i]->m_ID<<"--������Ϣ����" << endl;
					flag = true;
					//��ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showperson();
				}
			}
			if (flag == false)
			{
				cout << "���޴��˻����������д�" << endl;
			}
		}
		if (select == 2)
		{
			int id = 0;
			cout << "��������->���ҵľ������" << endl;
			cin >> id;
			int idex=this->IsExist(id);
			if (idex != -1)
			{
				cout << "�鵽����" << endl;
				this->m_EmpArray[idex]->showperson();
			}
			else
			{
				cout << "����ʧ�� ���޴���"<<endl;
			}
			
		}
	}
	system("pause");
	system("cls");
}

//���˳��
void WorkerManager::line_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�� ���ļ�������" << endl;
		system("pause");
		system("cls");
	}

	else 
	{
		//�� �� �� ����
		cout << "��ѡ������Ҫ�����з�ʽ" << endl;
		cout << "1  ����   2  ����  " << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int maxORmin = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					//����  ����һ����� Ȼ��������
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
				//�ж� ����������Сֵ �Ƿ����㷨�����������С��ֵ
			if (i != maxORmin)
			{
				worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[maxORmin];
				this->m_EmpArray[maxORmin] = temp;
			}
		}
		cout << "����ɹ�  �����Ľ������" << endl;
		this->save();
		this->show_Emp();
	}	
}

//�������
void WorkerManager::clean_all()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�� ����Ҫ���" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "ȷ���Ƿ����" << endl;
		cout << "1 :ȷ��  2: ��" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���
			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);//��˼Ϊɾ��ԭ���ļ������´���
			ofs.close();
			if (this->m_EmpArray != NULL)
			{
				//ɾ��������ÿ��ֵ  ������ָ�벢��Ϊ�� Ȼ����������Ϊ0 �����ļ�Ϊ�գ�
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

//��������
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
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}
