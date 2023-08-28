#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <stack>
#include <deque>
#include <array>
#include <algorithm>
#include <iostream>
using namespace std;

void test1() {
	unordered_set<int> us;
	us.insert(1);
	us.insert(8);
	us.insert(7);
	us.insert(2);
	us.insert(9);
	us.insert(2);
	us.insert(3);
	us.insert(2);
	us.insert(1);
	us.insert(1);
	us.insert(8);

	for (int i : us)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test2() {
	multiset<int> ms;
	ms.insert(3);
	ms.insert(5);
	ms.insert(2);
	ms.insert(3);
	ms.insert(1);
	for (int i : ms)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test3() {
	unordered_map<string, int> um;
	um.insert(pair<string, int>("张鑫", 56));
	um.insert(pair<string, int>("张森", 24));
	um.insert(pair<string, int>("张淼", 11));
	um.insert(pair<string, int>("张焱", 35));
	um.insert(pair<string, int>("张垚", 98));

	for (auto i : um)
	{
		cout << i.first << " " << i.second << endl;
	}
}

void test4() {
	map<string, int> m;
	m.insert(pair<string, int>("张鑫", 56));
	m.insert(pair<string, int>("张森", 24));
	m.insert(pair<string, int>("张淼", 11));
	m.insert(pair<string, int>("张焱", 35));
	m.insert(pair<string, int>("张垚", 98));

	for (auto i : m)
	{
		cout << i.first << " " << i.second << endl;
	}
}

void test5() {
	multimap<string, int> mm;
	mm.insert(pair<string, int>("张鑫", 56));
	mm.insert(pair<string, int>("张森", 24));
	mm.insert(pair<string, int>("张淼", 11));
	mm.insert(pair<string, int>("张焱", 35));
	mm.insert(pair<string, int>("张垚", 98));
	mm.insert(pair<string, int>("张鑫", 56));
	mm.insert(pair<string, int>("张鑫", 56));
	mm.insert(pair<string, int>("张鑫", 56));


	for (auto i : mm)
	{
		cout << i.first << " " << i.second << endl;
	}
}

void test6() {
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(1);
	st.push(3);
	st.push(8);
	while (!st.empty())
	{
		cout << st.top() << " " << endl;
		st.pop();
	}
}

void test7() {
	deque<int> dq;
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	dq.push_front(0);
	dq.push_front(1);
	dq.push_front(2);
	dq.pop_back();
	dq.pop_front();
	dq.insert(dq.begin() + 2, 8);
	for (int i : dq)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test8() {
	array<int, 5> arr;
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 1;
	arr[3] = 3;
	arr[4] = 8;
	sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });
	for (int i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}


bool higherThanTop(char op1, char op2)
{
	int priority1 = 0;
	int priority2 = 0;

	if (op1 == '*' || op1 == '/')
		priority1 = 1;

	if (op2 == '*' || op2 == '/')
		priority2 = 1;


	return priority1 > priority2;
}

void convertToPostfix(const string& mid, string& behind)
{
	stack<char> st;

	for (auto i : mid)
	{
		if (isdigit(i))
		{
			behind += i;
		}
		else if (i == '+' || i == '-' || i == '*' || i == '/')
		{
			if (st.empty() || st.top() == '(')
			{
				st.push(i);
			}
			else if (higherThanTop(i, st.top()))
			{
				st.push(i);
			}
			else
			{
				while (!st.empty() && !higherThanTop(i, st.top()))
				{
					behind += st.top();
					st.pop();
				}
				st.push(i);
			}
		}
		else if (i == '(')
		{
			st.push(i);
		}
		else if (i == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				behind += st.top();
				st.pop();
			}
			if (!st.empty() && st.top() == '(')
			{
				st.pop(); // 弹出 '('
			}
		}
	}

	while (!st.empty())
	{
		behind += st.top();
		st.pop();
	}
}
int main1() {
	string mid = "1+5*(3+2)-4*5";
	string behind = "";
	convertToPostfix(mid, behind);
	cout << behind;
	return 0;
}

int calc(const string& s) {
	stack<int> st;
	for (char i : s)
	{
		if (isdigit(i))
		{
			st.push(i - 48);
		}
		else
		{
			if (i == '+')
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				int num = num2 + num1;
				st.push(num);
			}
			else if(i == '-')
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				int num = num2 - num1;
				st.push(num);
			}
			else if (i == '*')
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				int num = num2 * num1;
				st.push(num);
			}
			else if (i == '/')
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				int num = num2 / num1;
				st.push(num);
			}
		}
	}
	return st.top();
}
