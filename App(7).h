#pragma once
#include <vector>
#include "Student(1).h"

class App
{
public:
	App();
	~App();
	void run();

private:
	void add();
	void edit();
	void remove();
	void show();
private:
	vector<Student>		m_students;
}; 

