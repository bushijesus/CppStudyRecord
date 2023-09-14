#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	LPCTSTR pipeName = TEXT("my_pipe");
	HANDLE pipeHandle;

	if (pipeHandle == INVALID_HANDLE_VALUE) {
		cout << "Failed to open pipe. Error code: " << GetLastError() << std::endl;
		return 1;
	}
	// 连接到命名管道
	pipeHandle = CreateFile(
		pipeName,      // 管道名称
		GENERIC_READ,  // 管道的访问模式，此处为读取
		0,   // 共享模式，此处为独占访问
		NULL,   // 安全模式，此处为默认值
		OPEN_EXISTING,  // 打开现有的管道
		0,   // 文件属性，此处为默认值
		NULL  // 模板句柄，此处为默认值
	);

	// 读取命名管道中的数据
	char buffer[100];
	DWORD byteRead;
	bool success = ReadFile(pipeHandle, buffer, sizeof(buffer), &byteRead, NULL);

	if (success)
	{
		// 输出读到的数据
		cout << "Message received : " << buffer << endl;
	}

	// 关闭管道句柄
	CloseHandle(pipeHandle);
}
