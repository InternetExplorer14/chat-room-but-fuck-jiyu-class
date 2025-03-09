/*
MIT License

Copyright (c) 2025 luozezhong.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
�������ָ��:
g++ ������.cpp -o ������ -std=c++20 -O2 -static-libgcc -Wall -Wextra -lws2_32
*/
#include<winsock2.h>
#include<windows.h>
#include<cstring>//memset
#include<cstdlib>
#include<thread>
#include<ws2tcpip.h>
#include<fstream>//file io
#include<vector>
#include<string>//str to Msgbox


//һ�Ѻ�������
void loadwinapilib();//���ؿ�
WNDCLASSEX registerwcex(const char[]);//ע�ᴰ����
typedef long long WINAPI(*SPDA)(VOID);//����ĺ���ָ��������
SPDA SetProcessDPIAware;//����Ҫȫ����
bool IsWin81OrLater();


//����
HINSTANCE hInstance_WinMain;
int now_group_id;
std::fstream save;//file io stream

#include"������_���ڹ���.cpp"

#include"������_��ģ��.cpp"

#include"������_��Ӧģ��.cpp"

int WINAPI WinMain(
	HINSTANCE hInstance,//���̾��
	HINSTANCE,//��Ҫ��,XP���û����
	LPSTR lpCmdline,//�����в���
	int nShowCmd//��ʾ��ʽ
)//WinAPI�������еĺ���,����int main()
{
	hInstance_WinMain=hInstance;
	FreeConsole();//������̨,��֤������(�رջ���Լ�return,����aya��¼:"�벻Ҫ����������������,�����Լ����Լ����ˡ�")
	ShowWindow(GetConsoleWindow(),SW_HIDE);//���ؿ���̨
	{//���ؿ�
		HMODULE hModule=LoadLibrary("user32.dll");//hModule��user32.dll��̬������ָ��
		if(hModule){
			SetProcessDPIAware=(SPDA)GetProcAddress(hModule,"SetProcessDPIAware");//��user32.dll���ҵ�����
			if(SetProcessDPIAware){//ȷ��ָ��ɵ���
				if(IsWin81OrLater()){//ֻ֧��Win8.1+(����Ϊ��֮ǰ��1920:1080����ʾ����?��,������,���Բ�֧��)
					SetProcessDPIAware();//Ҫ��֧�ָ�DPI������ �˻�:������Щ
				}
			}
		}
		FreeLibrary(hModule);//�ͷ��ڴ�
	}
	{//����
		if(
		MessageBox(NULL,"�������֤��������,����,��ȡ�ļ�,�ļ������д�浵���û���������Ĵ浵����Ҫ�Ŀ�,�������������bug,���Է�����\n���߲�������ļ�����,�ȶ���,��ȫ������֤,������ѧϰʹ��,���߲�����ɵ��κκ��(�����������ڱ���ʦץ��,��ͬѧ���������ƶ��洢��)�⳥�͵�Ǹ!\n������յ�����������,���˸Ų�����!\n�Ƿ�ͬ�⣿","����",MB_YESNO|MB_ICONWARNING)//������������
		!=IDYES){
			return 0;
		}
	}
	
	#include"������_������.cpp"//��װ�����Ա������
	
	return 0;
}
WNDCLASSEX registerwcex(const char str[]){
	WNDCLASSEX wcex_t;//�����ඨ��
	memset(&wcex_t,0,sizeof(wcex_t));//ȫ������Ϊ�ֽ�0x00 �˻�:���
	wcex_t.cbSize=sizeof(wcex_t);//�����С,��WINAPI�ܹ�ʶ��
	wcex_t.lpfnWndProc=Wndproc;//������Ϊ��ʾ
	wcex_t.hCursor=LoadCursor(NULL,IDC_ARROW);//�����ģʽ
	wcex_t.style=CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS;//������Сʱ���������bug
	wcex_t.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);//������
	wcex_t.lpszClassName=str;//����������,���Ըĵ���Ҫ����,���ú���Ҫ��
	wcex_t.hIcon=LoadIcon(NULL,IDI_APPLICATION);//���ڵ�ͼ��
	wcex_t.hIconSm=LoadIcon(NULL,IDI_APPLICATION);//ͬ��
	return wcex_t;
}
bool IsWin81OrLater(){
	OSVERSIONINFO osver;
	osver.dwOSVersionInfoSize=sizeof(OSVERSIONINFO);
	if(GetVersionEx(&osver)){
		return (osver.dwMajorVersion>6||(osver.dwMajorVersion==6&&osver.dwMinorVersion>=3));
	}
	return 0;
}