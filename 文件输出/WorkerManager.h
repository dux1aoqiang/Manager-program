#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
//  ����һ����������� ��������һ��   ������ź����ã����ļ���
#include<fstream>
#define FILENAME "empFile.txt"






class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//��ʾ�˵�
	void Show_menu();
	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��  ��ֵ�������ڶ�ο��� **ǰ��һ���Ǹ���ָ������ͺ���һ����ָ��Ķ���
	worker** m_EmpArray;
	
	//���ټ��˵�ͨ��
	void AddEmp();

	//���ٱ���ռ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool FileIsEmpty;

	//���ļ���ֱ�Ӷ�ȡ����
	int get_EmpNum();

	//���ļ���ֱ�Ӷ�ȡ���ݲ��ҳ�ʼ��
	void  init_Emp();

	//��ʾ���ֵȵ�
	void show_Emp();

	//�Ȳ����Ƿ��д���
	int IsExist(int id);

	//ɾ����Ա
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//ѡ����ҷ�ʽ
	void findmater_Emp();

	//���˳��
	void line_Emp();
	
	//�������
	void clean_all();


	//�˳�ϵͳ
	void exitSystem();
	//��������
	~WorkerManager();
};