#include <regex>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main() {
	ifstream file("0829.log");
	if (!file.is_open()) {
		cout << "文件打开失败" << endl;
		return 1;
	}
	string line;
	regex pattern("(\\d{4}-\\d{2}-\\d{2}\\s\\d{2}:\\d{2}:\\d{2}).\\d{3}\\sINFO\\s-\\suser\\slogin,\\saction=login,\\susername=([a-zA-Z0-9]+)");
	map<string, int> loginCount;

	while (getline(file, line)) {
		smatch match;
		if (regex_search(line, match, pattern)) {
			string minute = match[1];
			string username = match[2];
			loginCount[minute + "-" + username]++;
		}
	}

	for (const auto& entry : loginCount) {
		string key = entry.first;
		int count = entry.second;
		cout << "Time: " << key.substr(0, 19) << ", Username: " << key.substr(20) << ", Login Count: " << count << endl;
	}

	return 0;
}