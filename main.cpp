#include <sstream>
#include <string>
#include <list>
#include <iostream>
#include <iomanip>
using namespace std;

void test1() {
	ostringstream stream;
	stream << 10 << "-" << "test";
	cout << stream.str() << endl;
}

void test2() {
	istringstream stream("10 20 nihao");
	int a = 0;
	int b = 0;
	string str;
	stream >> a >> b >> str;
	cout << "a = " << a << endl
		<< "b = " << b << endl
		<< "str = " << str << endl;
}

void test3() {
	cout << setiosflags(ios::left) << setw(7);
	cout << resetiosflags(ios::left);
	cout << setfill('.') << setw(30);
	cout << setfill(' ');
	cout << setiosflags(ios::showpos);
	cout << resetiosflags(ios::showpos);
	cout << setiosflags(ios::showpoint);
	cout << resetiosflags(ios::showpoint);
	cout << setiosflags(ios::scientific);
	cout << resetiosflags(ios::scientific);
	cout << setprecision(18);
	cout << setprecision(6);
	cout << setiosflags(ios::showpos) << 10 << endl;
	cout << setiosflags(ios::showpos) << oct << setw(10) << 15 << endl;
	cout << setiosflags(ios::scientific) << hex << setw(10) << 20 << endl;
}

void test4() {
	list<int> ls = { 3,4,5 };
	ls.push_back(6);
	ls.push_back(6);
	ls.push_back(6);
	ls.push_back(6);
	ls.push_back(6);
	ls.push_back(6);
	ls.push_back(6);
	ls.push_back(6);
	ls.push_back(6);
	ls.push_front(2);
	for (auto i : ls)
	{
		cout << i << ' ';
	}
	cout << endl;
	cout << ls.front() << endl;
	cout << ls.back() << endl;
	cout << ls.size() << endl;
	cout << ls.empty() << endl;
	ls.pop_back();
	ls.pop_front();
	//ls.remove(6);
	for (auto it = ls.begin(); it != ls.end();)
	{
		if (*it == 6)
		{
			it = ls.erase(it);
		}
		else
		{
			++it;
		}
	}

	ls.sort([](int a, int b) {return a > b; });
	ls.reverse();
	for (auto i : ls)
	{
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	test4();
	return 0;
}