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
软件编译指令:
g++ 聊天室.cpp -o 聊天室 -std=c++20 -O2 -static-libgcc -Wall -Wextra -lws2_32
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


//一堆函数声明
void loadwinapilib();//加载库
WNDCLASSEX registerwcex(const char[]);//注册窗口类
typedef long long WINAPI(*SPDA)(VOID);//后面的函数指针类型用
SPDA SetProcessDPIAware;//函数要全局用
bool IsWin81OrLater();


//变量
HINSTANCE hInstance_WinMain;
int now_group_id;
std::fstream save;//file io stream

#include"聊天室_窗口管理.cpp"

#include"聊天室_主模块.cpp"

#include"聊天室_响应模块.cpp"

int WINAPI WinMain(
	HINSTANCE hInstance,//进程句柄
	HINSTANCE,//不要管,XP后就没用了
	LPSTR lpCmdline,//命令行参数
	int nShowCmd//显示方式
)//WinAPI最先运行的函数,类似int main()
{
	hInstance_WinMain=hInstance;
	FreeConsole();//解绑控制台,保证会隐藏(关闭会把自己return,类似aya语录:"请不要尝试吞咽赛博灯泡,例如自己把自己封了。")
	ShowWindow(GetConsoleWindow(),SW_HIDE);//隐藏控制台
	{//加载库
		HMODULE hModule=LoadLibrary("user32.dll");//hModule是user32.dll动态引入后的指针
		if(hModule){
			SetProcessDPIAware=(SPDA)GetProcAddress(hModule,"SetProcessDPIAware");//在user32.dll里找到函数
			if(SetProcessDPIAware){//确保指针可调用
				if(IsWin81OrLater()){//只支持Win8.1+(你认为那之前有1920:1080的显示器吗?有,但不多,所以不支持)
					SetProcessDPIAware();//要求支持高DPI的声明 人话:清晰亿些
				}
			}
		}
		FreeLibrary(hModule);//释放内存
	}
	{//声明
		if(
		MessageBox(NULL,"本软件保证不掺后门,病毒,窃取文件,文件仅会读写存档、用户主动导入的存档、必要的库,若有问题可能是bug,可以反馈。\n作者不对软件的兼容性,稳定性,安全性做保证,仅用于学习使用,作者不对造成的任何后果(包括但不限于被老师抓到,被同学哄抢导致移动存储损坏)赔偿和道歉!\n如果你收到了他人辱骂,本人概不负责!\n是否同意？","声明",MB_YESNO|MB_ICONWARNING)//宇宙免责声明
		!=IDYES){
			return 0;
		}
	}
	
	#include"聊天室_启动器.cpp"//分装代码以避免混乱
	
	return 0;
}
WNDCLASSEX registerwcex(const char str[]){
	WNDCLASSEX wcex_t;//窗口类定义
	memset(&wcex_t,0,sizeof(wcex_t));//全部定义为字节0x00 人话:清空
	wcex_t.cbSize=sizeof(wcex_t);//定义大小,让WINAPI能够识别
	wcex_t.lpfnWndProc=Wndproc;//窗口设为显示
	wcex_t.hCursor=LoadCursor(NULL,IDC_ARROW);//鼠标点击模式
	wcex_t.style=CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS;//调整大小时不会出逆天bug
	wcex_t.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);//背景用
	wcex_t.lpszClassName=str;//窗口类名称,可以改但不要重名,调用函数要用
	wcex_t.hIcon=LoadIcon(NULL,IDI_APPLICATION);//窗口的图标
	wcex_t.hIconSm=LoadIcon(NULL,IDI_APPLICATION);//同上
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