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
		cout << "    1�����ѧ����Ϣ 2���༭ѧ����Ϣ\n"
			<< "    3����ʾѧ����Ϣ 4��ɾ��\n"
			<< "    5���˳�ϵͳ\n";

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
	cout << "������ѧ����Ϣ, ��ʽ������ �Ա� ���� �ֻ�����\n";
	Student stu;
	cin >> stu;
	m_students.push_back(stu);
}

void App::edit()
{
	cout << "������Ҫ�༭��ѧ������:";
	string name;
	cin >> name;
	auto it = std::find(m_students.begin(), m_students.end(), name);
	if (it != m_students.end()) {
		cout << "������ѧ����Ϣ, ��ʽ������ �Ա� ���� �ֻ�����\n";
		cin >> *it;
	}
	else {
		cout << "ѧ��'" << name << "' �����ڣ��༭ʧ��\n";
	}
}

void App::remove()
{
	cout << "������Ҫɾ����ѧ������:";
	string name;
	cin >> name;
	auto it = std::find(m_students.begin(), m_students.end(), name);
	if (it != m_students.end()) {
		m_students.erase(it);
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "ѧ��'" << name << "' �����ڣ�ɾ��ʧ��\n";
	}
}

void App::show()
{
	for (const Student &i : m_students) {
		cout << i << endl;
	}
}
