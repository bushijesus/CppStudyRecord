#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "App(7).h"
using namespace std;

App::App()
{
	ifstream file("0824.dat", ios::binary);
	Student stu;
	while (file >> stu)
	{
		m_students.push_back(stu);
	}
}
 

App::~App()
{
	ofstream file("0824.dat", ios::binary);
	for (const auto &i : m_students) {
		file << i;
	}
}

void App::run()
{
	while (true)
	{
		cout << "    1、添加学生信息 2、编辑学生信息\n"
			<< "    3、显示学生信息 4、删除\n"
			<< "    5、退出系统\n";

		int n;
		cin >> n;
		if (n == 1) add();
		else if (n == 2) edit();
		else if (n == 3) show();
		else if (n == 4) remove();
		else if (n == 5) break;
	}
}

void App::add()
{
	cout << "请输入学生信息, 格式：姓名 性别 年龄 手机号码\n";
	Student stu;
	cin >> stu;
	m_students.push_back(stu);
}

void App::edit()
{
	cout << "请输入要编辑的学生姓名:";
	string name;
	cin >> name;
	auto it = std::find(m_students.begin(), m_students.end(), name);
	if (it != m_students.end()) {
		cout << "请输入学生信息, 格式：姓名 性别 年龄 手机号码\n";
		cin >> *it;
	}
	else {
		cout << "学生'" << name << "' 不存在，编辑失败\n";
	}
}

void App::remove()
{
	cout << "请输入要删除的学生姓名:";
	string name;
	cin >> name;
	auto it = std::find(m_students.begin(), m_students.end(), name);
	if (it != m_students.end()) {
		m_students.erase(it);
		cout << "删除成功" << endl;
	}
	else {
		cout << "学生'" << name << "' 不存在，删除失败\n";
	}
}

void App::show()
{
	for (const Student &i : m_students) {
		cout << i << endl;
	}
}
