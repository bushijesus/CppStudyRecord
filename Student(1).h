#pragma once
#include <string>
#include <fstream>
using namespace std;
 
class Student
{
public:
	Student();
	~Student();
	
	bool operator==(const string &name) const;

	friend istream &operator>>(istream &in, Student &stu);
	friend ostream &operator<<(ostream &out, const Student &stu);
private:
	void write(const string &str, ofstream &file) const;
	void write(const int val, ofstream &file) const;
	void read(string &str, ifstream &file) const;
	void read(int &val, ifstream &file) const;
private:
	//姓名、年龄、性别、手机号码
	string	m_name;
	string	m_sex;
	string	m_phone;
	int  	m_age;
};

