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
			cout << "***** 1�����ѧ����Ϣ *****" << endl;
			add();
		}
		else if (choice == 2)
		{
			cout << "***** 2���༭ѧ����Ϣ *****" << endl;
			edit();
		}
		else if (choice == 3)
		{
			cout << "***** 3����ʾѧ����Ϣ *****" << endl;
			show();
		}
		else if (choice == 4)
		{
			cout << "***** �˳��ɹ��� *****" << endl;
			break;
		}
		else
		{
			cout << "***** ��Ч���룬�����ԣ� *****" << endl;
		}
	}
}

void App::menu()
{
	cout << "--------------------------------" << endl;
	cout << "             ��ѡ��           " << endl;
	cout << "1�����ѧ����Ϣ  2���༭ѧ����Ϣ" << endl;
	cout << "3����ʾѧ����Ϣ  4���˳���ǰϵͳ" << endl;
	cout << "--------------------------------" << endl;
}

void App::add()
{
	string name;
	int age;
	char sex;
	string num;
	cout << "������Ҫ���ѧ������Ϣ�����������䡢�Ա��ֻ���" << endl;
	cin >> name >> age >> sex >> num;
	ofstream out("Student.txt", ios::binary);
	if (!out)
	{
		cout << "������ļ�ʧ��" << endl;
	}
	// д�������ĳ����Լ�����
	size_t lenOfName = name.size();
	out.write((const char*)&lenOfName, 2);
	out.write(name.c_str(), lenOfName);
	// д������
	out.write((const char*)&age, 4);
	// д���Ա�
	out.write((const char*)&sex, 1);
	// д���ֻ���
	size_t lenOfNum = num.size();
	out.write((const char*)&lenOfNum, 2);
	out.write(num.c_str(), lenOfNum);

	cout << "��ӳɹ���" << endl;
	out.close();
}

void App::edit()
{
	string name;
	cout << "������Ҫ�༭��ѧ��������" << endl;
	cin >> name;


	ifstream in("Student.txt", ios::binary);
	ofstream out("newStudent.txt", ios::binary);

	while (!in.eof())
	{
		// ��ȡԭ����
		
		// ��ȡ���������Լ�����
		string originName;
		size_t lenOfName = 0;
		in.read((char*)(&lenOfName), 2);
		originName.resize(lenOfName);
		in.read(&originName[0], lenOfName);

		// ��ȡ����
		int originAge;
		in.read((char*)(&originAge), 4);

		// ��ȡ�Ա�
		char originSex;
		in.read(&originSex, 1);

		// ��ȡ�绰����
		string originNum;
		size_t lenOfNum = 0;
		in.read((char*)(&lenOfNum), 2);
		originNum.resize(lenOfNum);
		in.read(&originNum[0], lenOfNum);

		// �ж��Ƿ�Ϊ��Ҫ�༭��ѧ��
		if (name == originName)
		{
			// д��������
			cout << "�������µ�ѧ����Ϣ�����䡢�Ա𡢵绰" << endl;
			int newAge;
			char newSex;
			string newNum;
			cin >> newAge >> newSex >> newNum;
			// д�������ĳ����Լ�����
			size_t lenOfName = name.size();
			out.write((const char*)&lenOfName, 2);
			out.write(name.c_str(), lenOfName);
			// д��������
			out.write((const char*)&newAge, 4);
			// д�����Ա�
			out.write((const char*)&newSex, 1);
			// д�����ֻ���
			size_t lenOfNum = newNum.size();
			out.write((const char*)&lenOfNum, 2);
			out.write(newNum.c_str(), lenOfNum);
		}
		else
		{
			// д��ԭ����
			// д�������ĳ����Լ�����
			size_t lenOfName = originName.size();
			out.write((const char*)&lenOfName, 2);
			out.write(originName.c_str(), lenOfName);
			// д������
			out.write((const char*)&originAge, 4);
			// д���Ա�
			out.write((const char*)&originSex, 1);
			// д���ֻ���
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
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "�޸�ʧ��" << endl;
	}
}

void App::show() const
{
	ifstream in("Student.txt", ios::binary);

	// ����ļ��Ƿ�ɹ���
	if (!in)
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	while (!in.eof())
	{
		// ��ȡ���������Լ�����
		string name;
		size_t lenOfName = 0;
		in.read((char*)(&lenOfName), 2);
		name.resize(lenOfName);
		in.read((char*)name.c_str(), lenOfName);

		// ��ȡ����
		int age;
		in.read((char*)(&age), 4);

		// ��ȡ�Ա�
		char sex;
		in.read(&sex, 1);

		// ��ȡ�绰����
		string num;
		size_t lenOfNum = 0;
		in.read((char*)(&lenOfNum), 2);
		num.resize(lenOfNum);
		in.read((char*)num.c_str(), lenOfNum);

		cout << "������" << name << " ���䣺" << age << " �Ա�" << sex << " �绰���룺" << num << endl;
	}

	in.close();
}