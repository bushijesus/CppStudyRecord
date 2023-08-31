#include <thread>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <numeric>
#include <windows.h>
using namespace std;

void singleThread() {
	vector<string> filelist;
	vector<int> age;
	for (int i = 1; i <= 5; ++i) {
		filelist.push_back(to_string(i) + ".txt");
	}
	for (string filename : filelist) {
		ifstream file(filename);
		string line;
		while (getline(file, line)) {
			istringstream ss(line);
			string item;
			for (int j = 0; j < 2; ++j) {
				if (getline(ss, item, ',')) {
					if (j == 1) {
						age.push_back(stoi(item));
					}
				}
				else {
					break;
				}
			}
		}
	}
	cout << accumulate(age.begin(), age.end(), 0) / age.size() << endl;
}

int main() {
	DWORD start, end;
	start = GetTickCount();
	singleThread();
	end = GetTickCount() - start;
	cout << end << endl;
	return 0;
}
vector<int> age;

void multiFile1() {
	ifstream file("1.txt");
	string line;
	while (getline(file, line)) {
		istringstream ss(line);
		string item;
		for (int j = 0; j < 2; ++j) {
			if (getline(ss, item, ',')) {
				if (j == 1) {
					age.push_back(stoi(item));
				}
			}
			else {
				break;
			}
		}
	}
}
void multiFile2() {
	ifstream file("2.txt");
	string line;
	while (getline(file, line)) {
		istringstream ss(line);
		string item;
		for (int j = 0; j < 2; ++j) {
			if (getline(ss, item, ',')) {
				if (j == 1) {
					age.push_back(stoi(item));
				}
			}
			else {
				break;
			}
		}
	}
}
void multiFile3() {
	ifstream file("3.txt");
	string line;
	while (getline(file, line)) {
		istringstream ss(line);
		string item;
		for (int j = 0; j < 2; ++j) {
			if (getline(ss, item, ',')) {
				if (j == 1) {
					age.push_back(stoi(item));
				}
			}
			else {
				break;
			}
		}
	}
}
void multiFile4() {
	ifstream file("4.txt");
	string line;
	while (getline(file, line)) {
		istringstream ss(line);
		string item;
		for (int j = 0; j < 2; ++j) {
			if (getline(ss, item, ',')) {
				if (j == 1) {
					age.push_back(stoi(item));
				}
			}
			else {
				break;
			}
		}
	}
}
void multiFile5() {
	ifstream file("5.txt");
	string line;
	while (getline(file, line)) {
		istringstream ss(line);
		string item;
		for (int j = 0; j < 2; ++j) {
			if (getline(ss, item, ',')) {
				if (j == 1) {
					age.push_back(stoi(item));
				}
			}
			else {
				break;
			}
		}
	}
}

int main2() {
	DWORD start, end;
	start = GetTickCount();
	
	thread th1(multiFile1);
	th1.join();
	thread th2(multiFile2);
	th2.join();
	thread th3(multiFile3);
	th3.join();
	thread th4(multiFile4);
	th4.join();
	thread th5(multiFile5);
	th5.join();

	end = GetTickCount() - start;
	cout << accumulate(age.begin(), age.end(), 0) / age.size() << endl;
	cout << end << endl;
	return 0;
}