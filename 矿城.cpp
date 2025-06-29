#include<windows.h>
#include<bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void getpw(int len),dl(),pwc(),pwc1(),pwc2();
string pw,password;
HWND hwnd=GetConsoleWindow();
void gotoxy(int x,int y) 
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
	return 0;
} 
int main()
{
	system("title 矿城");
	system("cls");
	int choose=1;
	while(1) 
	{
		system("cls");
		color(160+15);
		cout<<"                    "<<endl; 
		color(128+14);
		cout<<"        矿城        "<<endl; 
		cout<<"                    "<<endl; 
		cout<<"      进入游戏      "<<endl;
		cout<<"                    "<<endl; 
		cout<<"      关于游戏      "<<endl;
		cout<<"                    "<<endl; 
		cout<<"      退出游戏      "<<endl;
		cout<<"                    "<<endl;
		color(128+13);
		cout<<"〓〓〓〓〓〓〓〓〓〓";
		color(128+4);
		gotoxy(3,1+choose*2);
		cout<<"→";
		gotoxy(15,1+choose*2);
		cout<<"←"; 
		while(1)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：确认\n","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_UP))
			{ 
				if(choose>1)
				{
					gotoxy(3,1+choose*2);
					cout<<"  ";
					gotoxy(15,1+choose*2);
					cout<<"  "; 
					choose--;
					gotoxy(3,1+choose*2);
					cout<<"→";
					gotoxy(15,1+choose*2);
					cout<<"←"; 
				}
			}
			if(GetAsyncKeyState(VK_DOWN))
			{ 
				if(choose<3)
				{
					gotoxy(3,1+choose*2);
					cout<<"  ";
					gotoxy(15,1+choose*2);
					cout<<"  "; 
					choose++;
					gotoxy(3,1+choose*2);
					cout<<"→";
					gotoxy(15,1+choose*2);
					cout<<"←"; 
				}
			}
			if(GetAsyncKeyState(VK_SPACE))
			{ 
				if(choose==1)
				{
					color(15);
					system("cls");
					cout<<"加载中..."; 
					system("数据\\主程序.exe /MIN");
					break;
				}
				if(choose==2) 
				{
					color(15);
					system("cls");
					cout<<"^@%[&*5^*&%<*&.#(@U,Y(*&!#|^%"<<endl<<"（作者不想写了，自己摸索去...）"<<endl;
					color(10);
					cout<<"按下esc键返回"<<endl<<"按下空格键访问官网(?"; 
					while(!GetAsyncKeyState(VK_ESCAPE))
					{
						if(GetAsyncKeyState(VK_SPACE))
						{
							system("start https://www.bilibili.com/video/BV1GJ411x7h7");
						}
					} 
					color(15);
					break;
				}
				if(choose==3)
				{
					exit(0);
				}
			}
			Sleep(300);
		}
	}
}
