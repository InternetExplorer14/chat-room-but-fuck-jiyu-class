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
#include<thread>
#include<queue>
namespace main_module{
	bool server_run;
	class message{
	public:
		std::string message;
		std::string from;
	};
	std::queue<message>thread_communication_queue;
	std::string displayed_message;
	void runservice(){
		
	}
	void runservice_group(){
		
	}
	void runservice_group(std::string group_name,std::string password="",int port=10000){
		
	}
	void group_chat_front_end_service_thread(){
		
	}
	void chat_front_end_service_thread(){
		
	}
	void run_group_chat_front_end_service(std::string group_name,std::string password,int port){
		/*
		MessageBox(HWND_manager["聊天室"],"还没做好QwQ","连接失败",MB_OK|MB_ICONERROR);
		return;
		std::string str;
		str+=
		str+=",群的名字是"
		str+=
		if(MessageBox(HWND_manager["聊天室"],str.c_str(),"询问",MB_OKCANCEL|MB_ICONQUESTION)!=IDOK){
			return;
		}
		*/
		//std::thread thread_main_server(group_name,password,port,serverSocket);
		//thread_main_server.detach();
	}
	void run_chat_front_end_service(){
		MessageBox(HWND_manager["聊天室"],"还没做好QwQ","连接失败",MB_OK|MB_ICONERROR);
	}
	void group_chat_back_end_service_thread(){
		/*
		WSADATA wsaData;
		if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0){
			MessageBox(HWND_manager["聊天室"],"启动Winsock失败,请尝试重启软件,不行请反馈bug!","error",MB_OK|MB_ICONERROR);
			return;
		}
		SOCKET serverSocket=socket(AF_INET,SOCK_STREAM,0);
		if(serverSocket==INVALID_SOCKET){
			MessageBox(HWND_manager["聊天室"],"创建Winsock失败,请尝试重启软件,不行请反馈bug!","error",MB_OK|MB_ICONERROR);
			WSACleanup();
			return;
		}
		sockaddr_in serverAddr;
		serverAddr.sin_family=AF_INET;
		serverAddr.sin_port=htons(port);
		serverAddr.sin_addr.s_addr=INADDR_ANY;
		if(bind(serverSocket,(sockaddr*)&serverAddr,sizeof(serverAddr))==SOCKET_ERROR){
			MessageBox(HWND_manager["聊天室"],"端口绑定失败,请尝试重启软件,不行请反馈bug!","error",MB_OK|MB_ICONERROR);
			closesocket(serverSocket);
			WSACleanup();
			return;
		}
		*/
	}
	void chat_back_end_service_thread(){
		
	}
	void run_group_chat_back_end_service(std::string group_name,std::string password="",int port=10000){
		if(MessageBox(HWND_manager["聊天室"],"你确定要创建吗?请您保证此盘的东西不会在重启后丢失,且不会删除目录下的\"saves.txt\"!","重大警告",MB_YESNO|MB_ICONWARNING)!=IDYES){
			return;
		}
		if(MessageBox(HWND_manager["聊天室"],"再次询问一次,你确认要创建吗?您应尽群主的责任!","重大警告",MB_YESNO|MB_ICONWARNING)!=IDYES){
			return;
		}
		
		MessageBox(HWND_manager["聊天室"],"还没做好QwQ","创建失败",MB_OK|MB_ICONERROR);
		return;
		
	}
	void run_chat_back_end_service(){
		MessageBox(HWND_manager["聊天室"],"还没做好QwQ","创建失败",MB_OK|MB_ICONERROR);
	}
	void group_main_server_thread(){//群聊的服务器后端
		
	}
}