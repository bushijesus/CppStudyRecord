#include <thread>
#include <string>
#include <iostream>
using namespace std;

class A {
public:
	void output(string name) {
		for (int i = 0; i < 3; i++)
		{
			cout << name << "--test" << i << endl;
		}
	}
};
void test1(string name) {
	for (int i = 0; i < 3; i++)
	{
		cout << name << "--test" << i << endl;
	}
}
int main1() {
	thread th1(test1, "线程");
	th1.join();

	A a1;
	thread th2(&A::output, a1, "线程");
	th2.join();

	thread th3([]() {
		for (int i = 0; i < 3; i++)
		{
			cout << "Lambda" << i << endl;
		}
		});
	th3.join();
	return 0;
}