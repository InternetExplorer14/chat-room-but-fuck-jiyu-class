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
	WNDCLASSEX wcex=registerwcex("WINDOW");//�����ඨ��
	if(!RegisterClassEx(&wcex)){//ע�Ტ�ж��Ƿ����
		MessageBox(NULL,"Window Registration Failed!","Error!",MB_ICONERROR|MB_OK);
		return 0;
	}
	
	//������!=����
	HWND_manager["������"]=CreateWindow(//���ڱ����봴������
		"WINDOW",
		"������",
		
		WS_VISIBLE|
		WS_OVERLAPPED|
		WS_CAPTION|
		WS_SYSMENU|
		WS_MINIMIZEBOX,//������ʽ
		
		CW_USEDEFAULT,//x����
		CW_USEDEFAULT,//y����
		
		1000,//���
		720,//�߶�
		
		NULL,NULL,hInstance,NULL//����
	);
	if(!HWND_manager["������"]){
		MessageBox(NULL,"Failed code:can not Creation Window \"HWND_manager[\"������\"]\".","Error!",MB_ICONERROR|MB_OK);
		DWORD errorCode=GetLastError();
		char errorMsg[256];
		snprintf(errorMsg,sizeof(errorMsg),"Error code:%lu",errorCode);
		MessageBox(NULL,errorMsg,"code",MB_OK);
		return 0;
	}
	
	
	//���ھ�Ҫ����ؼ�����������
	
	HWND_manager["+Ⱥ"]=CreateWindow(
		"BUTTON",//��ť����
		"+Ⱥ",//��ť����
		WS_CHILD|WS_VISIBLE,/*��ť��ʽ*/
		
		10,//X
		10,//Y
		
		50,//��
		30,//��
		
		HWND_manager["������"],//������
		(HMENU)1,//��ϢID
		hInstance,NULL
	);
	ShowWindow(HWND_manager["������"],nShowCmd);//���Ĵ�����ʾ״̬
	UpdateWindow(HWND_manager["������"]);//���´���
	HWND_manager["�����������ڵ�Ⱥ"]=CreateWindow(
		"BUTTON",
		"�����������ڵ�Ⱥ",
		WS_CHILD|WS_VISIBLE,
		
		70,
		10,
		
		170,
		30,
		
		HWND_manager["������"],
		(HMENU)2,
		hInstance,NULL
	);
	ShowWindow(HWND_manager["������"],nShowCmd);//���Ĵ�����ʾ״̬
	UpdateWindow(HWND_manager["������"]);//���´���
	CreateWindow(
		"STATIC",
		"Ⱥ��:",
		WS_CHILD|WS_VISIBLE,
		
		220,
		10,
		
		200,
		70,
		
		HWND_manager["������"],
		(HMENU)2,
		hInstance,NULL
	);
	
	ShowWindow(HWND_manager["������"],nShowCmd);//���Ĵ�����ʾ״̬
	UpdateWindow(HWND_manager["������"]);//���´���
	MSG msg={};
	while(GetMessage(&msg,NULL,0,0)>0){//��ȡ��Ϣ���ж��Ƿ���������д���
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}//����Ϣѭ��