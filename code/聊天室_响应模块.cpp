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
LRESULT CALLBACK Wndproc(
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam
)//检测窗口事件的函数
{
	switch(Msg){//检测是什么事件
		case WM_DESTROY:{//如果是退出
			PostQuitMessage(0);//停止窗口
			return 0;
		}
		case WM_COMMAND:{
	  		switch(LOWORD(wParam)){
	  			case 1:{//这里的1就是刚刚的信息ID from 聊天室_启动器.cpp
					main_module::runservice_group();
					break;
				}
				case 2:{//from 聊天室_启动器.cpp
					//main_module::run_group_chat_back_end_service(/*group_name,password,port*/);
					break;
				}
				default:{
					MessageBox(hWnd,"程序崩溃,请不要删除saves.txt,向作者反馈错误码:ERROR_NOT_FIND_THIS_COMMAND_CODE_FUNCTION\ntips:你可以截图","error",MB_OK|MB_ICONERROR);
					PostQuitMessage(0);
				}
			}
		}
		default:{
			return DefWindowProc(hWnd,Msg,wParam,lParam);
		}
	}
}