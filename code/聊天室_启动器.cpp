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
	WNDCLASSEX wcex=registerwcex("WINDOW");//窗口类定义
	if(!RegisterClassEx(&wcex)){//注册并判断是否出错
		MessageBox(NULL,"Window Registration Failed!","Error!",MB_ICONERROR|MB_OK);
		return 0;
	}
	
	//窗口类!=窗口
	HWND_manager["聊天室"]=CreateWindow(//窗口变量与创建函数
		"WINDOW",
		"聊天室",
		
		WS_VISIBLE|
		WS_OVERLAPPED|
		WS_CAPTION|
		WS_SYSMENU|
		WS_MINIMIZEBOX,//窗口样式
		
		CW_USEDEFAULT,//x坐标
		CW_USEDEFAULT,//y坐标
		
		1000,//宽度
		720,//高度
		
		NULL,NULL,hInstance,NULL//别问
	);
	if(!HWND_manager["聊天室"]){
		MessageBox(NULL,"Failed code:can not Creation Window \"HWND_manager[\"聊天室\"]\".","Error!",MB_ICONERROR|MB_OK);
		DWORD errorCode=GetLastError();
		char errorMsg[256];
		snprintf(errorMsg,sizeof(errorMsg),"Error code:%lu",errorCode);
		MessageBox(NULL,errorMsg,"code",MB_OK);
		return 0;
	}
	
	
	//现在就要进入控件创建环节了
	
	HWND_manager["+群"]=CreateWindow(
		"BUTTON",//按钮类名
		"+群",//按钮标题
		WS_CHILD|WS_VISIBLE,/*按钮样式*/
		
		10,//X
		10,//Y
		
		50,//宽
		30,//高
		
		HWND_manager["聊天室"],//父窗口
		(HMENU)1,//信息ID
		hInstance,NULL
	);
	ShowWindow(HWND_manager["聊天室"],nShowCmd);//更改窗口显示状态
	UpdateWindow(HWND_manager["聊天室"]);//更新窗口
	HWND_manager["创建局域网内的群"]=CreateWindow(
		"BUTTON",
		"创建局域网内的群",
		WS_CHILD|WS_VISIBLE,
		
		70,
		10,
		
		170,
		30,
		
		HWND_manager["聊天室"],
		(HMENU)2,
		hInstance,NULL
	);
	ShowWindow(HWND_manager["聊天室"],nShowCmd);//更改窗口显示状态
	UpdateWindow(HWND_manager["聊天室"]);//更新窗口
	CreateWindow(
		"STATIC",
		"群号:",
		WS_CHILD|WS_VISIBLE,
		
		220,
		10,
		
		200,
		70,
		
		HWND_manager["聊天室"],
		(HMENU)2,
		hInstance,NULL
	);
	
	ShowWindow(HWND_manager["聊天室"],nShowCmd);//更改窗口显示状态
	UpdateWindow(HWND_manager["聊天室"]);//更新窗口
	MSG msg={};
	while(GetMessage(&msg,NULL,0,0)>0){//获取信息并判断是否结束或者有错误
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}//主消息循环