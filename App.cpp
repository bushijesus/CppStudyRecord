#include "App.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void App::run()
{
	int choice;
	while (true)
	{
		menu();
		cin >> choice;
		if (choice == 1)
		{
			cout << "***** 1、添加学生信息 *****" << endl;
			add();
		}
		else if (choice == 2)
		{
			cout << "***** 2、编辑学生信息 *****" << endl;
			edit();
		}
		else if (choice == 3)
		{
			cout << "***** 3、显示学生信息 *****" << endl;
			show();
		}
		else if (choice == 4)
		{
			cout << "***** 退出成功！ *****" << endl;
			break;
		}
		else
		{
			cout << "***** 无效输入，请重试！ *****" << endl;
		}
	}
}

void App::menu()
{
	cout << "--------------------------------" << endl;
	cout << "             请选择：           " << endl;
	cout << "1、添加学生信息  2、编辑学生信息" << endl;
	cout << "3、显示学生信息  4、退出当前系统" << endl;
	cout << "--------------------------------" << endl;
}

void App::add()
{
	string name;
	int age;
	char sex;
	string num;
	cout << "请输入要添加学生的信息：姓名、年龄、性别、手机号" << endl;
	cin >> name >> age >> sex >> num;
	ofstream out("Student.txt", ios::binary);
	if (!out)
	{
		cout << "打开输出文件失败" << endl;
	}
	// 写入姓名的长度以及姓名
	size_t lenOfName = name.size();
	out.write((const char*)&lenOfName, 2);
	out.write(name.c_str(), lenOfName);
	// 写入年龄
	out.write((const char*)&age, 4);
	// 写入性别
	out.write((const char*)&sex, 1);
	// 写入手机号
	size_t lenOfNum = num.size();
	out.write((const char*)&lenOfNum, 2);
	out.write(num.c_str(), lenOfNum);

	cout << "添加成功！" << endl;
	out.close();
}

void App::edit()
{
	string name;
	cout << "请输入要编辑的学生姓名：" << endl;
	cin >> name;


	ifstream in("Student.txt", ios::binary);
	ofstream out("newStudent.txt", ios::binary);

	while (!in.eof())
	{
		// 读取原数据
		
		// 读取姓名长度以及姓名
		string originName;
		size_t lenOfName = 0;
		in.read((char*)(&lenOfName), 2);
		originName.resize(lenOfName);
		in.read(&originName[0], lenOfName);

		// 读取年龄
		int originAge;
		in.read((char*)(&originAge), 4);

		// 读取性别
		char originSex;
		in.read(&originSex, 1);

		// 读取电话号码
		string originNum;
		size_t lenOfNum = 0;
		in.read((char*)(&lenOfNum), 2);
		originNum.resize(lenOfNum);
		in.read(&originNum[0], lenOfNum);

		// 判断是否为想要编辑的学生
		if (name == originName)
		{
			// 写入新数据
			cout << "请输入新的学生信息：年龄、性别、电话" << endl;
			int newAge;
			char newSex;
			string newNum;
			cin >> newAge >> newSex >> newNum;
			// 写入姓名的长度以及姓名
			size_t lenOfName = name.size();
			out.write((const char*)&lenOfName, 2);
			out.write(name.c_str(), lenOfName);
			// 写入新年龄
			out.write((const char*)&newAge, 4);
			// 写入新性别
			out.write((const char*)&newSex, 1);
			// 写入新手机号
			size_t lenOfNum = newNum.size();
			out.write((const char*)&lenOfNum, 2);
			out.write(newNum.c_str(), lenOfNum);
		}
		else
		{
			// 写入原数据
			// 写入姓名的长度以及姓名
			size_t lenOfName = originName.size();
			out.write((const char*)&lenOfName, 2);
			out.write(originName.c_str(), lenOfName);
			// 写入年龄
			out.write((const char*)&originAge, 4);
			// 写入性别
			out.write((const char*)&originSex, 1);
			// 写入手机号
			size_t lenOfNum = originNum.size();
			out.write((const char*)&lenOfNum, 2);
			out.write(originNum.c_str(), lenOfNum);
		}
	}
	in.close();
	out.close();
	remove("Student.txt");
	int flag = rename("newStudent.txt", "Student.txt");
	if (flag == 0)
	{
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "修改失败" << endl;
	}
}

void App::show() const
{
	ifstream in("Student.txt", ios::binary);

	// 检查文件是否成功打开
	if (!in)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	while (!in.eof())
	{
		// 读取姓名长度以及姓名
		string name;
		size_t lenOfName = 0;
		in.read((char*)(&lenOfName), 2);
		name.resize(lenOfName);
		in.read((char*)name.c_str(), lenOfName);

		// 读取年龄
		int age;
		in.read((char*)(&age), 4);

		// 读取性别
		char sex;
		in.read(&sex, 1);

		// 读取电话号码
		string num;
		size_t lenOfNum = 0;
		in.read((char*)(&lenOfNum), 2);
		num.resize(lenOfNum);
		in.read((char*)num.c_str(), lenOfNum);

		cout << "姓名：" << name << " 年龄：" << age << " 性别：" << sex << " 电话号码：" << num << endl;
	}

	in.close();
}