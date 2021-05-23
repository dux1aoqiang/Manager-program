#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
//  开辟一个输出输入流 并且输入一个   （后面才好引用）宏文件名
#include<fstream>
#define FILENAME "empFile.txt"






class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//显示菜单
	void Show_menu();
	//记录职工人数
	int m_EmpNum;

	//职工数组指针  数值后面利于多次开发 **前面一个是父类指针的类型后面一个是指针的对象
	worker** m_EmpArray;
	
	//开辟加人的通道
	void AddEmp();

	//开辟保存空间
	void save();

	//判断文件是否为空
	bool FileIsEmpty;

	//从文件中直接读取人数
	int get_EmpNum();

	//从文件中直接读取数据并且初始化
	void  init_Emp();

	//显示名字等等
	void show_Emp();

	//先查找是否有此人
	int IsExist(int id);

	//删除成员
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//选择查找方式
	void findmater_Emp();

	//编号顺序
	void line_Emp();
	
	//清空所有
	void clean_all();


	//退出系统
	void exitSystem();
	//析构函数
	~WorkerManager();
};