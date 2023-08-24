#include "stdafx.h"
#include "Student(1).h"

#include <iostream>

Student::Student()
{
	 
}


Student::~Student()
{

}

bool Student::operator==(const string &name) const
{
	return this->m_name == name;
}

void Student::write(const string & str, ofstream & file) const
{
	int n = (int)str.size();
	file.write((const char*)&n, 1);
	file.write(str.c_str(), str.size());
}

void Student::write(const int val, ofstream & file) const
{
	file.write((const char*)&val, 1);
}

void Student::read(string & str, ifstream & file) const
{
	int n = 0;
	file.read((char*)&n, 1);
	str.resize(n);
	char buf[32] = { 0 };
	file.read(buf, n);
	str = buf;
}

void Student::read(int & val, ifstream & file) const
{
	val = 0;
	file.read((char*)&val, 1);
}


istream &operator >> (istream &in, Student &stu)
{
	ifstream *file = dynamic_cast<ifstream*>(&in);
	if (file) {
		stu.read(stu.m_name, *file);
		stu.read(stu.m_sex, *file);
		stu.read(stu.m_phone, *file);
		stu.read(stu.m_age, *file);
	}
	else {
		//姓名、性别 、年龄、 手机号码
		in >> stu.m_name
			>> stu.m_sex
			>> stu.m_age
			>> stu.m_phone;
	}

	
	return in;
}

ostream &operator<<(ostream &out, const Student &stu)
{
	ofstream *file = dynamic_cast<ofstream*>(&out);
	if (file) {
		stu.write(stu.m_name, *file);
		stu.write(stu.m_sex, *file);
		stu.write(stu.m_phone, *file);
		stu.write(stu.m_age, *file);
	}
	else {
		out << stu.m_name << "\t"
			<< stu.m_sex << "\t"
			<< stu.m_age << "\t"
			<< stu.m_phone;
	}
	
	return out;
}
