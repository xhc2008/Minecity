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
	system("title ���");
	system("cls");
	int choose=1;
	while(1) 
	{
		system("cls");
		color(160+15);
		cout<<"                    "<<endl; 
		color(128+14);
		cout<<"        ���        "<<endl; 
		cout<<"                    "<<endl; 
		cout<<"      ������Ϸ      "<<endl;
		cout<<"                    "<<endl; 
		cout<<"      ������Ϸ      "<<endl;
		cout<<"                    "<<endl; 
		cout<<"      �˳���Ϸ      "<<endl;
		cout<<"                    "<<endl;
		color(128+13);
		cout<<"��������������������";
		color(128+4);
		gotoxy(3,1+choose*2);
		cout<<"��";
		gotoxy(15,1+choose*2);
		cout<<"��"; 
		while(1)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"���Ƽ�����һ��\n���Ƽ�����һ��\n�ո����ȷ��\n","˵��",MB_ICONINFORMATION);
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
					cout<<"��";
					gotoxy(15,1+choose*2);
					cout<<"��"; 
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
					cout<<"��";
					gotoxy(15,1+choose*2);
					cout<<"��"; 
				}
			}
			if(GetAsyncKeyState(VK_SPACE))
			{ 
				if(choose==1)
				{
					color(15);
					system("cls");
					cout<<"������..."; 
					system("����\\������.exe /MIN");
					break;
				}
				if(choose==2) 
				{
					color(15);
					system("cls");
					cout<<"^@%[&*5^*&%<*&.#(@U,Y(*&!#|^%"<<endl<<"�����߲���д�ˣ��Լ�����ȥ...��"<<endl;
					color(10);
					cout<<"����esc������"<<endl<<"���¿ո�����ʹ���(?"; 
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
