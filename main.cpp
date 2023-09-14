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
	// ���ӵ������ܵ�
	pipeHandle = CreateFile(
		pipeName,      // �ܵ�����
		GENERIC_READ,  // �ܵ��ķ���ģʽ���˴�Ϊ��ȡ
		0,   // ����ģʽ���˴�Ϊ��ռ����
		NULL,   // ��ȫģʽ���˴�ΪĬ��ֵ
		OPEN_EXISTING,  // �����еĹܵ�
		0,   // �ļ����ԣ��˴�ΪĬ��ֵ
		NULL  // ģ�������˴�ΪĬ��ֵ
	);

	// ��ȡ�����ܵ��е�����
	char buffer[100];
	DWORD byteRead;
	bool success = ReadFile(pipeHandle, buffer, sizeof(buffer), &byteRead, NULL);

	if (success)
	{
		// �������������
		cout << "Message received : " << buffer << endl;
	}

	// �رչܵ����
	CloseHandle(pipeHandle);
}
