#include<windows.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
using namespace std;
const string jdata="      ■      ▄‖→◢█〓Φ¤※◣◤◥↘↓↙←↖↑↗        ",gdata="　▁▂▃▄▅▆▇██",hd_1data="△○◇□☆▲●◆■★",hd_2data="▲●◆■★",jndata="无  锋利加血荆棘闪避保护愤怒无畏轻装终结减速"; 
const int spcolor[12]={128,240,160,176,208,224,224},cjgoal[12]={0,2000,1000,2000,2000,100,1,100,100,100,1};
const int jcolor[31]={0,102,136,113,0,170,0,6,6,6,6,240,6,4,14,15,6,6,6,6,6,6,6,6,6,6,112,176,64,16},daycolor[6]={0,176,96,0,464},gcost[4]={0,500,1000,1500},cost[17]={0,8,1,10,1,1,8,6,5,5,5,8,6,8,8,8},yscolor[3]={4,8,10};
int ccolor=9,turn,clstime=20,hd_2a[10][10],hd_2color[5]={8,10,9,13,14},alb,ys[4]={0},useys;
int amap[1300][1300],day=1,lv=0,exp1=0,times=1,lastday=0,nowday=0,lastmon=0,nowmon=0,lastyear=0,nowyear=0;
int hometype=1,home_1[7][9],home_2[7][16],home_3[7][9],gc[6];
bool first=1,flag,hd_1flag[11][11],cdflag=1,ro=0,first1,od=true,books[66];
int jmap[37][22][8],fightmap[100],grow[5],plant[5],bmap[30][30][100],hd_1a[11][11],hd_3rgb[4],nowrgb[4];
int wx=0,wy=0,jx,jy,mapsize=1024,choose=1,new1=1,coin=0,gao=1,dhq=0,star=0;
int gaon=2000,deng=1,dengn=3000,size=3,tnt=0,dhp,hp,blv=1,hlv=1,alv=1,dlv=1,attack=0,defense=0,sj=0,fightcase=1,jnc=0;
int ld=0,lir=0,lr=0,lb=0,lc=0,lgo=0,lgr=0,lp=0,kuya=1,jj[17],sp[68],cjf[12],mx,my;
int color(int c),fx,c=0,go=0,gr=0,p=0,d=0,ir=0,s=0,r=0,b=0,score=0,fun=0,x2=0,y2=0,co=1,cor1=2,cor2=1,cor3=1;
int tx_x,tx_y,box1=0,box2=0,hunger=0,thirst=0,health=0,t_h=0,t_m=0,box01=0,box02=0,tx_map[110][110],tx_new=1,tx_type=1; 
char chome_1[7][18],chome_2[7][32],chome_3[7][18];
string edition="1.6.4.0";
void shjout1(),csm(),cj(),zd(),last_fight(),cjmenu(int casee);
void dhshop(),dhmenu(int casee),hd_4(),cangmenu(int casee),shj(),shjbx(),shjout(),finish();
void save(),error(),home4(),make(),hd(),hd_1(),hdmenu(),hd_1js(int ok),hd_2(),hd_3(),hd_3js(),ysmenu(),ysc(),yslz(int casee),yscmenu(int casee),cd();
void kmenu(),kmenu2(),kmenu4(),kmenu5(),sett(),outk(),gotoxy(int x,int y),jout(),din(),fight(),qh(),bx(),qhmenu(),qhmenu2(),fightmove(),gardenmenu();
void home2(),home3(),jmapout(),outmap(),move(),mapin(),ac(),menu(),aexit(),home(),jshop(),jshopmenu(),jshopmenu2(),jn(),ysdh(int di),ysdh2(int di);
void tanx(),zb(),book(),tx_make(),tx_move(),tx_mapout(int see),nhome1(),nhome2(),nhome3(),kmenu6(),anticheat();
void cang(),shop(),shopmenu(),shopmenu2(),jhome(),fhp(),fightmove2(),fhp2(),check(),check2(),jnmenu(),jnchoose(),garden(),gchoose(int cd),gshop(int casee);
void lfmove(),fhp3(),fhp4(),check3(),check4(),del(),gcls(int casee),outputcheck(int type),pieces(int type);
char cor();
HWND hwnd=GetConsoleWindow();
HMENU hmenu=GetSystemMenu(hwnd,false);
bool Ctrlhandler(DWORD fdwctrltype)
{
	switch(fdwctrltype)
	{
		case CTRL_CLOSE_EVENT:
			if(!first) aexit();
			return false;
	}
}
char cor()
{
	if(cor2==1)	return ' ';
	else return 0;
}
void del()
{
	for(int i=0;i<50;i++)
	{
		GetAsyncKeyState(VK_LEFT);
		GetAsyncKeyState(VK_RIGHT);
		GetAsyncKeyState(VK_DOWN);
		GetAsyncKeyState(VK_UP);
		GetAsyncKeyState(VK_ESCAPE);
		GetAsyncKeyState(VK_RETURN);
		GetAsyncKeyState(VK_SHIFT);
		GetAsyncKeyState(VK_TAB);
		GetAsyncKeyState(VK_DELETE);
	}
}
void rgb_init() 
{																
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);	
	GetConsoleMode(hOut, &dwOutMode);					
	dwInMode |= 0x0200;
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);
	SetConsoleMode(hOut, dwOutMode);
}
void rgb_set(int br,int bg,int bb) 
{
	printf("\033[48;2;%d;%d;%dm",br,bg,bb);
}
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
void mapin()
{
	int temp=0; 
	SetFileAttributes("数据\\a6.dll",FILE_ATTRIBUTE_NORMAL);
	freopen("数据\\a6.dll","r",stdin);
	for(int i=0;i<=mapsize;i++)
	{
		for(int j=0;j<=mapsize;j++)
		{
			cin>>amap[j][i];
		}
		temp++;
		if(temp==102)
		{
			temp=0;
			gotoxy(int(i/(mapsize/10)),1);
			cout<<"#";
		}
	}
	fclose(stdin); 
	SetFileAttributes("数据\\a6.dll",FILE_ATTRIBUTE_READONLY);
	SetFileAttributes("数据\\a6.dll",FILE_ATTRIBUTE_HIDDEN);
	//Sleep(100);
}
void gardenmenu(int casee)
{
	gotoxy(0,0);
	for(int i=0;i<4;i++)
	{
		if(casee==i+1)
		{
			color(4);
		}
		else
		{
			color(7);
		}
		cout<<i+1<<".";
		color(98);
		for(int j=0;j<2;j++)
		{
			cout<<gdata[grow[i]/100*2]<<gdata[grow[i]/100*2+1];
			if(grow[i]>=100)
			{
				cout<<" ";
			}
		}
		color(7);
		cout<<"种植:";
		if(plant[i]==0)
		{
			color(7);
			cout<<"无      "; 
		}
		else if(plant[i]==1)
		{
			color(6);
			cout<<"普通种子"; 
		}
		else if(plant[i]==2)
		{
			color(11);
			cout<<"高级种子"; 
		}
		else if(plant[i]==3)
		{
			color(14);
			cout<<"特级种子"; 
		}
		cout<<endl<<"  ";
		color(98);
		for(int j=0;j<2;j++)
		{
			cout<<gdata[grow[i]/100*2]<<gdata[grow[i]/100*2+1];
			if(grow[i]>=100)
			{
				cout<<cor();
			}
		}
		color(7);
		cout<<"生长:"<<grow[i]<<"/800    "<<endl<<endl;
	}
}
void gcls(int casee)
{
	int temp2=clock();
	while(clock()-temp2<=200)
	{
		for(int i=0;i<4;i++) 
		{
			if(plant[i]!=0&&grow[i]!=800&&rand()%3==0)
			{
				grow[i]=int((clock()-gc[i])/1000);
				//gardenmenu(casee);
			}
			if(grow[i]>800)
			{
				grow[i]=800;
			}
		}
		gardenmenu(casee);		
	}	
}
void garden()
{
	system("cls");
	int casee=1,blocks,temp;
	for(int i=0;i<4;i++) 
	{
		if(grow[i]!=0&&grow[i]!=800)
		{
			grow[i]=int((clock()-gc[i])/1000);
		}
		if(grow[i]>800)
		{
			grow[i]=800;
		}
	}
	gardenmenu(1);
	Sleep(200);
	while(1)
	{
		for(int i=0;i<4;i++) 
		{
			if(plant[i]!=0&&grow[i]!=800&&rand()%3==0)
			{
				grow[i]=int((clock()-gc[i])/1000);
				gardenmenu(casee);
			}
			if(grow[i]>800)
			{
				grow[i]=800;
			}
		}
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：种植/浇水/收获\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_UP)&&casee>1)
		{
			casee--;
			gcls(casee);
		}
		if(GetAsyncKeyState(VK_DOWN)&&casee<4)
		{
			casee++;
			gcls(casee);	
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(plant[casee-1]==0)
			{
				gchoose(casee);
				gardenmenu(casee);
			}
			else if(grow[casee-1]==800)
			{
				if(plant[casee-1]==1)
				{
					blocks=20;
				}
				else if(plant[casee-1]==2)
				{
					blocks=50;
				}
				else if(plant[casee-1]==3)
				{
					blocks=80;
				}
				cjf[4]+=blocks; 
				system("cls");
				color(15);
				cout<<"收获："<<endl;
				plant[casee-1]=0;
				grow[casee-1]=0;
				for(int i=1;i<=blocks;i++)
				{
					temp=rand()%15+1;
					if(temp==4)
					{	
						rgb_set(100,60,0);
					}
					else if(temp==6)
					{
						rgb_set(225,120,0);
					}
					else
					{
						color(jcolor[temp]);
					}
					cout<<jdata[temp*2]<<jdata[temp*2+1]<<cor();
					if(temp==11||temp==7)
					{
						cout<<" ";
					}
					jj[temp]++;
					if(i%10==0)
					{
						cout<<endl;
					}
					Sleep(50);
				}
				while(1)
				{
					if(GetAsyncKeyState(VK_ESCAPE))
					{
						color(0);
						system("cls");
						break;
					}
					if(GetAsyncKeyState(VK_CONTROL))
					{ 
						::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
					}
				}
				gardenmenu(casee);
			}
			gcls(casee);
		}
	}
	if(hometype==1)
	{
		nhome2();
	}
	else
	{
		home2();
	}
}
void gshop(int casee)
{
	gotoxy(0,0);
	color(14);
	cout<<"●"<<cor()<<coin<<"    "<<endl;
	if(casee==1)
	{
		color(4);
	}
	else
	{
		color(15);
	}
	cout<<"1.";
	color(6);
	cout<<"普通种子"<<endl;
	color(14);
	cout<<"  ●500"<<endl;
	if(casee==2)
	{
		color(4);
	}
	else
	{
		color(15);
	}
	cout<<"2.";
	color(11);
	cout<<"高级种子"<<endl;
	color(14);
	cout<<"  ●1000"<<endl;
	if(casee==3)
	{
		color(4);
	}
	else
	{
		color(15);
	}
	cout<<"3.";
	color(14);
	cout<<"特级种子"<<endl;
	color(14);
	cout<<"  ●1500"<<endl;
}
void gchoose(int cd) 
{
	system("cls");
	int casee=1;
	gshop(casee);
	Sleep(500);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：种植\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_UP)&&casee>1)
		{
			casee--;
			gshop(casee);
			Sleep(500);
		}
		if(GetAsyncKeyState(VK_DOWN)&&casee<3)
		{
			casee++;
			gshop(casee);
			Sleep(500);
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			plant[cd-1]=casee;
			gc[cd-1]=clock();
			if(gcost[casee]<=coin)
			{
				coin-=gcost[casee];
				break;
			}
		}
	}
	color(0);
	system("cls");
}
void shj()
{
	if(sp[1]==-1)
	{
		csm();
	}
	else
	{
		shjbx();
	}
}
void shjout1()
{
	color(11);
	cout<<"碎片收集"<<endl;
	for(int i=0;i<8;i++)
	{
		for(int j=1;j<=8;j++)
		{
			color(spcolor[sp[i*8+j]]);
			if(i*8+j<10)
			{
				cout<<"0";
			}
			cout<<i*8+j;
			color(0);
			cout<<"  ";
		}
		color(0);
		cout<<endl<<endl;
	}
}
void shjout()
{
	system("cls");
	shjout1();
	for(;;) 
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"左移键：宝箱\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			shjbx();
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(hometype==1)
			{
				nhome3();
			}
			else
			{
				home3();
			}
		}
	}
}
void finish()
{
	for(int i=0;i<8;i++)
	{
		for(int j=1;j<=8;j++)
		{
			if(sp[i*8+j]!=5)
			{
				return;
			}
		}
	}
	system("cls");
	shjout1();
	Sleep(1000);
	system("color 7e");
	system("cls");
	Sleep(200);
	system("color fe");
	Sleep(1500);
	system("color 7e");
	Sleep(200);
	system("color 0f");
	sp[1]=-1;
	csm();
}
void csm()
{
	system("cls");
	color(13);
	cout<<"敌人等级：MAX"<<endl;
	color(15);
	cout<<"攻击伤害："<<alv<<endl;
	cout<<"暴击几率："<<alv/10*9+9<<"%"<<endl;
	cout<<"防御减伤："<<dlv<<"%"<<endl;
	cout<<"血量上限："<<dlv/10*50+50<<endl;
	cout<<"使用技能：";
	for(int j=0;j<4;j++)
	{
		cout<<jndata[jnc*4+j];
	}
	cout<<endl;
	fightcase=1;
	cout<<"使用药水：无";
	useys=0;
	cout<<endl;
	color(13);
	cout<<"战斗模式：";
	color(14);
	cout<<"最终之战"<<endl; 
	color(5);
	cout<<"◆"<<cor();
	if(sj>=8)
	{
		color(10);
		flag=1;
	}
	else
	{
		color(4);
		flag=0;
	}
	cout<<sj<<"/8"<<endl;
	cout<<" 开始战斗 "<<endl;
	color(14);
	cout<<"另：不建议使用淡黄色角色，这与背景颜色一致";
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"空格键：开始战斗\ntab键：药水切换\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(blv!=0||hlv!=0)
			{
				::MessageBox(0,"需要完成所有『箭头记忆』和『方向反应』的战斗","",0);
				continue; 
			}
			if(useys==0)
			{
				if(flag)
				{
					break;
				}
			}
			else
			{
				if(ys[useys-1]>0)
				{
					if(flag)
					{
						ys[useys-1]--;
						break;
					}
				}
				else
				{
					::MessageBox(hwnd,"没有相应的药水","",0);
				}
			}		
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			color(0);
			if(hometype==1)
			{
				nhome3();
			}
			else
			{
				home3();
			}
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			color(15);
			gotoxy(8,6);
			if(useys==0)
			{
				useys++;
				cout<<"：力量药水"; 	
			}
			else if(useys==1)
			{
				useys++;
				cout<<"：防御药水"; 
			}
			else if(useys==2)
			{
				useys++;
				cout<<"：敏捷药水"; 
			}
			else if(useys==3)
			{
				useys=0;
				cout<<"：无        "; 	
			}
			Sleep(300);
		}
	}
	gotoxy(0,0);
	color(13);
	sj-=8;
	last_fight();
}
void lfmove()
{
	int size=0,wrong=0;
	gotoxy(0,7);
	color(14);
	cout<<"战斗开始！            ";
	while(1)
	{
		Sleep(1000);
		color(15);
		size=wrong=0;
		gotoxy(0,7);
		cout<<"                  "<<endl; 
		gotoxy(0,8);
		cout<<"                  "<<endl; 
		gotoxy(0,9);
		if(jnc==10) 
		{
			color(11);
		}
		else
		{
			color(13);
		}
		for(int i=0;i<7;i++)
		{
			pieces(8);
		}
		cout<<endl;
		Sleep(500);
		color(14);
		gotoxy(0,7);
		cout<<"？？？？？？？         "<<endl; 
		gotoxy(0,8);
		cout<<"？？？？？？？         "<<endl; 
		Sleep(500);
		for(int i=0;i<14;i++)
		{
			if(i<=6) gotoxy(i*2,7);
			else gotoxy((i-7)*2,8);
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"这个就不用我说了吧","说明",MB_ICONINFORMATION);
			}
			int a=rand()%4;
			if(a==0)
			{
				fightmap[i]=0;
				cout<<"↑"<<cor();
			}
			else if(a==1)
			{
				fightmap[i]=1;
				cout<<"↓"<<cor();
			}
			else if(a==2)
			{
				fightmap[i]=2;
				cout<<"←"<<cor();
			}
			else if(a==3)
			{
				fightmap[i]=3;
				cout<<"→"<<cor();
			}
		}
		if(jnc==10) 
		{
			color(11);
		}
		else
		{
			color(13);
		}
		for(int timee=55;timee!=0;timee--)
		{
			gotoxy(timee/8*2,9); 
			int temp=timee%8;
//			if(temp==7) cout<<"▉";
//			else if(temp==6) cout<<"▊";
//			else if(temp==5) cout<<"▋";
//			else if(temp==4) cout<<"▌";
//			else if(temp==3) cout<<"▍";
//			else if(temp==2) cout<<"▎";
//			else if(temp==1) cout<<"▏";
//			else if(temp==0) cout<<"  ";
			pieces(temp);
			if(jnc==10) 
			{
				Sleep(150);
			}
			else
			{
				Sleep(100);
			}
		}
		gotoxy(0,9);
		cout<<"                       "<<endl; 
		color(14);
		gotoxy(0,7);
		cout<<"？？？？？？？         "<<endl; 
		gotoxy(0,8);
		cout<<"？？？？？？？         "<<endl; 
		gotoxy(0,7);
		for(int i=0;i<20;i++)
		{
			GetAsyncKeyState(VK_LEFT);
			GetAsyncKeyState(VK_RIGHT);
			GetAsyncKeyState(VK_DOWN);
			GetAsyncKeyState(VK_UP);
			GetAsyncKeyState(VK_ESCAPE);
		}
		for(;size<14;)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"这个就不用我说了吧","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_ESCAPE))
			{ 
				if(::MessageBox(0,"中途退出即战斗失败","确定退出吗？",1)==1)
				{
					hp=0;
					check();
				}
			}
			Sleep(500);
			if(GetAsyncKeyState(VK_UP))
			{
				if(fightmap[size]==0)
				{
					color(10);
				}
				else
				{
					color(4);
					wrong++;
				}
				cout<<"↑"<<cor();
				size++;
				if(size==7) cout<<endl;
			}
			if(GetAsyncKeyState(VK_DOWN))
			{
				if(fightmap[size]==1)
				{
					color(10);
				}
				else
				{
					color(4);
					wrong++;
				}
				cout<<"↓"<<cor();
				size++;
				if(size==7) cout<<endl;
			}
			if(GetAsyncKeyState(VK_LEFT))
			{
				if(fightmap[size]==2)
				{
					color(10);
				}
				else
				{
					color(4);
					wrong++;
				}
				cout<<"←"<<cor();
				size++;
				if(size==7) cout<<endl;
			}
			if(GetAsyncKeyState(VK_RIGHT))
			{
				if(fightmap[size]==3)
				{
					color(10);
				}
				else
				{
					color(4);
					wrong++;
				}
				cout<<"→"<<cor();
				size++;
				if(size==7) cout<<endl;
			}
		}
		Sleep(500);
		bool flag=0;
		double hurt=(14-wrong)*alv,dd=wrong*500*(1.0-dlv*0.01);
		if(rand()%100<alv/10*9+9)
		{
			hurt*=2;
			flag=1;
		}
		if(useys==1)
		{
			hurt*=1.2;
		}
		else if(useys==2)
		{
			dd*=0.7;
		}
		else if(useys==3)
		{
			if(rand()%10==0)
			{
				dd=0;
			}
		}
		if(jnc==1)
		{
			hurt*=1.2;
		}
		else if(jnc==3)
		{
			hurt+=dd*0.2;
		}
		else if(jnc==4)
		{
			if(rand()%10==0)
			{
				dd=0;
			}
		}
		else if(jnc==5)
		{
			dd*=0.7;
		}
		else if(jnc==6)
		{
			hurt*=0.9+(1.0-double(hp)/double(dlv/10*50+50))/1.5;
		}
		else if(jnc==7)
		{
			hurt*=2.2;
			dd*=2;
		}
		else if(jnc==8)
		{
			dd*=2;
			if(rand()%10<6)
			{
				dd=0;
			}
		}
		else if(jnc==9)
		{
			if(dhp<5000||hurt>=dhp)
			{
				hurt=INT_MAX;
			}
		}
		hp-=dd;
		dhp-=hurt;
		color(6);
		gotoxy(27,0);
		if(flag)
		{
			color(4);
		}
		cout<<"-"<<int(hurt);
		gotoxy(27,6);
		color(13);
		cout<<"-"<<int(dd);
		Sleep(1000); 
		fhp3();
		for(;!GetAsyncKeyState(VK_SPACE);)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"空格键：下一回合","说明",MB_ICONINFORMATION);
			}
		}
	}	
}
void last_fight()
{
	system("cls");
	for(int i=0;i<6;i++)
	{
		color(240);
		gotoxy(0,7-i-1);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(0,7-i-1);
		cout<<"  ";
	}
	for(int i=0;i<6;i++)
	{
		color(240);
		gotoxy(i*2,0);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(i*2,0);
		cout<<"  ";
	}
	for(int i=0;i<6;i++)
	{
		color(240);
		gotoxy(12,i);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(12,i);
		cout<<"  ";
	}
	for(int i=0;i<6;i++)
	{
		color(240);
		gotoxy((7-i-1)*2,6);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy((7-i-1)*2,6);
		cout<<"  ";
	}
	
	for(int i=1;i<5;i++)
	{
		color(240);
		gotoxy(2,7-i-1);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(2,7-i-1);
		cout<<"  ";
	}
	for(int i=1;i<5;i++)
	{
		color(240);
		gotoxy(i*2,1);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(i*2,1);
		cout<<"  ";
	}
	for(int i=1;i<5;i++)
	{
		color(240);
		gotoxy(10,i);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(10,i);
		cout<<"  ";
	}
	for(int i=1;i<5;i++)
	{
		color(240);
		gotoxy((7-i-1)*2,5);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy((7-i-1)*2,5);
		cout<<"  ";
	}
	
	for(int i=2;i<4;i++)
	{
		color(240);
		gotoxy(4,7-i-1);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(4,7-i-1);
		cout<<"  ";
	}
	for(int i=2;i<4;i++)
	{
		color(240);
		gotoxy(i*2,2);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(i*2,2);
		cout<<"  ";
	}
	for(int i=2;i<4;i++)
	{
		color(240);
		gotoxy(8,i);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy(8,i);
		cout<<"  ";
	}
	for(int i=2;i<4;i++)
	{
		color(240);
		gotoxy((7-i-1)*2,4);
		cout<<"  ";
		Sleep(60);
		color(224);
		gotoxy((7-i-1)*2,4);
		cout<<"  ";
	}
	color(240);
	gotoxy(6,3);
	cout<<"  ";
	Sleep(100);
	color(224);
	gotoxy(6,3);
	cout<<"  ";
	Sleep(1000);
	for(int j=1;j<5;j++)
	{
		for(int i=0;i<j;i++)
		{
			gotoxy(6,0);
			color(208);
			cout<<"  ";
			Sleep(500-j*100);
			gotoxy(6,0);
			color(224);
			cout<<"  ";
			Sleep(500-j*100);
		}
	}
	gotoxy(6,0);
	color(237);
	cout<<"●"<<cor();
	Sleep(1000);
	gotoxy(6,6);
	color(237);
	cout<<"◆"<<cor();
	Sleep(1000);
	gotoxy(6,6);
	color(224+ccolor);
	cout<<"●"<<cor();
	for(int i=0;i<100;i++)
	{
		GetAsyncKeyState(VK_LEFT);
		GetAsyncKeyState(VK_RIGHT);
		GetAsyncKeyState(VK_DOWN);
		GetAsyncKeyState(VK_UP);
		GetAsyncKeyState(VK_ESCAPE);
		GetAsyncKeyState(VK_SPACE);
	}
	Sleep(1000);
	gotoxy(0,7);
	color(13);
	for(int i=0;i<=30000;i+=10) 
	{
		gotoxy(14,0);
		cout<<i<<"/30000";
	}
	for(int i=0;i<5;i++)
	{
		gotoxy(14,0);
		cout<<"               ";
		Sleep(150);
		gotoxy(14,0);
		cout<<"30000/30000";
		Sleep(150);
	}
	hp=dlv/10*50+50;
	Sleep(1000);
	dhp=30000;
	if(jnc==2)
	{
		hp*=1.2;
	}
	color(10);
	gotoxy(14,6);
	cout<<hp<<"/"<<dlv/10*50+50<<"              "<<endl;
	Sleep(1000);
	color(14);
	cout<<"按下空格键开始战斗";
	while(!GetAsyncKeyState(VK_SPACE)) 
	{
		if(GetAsyncKeyState(VK_ESCAPE)) 
		{
			if(::MessageBox(0,"你确定要逃跑吗？","退出战斗",1)==1)
			{
				if(hometype==1)
				{
					nhome3();
				}
				else
				{
					home3();
				}
			} 
		}
	}
	lfmove();
}
void shjbx()
{
	system("cls");
	color(14);
	gotoxy(0,0);
	cout<<"★ "<<star<<"    ";
	gotoxy(0,1);
	color(110);
	cout<<"          "<<endl; 
	cout<<"－－■"<<cor()<<"－－"<<endl; 
	color(103);
	cout<<"  ★"<<cor()<<"★"<<cor()<<"★"<<cor()<<"  "<<endl; 
	color(96);
	cout<<"          "<<endl; 
	if(star>=3) 
	{
		color(10);
	}
	else
	{
		color(8);
	}
	cout<<"   开启";
	int temp;
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"空格键：开启\n右移键：碎片\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(hometype==1)
			{
				nhome3();
			}
			else
			{
				home3();
			}
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			shjout();
		}	
		if(GetAsyncKeyState(VK_SPACE)&&star>=3)
		{
			for(int i=0;i<3;i++)
			{
				gotoxy(2+i*2,3);
				color(111);
				cout<<"★"<<cor();
				Sleep(500);
				star--;
				gotoxy(0,0);
				color(14);
				cout<<"★"<<cor()<<" "<<star<<"    ";
				Sleep(500);
				gotoxy(2+i*2,3);
				color(110);
				cout<<"★"<<cor();
				Sleep(500);
			}
			Sleep(500);
			color(110);
			gotoxy(4,2);
			cout<<"◆"<<cor();
			Sleep(500);
			gotoxy(0,1);
			cout<<"－－◆"<<cor()<<"－－"<<endl;
			color(6);
			cout<<"|        |"<<endl; 
			color(110);
			cout<<"  ★"<<cor()<<"★"<<cor()<<"★"<<cor()<<"  "<<endl; 
			color(96);
			cout<<"          "<<endl; 
			Sleep(1000);
			color(14);
			system("cls");
			for(int i=7;i>=0;i--)
			{
				color(14);
				gotoxy(0,0);
				cout<<"剩余:"<<i<<endl; 
				for(int j=0;j<10;j++)
				{
					temp=rand()%64+1;
					if(sp[temp]!=5)
					{
						break;
					}
				}
				color(spcolor[sp[temp]+1]);
				if(temp<10)
				{
					cout<<"0";
				}
				cout<<temp;
				color(14);
				if(sp[temp]==5)
				{
					cout<<endl<<"已经拥有相同碎片     "<<endl;
					cout<<"转换为●"<<cor()<<"500 ";
					coin+=500; 
				}
				else
				{
					cout<<endl<<temp<<"号碎片("<<sp[temp]+1<<"级)       "<<endl;
					cout<<"            ";
					sp[temp]++;
				}
				Sleep(1000);
				while(!GetAsyncKeyState(VK_SPACE))
				{
					if(GetAsyncKeyState(VK_CONTROL))
					{ 
						::MessageBox(hwnd,"空格键：下一个","说明",MB_ICONINFORMATION);
					}
				}
			}
			finish();
			shjbx();
		}
	}
}
void bx()
{
	system("cls");
	color(14);
	gotoxy(0,0);
	cout<<"● "<<cor()<<coin<<"    ";
	gotoxy(0,1);
	color(96);
	cout<<"          "<<endl; 
	cout<<"－－"; 
	color(110);
	cout<<"◆"<<cor();
	color(96);
	cout<<"－－"<<endl; 
	cout<<"          "<<endl; 
	cout<<"          "<<endl;  
	color(4);
	cout<<" 普通宝箱"<<endl; 
	color(14);
	if(box1>0)
	{
		cout<<" 拥有："<<box1<<" ";
	}
	else
	{
		cout<<"  ●"<<cor()<<"200  ";
	}
	gotoxy(12,1);
	color(176);
	cout<<"          "<<endl; 
	gotoxy(12,2);
	cout<<"－－"; 
	color(190);
	cout<<"◆"<<cor();
	color(176);
	cout<<"－－"<<endl; 
	gotoxy(12,3);
	cout<<"          "<<endl; 
	gotoxy(12,4);
	cout<<"          "<<endl;  
	color(15);
	gotoxy(12,5);
	cout<<" 高级宝箱"<<endl; 
	color(14);
	gotoxy(12,6);
	if(box2>0)
	{
		cout<<" 拥有："<<box2<<" ";
	}
	else
	{
		cout<<"  ●"<<cor()<<"500  ";
	}
	int casee=1;
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"左移键：普通宝箱\n右移键：高级宝箱\n空格键：打开\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			casee=1;
			gotoxy(0,5);
			color(4);
			cout<<" 普通宝箱"<<endl; 
			gotoxy(12,5);
			color(15);
			cout<<" 高级宝箱"<<endl; 
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			casee=2;
			gotoxy(0,5);
			color(15);
			cout<<" 普通宝箱"<<endl; 
			gotoxy(12,5);
			color(4);
			cout<<" 高级宝箱"<<endl; 
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			color(0);
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home3();
			}
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(casee==1)
			{
				if(coin>=200||box1>0)
				{
					if(box1>0) box1--;
					else coin-=200;
					int a=rand()%6,b;
					gotoxy(0,1);
					color(0);
					cout<<"          "<<endl; 
					if(a==0||a==1)
					{
						color(14);
						b=rand()%100+150;
						cout<<"● "<<cor()<<b<<"      ";
						coin+=b;
					}
					else if(a==2)
					{
						b=1;
						color(208);
						if(rand()%2==0)
						{
							cout<<"攻";
							color(15); 
							cout<<"  "<<b<<"       ";
							attack+=b; 
						}
						else
						{
							cout<<"防";
							color(15);
							cout<<"  "<<b<<"       ";
							defense+=b;	
						} 
					}
					else if(a==3)
					{
						color(10);
						b=rand()%21+5;
						cout<<"LV "<<b<<"%      ";
						exp1+=b;
						lv+=exp1/100;
						exp1=exp1%100;
					}
					else if(a==4)
					{
						b=1;
						color(5);
						cout<<"◆"<<cor();
						color(15);
						cout<<"  "<<b<<"       ";
						sj+=b;
					}
					else if(a==5)
					{
						b=1;
						color(235);
						cout<<"券";
						color(15);
						cout<<"  "<<b<<"       ";
						dhq+=b;
					}
					color(14);
					gotoxy(0,0);
					cout<<"● "<<cor()<<coin<<"    ";
					Sleep(1000);
					gotoxy(0,1);
					color(96);
					cout<<"          "<<endl; 
					cout<<"－－"; 
					color(110);
					cout<<"◆"<<cor();
					color(96);
					cout<<"－－"<<endl; 
					color(14);
					gotoxy(0,6);
					if(box1>0)
					{
						cout<<" 拥有："<<box1<<" ";
					}
					else
					{
						cout<<"  ●"<<cor()<<"200  ";
					}
				}
			}
			else if(casee==2)
			{
				if(coin>=500||box2>0)
				{
					if(box2>0) box2--;
					else coin-=500;
					int a=rand()%6,b;
					gotoxy(12,1);
					color(0);
					cout<<"          "<<endl; 
					gotoxy(12,2);
					if(a==0||a==4)
					{
						color(14);
						b=rand()%121+450;
						cout<<"● "<<cor()<<b<<"      ";
						coin+=b;
					}
					else if(a==1)
					{
						color(10);
						b=rand()%61+10;
						cout<<"LV "<<b<<"%      ";
						exp1+=b;
						lv+=exp1/100;
						exp1=exp1%100;
					}
					else if(a==2)
					{
						b=rand()%3+3;
						color(208);
						if(rand()%2==0)
						{
							cout<<"攻";
							color(15); 
							cout<<"  "<<b<<"       ";
							attack+=b; 
						}
						else
						{
							cout<<"防";
							color(15);
							cout<<"  "<<b<<"       ";
							defense+=b;	
						}
					}
					else if(a==3)
					{
						b=rand()%3+3;
						color(5);
						cout<<"◆"<<cor();
						color(15);
						cout<<"  "<<b<<"       ";
						sj+=b;
					}
					else if(a==5)
					{
						b=rand()%3+2;
						color(235);
						cout<<"券";
						color(15);
						cout<<"  "<<b<<"       ";
						dhq+=b;
					}
					color(14);
					gotoxy(0,0);
					cout<<"● "<<cor()<<coin<<"    ";
					Sleep(1000);
					color(176);
					gotoxy(12,1);
					cout<<"          "<<endl; 
					gotoxy(12,2);
					cout<<"－－"; 
					color(190);
					cout<<"◆"<<cor();
					color(176);
					cout<<"－－"<<endl;
					color(14);
					gotoxy(12,6);
					if(box2>0)
					{
						cout<<" 拥有："<<box2<<" ";
					}
					else
					{
						cout<<"  ●"<<cor()<<"500  ";
					}
				}
			}
		}
	}
}
void qhmenu()
{
	gotoxy(0,0);
	color(15);
	flag=1;
	cout<<"攻击 LV"<<alv<<"            "<<endl;
	cout<<"伤害："<<alv<<"             "<<endl; 
	cout<<"暴击几率："<<alv/10*9+9<<"%             "<<endl<<" "; 
	color(208);
	cout<<"攻";
	if(alv<=attack)
	{
		color(10);
	}
	else
	{
		color(4);
		flag=0;
	}
	cout<<attack<<"/"<<alv<<"          "<<endl<<" ";
	color(14);
	cout<<"●"<<cor();
	if(alv*100<=coin)
	{
		color(10);
	}
	else
	{
		color(4);
		flag=0;
	}
	cout<<coin<<"/"<<alv*100<<"         "<<endl;
	if(flag)
	{
		color(10);
	}
	else
	{
		color(4);
	}
	cout<<" 升级      "<<endl; 
}
void qhmenu2()
{
	gotoxy(0,0);
	color(15);
	flag=1;
	cout<<"防御 LV"<<dlv<<"               "<<endl;
	cout<<"减伤："<<dlv<<"%             "<<endl; 
	cout<<"血量上限："<<dlv/10*50+50<<"             "<<endl<<" ";
	color(208);
	cout<<"防";
	if(dlv<=defense)
	{
		color(10);
	}
	else
	{
		color(4);
		flag=0;
	}
	cout<<defense<<"/"<<dlv<<"        "<<endl<<" ";
	color(14);
	cout<<"●"<<cor();
	if(dlv*100<=coin)
	{
		color(10);
	}
	else
	{
		color(4);
		flag=0;
	}
	cout<<coin<<"/"<<dlv*100<<"            "<<endl;
	if(flag)
	{
		color(10);
	}
	else
	{
		color(4);
	}
	cout<<" 升级"<<endl; 
}
void qh()
{
	system("cls");
	int casee=1;
	qhmenu();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"左移键：攻击升级\n右移键：防御升级\n空格键：升级\ntab键：技能\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			system("cls");
			jn();
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			casee=1;
			qhmenu();
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			casee=2;
			qhmenu2();
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			color(0);
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home3();
			}
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(casee==1&&flag)
			{
				if(alv>=95)
				{
					::MessageBox(hwnd,"等级已到达上限！","",0);
				}
				else if(lv>alv)
				{
					coin-=alv*100;
					attack-=alv;
					alv++;
					qhmenu();
					Sleep(300);
				}
				else
				{
					::MessageBox(hwnd,"攻击等级不得超过人物等级","",0);
				}
			}
			else if(casee==2&&flag)
			{
				if(dlv>=95)
				{
					::MessageBox(hwnd,"等级已到达上限！","",0);
				}
				else if(lv>dlv)
				{
					coin-=dlv*100;
					defense-=dlv;
					dlv++;
					qhmenu2();
					Sleep(300);
				}
				else
				{
					::MessageBox(hwnd,"防御等级不得超过人物等级","等级不足",0);
				}
			}
		}
	}
}
void jnmenu()
{
	gotoxy(0,0);
	for(int i=0;i<=10;i++)
	{
		if(jnc==i)
		{
			color(4);
		} 
		else
		{
			color(15);
		}
		if(i<10)
		{
			cout<<"0";
		}
		cout<<i<<".";
		for(int j=0;j<4;j++)
		{
			cout<<jndata[i*4+j];
		}
		cout<<endl;
	} 
}
void jnchoose()
{
	system("cls");
	jnmenu();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：选择","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_UP)&&jnc>0)
		{ 
			jnc--;
			jnmenu();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_DOWN)&&jnc<10)
		{ 
			jnc++;
			jnmenu();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_SPACE))
		{ 
			Sleep(100);
			break;
		}
	}
	jn();
}
void jn()
{
	system("cls");
	color(15);
	cout<<"技能：";
	for(int j=0;j<4;j++)
	{
		cout<<jndata[jnc*4+j];
	}
	cout<<endl;
	cout<<"技能作用：";
	if(jnc==0)
	{
		cout<<"无"; 
	}
	else if(jnc==1)
	{
		cout<<"攻击力*1.2"; 
	}
	else if(jnc==2)
	{
		cout<<"初始血量*1.2"; 
	}
	else if(jnc==3)
	{
		cout<<"敌人额外受到玩家受到伤害的20%"; 
	}
	else if(jnc==4)
	{
		cout<<"10%几率闪避伤害"; 
	}
	else if(jnc==5)
	{
		cout<<"减少受到伤害的30%"; 
	}
	else if(jnc==6)
	{
		cout<<"伤害随血量减少而增加"; 
	}
	else if(jnc==7)
	{
		cout<<"攻击伤害*2.2但受到的伤害*2"; 
	}
	else if(jnc==8)
	{
		cout<<"60%几率闪避伤害但受到的伤害*2"; 
	}
	else if(jnc==9)
	{
		cout<<"敌人血量低于10%或最后一击时一击终结"; 
	}
	else if(jnc==10)
	{
		cout<<"箭头显示时间增加"; 
	}
	color(4);
	cout<<endl<<"更换技能"; 
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"esc键：退出\n空格键：更换技能\ntab键：药水","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_SPACE))
		{ 
			jnchoose();
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{ 
			break;
		}
		if(GetAsyncKeyState(VK_TAB))
		{ 
			ysmenu();
		}
	}
	if(hometype==1)
	{
		nhome2();
	}
	else
	{
		home3();
	}
}
void fight()
{
	system("cls");
	color(13);
	cout<<"敌人等级："<<blv<<endl;
	color(15);
	cout<<"攻击伤害："<<alv<<endl;
	cout<<"暴击几率："<<alv/10*9+9<<"%"<<endl;
	cout<<"防御减伤："<<dlv<<"%"<<endl;
	cout<<"血量上限："<<dlv/10*50+50<<endl;
	cout<<"使用技能：";
	for(int j=0;j<4;j++)
	{
		cout<<jndata[jnc*4+j];
	}
	cout<<endl;
	fightcase=1;
	cout<<"使用药水：无";
	useys=0;
	cout<<endl;
	color(13);
	cout<<"战斗模式：箭头记忆"<<endl; 
	color(5);
	cout<<"◆"<<cor();
	if(sj>=2)
	{
		color(10);
		flag=1;
	}
	else
	{
		color(4);
		flag=0;
	}
	cout<<sj<<"/2"<<endl;
	cout<<" 开始战斗 ";
	Sleep(500); 
	gotoxy(18,5);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"空格键：开始战斗\nshift键：模式切换\ntab键：药水切换\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(blv==0&&fightcase==1)
			{
				::MessageBox(0,"已完成“箭头记忆”所有战斗","",0);
				continue; 
			} 
			if(hlv==0&&fightcase==2)
			{
				::MessageBox(0,"已完成“方向反应”所有战斗","",0);
				continue;
			} 
			if(useys==0)
			{
				if(flag)
				{
					break;
				}
			}
			else
			{
				if(ys[useys-1]>0)
				{
					if(flag)
					{
						ys[useys-1]--;
						break;
					}
				}
				else
				{
					::MessageBox(hwnd,"没有相应的药水","",0);
				}
			}		
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			color(0);
			if(hometype==1)
			{
				nhome3();
			}
			else
			{
				home3();
			}
		}
		if(GetAsyncKeyState(VK_SHIFT))
		{
			color(13);
			gotoxy(8,7);
			if(fightcase==1)
			{
				fightcase=2;
				cout<<"：方向反应"; 
				gotoxy(10,0);
				cout<<hlv<<"    ";
			}
			else if(fightcase==2)
			{
				fightcase=1;
				cout<<"：箭头记忆"; 
				gotoxy(10,0);
				cout<<blv<<"    ";
			}
			Sleep(300);
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			color(15);
			gotoxy(8,6);
			if(useys==0)
			{
				useys++;
				cout<<"：力量药水"; 	
			}
			else if(useys==1)
			{
				useys++;
				cout<<"：防御药水"; 
			}
			else if(useys==2)
			{
				useys++;
				cout<<"：敏捷药水"; 
			}
			else if(useys==3)
			{
				useys=0;
				cout<<"：无        "; 	
			}
			Sleep(300);
		}
	}
	gotoxy(0,0);
	color(13);
	sj-=2;
	color(15);
	system("cls");
	cout<<"加载中……";
	for(int i=0;i<100;i++)
	{
		GetAsyncKeyState(VK_LEFT);
		GetAsyncKeyState(VK_RIGHT);
		GetAsyncKeyState(VK_DOWN);
		GetAsyncKeyState(VK_UP);
		GetAsyncKeyState(VK_ESCAPE);
	}
	if(fightcase==1)
	{
		fightmove();
	}
	else
	{
		fightmove2();
	}
}
void check()
{
	if(hp<=0)
	{
		system("cls");
		color(4);
		cout<<"战斗失败！";
		Sleep(2000);
		for(;!GetAsyncKeyState(VK_ESCAPE);)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
			}
		}
		if(hometype==1)
		{
			nhome3();
		}
		else
		{
			home3();
		}
	}
	if(dhp<=0)
	{
		system("cls");
		color(10);
		cout<<"战斗胜利！"<<endl;
		cjf[5]++;
		score=double(hp)/double(dlv/10*50+50)*120;
		if(score>100)
		{
			score=100;
		}
		cout<<"分数："<<score<<endl;
		color(14);
		for(int i=0;i<5;i++) 
		{
			if(i>=score/20)
			{
				cout<<"☆"<<cor();
			}
			else
			{
				cout<<"★"<<cor();
			}
		}
		color(10);
		cout<<endl<<"战利品："<<endl;
		color(14);
		cout<<"●"<<cor()<<blv*100<<endl;
		color(10);
		cout<<"LV"<<blv<<"%"<<endl;
		color(208);
		cout<<"攻";
		color(15); 
		cout<<int(blv/2)<<endl;
		color(208);
		cout<<"防";
		color(15); 
		cout<<int(blv/2)<<endl;
		Sleep(500);
		coin+=blv*100;
		exp1+=blv;
		lv+=exp1/100;
		exp1=exp1%100;
		attack+=int(blv/2);
		defense+=int(blv/2); 
		blv++;
		if(blv>=101)
		{
			blv=0;
		}
		for(;!GetAsyncKeyState(VK_ESCAPE);)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
			}
		}
		if(hometype==1)
		{
			nhome3();
		}
		else
		{
			home3();
		}
	}
}
void check2()
{
	if(hp<=0)
	{
		system("cls");
		color(4);
		cout<<"战斗失败！";
		Sleep(2000);
		for(;!GetAsyncKeyState(VK_ESCAPE);)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
			}
		}
		if(hometype==1)
		{
			nhome3();
		}
		else
		{
			home3();
		}
	}
	if(dhp<=0)
	{
		system("cls");
		color(10);
		cout<<"战斗胜利！"<<endl;
		cjf[5]++;
		score=double(hp)/double(dlv/10*50+50)*120;
		if(score>100)
		{
			score=100;
		}
		cout<<"分数："<<score<<endl;
		color(14);
		for(int i=0;i<5;i++) 
		{
			if(i>=score/20)
			{
				cout<<"☆"<<cor();
			}
			else
			{
				cout<<"★"<<cor();
			}
		}
		color(10);
		cout<<endl<<"战利品："<<endl;
		color(14);
		cout<<"●"<<cor()<<hlv*100<<endl;
		color(10);
		cout<<"LV"<<hlv<<"%"<<endl;
		color(208);
		cout<<"攻";
		color(15); 
		cout<<int(hlv/2)<<endl;
		color(208);
		cout<<"防";
		color(15); 
		cout<<int(hlv/2)<<endl;
		Sleep(500);
		coin+=hlv*100;
		exp1+=hlv;
		lv+=exp1/100;
		exp1=exp1%100;
		attack+=int(hlv/2);
		defense+=int(hlv/2); 
		hlv++;
		if(hlv>=101)
		{
			hlv=0;
		}
		for(;!GetAsyncKeyState(VK_ESCAPE);)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
			}
		}
		if(hometype==1)
		{
			nhome3();
		}
		else
		{
			home3();
		}
	}
}
void fhp()
{
	gotoxy(0,0);
	color(13);
	if(dhp<0) dhp=0;
	if(hp<0) hp=0;
	cout<<"  ●"<<cor()<<"  "<<dhp<<"/"<<blv*50<<"                     ";
	gotoxy(0,2);
	color(ccolor);
	cout<<"  ●"<<cor()<<"  ";
	if(hp>50)
	{
		color(10);
	}
	else
	{
		color(4);
	}
	cout<<hp<<"/"<<dlv/10*50+50<<"              ";
	check();
	gotoxy(0,5);
	color(15);
	cout<<"回合"<<turn; 
}
void fhp2(bool hurt)
{
	gotoxy(0,0);
	color(13);
	cout<<"  ";
	if(hurt)
	{
		color(77);
	}
	if(dhp<0) dhp=0;
	if(hp<0) hp=0;
	cout<<"●"<<cor();
	color(13);
	cout<<"  ";
	cout<<dhp<<"/"<<hlv*50<<"                     ";
	if(hp>50)
	{
		color(10);
	}
	else
	{
		color(4);
	}
	gotoxy(7,2);
	cout<<hp<<"/"<<dlv/10*50+50<<"              ";
	check2(); 
}
void fhp3()
{
	gotoxy(14,0);
	color(13);
	if(dhp<0) dhp=0;
	if(hp<0) hp=0;
	cout<<dhp<<"/"<<"30000                         ";
	gotoxy(14,6);
	if(hp>50)
	{
		color(10);
	}
	else
	{
		color(4);
	}
	cout<<hp<<"/"<<dlv/10*50+50<<"                 ";
	check3();
}
void check3()
{
	if(hp<=0)
	{
		system("cls");
		color(4);
		cout<<"战斗失败！"<<endl;
		color(14);
		cout<<"最终之战不是那么容易的，继续努力吧！";
		Sleep(2000);
		for(;!GetAsyncKeyState(VK_ESCAPE);)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
			}
		}
		if(hometype==1)
		{
			nhome3();
		}
		else
		{
			home3();
		}
	}
	if(dhp<=0)
	{
		gotoxy(6,0);
		color(228);
		cout<<"●"<<cor();
		Sleep(1000);
		system("cls");
		system("color 7e");
		Sleep(200);
		system("color fe");
		Sleep(1500);
		system("color 7e");
		Sleep(200);
		system("color 0f");
		color(13);
		cout<<"最终之战"<<endl;
		color(10);
		cout<<"战斗胜利！"<<endl;
		score=double(hp)/double(dlv/10*50+50)*120;
		if(score>100)
		{
			score=100;
		}
		cout<<"分数："<<score<<endl;
		color(14);
		for(int i=0;i<5;i++) 
		{
			if(i>=score/20)
			{
				cout<<"☆"<<cor();
			}
			else
			{
				cout<<"★"<<cor();
			}
		}
		color(10);
		cout<<endl<<"战利品："<<endl;
		color(14);
		cout<<"●"<<cor()<<10000<<endl;
		color(10);
		cout<<"LV"<<"+10"<<endl;
		Sleep(500);
		coin+=10000;
		lv+=10;
		blv=1;
		hlv=1;
		for(;!GetAsyncKeyState(VK_ESCAPE);)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
			}
		}
		if(hometype==1)
		{
			nhome3();
		}
		else
		{
			home3();
		}
	}
}
void fhp4()
{
	gotoxy(0,0);
	color(13);
	if(dhp<0) dhp=0;
	if(hp<0) hp=0;
	cout<<"  ●"<<cor()<<"  "<<dhp<<"/"<<blv*50<<"                     ";
	gotoxy(0,2);
	color(ccolor);
	cout<<"  ●"<<cor()<<"  ";
	if(hp>50)
	{
		color(10);
	}
	else
	{
		color(4);
	}
	cout<<hp<<"/"<<dlv/10*50+50<<"              ";
	check4();
}
void check4()
{
	
}
void fightmove()
{
	system("cls");
	turn=1;
	int size=0,wrong=0;
	dhp=blv*50;
	hp=dlv/10*50+50;
	if(jnc==2)
	{
		hp*=1.2;
	}
	fhp();
	while(1)
	{
		Sleep(1000);
		color(15);
		size=wrong=0;
		gotoxy(0,4);
		for(int i=0;i<=(blv+100)/20;i++)
		{
			cout<<"  ";
		}
		gotoxy(0,4);
		cout<<"ready ";
		Sleep(500);
		gotoxy(0,4);
		cout<<"go!   ";
		Sleep(500);
		gotoxy(0,4);
		cout<<"       ";
		for(int i=0;i<(blv+100)/20;i++)
		{
			gotoxy(i*2,4);
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"根据闪过的箭头按下相应的键","说明",MB_ICONINFORMATION);
			}
			int a=rand()%4;
			if(a==0)
			{
				fightmap[i]=0;
				cout<<"↑"<<cor();
			}
			else if(a==1)
			{
				fightmap[i]=1;
				cout<<"↓"<<cor();
			}
			else if(a==2)
			{
				fightmap[i]=2;
				cout<<"←"<<cor();
			}
			else if(a==3)
			{
				fightmap[i]=3;
				cout<<"→"<<cor();
			}
			if(jnc==10) Sleep(((20-blv%20)*20+400)*1.2);
			else Sleep((20-blv%20)*20+400);
			gotoxy(i*2,4);
			cout<<"？";
		}
		gotoxy(0,4);
		for(int i=0;i<20;i++)
		{
			GetAsyncKeyState(VK_LEFT);
			GetAsyncKeyState(VK_RIGHT);
			GetAsyncKeyState(VK_DOWN);
			GetAsyncKeyState(VK_UP);
			GetAsyncKeyState(VK_ESCAPE);
		}
		for(;size<(blv+100)/20;)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"根据闪过的箭头按下相应的键","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_ESCAPE))
			{ 
				if(::MessageBox(0,"中途退出即战斗失败","确定退出吗？",1)==1)
				{
					hp=0;
					check();
				}
			}
			Sleep(500);
			if(GetAsyncKeyState(VK_UP))
			{
				if(fightmap[size]==0)
				{
					color(10);
				}
				else
				{
					color(4);
					wrong++;
				}
				cout<<"↑"<<cor();
				size++;
			}
			if(GetAsyncKeyState(VK_DOWN))
			{
				if(fightmap[size]==1)
				{
					color(10);
				}
				else
				{
					color(4);
					wrong++;
				}
				cout<<"↓"<<cor();
				size++;
			}
			if(GetAsyncKeyState(VK_LEFT))
			{
				if(fightmap[size]==2)
				{
					color(10);
				}
				else
				{
					color(4);
					wrong++;
				}
				cout<<"←"<<cor();
				size++;
			}
			if(GetAsyncKeyState(VK_RIGHT))
			{
				if(fightmap[size]==3)
				{
					color(10);
				}
				else
				{
					color(4);
					wrong++;
				}
				cout<<"→"<<cor();
				size++;
			}
		}
		Sleep(500);
		bool flag=0;
		double hurt=((blv+100)/20-wrong)*alv,dd=wrong*blv*(1.0-dlv*0.01);
		if(rand()%100<alv/10*9+9)
		{
			hurt*=2;
			flag=1;
		}
		if(useys==1)
		{
			hurt*=1.2;
		}
		else if(useys==2)
		{
			dd*=0.7;
		}
		else if(useys==3)
		{
			if(rand()%10==0)
			{
				dd=0;
			}
		}
		if(jnc==1)
		{
			hurt*=1.2;
		}
		else if(jnc==3)
		{
			hurt+=dd*0.2;
		}
		else if(jnc==4)
		{
			if(rand()%10==0)
			{
				dd=0;
			}
		}
		else if(jnc==5)
		{
			dd*=0.7;
		}
		else if(jnc==6)
		{
			hurt*=0.9+(1.0-double(hp)/double(dlv/10*50+50))/1.5;
		}
		else if(jnc==7)
		{
			hurt*=2.2;
			dd*=2;
		}
		else if(jnc==8)
		{
			dd*=2;
			if(rand()%10<6)
			{
				dd=0;
			}
		}
		else if(jnc==9)
		{
			if(dhp<blv*50/10||hurt>=dhp)
			{
				hurt=INT_MAX;
			}
		}
		hp-=dd;
		dhp-=hurt;
		color(6);
		gotoxy(20,0);
		if(flag)
		{
			color(4);
		}
		cout<<"-"<<int(hurt);
		gotoxy(20,2);
		color(13);
		cout<<"-"<<int(dd);
		Sleep(1000); 
		turn++;
		fhp();
		for(;!GetAsyncKeyState(VK_SPACE);)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"空格键：下一回合","说明",MB_ICONINFORMATION);
			}
		}
	}	
}
void fightmove2()
{
	system("cls");
	int now=rand()%4,next=rand()%4;
	double hurt=0,dd=0; 
	bool flag;
	dhp=hlv*50;
	hp=dlv/10*50+50;
	if(jnc==2)
	{
		hp*=1.2;
	}
	fhp2(0);
	color(15);
	gotoxy(0,3);
	cout<<"ready ";
	Sleep(500);
	gotoxy(0,3);
	cout<<"go!   ";
	Sleep(500);
	gotoxy(0,3);
	cout<<"       ";
	while(1)
	{
		flag=0;
		gotoxy(0,2);
		color(15);
		if(now==0)
		{
			cout<<"↑"<<cor();
		}
		else if(now==1)
		{
			cout<<"↓"<<cor();
		}
		else if(now==2)
		{
			cout<<"←"<<cor();
		}
		else if(now==3)
		{
			cout<<"→"<<cor();
		}
		gotoxy(0,3);
		color(15);
		if(next==0)
		{
			cout<<"↑"<<cor();
		}
		else if(next==1)
		{
			cout<<"↓"<<cor();
		}
		else if(next==2)
		{
			cout<<"←"<<cor();
		}
		else if(next==3)
		{
			cout<<"→"<<cor();
		}
		color(15);
		cout<<" 下一个";
		gotoxy(2,2);
		color(ccolor);
		if(dd>0)
		{
			color(ccolor+64); 
		}
		cout<<"●"<<cor();
		hurt=0;
		dd=0;
		for(int i=0;i<36-hlv/3;i++)
		{
			if(jnc==10) Sleep(30);
			else Sleep(25);
			if(GetAsyncKeyState(VK_CONTROL))
	 		{ 
				::MessageBox(hwnd,"根据箭头按下相应的按键","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_ESCAPE))
			{
				if(::MessageBox(0,"中途退出即战斗失败","确定退出吗？",1)==1)
				{
					hp=0;
					check2();
				}
			}
			if(GetAsyncKeyState(VK_LEFT))
			{
				if(now==2)	
				{
					hurt=alv;
					flag=1;
					break;
				}
				else
				{
					break;
				}
			}
			if(GetAsyncKeyState(VK_RIGHT))
			{
				if(now==3)	
				{
					hurt=alv;
					flag=1;
					break;
				}
				else
				{
					break;
				}
			}
			if(GetAsyncKeyState(VK_UP))
			{
				if(now==0)	
				{
					hurt=alv;
					flag=1;
					break;
				}
				else
				{
					break;
				}
			}
			if(GetAsyncKeyState(VK_DOWN))
			{
				if(now==1)	
				{
					hurt=alv;
					flag=1;
					break;
				}
				else
				{
					break;
				}
			}
		}	
		gotoxy(0,2);
		if(flag)
		{
			color(175);
		}
		else
		{
			dd=hlv*(1.0-dlv*0.01);
			color(79);
		}
		if(now==0)
		{
			cout<<"↑"<<cor();
		}
		else if(now==1)
		{
			cout<<"↓"<<cor();
		}
		else if(now==2)
		{
			cout<<"←"<<cor();
		}
		else if(now==3)
		{
			cout<<"→"<<cor();
		}
		if(rand()%100<alv/10*9+9)
		{
			hurt*=2;
			flag=1;
		}
		if(useys==1)
		{
			hurt*=1.2;
		}
		else if(useys==2)
		{
			dd*=0.7;
		}
		else if(useys==3)
		{
			if(rand()%10==0)
			{
				dd=0;
			}
		}
		if(jnc==1)
		{
			hurt*=1.2;
		}
		else if(jnc==3)
		{
			hurt+=dd*0.2;
		}
		else if(jnc==4)
		{
			if(rand()%10==0)
			{
				dd=0;
			}
		}
		else if(jnc==5)
		{
			dd*=0.7;
		}
		else if(jnc==6)
		{
			hurt*=0.9+(1.0-double(hp)/double(dlv/10*50+50))/1.5;
		}
		else if(jnc==7)
		{
			hurt*=2.2;
			dd*=2;
		}
		else if(jnc==8)
		{
			dd*=2;
			if(rand()%10<6)
			{
				dd=0;
			}
		}
		else if(jnc==9)
		{
			if(dhp<blv*50/10||hurt>=dhp)
			{
				hurt=INT_MAX;
			}
		}
		hp-=dd;
		dhp-=hurt;
		Sleep(200);
		now=next;
		next=rand()%4;
		fhp2(hurt>0);
	}	
}
void jout(int x,int y,int xuan)
{
	int temp=jmap[y+1][x+1][xuan];
	gotoxy(y*2,x);
	if(temp==4)
	{
		rgb_set(100,60,0);
	}
	else if(temp==6)
	{
		rgb_set(225,120,0);
	}
	else
	{
		color(jcolor[temp]);
	}
	cout<<jdata[temp*2]<<jdata[temp*2+1];
	if(temp==7)
	{
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"▄";
	}
	else if(temp==11)
	{
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"█";
	}
	else if(temp==3||temp==8||temp==9||temp==10||(temp>=13&&temp<=25))
	{
		cout<<cor();
	}
	gotoxy(72,0);
	color(7);
	if(choose==0)
	{
		color(12);
	}
	cout<<"拆除"<<endl;
	color(102);
	gotoxy(72,1);
	cout<<"  ";
	color(7);
	if(choose==1)
	{
		color(12);
	}
	cout<<jj[1]<<"    "<<endl;
	color(136);
	gotoxy(72,2);
	cout<<"  ";
	color(7);
	if(choose==2)
	{
		color(12);
	}
	cout<<jj[2]<<"    "<<endl;
	color(113);
	gotoxy(72,3);
	cout<<"■"<<cor();
	color(7);
	if(choose==3)
	{
		color(12);
	}
	cout<<jj[3]<<"    "<<endl;
	rgb_set(100,60,0);
	gotoxy(72,4);
	cout<<"  ";
	color(7);
	if(choose==4)
	{
		color(12);
	}
	cout<<jj[4]<<"    "<<endl;
	color(170);
	gotoxy(72,5);
	cout<<"  ";
	color(7);
	if(choose==5)
	{
		color(12);
	}
	cout<<jj[5]<<"    "<<endl;
	rgb_set(225,120,0);
	gotoxy(72,6);
	cout<<"  ";
	color(7);
	if(choose==6)
	{
		color(12);
	}
	cout<<jj[6]<<"    "<<endl;
	color(6);
	gotoxy(72,7);
	cout<<"▄";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"▄";
	color(7);
	if(choose==7)
	{
		color(12);
	}
	cout<<jj[7]<<"    "<<endl;
	color(6);
	gotoxy(72,8);
	cout<<"‖"<<cor();
	color(7);
	if(choose==8)
	{
		color(12);
	}
	cout<<jj[8]<<"    "<<endl;
	color(6);
	gotoxy(72,9);
	cout<<"→"<<cor();
	color(7);
	if(choose==9)
	{
		color(12);
	}
	cout<<jj[9]<<"    "<<endl;
	color(6);
	gotoxy(72,10);
	cout<<"◢"<<cor();
	color(7);
	if(choose==10)
	{
		color(12);
	}
	cout<<jj[10]<<"    "<<endl;
	color(240);
	gotoxy(72,11);
	cout<<"█";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"█";
	color(7);
	if(choose==11)
	{
		color(12);
	}
	cout<<jj[11]<<"    "<<endl;
	color(6);
	gotoxy(72,12);
	cout<<"〓";
	color(7);
	if(choose==12)
	{
		color(12);
	}
	cout<<jj[12]<<"    "<<endl;
	color(4);
	gotoxy(72,13);
	cout<<"Φ"<<cor();
	color(7);
	if(choose==13)
	{
		color(12);
	}
	cout<<jj[13]<<"    "<<endl;
	color(14);
	gotoxy(72,14);
	cout<<"¤"<<cor();
	color(7);
	if(choose==14)
	{
		color(12);
	}
	cout<<jj[14]<<"    "<<endl;
	color(15);
	gotoxy(72,15);
	cout<<"※"<<cor();
	color(7);
	if(choose==15)
	{
		color(12);
	}
	cout<<jj[15]<<"    "<<endl;
}
void jmapout(int xuan)
{
	int temp;
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=35;j++)
		{
			temp=jmap[j][i][xuan];
			if(temp==4)
			{
				rgb_set(100,60,0);
			}
			else if(temp==6)
			{
				rgb_set(225,120,0);
			}
			else
			{
				color(jcolor[temp]);
			}
			cout<<jdata[temp*2]<<jdata[temp*2+1];
			if(temp==7)
			{
				if(cor1==1) cout<<" ";
				else if(cor1==2) cout<<"▄";
			}
			else if(temp==11)
			{
				if(cor1==1) cout<<" ";
				else if(cor1==2) cout<<"█";
			}
			else if(temp==3||temp==8||temp==9||temp==10||(temp>=13&&temp<=25))
			{
				cout<<cor();
			}
		}
		color(0);
		puts("");
	}
}
void jhome(int xuan)
{
	int x=8,y=0,temp;
	gotoxy(72,0);
	cout<<"      ";
	choose=0;
	jout(0,8,xuan);
	gotoxy(y*2,x);
	while(1)
	{
		Sleep(100);
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\n空格键：放置物品\ntab键：切换物品\nesc键：退出\nshift键：切换样式","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(x<19)
			{
				x++;	
				gotoxy(y*2,x);
			}
		}
		if(GetAsyncKeyState(VK_UP)) 
		{
			if(x>0)
			{
				x--;	
				gotoxy(y*2,x);
			}
			fx=1;
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(y>0)
			{
				y--;	
				gotoxy(y*2,x);
			}		
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(y<34)
			{
				y++;	
				gotoxy(y*2,x);
			}
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home2();
			}
		}
		if(GetAsyncKeyState(VK_SHIFT))
		{
			if(jmap[y+1][x+1][xuan]==10)
			{
				jmap[y+1][x+1][xuan]=16;
			}
			else if(jmap[y+1][x+1][xuan]==16)
			{
				jmap[y+1][x+1][xuan]=17;
			}
			else if(jmap[y+1][x+1][xuan]==17)
			{
				jmap[y+1][x+1][xuan]=18;
			}
			else if(jmap[y+1][x+1][xuan]==18)
			{
				jmap[y+1][x+1][xuan]=10;
			}
			if(jmap[y+1][x+1][xuan]==9)
			{
				jmap[y+1][x+1][xuan]=19;
			}
			else if(jmap[y+1][x+1][xuan]>=19&&jmap[y+1][x+1][xuan]<25)
			{
				jmap[y+1][x+1][xuan]++;
			}
			else if(jmap[y+1][x+1][xuan]==25)
			{
				jmap[y+1][x+1][xuan]=9;
			}
			if(jmap[y+1][x+1][xuan]==6)
			{
				jmap[y+1][x+1][xuan]=26;
			}
			else if(jmap[y+1][x+1][xuan]>=26&&jmap[y+1][x+1][xuan]<29)
			{
				jmap[y+1][x+1][xuan]++;
			}
			else if(jmap[y+1][x+1][xuan]==29)
			{
				jmap[y+1][x+1][xuan]=6;
			}
			jout(x,y,xuan);
			gotoxy(y*2,x);
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(choose==0)
			{
				temp=jmap[y+1][x+1][xuan];
				if(temp>=16&&temp<=18)
				{
					temp=10;
				}
				if(temp>18&&temp<26)
				{
					temp=9;
				}
				if(temp>=26)
				{
					temp=6;
				}
				jj[temp]++;
				jmap[y+1][x+1][xuan]=0;
				jout(x,y,xuan);
				gotoxy(y*2,x);
			}
			else if(jj[choose]>0)
			{
				temp=jmap[y+1][x+1][xuan];
				if(temp>=16&&temp<=18)
				{
					temp=10;
				}
				if(temp>18&&temp<26)
				{
					temp=9;
				}
				if(temp>=26)
				{
					temp=6;
				}
				jj[temp]++;
				jj[choose]--;
				jmap[y+1][x+1][xuan]=choose;
				jout(x,y,xuan);
				gotoxy(y*2,x);
			}
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			choose++;
			if(choose>15)
			{
				choose=0;
			}
			jout(x,y,xuan);
			gotoxy(y*2,x);
		}
	}
}
void jshopmenu()
{
	color(14);
	cout<<"材料商店（买） *"<<times<<"    "<<endl;
	cout<<"金币x"<<coin<<"  "<<endl;
	cout<<"材料   单价   已有"<<endl;
	color(102);
	cout<<"  ";
	color(7);
	if(choose==1)
	{
		color(12);
	}
	cout<<"      80    "<<jj[1]<<endl;
	color(136);
	cout<<"  ";
	color(7);
	if(choose==2)
	{
		color(12);
	}
	cout<<"      10    "<<jj[2]<<endl;
	color(113);
	cout<<"■"<<cor();
	color(7);
	if(choose==3)
	{
		color(12);
	}
	cout<<"      100   "<<jj[3]<<endl;
	rgb_set(100,60,0);
	cout<<"  ";
	color(7);
	if(choose==4)
	{
		color(12);
	}
	cout<<"      10    "<<jj[4]<<endl;
	color(170);
	cout<<"  ";
	color(7);
	if(choose==5)
	{
		color(12);
	}
	cout<<"      10    "<<jj[5]<<endl;
	rgb_set(225,120,0);
	cout<<"  ";
	color(7);
	if(choose==6)
	{
		color(12);
	}
	cout<<"      80    "<<jj[6]<<endl;
	color(6);
	cout<<"▄";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"▄";
	color(7);
	if(choose==7)
	{
		color(12);
	}
	cout<<"      60    "<<jj[7]<<endl;
	color(6);
	cout<<"‖"<<cor();
	color(7);
	if(choose==8)
	{
		color(12);
	}
	cout<<"      50    "<<jj[8]<<endl;
	color(6);
	cout<<"→"<<cor();
	color(7);
	if(choose==9)
	{
		color(12);
	}
	cout<<"      50    "<<jj[9]<<endl;
	color(6);
	cout<<"◢"<<cor();
	color(7);
	if(choose==10)
	{
		color(12);
	}
	cout<<"      50    "<<jj[10]<<endl;
	color(240);
	cout<<"█";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"█";
	color(7);
	if(choose==11)
	{
		color(12);
	}
	cout<<"      80    "<<jj[11]<<endl;
	color(6);
	cout<<"〓";
	color(7);
	if(choose==12)
	{
		color(12);
	}
	cout<<"      60    "<<jj[12]<<endl;
	color(4);
	cout<<"Φ"<<cor();
	color(7);
	if(choose==13)
	{
		color(12);
	}
	cout<<"      80    "<<jj[13]<<endl;
	color(14);
	cout<<"¤"<<cor();
	color(7);
	if(choose==14)
	{
		color(12);
	}
	cout<<"      80    "<<jj[14]<<endl;
	color(15);
	cout<<"※"<<cor();
	color(7);
	if(choose==15)
	{
		color(12);
	}
	cout<<"      80    "<<jj[15]<<endl;
}
void jshopmenu2()
{
	color(14);
	cout<<"材料商店（卖） *"<<times<<"    "<<endl;
	cout<<"金币x"<<coin<<"  "<<endl;
	cout<<"材料   单价   已有"<<endl;
	color(102);
	cout<<"  ";
	color(7);
	if(choose==1)
	{
		color(12);
	}
	cout<<"      8     "<<jj[1]<<"   "<<endl;
	color(136);
	cout<<"  ";
	color(7);
	if(choose==2)
	{
		color(12);
	}
	cout<<"      1     "<<jj[2]<<"   "<<endl;
	color(113);
	cout<<"■"<<cor();
	color(7);
	if(choose==3)
	{
		color(12);
	}
	cout<<"      10    "<<jj[3]<<"   "<<endl;
	rgb_set(100,60,0);
	cout<<"  ";
	color(7);
	if(choose==4)
	{
		color(12);
	}
	cout<<"      1     "<<jj[4]<<"   "<<endl;
	color(170);
	cout<<"  ";
	color(7);
	if(choose==5)
	{
		color(12);
	}
	cout<<"      1     "<<jj[5]<<"   "<<endl;
	rgb_set(225,120,0);
	cout<<"  ";
	color(7);
	if(choose==6)
	{
		color(12);
	}
	cout<<"      8     "<<jj[6]<<"   "<<endl;
	color(6);
	cout<<"▄";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"▄";
	color(7);
	if(choose==7)
	{
		color(12);
	}
	cout<<"      6     "<<jj[7]<<"   "<<endl;
	color(6);
	cout<<"‖"<<cor();
	color(7);
	if(choose==8)
	{
		color(12);
	}
	cout<<"      5     "<<jj[8]<<"   "<<endl;
	color(6);
	cout<<"→"<<cor();
	color(7);
	if(choose==9)
	{
		color(12);
	}
	cout<<"      5     "<<jj[9]<<"   "<<endl;
	color(6);
	cout<<"◢"<<cor();
	color(7);
	if(choose==10)
	{
		color(12);
	}
	cout<<"      5     "<<jj[10]<<"   "<<endl;
	color(240);
	cout<<"█";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"█";
	color(7);
	if(choose==11)
	{
		color(12);
	}
	cout<<"      8     "<<jj[11]<<"   "<<endl;
	color(6);
	cout<<"〓";
	color(7);
	if(choose==12)
	{
		color(12);
	}
	cout<<"      6     "<<jj[12]<<"   "<<endl;
	color(4);
	cout<<"Φ"<<cor();
	color(7);
	if(choose==13)
	{
		color(12);
	}
	cout<<"      8     "<<jj[13]<<"   "<<endl;
	color(14);
	cout<<"¤"<<cor();
	color(7);
	if(choose==14)
	{
		color(12);
	}
	cout<<"      8     "<<jj[14]<<"   "<<endl;
	color(15);
	cout<<"※"<<cor();
	color(7);
	if(choose==15)
	{
		color(12);
	}
	cout<<"      8     "<<jj[15]<<"   "<<endl;
}
void jshop()
{
	system("cls");
	gotoxy(0,0);
	choose=1;
	jshopmenu();
	int casee=1;
	times=1; 
	Sleep(100);
	while(!GetAsyncKeyState(VK_ESCAPE))
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：确认\ntab键：买/卖切换\nesc键：退出\nshift键：切换数量","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_SHIFT))
		{
			if(times==1)
			{
				times=5;
			}
			else if(times==5)
			{
				times=10; 
			} 
			else if(times==10)
			{
				times=50;
			}
			else if(times==50)
			{
				times=100;
			}
			else
			{
				times=1;
			}
			gotoxy(0,0);
			if (casee==1) 
			{
				jshopmenu();
			}
			else if (casee==2) 
			{
				jshopmenu2();
			}
			Sleep(300);
		}
		if(GetAsyncKeyState(VK_TAB))
	  	{
			gotoxy(0,0);
			if (casee==1) 
			{
				casee=2;
				jshopmenu2();
			}
			else if (casee==2) 
			{
				casee=1;
				jshopmenu();
			}
			Sleep(200);
		}
		if(GetAsyncKeyState(VK_UP)&&choose>1)
	  	{
			choose--;
			gotoxy(0,0);
			if (casee==1) jshopmenu();
			if (casee==2) jshopmenu2();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_DOWN)&&choose<15)
		{
			choose++;
			if(choose>lv)
			{
				::MessageBox(hwnd,"下一级解锁","等级不足",MB_ICONINFORMATION);
				choose--;
			}
			else
			{
				gotoxy(0,0);
				if (casee==1) jshopmenu();
				if (casee==2) jshopmenu2();
				Sleep(100);
			}	
		}
		if(casee==1)
		{
			if(GetAsyncKeyState(VK_SPACE))
			{
				if(coin>=cost[choose]*10*times)
				{
					coin-=cost[choose]*10*times;
					jj[choose]+=times;
					gotoxy(0,0);
					jshopmenu();
					Sleep(200);
				}
			}
		}
		else
		{
			if(GetAsyncKeyState(VK_SPACE))
			{
				if(jj[choose]>=times)
				{
					coin+=cost[choose]*times;
					jj[choose]-=times;
					gotoxy(0,0);
					jshopmenu2();
					Sleep(30);
				}
			}
		}
	}
	if(hometype==1)
	{
		nhome2();
	}
	else
	{
		home2();
	}
}
void outk()
{
	if(kuya==1)
	{
		cout<<"▓";
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"▓";
	}
	if(kuya==2)
	{
		cout<<"◎"<<cor();
	}
	if(kuya==3)
	{
		cout<<"※"<<cor();
	}
	if(kuya==4)
	{
		cout<<"█";
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"█";
	}
	if(kuya==5)
	{
		cout<<"矿";
	}
}
void make()
{
	int x,y,leng;
	for(int i=0;i<=mapsize;i++)
	{
		for(int j=0;j<=mapsize;j++)
		{
			amap[j][i]=8;
		}
		amap[i][0]=-1;
	}
	srand((unsigned)time(NULL));
	for(int i=0;i<rand()%10+750;i++)
	{
		x=rand()%(mapsize-10)+3;
		y=rand()%(mapsize-10)+3;
		leng=rand()%10+3;
		for(int j=0;j<rand()%10+13;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=-1;
			}
		}
	}
	for(int i=0;i<rand()%50+1000;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%250+3;
		leng=rand()%2+1;
		for(int j=0;j<rand()%2+1;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=0;
			}
		}
	}
	for(int i=0;i<rand()%50+500;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%250+3;
		leng=rand()%2+1;
		for(int j=0;j<rand()%2+1;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=7;
			}
		}
	}
	for(int i=0;i<rand()%20+400;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%250+3+256;
		leng=rand()%2+1;
		for(int j=0;j<rand()%2+1;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=11;
			}
		}
	}
	for(int i=0;i<rand()%20+360;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%250+3+256;
		leng=rand()%2+1;
		for(int j=0;j<rand()%2+1;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=14;
			}
		}
	}
	for(int i=0;i<rand()%10+300;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%250+3+512;
		leng=rand()%2+1;
		for(int j=0;j<rand()%2+1;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=4;
			}
		}
	}
	for(int i=0;i<rand()%5+200;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%250+3+512;
		leng=rand()%2+1;
		for(int j=0;j<rand()%2+1;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=1;
			}
		}
	}
	for(int i=0;i<rand()%5+160;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%250+3+768;
		leng=rand()%2+1;
		for(int j=0;j<rand()%2+1;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=2;
			}
		}
	}
	for(int i=0;i<rand()%5+100;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%250+3+768;
		leng=rand()%2+1;
		for(int j=0;j<rand()%2+1;j++)
		{
			for(int k=0;k<leng;k++)
			{
				amap[x+j][y+k]=13;
			}
		}
	}
	for(int i=0;i<rand()%5+200;i++)
	{
		x=rand()%(mapsize-5)+3;
		y=rand()%(mapsize-5)+3;
		amap[x][y]=16;
	}
	for(int i=0;i<=mapsize;i++)
	{
		amap[i][1]=10;
		amap[i][2]=6;
		amap[i][3]=6;
		amap[i][256]=5;
		amap[i][512]=5;
		amap[i][768]=5;
	}
	for(int i=0;i<rand()%256+512;i++)
	{
		amap[rand()%1024][4]=6;
	}
}
void kmenu()
{
	gotoxy(0,0);
	color(9);
	cout<<"1.矿石样式"<<endl; 
	color(8);
	cout<<"煤矿石 ";
	color(0*16+8);
	outk();
	color(0);
	cout<<endl;
	color(7);
	cout<<"铁矿石 ";
	color(7*16+8);
	outk();
	color(0);
	cout<<endl;
	color(11);
	cout<<"钻石矿 ";
	color(11*16+8);
	outk();
	color(0);
	cout<<endl;
	color(14);
	cout<<"金矿石 ";
	color(14*16+8);
	outk();
	color(0);
	cout<<endl;
	color(4);
	cout<<"红石矿 ";
	color(4*16+8);
	outk();
	color(0);
	cout<<endl;
	color(1);
	cout<<"青金石 ";
	color(1*16+8);
	outk();
	color(0);
	cout<<endl;
	color(2);
	cout<<"绿宝石 ";
	color(2*16+8);
	outk();
	color(0);
	cout<<endl;
	color(13);
	cout<<"紫水晶 ";
	color(13*16+8);
	outk();
	color(0);
	cout<<endl;
}
void kmenu2()
{
	gotoxy(0,0);
	color(9);
	cout<<"2.角色颜色"<<endl; 
	color(ccolor);
	cout<<" < ● >"<<endl;
}
void kmenu3()
{
	gotoxy(0,0);
	color(9);
	cout<<"3.矿洞时间"<<endl; 
	if(day==1)
	{
		cout<<"< 早晨 >";
		color(179);
	}
	else if(day==2)
	{
		cout<<"< 傍晚 >";
		color(96);
	}
	else if(day==3)
	{
		cout<<"< 夜晚 >";
		color(0);
	}
	else if(day==4)
	{
		cout<<"< 幻境 >";
		color(464);
	}
	cout<<endl<<"              "<<endl;
	cout<<"              "<<endl;
	cout<<"              "<<endl;
	cout<<"              "<<endl;
	color(170);
	cout<<"              "<<endl;
	rgb_set(100,60,0);
	cout<<"              "<<endl;
	cout<<"              "<<endl;
	color(0);
}
void kmenu4()
{
	gotoxy(0,0);
	color(9);
	cout<<"4.刷新间隔"<<endl; 
	cout<<"如果电脑运算较慢，可将刷新间隔减小"<<endl; 
	color(15);
	cout<<" <"<<clstime<<">    "<<endl; 
}
void kmenu5()
{
	gotoxy(0,0);
	color(11);
	cout<<"5.主页面设置"<<endl; 
	color(15);
	if(hometype==1)
	{
		cout<<"新版主页面"<<endl; 
	}
	else
	{
		cout<<"旧版主页面"<<endl; 
	} 
}
void kmenu6()
{
	color(15);
	cout<<"6.画面校准"<<endl;
	cout<<"如果出现画面错位，可以进行调整"<<endl;
	color(10);
	cout<<"调整"; 
}
void kmenu7()
{
	string data="语缴韬";
	gotoxy(0,0);
	color(15);
	cout<<"7.关于"<<endl;
	cout<<"制作者：";
	for(int i=0;i<6;i++)
	{
		//cout<<char(data[i]-3);
	}
	cout<<"reeper";
	cout<<endl<<"编程语言：C++";
	cout<<endl<<"版本："<<edition<<endl;
	cout<<"=============="<<endl;
}
void sett()
{
	system("cls");
	kmenu();
	Sleep(100);
	int casee=0;
	while(1)
	{
		if(GetAsyncKeyState(VK_TAB))
		{
			Sleep(200); 
			system("cls");
			casee++;
			if(casee==7)
			{
				casee=0;
			}
			if(casee==1) 
			{
				kmenu2();
			}
			else if(casee==0)
			{
				kmenu();
			}
			else if(casee==3)
			{
				kmenu4();
			}
			else if(casee==4)
			{
				kmenu5();
			}
			else if(casee==5)
			{
				kmenu6();
			}
			else if(casee==2)
			{
				kmenu3();
			}
			else
			{
				kmenu7();
			}
		}
		if(casee==1)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"左移键：上一个\n右移键：下一个\nesc键：保存并退出\ntab键：切换设置","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_RIGHT))
			{
				ccolor++;
				if(ccolor>15)
				{
					ccolor=1;
				}
				kmenu2();
				Sleep(200);
			}
			if(GetAsyncKeyState(VK_LEFT))
			{
				ccolor--;
				if(ccolor<1)
				{
					ccolor=15;
				}
				kmenu2();
				Sleep(200);
			}
		}
		else if(casee==0)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\nesc键：保存并退出\ntab键：切换设置","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_UP))
			{
				kuya++;
				if(kuya>5)
				{
					kuya=1;
				}
				kmenu();
				Sleep(100);
			}
			if(GetAsyncKeyState(VK_DOWN))
			{
				kuya--;
				if(kuya<1)
				{
					kuya=5;
				}
				kmenu();
				Sleep(100);
			}
		}
		else if(casee==3)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"左移键：减少\n右移键：增加\nesc键：保存并退出\ntab键：切换设置","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_RIGHT))
			{
				if(clstime<100)
				{
					clstime+=10;
				}
				kmenu4();
				Sleep(100);
			}
			if(GetAsyncKeyState(VK_LEFT))
			{
				if(clstime<0||clstime%10!=0) clstime=100;
				if(clstime>0)
				{
					clstime-=10;
				}
				kmenu4();
				Sleep(100);
			}
		}
		else if(casee==4)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"shift键：更改\n空格键或esc键：确认\ntab键：切换设置","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_SHIFT))
			{
				if(hometype==1)
				{
					hometype=2; 
				} 
				else
				{
					hometype=1;
					mx=7;
					my=3;
				}
				kmenu5();
				Sleep(200);
			}
		}
		else if(casee==5)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"esc键：保存并退出\n空格键：开始校准\ntab键：切换设置","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_SPACE)) 
			{
				color(15);
				system("cls");
				cout<<"校准(1/3)"<<endl;
				outputcheck(1);
				color(15);
				cout<<"检查绿条和红条是否对齐"<<endl;
				cout<<"已对齐：空格键确认"<<endl; 
				cout<<"未对齐：TAB键调整"<<endl; 
				Sleep(300);
				while(!GetAsyncKeyState(VK_SPACE))
				{
					if(GetAsyncKeyState(VK_TAB))
					{
						cor2++;
						if(cor2==2) cor2=0;
						gotoxy(0,1);
						outputcheck(1);
						Sleep(500);
					}
				}
				color(0);
				system("cls");
				color(15);
				cout<<"校准(2/3)"<<endl;
				outputcheck(2);
				color(15);
				cout<<"检查绿条和红条是否对齐,以及是否显示完全"<<endl;
				cout<<"已对齐：空格键确认"<<endl; 
				cout<<"未对齐：TAB键调整"<<endl; 
				Sleep(300);
				while(!GetAsyncKeyState(VK_SPACE))
				{
					if(GetAsyncKeyState(VK_TAB))
					{
						cor1++;
						if(cor1==3) cor1=0;
						gotoxy(0,1);
						outputcheck(2);
						Sleep(500);
					}
				}
				color(0);
				system("cls");
				color(15);
				cout<<"校准(3/3)"<<endl;
				outputcheck(3);
				color(15);
				cout<<"检查从上到下是否均匀增长"<<endl;
				cout<<"是：空格键确认"<<endl; 
				cout<<"否：TAB键调整"<<endl; 
				Sleep(300);
				while(!GetAsyncKeyState(VK_SPACE))
				{
					if(GetAsyncKeyState(VK_TAB))
					{
						cor3++;
						if(cor3==2) cor3=0;
						gotoxy(0,1);
						outputcheck(3);
						Sleep(500);
					}
				}
				color(0);
				system("cls");
				kmenu6();
				Sleep(300);
			}
		}	
		else if(casee==2)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"左移键：上一个\n右移键：下一个\nesc键：保存并退出\ntab键：切换设置","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_RIGHT))
			{
				day++;
				if(day>4)
				{
					day=1;
				}
				kmenu3();
				Sleep(200);
			}
			if(GetAsyncKeyState(VK_LEFT))
			{
				day--;
				if(day<1)
				{
					day=4;
				}
				kmenu3();
				Sleep(200);
			}
		}	
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home4();
			}
			break; 
		}
	}
}
void save()
{
	SetFileAttributes("数据\\a6.dll",FILE_ATTRIBUTE_NORMAL);
	freopen("数据\\a6.dll","w",stdout);
	for(int i=0;i<=mapsize;i++)
	{
		for(int j=0;j<=mapsize;j++)
		{
			cout<<amap[j][i]<<" ";
		}
		cout<<endl;
	}
	SetFileAttributes("数据\\a6.dll",FILE_ATTRIBUTE_READONLY);
	SetFileAttributes("数据\\a6.dll",FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes("数据\\d8.dll",FILE_ATTRIBUTE_NORMAL);
	freopen("数据\\d8.dll","w",stdout);
	for(int i=1;i<=64;i++)
	{
		cout<<sp[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=10;i++)
	{
		cout<<cjf[i]<<" ";
	}
	cout<<star<<" "<<dhq<<" "<<cdflag<<" ";
	for(int i=0;i<3;i++)
	{
		cout<<ys[i]<<" ";
	}
	cout<<alb<<" ";
	for(int i=0;i<5;i++)
	{
		cout<<grow[i]<<" "<<plant[i]<<" ";
	}
	cout<<clstime<<" "<<jnc<<" "<<blv<<" "<<hlv<<" "<<alv<<" "<<dlv<<" "<<attack<<" "<<defense<<" "<<sj<<" "<<nowyear<<" "<<nowmon<<" "<<nowday<<" "<<lv<<" "<<exp1<<" 0 "<<day<<" "<<ccolor<<" "<<lc<<" "<<lir<<" "<<ld<<" "<<lgo<<" "<<lr<<" "<<lb<<" "<<lgr<<" "<<lp<<" "<<gao<<" "<<gaon<<" "<<deng<<" "<<dengn<<" "<<tnt<<" "<<kuya<<" ";
	for(int i=1;i<=15;i++)
	{
		cout<<jj[i]<<" ";
	}
	cout<<coin<<endl;
	for(int k=0;k<6;k++)
	{
		for(int i=1;i<=20;i++)
		{
			for(int j=1;j<=35;j++)
			{
				cout<<jmap[j][i][k]<<" ";
			}
			cout<<endl;
		}	
	}
	cout<<box1<<" "<<box2<<" "<<hometype<<" ";
	for(int i=1;i<=64;i++)
	{
		cout<<books[i]<<" ";
	}
	cout<<cor1<<" "<<cor2<<" "<<cor3<<" ";
	SetFileAttributes("数据\\d8.dll",FILE_ATTRIBUTE_READONLY);
	SetFileAttributes("数据\\d8.dll",FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes("数据\\3f.dll",FILE_ATTRIBUTE_NORMAL);
	freopen("数据\\3f.dll","w",stdout);
	cout<<tx_x<<" "<<tx_y<<" "<<tx_type<<" "<<tx_new<<" "<<health<<" "<<thirst<<" "<<hunger<<" "<<t_h<<" "<<t_m<<" "<<box01<<" "<<box02<<" "<<co<<endl; 
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			cout<<tx_map[j][i]<<" ";
		}
		cout<<endl;
	}
	SetFileAttributes("数据\\3f.dll",FILE_ATTRIBUTE_READONLY);
	SetFileAttributes("数据\\3f.dll",FILE_ATTRIBUTE_HIDDEN);
	fclose(stdout);
}
void aexit()
{
	alb=rand()%11;
	color(15);
	system("cls");
	if(!ro)
	{
		for(int i=0;i<4;i++) 
		{
			if(grow[i]!=0&&grow[i]!=800)
			{
				grow[i]=int((clock()-gc[i])/1000);
			}
		}
		cout<<"正在保存..."; 
		save();
	}
	EnableMenuItem(hmenu,SC_CLOSE,MF_ENABLED);
	exit(0);
}
void shopmenu2()
{
	color(14);
	cout<<"金币x"<<coin<<"   "<<endl;
	color(15);
	cout<<"< 矿石   "<<endl; 
	cout<<"   单价    数量"<<endl;
	color(0*16+8);
	outk();
	color(8);
	cout<<" 5       "<<lc<<"     "<<endl;
	color(7*16+8);
	outk();
	color(7);
	cout<<" 10      "<<lir<<"     "<<endl;
	color(11*16+8);
	outk();
	color(11);
	cout<<" 20      "<<ld<<"     "<<endl;
	color(14*16+8);
	outk();
	color(14);
	cout<<" 25      "<<lgo<<"     "<<endl;
	color(4*16+8);
	outk();
	color(4);
	cout<<" 30      "<<lr<<"     "<<endl;
	color(1*16+8);
	outk();
	color(1);
	cout<<" 50      "<<lb<<"     "<<endl;
	color(2*16+8);
	outk();
	color(2);
	cout<<" 60      "<<lgr<<"     "<<endl;
	color(13*16+8);
	outk();
	color(13);
	cout<<" 80      "<<lp<<"     "<<endl;
	color(14);
	cout<<"总计:" <<lc*5+lir*10+ld*20+lgo*25+lr*30+lb*50+lgr*60+lp*80<<"       "<<endl;
	color(12);
	cout<<" 卖出"; 
}
void shopmenu()
{
	color(14);
	cout<<"金币x"<<coin<<"    "<<endl;
	color(15);
	cout<<"  工具 >  "<<endl; 
	color(7);
	if(choose==1)
	{
		color(12);
	}
	cout<<"镐子 500"<<endl;
	color(7);
	if(choose==2)
	{
		color(12);
	}
	cout<<"矿灯 500"<<endl;
	color(7);
	if(choose==3)
	{
		color(12);
	}
	cout<<"炸药 100"<<endl;
}
void shop()
{
	system("cls");
	gotoxy(0,0);
	choose=1;
	shopmenu();
	int casee=1;
	Sleep(200);
	while(!GetAsyncKeyState(VK_ESCAPE))
	{
		if(casee==1)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n右移键：下一页\n空格键：确认\nesc键：退出","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_UP)&&choose>1)
	  		{
				choose--;
				gotoxy(0,0);
				shopmenu();
				Sleep(100);
			}
			if(GetAsyncKeyState(VK_DOWN)&&choose<3)
			{
				choose++;
				if(choose==3&&lv<1)
				{
					::MessageBox(hwnd,"等级到达1级后解锁“炸药”","等级不足",MB_ICONINFORMATION);
					choose--;
				}
				else
				{
					gotoxy(0,0);
					shopmenu();
					Sleep(100);
				}
				
			}
			if(GetAsyncKeyState(VK_SPACE))
			{
				if(choose==1&&coin>=500)
				{
					coin-=500;
					if(gaon==0)
					{
						if(gao==0) gao++;
						gaon=2000;
					} 
					else gao++;
					gotoxy(0,5);
					color(15);
					cout<<"购买成功";
					gotoxy(0,0);
					shopmenu();
					Sleep(500);
					gotoxy(0,5);
					cout<<"         "; 
				}
				if(choose==2&&coin>=500)
				{
					coin-=500;
					if(dengn==0)
					{
						if(deng==0)deng++;
						dengn=3000;
					} 
					else deng++;
					gotoxy(0,5);
					color(15);
					cout<<"购买成功";
					gotoxy(0,0);
					shopmenu();
					Sleep(500);
					gotoxy(0,5);
					cout<<"         "; 
				}
				if(choose==3&&coin>=100)
				{
					coin-=100;
					tnt++;
					gotoxy(0,5);
					color(15);
					cout<<"购买成功";
					gotoxy(0,0);
					shopmenu();
					Sleep(500);
					gotoxy(0,5);
					cout<<"         "; 
				}
			}
		}
		if(casee==2)
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"左移键：上一页\n空格键：卖出\nesc键：退出","说明",MB_ICONINFORMATION);
			}
			if(GetAsyncKeyState(VK_SPACE))
			{
				coin+=lc*5+lir*10+ld*20+lgo*25+lr*30+lb*50+lgr*60+lp*80;
				ld=lir=lr=lb=lc=lgo=lgr=lp=0;
				gotoxy(0,0);
				shopmenu2();
			}
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			casee=2;
			system("cls");
			shopmenu2();
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			casee=1;
			system("cls");
			shopmenu();
		}
	}
	if(hometype==1)
	{
		nhome1();
	}
	else
	{
		home();
	}	
}
void cangmenu(int casee)
{
	system("cls");
	color(15);
	cout<<" 仓库"<<endl; 
	if(casee==1)
	{
		color(15);
		cout<<" 工具>"<<endl;
		color(7); 
		cout<<" 镐子 "<<gao<<"("<<gaon<<"/2000)"<<endl;
		cout<<" 矿灯 "<<deng<<"("<<dengn<<"/3000)"<<endl;
		cout<<" 炸药 "<<tnt<<endl;
	}
	else if(casee==2)
	{
		color(15);
		cout<<"<矿石>"<<endl;
		color(0*16+8);
		outk();
		color(8);
		cout<<"  "<<lc<<endl;
		color(7*16+8);
		outk();
		color(7);
		cout<<"  "<<lir<<endl;
		color(11*16+8);
		outk();
		color(11);
		cout<<"  "<<ld<<endl;
		color(14*16+8);
		outk();
		color(14);
		cout<<"  "<<lgo<<endl;
		color(4*16+8);
		outk();
		color(4);
		cout<<"  "<<lr<<endl;
		color(1*16+8);
		outk();
		color(1);
		cout<<"  "<<lb<<endl;
		color(2*16+8);
		outk();
		color(2);
		cout<<"  "<<lgr<<endl;
		color(13*16+8);
		outk();
		color(13);
		cout<<"  "<<lp<<endl;
	}
	else if(casee==3)
	{
		color(15);
		cout<<"<建筑>"<<endl;
		for(int j=1;j<=15;j++)
		{
			color(0);
			cout<<" ";
			if(j==4)
			{
				rgb_set(100,60,0);
			}
			else if(j==6)
			{
				rgb_set(225,120,0);
			}
			else
			{
				color(jcolor[j]);
			}
			cout<<jdata[j*2]<<jdata[j*2+1];
			if(j==7)
			{
				if(cor1==1) cout<<" ";
				else if(cor1==2) cout<<"▄";
			}
			else if(j==11)
			{
				if(cor1==1) cout<<" ";
				else if(cor1==2) cout<<"█";
			}
			else if(j==3||j==8||j==9||j==10||(j>=13&&j<=25))
			{
				cout<<cor();
			}
			color(15);
			cout<<" "<<jj[j]<<endl;
		}
	}
	else if(casee==4)
	{
		color(15);
		cout<<"<战斗>"<<endl<<" ";
		color(208);
		cout<<"攻";
		color(15); 
		cout<<attack<<endl<<" ";
		color(208);
		cout<<"防";
		color(15); 
		cout<<defense<<endl<<" ";
		color(5);
		cout<<"◆"<<cor();
		color(15);
		cout<<sj<<endl;
	}
	else if(casee==5)
	{
		color(15);
		cout<<"<药水>"<<endl<<" ";
		color(116);
		cout<<"█";
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"█";
		color(15);
		cout<<ys[0]<<endl<<" ";
		color(120);
		cout<<"█";
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"█";
		color(15);
		cout<<ys[1]<<endl<<" ";
		color(122);
		cout<<"█";
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"█";
		color(15);
		cout<<ys[2]<<endl;
	}
	else if(casee==6)
	{
		color(15);
		cout<<"<杂项 "<<endl<<" ";
		color(14);
		cout<<"金币 "<<coin<<endl<<" ";
		color(235);
		cout<<"券";
		color(14);
		cout<<" "<<dhq<<endl<<" ";
		color(14);
		cout<<"★ "<<cor()<<star<<endl;
	}
}
void cang()
{
	int casee=1;
	cangmenu(casee);
	while(!GetAsyncKeyState(VK_ESCAPE))
	{
		Sleep(200);
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"esc键：退出\n左移键：上一页\n右移键：下一页","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_LEFT)&&casee>1)
		{ 
			casee--;
			cangmenu(casee);
		}
		if(GetAsyncKeyState(VK_RIGHT)&&casee<6)
		{ 
			casee++;
			cangmenu(casee);
		}
	}
	if(hometype==1)
	{
		nhome2();
	}
	else
	{
		home();
	}	
}
void error() 
{
	fun++;
	if(fun>=400)
	{
		::MessageBox(hwnd,"出现了一些错误\n即将保存并退出\n错误编号：#error1","错误！",MB_ICONWARNING);
		aexit();
	} 
}
void hdmenu()
{
	gotoxy(0,0);
	color(14);
	cout<<"      活动            "<<endl;
	cout<<" ______________"<<endl;
	cout<<"|              |"<<endl;
	cout<<"|";
	if(choose==1)
	{
		color(12);
	}
	cout<<"   图形填空   "; 
	color(14);  
	cout<<"|"<<endl; 
	cout<<"|";
	if(choose==2)
	{
		color(12);
	}
	cout<<"   抽奖小屋   ";   
	color(14);  
	cout<<"|"<<endl;
	cout<<"|";
	if(choose==3)
	{
		color(12);
	}
	cout<<"   调色游戏   ";   
	color(14);  
	cout<<"|"<<endl; 
	cout<<"|";
	if(choose==4)
	{
		color(12);
	}
	cout<<"   三点连线   ";   
	color(14);  
	cout<<"|"<<endl; 
	cout<<"|______________|"<<endl;
	if(choose==1)
	{
		cout<<"需要1000金币 "; 
	}
	else if(choose==2)
	{
		cout<<"每次100金币  "; 
	}
	else if(choose==3)
	{
		cout<<"需要1000金币 ";
	}
	else
	{
		cout<<"每次2000金币 ";
	}
	Sleep(100);
}
void hd()
{
	choose=1;
	system("cls");
	hdmenu();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(choose==1)
			{
				if(coin<1000)
				{
					::MessageBox(hwnd,"需要1000金币","金币不足",MB_ICONINFORMATION);
				}
				else
				{
					coin-=1000;
					cjf[9]++;
					hd_1();
				} 
			}
			else if(choose==2)
			{
				hd_2();
			}
			else if(choose==3)
			{
				if(coin<1000)
				{
					::MessageBox(hwnd,"需要1000金币","金币不足",MB_ICONINFORMATION);
				}
				else
				{
					coin-=1000;
					cjf[9]++;
					hd_3();
				} 
			}
			else
			{
				if(coin<2000)
				{
					::MessageBox(hwnd,"需要2000金币","金币不足",MB_ICONINFORMATION);
				}
				else
				{
					hd_4();
				} 
			}
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{ 
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home2();
			}	
		}
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：确认\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_UP)&&choose>1)
		{
			choose--;
			hdmenu();
		}
		if(GetAsyncKeyState(VK_DOWN)&&choose<4)
		{
			choose++;
			hdmenu();
		}
	}
}
void hd_1next(int x,int y)
{
	color(4);
	gotoxy(x*2,y);
	cout<<hd_1data[hd_1a[x][y]*2+hd_1flag[x][y]*10]<<hd_1data[hd_1a[x][y]*2+hd_1flag[x][y]*10+1];
}
void hd_1back(int x,int y)
{
	color(15);
	gotoxy(x*2,y);
	cout<<hd_1data[hd_1a[x][y]*2+hd_1flag[x][y]*10]<<hd_1data[hd_1a[x][y]*2+hd_1flag[x][y]*10+1];
}
void hd_1()
{
	system("cls");
	color(15);
	int x=0,y=0,ok=0,now=0;
	double time=20.0;
	for(int j=0;j<10;j++)
	{
		for(int i=0;i<10;i++)
		{
			hd_1flag[i][j]=0;
			hd_1a[i][j]=rand()%5;
			cout<<hd_1data[hd_1a[i][j]*2+hd_1flag[i][j]*10]<<hd_1data[hd_1a[i][j]*2+hd_1flag[i][j]*10+1];
		}
		cout<<endl;
	}
	cout<<"当前："<<hd_1data[now*2+10]<<hd_1data[now*2+11]<<endl;
	cout<<"已完成："<<ok<<"%    "<<endl;
	cout<<"剩余时间：20.0s"<<endl;
	cout<<"ready ";
	for(int i=0;i<100;i++)
	{
		Sleep(9);
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\nshift键：切换图形\n空格键：填充图形","说明",MB_ICONINFORMATION);
		} 
	}
	gotoxy(0,13);
	cout<<"go!   ";
	for(int i=0;i<100;i++)
	{
		Sleep(9);
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\nshift键：切换图形\n空格键：填充图形","说明",MB_ICONINFORMATION);
		} 
	}
	gotoxy(0,13);
	cout<<"      ";
	hd_1next(0,0);
	while(1)
	{
		Sleep(100);
		time-=0.1;
		gotoxy(0,12);
		if(time>5)
		{
			color(10);
		}
		else
		{
			color(4);
		}
		if(time<=0)
		{
			hd_1js(ok);
		}
		cout<<"剩余时间：";
		printf("%.1f",time);
		cout<<"s      ";
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\nshift键：切换图形\n空格键：填充图形","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_SHIFT))
		{
			now++;
			if(now>=5)
			{
				now=0;
			}
			color(15);
			gotoxy(0,10);
			cout<<"当前："<<hd_1data[now*2+10]<<hd_1data[now*2+11];
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(x>0)
			{
				hd_1back(x,y);
				x--;
				hd_1next(x,y);
			}
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(x<9)
			{
				hd_1back(x,y);
				x++;
				hd_1next(x,y);
			}
		}
		if(GetAsyncKeyState(VK_UP))
		{
			if(y>0)
			{
				hd_1back(x,y);
				y--;
				hd_1next(x,y);
			}
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(y<9)
			{
				hd_1back(x,y);
				y++;
				hd_1next(x,y);
			}
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(now==hd_1a[x][y])
			{
				ok++;
				hd_1flag[x][y]=1;
				hd_1next(x,y);
				color(15);
				gotoxy(0,11);
				cout<<"已完成："<<ok<<"%    ";
				if(ok>=100)
				{
					hd_1js(ok);
				}
			}
		}
	}
}
void hd_1js(int ok)
{
	system("cls");
	color(10);
	cout<<"完成"<<ok<<"%"<<endl;
	cout<<"奖励："<<endl;
	color(14);
	cout<<"●"<<cor()<<ok*20;
	coin+=ok*20;
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home2();
			}
		} 
	}
}
void hd_2()
{
	system("cls");
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			hd_2a[i][j]=rand()%5;
			color(hd_2color[hd_2a[i][j]]);
			cout<<hd_2data[hd_2a[i][j]*2]<<hd_2data[hd_2a[i][j]*2+1];
		}
		cout<<endl;
	}
	for(int i=0;i<5;i++)
	{
		gotoxy(21,i);
		color(hd_2color[i]);
		cout<<hd_2data[i*2]<<hd_2data[i*2+1]<<"："<<i*50<<"金币";
	}
	gotoxy(0,10);
	color(10);
	cout<<"100金币一次"; 
	gotoxy(0,11);
	color(14);
	cout<<"现有金币："<<coin;
	int x,y;	
	while(1)
	{
		x=rand()%10;
		y=rand()%10;
		gotoxy(x*2,y);
		color(576+hd_2color[hd_2a[y][x]]);
		cout<<hd_2data[hd_2a[y][x]*2]<<hd_2data[hd_2a[y][x]*2+1];
		Sleep(500);
		gotoxy(x*2,y);
		color(hd_2color[hd_2a[y][x]]);
		cout<<hd_2data[hd_2a[y][x]*2]<<hd_2data[hd_2a[y][x]*2+1];
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(coin<100)
			{
				::MessageBox(hwnd,"需要100金币","金币不足",MB_ICONINFORMATION);
			}
			else
			{
				coin-=100;
				gotoxy(0,11);
				color(14);
				cout<<"现有金币："<<coin;
				for(int i=0;i<20;i++)
				{
					x=rand()%10;
					y=rand()%10;
					gotoxy(x*2,y);
					color(576+hd_2color[hd_2a[y][x]]);
					cout<<hd_2data[hd_2a[y][x]*2]<<hd_2data[hd_2a[y][x]*2+1];
					Sleep(50);
					gotoxy(x*2,y);
					color(hd_2color[hd_2a[y][x]]);
					cout<<hd_2data[hd_2a[y][x]*2]<<hd_2data[hd_2a[y][x]*2+1];
				}	
				for(int i=0;i<10;i++)
				{
					gotoxy(x*2,y);
					color(576+hd_2color[hd_2a[y][x]]);
					cout<<hd_2data[hd_2a[y][x]*2]<<hd_2data[hd_2a[y][x]*2+1];
					Sleep(100);
					gotoxy(x*2,y);
					color(hd_2color[hd_2a[y][x]]);
					cout<<hd_2data[hd_2a[y][x]*2]<<hd_2data[hd_2a[y][x]*2+1];
					Sleep(100);
				}
				coin+=hd_2a[y][x]*50;
				gotoxy(0,11);
				color(14);
				cout<<"现有金币："<<coin;
			}
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{ 
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home2();
			}
		}
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"空格键：抽奖\nesc键：退出","说明",MB_ICONINFORMATION);
		}
	}
}
void hd_3next(int casee)
{
	gotoxy(0,4);
	rgb_set(nowrgb[0],nowrgb[1],nowrgb[2]);
	cout<<"        "<<endl<<"        "<<endl;
	if(casee==1) color(4);
	else color(15);
	cout<<"红 <"<<nowrgb[0]<<">   "<<endl;
	if(casee==2) color(4);
	else color(15);
	cout<<"绿 <"<<nowrgb[1]<<">   "<<endl;
	if(casee==3) color(4);
	else color(15);
	cout<<"蓝 <"<<nowrgb[2]<<">   "<<endl;
}
void hd_3()
{
	system("cls");
	srand((unsigned)time(NULL));
	for(int i=0;i<3;i++)
	{
		hd_3rgb[i]=rand()%255+1;
		nowrgb[i]=0;
	}
	color(10);
	cout<<"目标颜色："<<endl; 
	rgb_set(hd_3rgb[0],hd_3rgb[1],hd_3rgb[2]);
	cout<<"        "<<endl<<"        "<<endl;
	color(10);
	cout<<"现在颜色："<<endl;
	int casee=1;
	hd_3next(casee);
	double time=30;
	color(10);
	cout<<"剩余时间：30.00s"<<endl;
	cout<<"ready ";
	for(int i=0;i<100;i++)
	{
		Sleep(9);
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\nshift键：切换图形\n空格键：填充图形","说明",MB_ICONINFORMATION);
		} 
	}
	gotoxy(0,10);
	cout<<"go!   ";
	for(int i=0;i<100;i++)
	{
		Sleep(9);
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\nshift键：切换图形\n空格键：填充图形","说明",MB_ICONINFORMATION);
		} 
	}
	gotoxy(0,10);
	cout<<"      ";
	while(1)
	{
		Sleep(50);
		time-=0.05;
		gotoxy(0,9);
		if(time>5)
		{
			color(10);
		}
		else
		{
			color(4);
		}
		if(time<=0)
		{
			hd_3js();
		}
		cout<<"剩余时间：";
		printf("%.2f",time);
		cout<<"s     ";
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n左移键：减少\n右移键：增加","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(nowrgb[casee-1]>0)
			{
				nowrgb[casee-1]--;
				hd_3next(casee);
			}
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(nowrgb[casee-1]<255)
			{
				nowrgb[casee-1]++;
				hd_3next(casee);
			}
		}
		if(GetAsyncKeyState(VK_UP))
		{
			if(casee>1)
			{
				casee--;
				hd_3next(casee);
			}
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(casee<3)
			{
				casee++;
				hd_3next(casee);
			}
		}
	}
}
void hd_3js()
{
	system("cls");
	color(10);
	cout<<"目标颜色："<<endl; 
	rgb_set(hd_3rgb[0],hd_3rgb[1],hd_3rgb[2]);
	cout<<"        "<<endl<<"        "<<endl;
	color(15);
	cout<<"红 "<<hd_3rgb[0]<<"   "<<endl;
	cout<<"绿 "<<hd_3rgb[1]<<"   "<<endl;
	cout<<"蓝 "<<hd_3rgb[2]<<"   "<<endl;
	color(10);
	cout<<"现在颜色："<<endl;
	rgb_set(nowrgb[0],nowrgb[1],nowrgb[2]);
	cout<<"        "<<endl<<"        "<<endl;
	color(15);
	cout<<"红 "<<nowrgb[0]<<"   "<<endl;
	cout<<"绿 "<<nowrgb[1]<<"   "<<endl;
	cout<<"蓝 "<<nowrgb[2]<<"   "<<endl;
	int wc=0;
	for(int i=0;i<3;i++)
	{
		wc+=abs(nowrgb[i]-hd_3rgb[i]);
	}
	color(10);
	cout<<"总误差："<<wc<<endl;
	color(14);
	cout<<"获得金币："<<2000-wc*6;
	if(2000-wc*6>0)
	{
		coin+=2000-wc*6;
	}
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home2();
			}
		} 
	}
}
void hd_4()
{
	color(15);
	system("cls");
	int jl[3];
	color(15);
	for(int i=0;i<3;i++)
	{
		cout<<"●  "<<cor();
	}
	gotoxy(0,2);
	color(14);
	cout<<"现有金币："<<coin;
	del();
	Sleep(300);
	while(1)
	{
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(coin<2000)
			{
				::MessageBox(hwnd,"需要2000金币","金币不足",MB_ICONINFORMATION);
			}
			else
			{
				coin-=2000;
				gotoxy(0,2);
				color(14);
				cout<<"现有金币："<<coin;
				for(int i=0;i<3;i++)
				{
					Sleep(800);
					jl[i]=rand()%3;
					gotoxy(i*4,0);
					if(jl[i]==0)
					{
						color(4);
					}
					else if(jl[i]==1)
					{
						color(10);
					}
					else
					{
						color(9);
					}
					cout<<"●  "<<cor();
				}
				Sleep(800);
				gotoxy(0,2);
				color(0);
				cout<<"                      ";
				if(jl[0]!=jl[1]&&jl[1]!=jl[2]&&jl[0]!=jl[2])
				{
					gotoxy(0,1);
					color(14);
					cout<<"一等奖"<<endl;
					color(14);
					cout<<"●"<<cor()<<"1500"<<endl;
					color(10);
					cout<<"LV 30%"<<endl;
					color(235);
					cout<<"券";
					color(14);
					cout<<"6"<<endl;
					coin+=1500;
					exp1+=30;
					lv+=exp1/100;
					exp1=exp1%100;
					dhq+=6;
				}
				else if(jl[0]==jl[1]&&jl[1]==jl[2])
				{
					gotoxy(0,1);
					color(14);
					cout<<"二等奖"<<endl;
					color(14);
					cout<<"●"<<cor()<<"1000"<<endl;
					color(10);
					cout<<"LV 20%"<<endl;
					color(235);
					cout<<"券";
					color(14);
					cout<<"4"<<endl;
					coin+=1000;
					exp1+=20;
					lv+=exp1/100;
					exp1=exp1%100;
					dhq+=4;
				}
				else
				{
					gotoxy(0,1);
					color(14);
					cout<<"三等奖"<<endl;
					color(14);
					cout<<"●"<<cor()<<"500"<<endl;
					color(10);
					cout<<"LV 10%"<<endl;
					color(235);
					cout<<"券";
					color(14);
					cout<<"2"<<endl;
					coin+=500;
					exp1+=10;
					lv+=exp1/100;
					exp1=exp1%100;
					dhq+=2;
				}
				Sleep(1000);
				hd_4();
			}
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{ 
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home2();
			}
		}
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"空格键：开启\nesc键：退出","说明",MB_ICONINFORMATION);
		}
	} 
}
void ysmenu()
{
	system("cls");
	color(13);
	cout<<"     药水"<<endl; 
	color(116);
	cout<<"█";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"█";
	color(15);
	cout<<" 力量药水："<<ys[0]<<endl;
	color(120);
	cout<<"█";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"█";
	color(15);
	cout<<" 防御药水："<<ys[1]<<endl;
	color(122);
	cout<<"█";
	if(cor1==1) cout<<" ";
	else if(cor1==2) cout<<"█";
	color(15);
	cout<<" 敏捷药水："<<ys[2]<<endl;
	color(4);
	cout<<"   炼制药水";
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"空格键：炼制药水\ntab键：强化\nesc键：退出","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home3();
			}
		} 
		if(GetAsyncKeyState(VK_SPACE))
		{
			ysc();
		} 
		if(GetAsyncKeyState(VK_TAB))
		{ 
			qh();
		}
	}
}
void yscmenu(int casee)
{
	gotoxy(0,0);
	color(11);
	cout<<"选择原料"<<endl;
	color(4);
	cout<<"●"<<cor();
	if(casee==1)
	{
		color(4);
	}
	else
	{
		color(15);
	}
	cout<<"红色炼药石"<<endl;
	color(8);
	cout<<"●"<<cor();
	if(casee==2)
	{
		color(4);
	}
	else
	{
		color(15);
	}
	cout<<"灰色炼药石"<<endl;
	color(10);
	cout<<"●"<<cor();
	if(casee==3)
	{
		color(4);
	}
	else
	{
		color(15);
	}
	cout<<"绿色炼药石"<<endl;
	color(14);
	cout<<"需要金币：1000"<<endl;
	cout<<"现有金币："<<coin; 
}
void ysc()
{
	system("cls");
	yscmenu(1);
	Sleep(100);
	int casee=1;
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：开始炼药\nesc键：退出","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			ysmenu();
		} 
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(coin>=1000)
			{
				coin-=1000;
				yslz(casee);
			}
			else
			{
				::MessageBox(hwnd,"需要1000金币","金币不足",0);
			}
		} 
		if(GetAsyncKeyState(VK_UP))
		{
			if(casee>1)
			{
				casee--;
			}
			yscmenu(casee);
			Sleep(100);
		} 
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(casee<3)
			{
				casee++;
			}
			yscmenu(casee);
			Sleep(100);
		} 
	}
}
void ysdh(int di)
{
	gotoxy(0,0);
	color(121);
	cout<<gdata[16-di*2]<<gdata[17-di*2];
	if(16-di*2!=0)
	{
		cout<<" ";
	}
	color(9);
	cout<<"    "<<endl;
	if(di!=8)
	{
		cout<<"  ▏ "<<endl;
	}
	else
	{
		cout<<"     "<<endl;
	}
	cout<<"  ";
	color(121);
	cout<<gdata[di*2]<<gdata[di*2+1]<<gdata[di*2]<<gdata[di*2+1];
	color(9);
	cout<<"  ";
}
void ysdh2(int di)
{
	gotoxy(0,0);
	color(125);
	cout<<gdata[16-di*2]<<gdata[17-di*2];
	if(16-di*2!=0)
	{
		cout<<" ";
	}
	color(13);
	cout<<"    "<<endl;
	if(di!=8)
	{
		cout<<"  ▏ "<<endl;
	}
	else
	{
		cout<<"     "<<endl;
	}
}
void yslz(int casee)
{
	system("cls");
	ysdh(0);
	for(int i=1;i<=8;i++)
	{
		ysdh(i);
		Sleep(200);
	}
	system("cls");
	color(121);
	gotoxy(2,2);
	cout<<"█ ";
	Sleep(1000);
	gotoxy(2,0);
	color(yscolor[casee-1]);
	cout<<"●"<<cor();
	Sleep(200);
	gotoxy(2,0);
	color(0);
	cout<<"  ";
	gotoxy(2,1);
	color(yscolor[casee-1]);
	cout<<"●"<<cor();
	Sleep(200);
	gotoxy(2,1);
	color(0);
	cout<<"  ";
	Sleep(1000);
	for(int i=1;i<=8;i++)
	{
		ysdh2(i);
		Sleep(200);
	}
	system("cls");
	color(121);
	gotoxy(2,2);
	cout<<"█ ";
	Sleep(1000);
	if(rand()%10<9)
	{
		color(112+yscolor[casee-1]);
		gotoxy(2,2);
		cout<<"█ ";
		Sleep(1000);
		color(10);
		system("cls");
		cout<<"炼制成功！"<<endl;
		cout<<"获得："; 
		color(112+yscolor[casee-1]);
		cout<<"█ ";
		color(yscolor[casee-1]);
		cout<<" ";
		if(casee==1)
		{
			cout<<"力量药水"; 
		}
		else if(casee==2)
		{
			cout<<"防御药水"; 
		}
		else
		{
			cout<<"敏捷药水"; 
		}
		ys[casee-1]++;
		cjf[7]++;
	}
	else
	{
		color(112);
		gotoxy(2,2);
		cout<<"  ";
		Sleep(1000);
		color(4);
		system("cls");
		cout<<"炼制失败！"<<endl;
	} 
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			ysmenu();
		} 
	}
}
void dhshop()
{
	system("cls");
	color(13);
	cout<<"  兑换"<<endl;
	cout<<endl<<endl;
	color(235);
	cout<<"券";
	color(15);
	cout<<"1 -> 材料礼包（所有材料各1个）"<<endl;
	color(235);
	cout<<"券";
	color(15);
	cout<<"1 -> 战斗礼包（攻防碎片各5个）"<<endl;
	color(235);
	cout<<"券";
	color(15);
	cout<<"1 -> 矿石礼包（所有矿石各1个）"<<endl;
	color(235);
	cout<<"券";
	color(15);
	cout<<"1 -> 水晶礼包（含战斗水晶2个）"<<endl;
	color(235);
	cout<<"券";
	color(15);
	cout<<"1 -> 星星礼包（  含星星1个  ）"<<endl;
	int casee=1;
	dhmenu(casee);
	while(1)
	{
		Sleep(300);
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：兑换\nesc键：退出","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home4();
			}
		} 
		if(GetAsyncKeyState(VK_UP))
		{
			if(casee>1)
			{
				casee--;
			}
			dhmenu(casee);
		} 
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(casee<5)
			{
				casee++;
			}
			dhmenu(casee);
		} 
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(dhq>0)
			{
				dhq--;
				if(casee==1)
				{
					for(int i=1;i<=15;i++)
					{
						jj[i]++;
					}
				}
				else if(casee==2)
				{
					attack+=5;
					defense+=5; 
				}
				else if(casee==3)
				{
					lc+=1;
					lir+=1;
					ld+=1;
					lgo+=1;
					lr+=1;
					lb+=1;
					lgr+=1;
					lp+=1;
				}
				else if(casee==4)
				{
					sj+=2; 
				} 
				else if(casee==5)
				{
					star++; 
				} 
			}	
			dhmenu(casee);
		} 
	}
}
void dhmenu(int casee)
{
	gotoxy(0,1);
	color(235);
	cout<<"券";
	color(15);
	cout<<dhq<<"   "<<endl;
	for(int i=2;i<=6;i++)
	{
		gotoxy(32,i+1);
		if(casee==i-1)
		{
			color(10);
		}
		else
		{
			color(15);
		}
		cout<<"兑换";
	}
}
void nhome1()
{
	error();
	system("cls");
	color(14);
	cout<<"●"<<cor()<<coin<<"   ";
	color(10);
	cout<<"LV"<<lv<<"  "<<exp1<<"%  ";
	color(10);
	cout<<"矿区 "<<endl;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<8;j++)
		{
			color(home_1[i][j]*16);
			cout<<chome_1[i][j*2]<<chome_1[i][j*2+1];
		}
		cout<<endl;
	}
	gotoxy(mx*2,my+1);
	color(home_1[my][mx]*16+ccolor);
	cout<<"●"<<cor();
	del();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\n空格键：进入\nesc键：保存并退出游戏","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_LEFT))
		{
			gotoxy(mx*2,my+1);
			color(home_1[my][mx]*16);
			cout<<chome_1[my][mx*2]<<chome_1[my][mx*2+1];
			if(mx>0) mx--;
			gotoxy(mx*2,my+1);
			color(home_1[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			gotoxy(mx*2,my+1);
			color(home_1[my][mx]*16);
			cout<<chome_1[my][mx*2]<<chome_1[my][mx*2+1];
			if(mx<7) mx++;
			gotoxy(mx*2,my+1);
			color(home_1[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			gotoxy(mx*2,my+1);
			color(home_1[my][mx]*16);
			cout<<chome_1[my][mx*2]<<chome_1[my][mx*2+1];
			if(my<5) my++;
			gotoxy(mx*2,my+1);
			color(home_1[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_UP))
		{
			gotoxy(mx*2,my+1);
			color(home_1[my][mx]*16);
			cout<<chome_1[my][mx*2]<<chome_1[my][mx*2+1];
			if(my>0) my--;
			gotoxy(mx*2,my+1);
			color(home_1[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(::MessageBox(hwnd,"是否保存并退出游戏？","",4)==6) aexit();
			else continue;
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			color(0);
			if(mx==0)
			{
				ac();
				system("cls");
				wx=0;
				wy=mapsize/2;
				if(choose==1)
				{
					new1=0;
					make();
				} 
				else if(choose==2&&new1==1)
				{
					new1=0;
				}
				system("cls");
				od=true;
				size=5;
				outmap();
				move();
				}
			else if(my==0&&(mx==2||mx==3||mx==4))
			{	
				shop();
			}
			else if((mx==6||mx==7)&&(my==2||my==3))
			{
				mx=0;
				nhome2();
			}
		}
	}
}
void nhome2()
{
	error();
	system("cls");
	color(14);
	cout<<"●"<<cor()<<coin<<"   ";
	color(10);
	cout<<"LV"<<lv<<"  "<<exp1<<"%  ";
	color(11);
	cout<<"城区 "<<endl;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<15;j++)
		{
			color(home_2[i][j]*16);
			cout<<chome_2[i][j*2]<<chome_2[i][j*2+1];
		}
		cout<<endl;
	}
	gotoxy(mx*2,my+1);
	color(home_2[my][mx]*16+ccolor);
	cout<<"●"<<cor();
	del();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\n空格键：进入\nesc键：保存并退出游戏\ntab键：游戏设置\nenter键：成就","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_LEFT))
		{
			gotoxy(mx*2,my+1);
			color(home_2[my][mx]*16);
			cout<<chome_2[my][mx*2]<<chome_2[my][mx*2+1];
			if(mx>0) mx--;
			gotoxy(mx*2,my+1);
			color(home_2[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			gotoxy(mx*2,my+1);
			color(home_2[my][mx]*16);
			cout<<chome_2[my][mx*2]<<chome_2[my][mx*2+1];
			if(mx<14) mx++;
			gotoxy(mx*2,my+1);
			color(home_2[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			gotoxy(mx*2,my+1);
			color(home_2[my][mx]*16);
			cout<<chome_2[my][mx*2]<<chome_2[my][mx*2+1];
			if(my<5) my++;
			gotoxy(mx*2,my+1);
			color(home_2[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_UP))
		{
			gotoxy(mx*2,my+1);
			color(home_2[my][mx]*16);
			cout<<chome_2[my][mx*2]<<chome_2[my][mx*2+1];
			if(my>0) my--;
			gotoxy(mx*2,my+1);
			color(home_2[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(::MessageBox(hwnd,"是否保存并退出游戏？","",4)==6) aexit();
			else continue;
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			color(0);
			sett();	
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			color(0);
			cj();
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			color(0);
			if((mx==0||mx==1)&&(my==2||my==3))
			{
				mx=7;
				nhome1();
			}
			if((mx==13||mx==14)&&(my==2||my==3))
			{
				mx=0;
				nhome3();
			}
			else if((mx==0||mx==1)&&(my==0||my==1))
			{
				cang();
			}
			else if(mx==3&&(my==4||my==5))
			{
				if(lv>=50)
				{
					book();
				}
				else
				{
					::MessageBox(hwnd,"等级到达50级后解锁“书库”","等级不足",MB_ICONINFORMATION);
				}
			}
			else if((mx==0||mx==1)&&(my==4||my==5))
			{
				if(lv>=20)
				{
					hd();
				}
				else
				{
					::MessageBox(hwnd,"等级到达20级后解锁“活动”","等级不足",MB_ICONINFORMATION);
				}
			}
			else if((mx==4||mx==5||mx==6)&&(my==0||my==1))
			{
				if(lv>=5)
				{
					int f=1;
					system("cls");
					color(11);
					gotoxy(72,0);
					cout<<"< 1 >"<<endl;
					gotoxy(0,0);
					jmapout(f-1);
					for(;;)
					{
						if(GetAsyncKeyState(VK_ESCAPE))
						{ 
							if(hometype==1)
							{
								nhome2();
							}
							else
							{
								home2();
							}	
						}
						if(GetAsyncKeyState(VK_CONTROL))
						{ 
							::MessageBox(hwnd,"左移键：上一个\n右移键：下一个\n空格键：确认\nesc键：退出","说明",MB_ICONINFORMATION);
						}
						if(GetAsyncKeyState(VK_LEFT))
						{
							if(f>1)
							{
								f--;
								gotoxy(74,0);
								color(11);
								cout<<f;
								gotoxy(0,0);
								jmapout(f-1);					
							}	
							Sleep(50);
						}
						if(GetAsyncKeyState(VK_RIGHT))
						{
							if(f<6)
							{
								f++;
								gotoxy(74,0);
								color(11);
								cout<<f;
								gotoxy(0,0);
								jmapout(f-1);
							}	
							Sleep(50);	
						}
						if(GetAsyncKeyState(VK_SPACE))
						{
							break;	
						}
					}
					jhome(f-1);
				}
				else
				{
					::MessageBox(hwnd,"等级到达5级后解锁“建造”","等级不足",MB_ICONINFORMATION);
				}
			}
			else if((mx==9||mx==10)&&(my==0||my==1))
			{
				if(lv>=15)
				{
					garden();
				}
				else
				{
					::MessageBox(hwnd,"等级到达15级后解锁“花园”","等级不足",MB_ICONINFORMATION);
				}
			}
			else if((mx==13||mx==14)&&(my==0||my==1))
			{
				if(lv>=5)
				{
					zb();
				}
				else
				{
					::MessageBox(hwnd,"等级到达5级后解锁“装备”","等级不足",MB_ICONINFORMATION);
				}
			}
			else if((mx==6||mx==7)&&(my==4||my==5))
			{
				if(lv>=5)
				{
					jshop();
				}
				else
				{
					::MessageBox(hwnd,"等级到达5级后解锁“材料”","等级不足",MB_ICONINFORMATION);
				}
			}
			else if((mx==11||mx==12)&&(my==4||my==5))
			{
				if(lv>=5)
				{
					bx();
				}
				else
				{
					::MessageBox(hwnd,"等级到达5级后解锁“宝箱”","等级不足",MB_ICONINFORMATION);
				}
			}
			else if(mx==14&&(my==4||my==5))
			{
				if(lv>=20)
				{
					Sleep(100);
					dhshop();
				}
				else
				{
					::MessageBox(hwnd,"等级到达20级后解锁“兑换”","等级不足",MB_ICONINFORMATION);
				}
			}
		}
	}
}
void nhome3()
{
	error();
	system("cls");
	color(14);
	cout<<"●"<<cor()<<coin<<"   ";
	color(10);
	cout<<"LV"<<lv<<"  "<<exp1<<"%  ";
	color(11);
	cout<<"郊区 "<<endl;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<8;j++)
		{
			color(home_3[i][j]*16);
			cout<<chome_3[i][j*2]<<chome_3[i][j*2+1];
		}
		cout<<endl;
	}
	gotoxy(mx*2,my+1);
	color(home_3[my][mx]*16+ccolor);
	cout<<"●"<<cor();
	del();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\n空格键：进入\nesc键：保存并退出游戏\ntab键：游戏设置\nenter键：成就","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_LEFT))
		{
			gotoxy(mx*2,my+1);
			color(home_3[my][mx]*16);
			cout<<chome_3[my][mx*2]<<chome_3[my][mx*2+1];
			if(mx>0) mx--;
			gotoxy(mx*2,my+1);
			color(home_3[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			gotoxy(mx*2,my+1);
			color(home_3[my][mx]*16);
			cout<<chome_3[my][mx*2]<<chome_3[my][mx*2+1];
			if(mx<7) mx++;
			gotoxy(mx*2,my+1);
			color(home_3[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			gotoxy(mx*2,my+1);
			color(home_3[my][mx]*16);
			cout<<chome_3[my][mx*2]<<chome_3[my][mx*2+1];
			if(my<5) my++;
			gotoxy(mx*2,my+1);
			color(home_3[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_UP))
		{
			gotoxy(mx*2,my+1);
			color(home_3[my][mx]*16);
			cout<<chome_3[my][mx*2]<<chome_3[my][mx*2+1];
			if(my>0) my--;
			gotoxy(mx*2,my+1);
			color(home_3[my][mx]*16+ccolor);
			cout<<"●"<<cor();
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(::MessageBox(hwnd,"是否保存并退出游戏？","",4)==6) aexit();
			else continue;
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			color(0);
			if((mx==0||mx==1)&&(my==2||my==3))
			{
				mx=14;
				nhome2();
			}
			else if((mx==2||mx==3||mx==4)&&my==0)
			{
				if(lv>=5)
				{
					zd();
				}
				else
				{
					::MessageBox(hwnd,"等级到达5级后解锁“战斗”","等级不足",MB_ICONINFORMATION);
				}
			}
			else if((mx==6||mx==7)&&(my==2||my==3))
			{
				if(lv>=10)
				{
					tanx();
				}
				else
				{
					::MessageBox(hwnd,"等级到达10级后解锁“探险”","等级不足",MB_ICONINFORMATION);
				}
			}
		}
	}
}
void home()
{
	error();
	size=5;
	system("cls");
	bool tt=1;
	color(14);
	cout<<"●"<<cor()<<coin<<"   ";
	color(10);
	cout<<"LV"<<lv<<"  "<<exp1<<"%   "<<endl;
	color(14);
	cout<<"     商店"<<endl;
	cout<<"      ↑"<<cor()<<endl; 
	cout<<"挖矿←"<<cor()<<"●"<<cor()<<"→"<<cor()<<"退出"<<endl;
	cout<<"      ↓"<<cor()<<endl; 
	cout<<"     仓库"<<endl;
	color(14);
	cout<<"   ●"<<cor();
	color(15);
	cout<<"○"<<cor()<<"○"<<cor()<<"○"<<cor(); 
	del();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：进入商店\n下移键：进入仓库\n左移键：开始挖矿\n右移键：保存并退出游戏\nshift键：下一页\ntab键：上一页","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_SHIFT))
		{
			Sleep(100);
			home2();
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			Sleep(100);
			home4();
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			ac();
			system("cls");
			wx=0;
			wy=mapsize/2;
			if(choose==1)
			{
				new1=0;
				make();
			} 
			else if(choose==2&&new1==1)
			{
				new1=0;
			}
			system("cls");
			od=true;
			size=5;
			outmap();
			move();
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			aexit();
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			cang();
		}
		if(GetAsyncKeyState(VK_UP))
		{
			shop();
		}
	}
}
void home2()
{
	error();
	system("cls");
	color(14);
	cout<<"●"<<cor()<<coin<<"   ";
	color(10);
	cout<<"LV"<<lv<<"  "<<exp1<<"%   "<<endl;
	color(11);
	cout<<"     活动"<<endl;
	cout<<"      ↑"<<cor()<<endl; 
	cout<<"建造←"<<cor()<<"●"<<cor()<<"→"<<cor()<<"花园"<<endl;
	cout<<"      ↓" <<cor()<<endl; 
	cout<<"     材料"<<endl;
	color(15);
	cout<<"   ○"<<cor();
	color(11);
	cout<<"●"<<cor();
	color(15);
	cout<<"○"<<cor()<<"○"<<cor();
	del();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：游戏设置\n下移键：材料商店\n左移键：建造\n右移键：进入花园\nshift键：下一页\ntab键：上一页","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_SHIFT))
		{
			Sleep(100);
			home3();
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			Sleep(100);
			home();
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(lv>=5)
			{
				int f=1;
				system("cls");
				color(11);
				gotoxy(72,0);
				cout<<"< 1 >"<<endl;
				gotoxy(0,0);
				jmapout(f-1);
				for(;;)
				{
					if(GetAsyncKeyState(VK_ESCAPE))
					{ 
						home2();
					}
					if(GetAsyncKeyState(VK_CONTROL))
					{ 
						::MessageBox(hwnd,"左移键：上一个\n右移键：下一个\n空格键：确认\nesc键：退出","说明",MB_ICONINFORMATION);
					}
					if(GetAsyncKeyState(VK_LEFT))
					{
						if(f>1)
						{
							f--;
							gotoxy(74,0);
							color(11);
							cout<<f;
							gotoxy(0,0);
							jmapout(f-1);					
						}	
						Sleep(50);
					}
					if(GetAsyncKeyState(VK_RIGHT))
					{
						if(f<6)
						{
							f++;
							gotoxy(74,0);
							color(11);
							cout<<f;
							gotoxy(0,0);
							jmapout(f-1);
						}	
						Sleep(50);	
					}
					if(GetAsyncKeyState(VK_SPACE))
					{
						break;	
					}
				}
				jhome(f-1);
			}
			else
			{
				::MessageBox(hwnd,"等级到达5级后解锁“建造”","等级不足",MB_ICONINFORMATION);
			}
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(lv>=15)
			{
				garden();
			}
			else
			{
				::MessageBox(hwnd,"等级到达15级后解锁“花园”","等级不足",MB_ICONINFORMATION);
			}
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(lv>=5)
			{
				jshop();
			}
			else
			{
				::MessageBox(hwnd,"等级到达5级后解锁“材料”","等级不足",MB_ICONINFORMATION);
			}
		}
		if(GetAsyncKeyState(VK_UP))
		{
			if(lv>=20)
			{
				hd();
			}
			else
			{
				::MessageBox(hwnd,"等级到达20级后解锁“活动”","等级不足",MB_ICONINFORMATION);
			}
		}
	}
}
void home3()
{
	error();
	system("cls");
	color(14);
	cout<<"●"<<cor()<<coin<<"   ";
	color(10);
	cout<<"LV"<<lv<<"  "<<exp1<<"%   "<<endl;
	color(13);
	cout<<"     装备"<<endl;
	cout<<"      ↑"<<cor()<<endl; 
	cout<<"战斗←"<<cor()<<"●"<<cor()<<"→"<<cor()<<"探险"<<endl;
	cout<<"      ↓"<<cor()<<endl; 
	cout<<"     宝箱"<<endl;
	color(15);
	cout<<"   ○"<<cor()<<"○"<<cor();
	color(13);
	cout<<"●"<<cor();
	color(15);
	cout<<"○"<<cor();
	del();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：装备\n下移键：宝箱\n左移键：开始战斗\n右移键：探险\nshift键：下一页\ntab键：上一页","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_SHIFT))
		{
			Sleep(100);
			home4();
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			Sleep(100);
			home2();
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(lv>=5)
			{
				zd();
			}
			else
			{
				::MessageBox(hwnd,"等级到达5级后解锁“战斗”","等级不足",MB_ICONINFORMATION);
			}
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(lv>=10)
			{
				tanx();
			}
			else
			{
				::MessageBox(hwnd,"等级到达10级后解锁“探险”","等级不足",MB_ICONINFORMATION);
			}
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(lv>=5)
			{
				bx();
			}
			else
			{
				::MessageBox(hwnd,"等级到达5级后解锁“宝箱”","等级不足",MB_ICONINFORMATION);
			}
		}
		if(GetAsyncKeyState(VK_UP))
		{
			if(lv>=5)
			{
				zb();
			}
			else
			{
				::MessageBox(hwnd,"等级到达5级后解锁“装备”","等级不足",MB_ICONINFORMATION);
			}
		}
	}
}
void home4()
{
	error();
	system("cls");
	color(14);
	cout<<"●"<<cor()<<coin<<"   ";
	color(10);
	cout<<"LV"<<lv<<"  "<<exp1<<"%   "<<endl;
	color(4);
	cout<<"     书库"<<endl;
	cout<<"      ↑"<<cor()<<endl; 
	cout<<"设置←"<<cor()<<"●"<<cor()<<"→"<<cor()<<"兑换"<<endl;
	cout<<"      ↓"<<cor() <<endl; 
	cout<<"     成就"<<endl;
	color(15);
	cout<<"   ○"<<cor()<<"○"<<cor()<<"○"<<cor();
	color(4);
	cout<<"●"<<cor();
	del();
	Sleep(100);
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{
			::MessageBox(hwnd,"上移键：书库\n下移键：成就\n左移键：设置\n右移键：兑换\nshift键：下一页\ntab键：上一页","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_SHIFT))
		{
			Sleep(100);
			home();
		}
		if(GetAsyncKeyState(VK_TAB))
		{
			Sleep(100);
			home3();
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			sett();	
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(lv>=20)
			{
				dhshop();
			}
			else
			{
				::MessageBox(hwnd,"等级到达20级后解锁“兑换”","等级不足",MB_ICONINFORMATION);
			}
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			cj();
		}
		if(GetAsyncKeyState(VK_SPACE)&&GetAsyncKeyState(VK_RETURN))
		{
			cd();
		}
		if(GetAsyncKeyState(VK_UP))
		{
			if(lv>=50)
			{
				book();
			}
			else
			{
				::MessageBox(hwnd,"等级到达50级后解锁“书库”","等级不足",MB_ICONINFORMATION);
			}
		}
	}
}
void zb()
{
	qh();
}
void tx_mapout()
{
	int see=5;
	gotoxy(23,3);
	color(15);
	if(tx_type!=4)
	{						
		cout<<"时间："<<t_h<<"时"<<t_m<<"分（"; 
		if(t_h>4)
		{
			if(t_h>7)
			{
				if(t_h>10)
				{
					if(t_h>12)
					{
						if(t_h>16)
						{
							if(t_h>19)
							{
								cout<<"夜晚";
								see=3;
							}
							else
							{
								cout<<"傍晚";	
								see=4;
							}
						}
						else
						{
							cout<<"下午";
							see=5;
						}
					}
					else
					{
						cout<<"中午";
						see=5;
					}
				}
				else
				{
					cout<<"上午";
					see=5;
				}
			}
			else
			{
				cout<<"早晨";
				see=4;
			}
		}
		else
		{
			cout<<"夜晚";
			see=3;
		}
		cout<<"）   "; 
	}
	else
	{
		cout<<"??时"<<"??分              ";
		see=5; 
	}
	gotoxy(0,0);
	for(int i=tx_x-5;i<=tx_x+5;i++)
	{
		for(int j=tx_y-5;j<=tx_y+5;j++)
		{
			if((see==4)&&(i==tx_x-5||i==tx_x+5||j==tx_y-5||j==tx_y+5))
			{
				color(96);
				cout<<"  ";
			}
			else if((see==3)&&(i==tx_x-5||i==tx_x+5||j==tx_y-5||j==tx_y+5||i==tx_x-4||i==tx_x+4||j==tx_y-4||j==tx_y+4))
			{
				color(0);
				cout<<"  ";
			}
			else if(i==tx_x&&j==tx_y)
			{
				if(tx_map[tx_y][tx_x]==0)
				{
					if(tx_type==1)
					{
						color(160+ccolor);
					}
					else if(tx_type==2)
					{
						color(240+ccolor);
					}
					else if(tx_type==3)
					{
						color(224+ccolor);
					}
					else if(tx_type==4)
					{
						color(208+ccolor);
					}
				}
				cout<<"●"<<cor();
			}
			else if(j<0||i<0||j>100||i>100)
			{
				if(see==4)
				{
					color(96);
				}
				else
				{
					color(0);
				}
				cout<<"  ";
			}
			else if(tx_map[j][i]==0)
			{
				if(tx_type==1)
				{
					color(160);
				}
				else if(tx_type==2)
				{
					color(240);
				}
				else if(tx_type==3)
				{
					color(224);
				}
				else if(tx_type==4)
				{
					color(208);
				}
				cout<<"  ";
			}
			else if(tx_map[j][i]==6)
			{
				if(tx_type==1) 
				{
					color(128);
				}
				else if(tx_type==2)
				{
					color(176);
				}
				cout<<"  ";
			}
			else if(tx_map[j][i]==1)
			{
				if(tx_type==1) 
				{
					color(166);
				}
				else if(tx_type==2)
				{
					color(246);
				}
				else if(tx_type==3)
				{
					color(230);
				}
				else if(tx_type==4)
				{
					color(214);
				}
				cout<<"■"<<cor();
			}
			else if(tx_map[j][i]==2)
			{
				if(tx_type==1) 
				{
					color(171);
				}
				else if(tx_type==2)
				{
					color(251);
				}
				else if(tx_type==3)
				{
					color(235);
				}
				else if(tx_type==4)
				{
					color(219);
				}
				cout<<"■"<<cor();
			}
			else if(tx_map[j][i]==3)
			{
				if(tx_type==1) 
				{
					color(167);
				}
				else if(tx_type==2)
				{
					color(247);
				}
				else if(tx_type==3)
				{
					color(231);
				}
				cout<<"▲"<<cor();
			}
			else if(tx_map[j][i]==4)
			{
				if(tx_type==1) 
				{
					color(173);
				}
				else if(tx_type==2)
				{
					color(253);
				}
				else if(tx_type==3)
				{
					color(237);
				}
				else if(tx_type==4)
				{
					color(208);
				}
				cout<<"◆"<<cor();
			}
			else if(tx_map[j][i]==5)
			{
				if(tx_type==1) 
				{
					color(16);
				}
				cout<<"  ";
			}
			else if(tx_map[j][i]==7)
			{
				if(tx_type==1) 
				{
					color(172);
				}
				else if(tx_type==2)
				{
					color(252);
				}
				else if(tx_type==3)
				{
					color(236);
				}
				cout<<"■"<<cor();
			} 
		}
		color(0);
		cout<<"█"<<endl;
	}
	color(15);
	if(GetAsyncKeyState(VK_F3))cout<<"debug: x:"<<tx_x<<" y:"<<tx_y<<" count:"<<co<<"         ";
	else  cout<<"                                 ";
	gotoxy(23,0);
	color(12);
	cout<<"健康值："<<health<<"/1000    "; 
	gotoxy(23,1);
	color(6);
	cout<<"饥饿值："<<hunger<<"/1000    "; 
	gotoxy(23,2);
	color(9);
	cout<<"口渴值："<<thirst<<"/1000    "; 
	gotoxy(23,4);
	color(15);
	cout<<"地图类型："; 
	if(tx_type==1) 
	{
		color(10);
		cout<<"草地"; 
	}
	else if(tx_type==2)
	{
		color(15);
		cout<<"雪地";
	}
	else if(tx_type==3)
	{
		color(15);
		cout<<"沙漠";
	}
	else if(tx_type==4)
	{
		color(15);
		cout<<"幻境";
	}
	gotoxy(23,5); 
	if(y2<0||x2<0||y2>100||x2>100)
	{
		color(240);
		cout<<"█ ";
		color(15);
		cout<<"边界     "; 
	}
	else if(tx_map[x2][y2]==0)
	{
		if(tx_type==1)
		{
			color(160);
			cout<<"  ";
			color(10);
			cout<<"草       "; 
		}
		else if(tx_type==2)
		{
			color(240);
			cout<<"  ";
			color(15);
			cout<<"雪       "; 
		}
		else if(tx_type==3)
		{
			color(224);
			cout<<"  ";
			color(14);
			cout<<"沙子     "; 
		}
		else if(tx_type==4)
		{
			color(208);
			cout<<"  ";
			color(13);
			cout<<"???     "; 
		}
	}
	else if(tx_map[x2][y2]==6)
	{
		if(tx_type==1)
		{
			color(128);
			cout<<"  ";
			color(8);
			cout<<"石头     "; 
		}
		else if(tx_type==2)
		{
			color(176);
			cout<<"  ";
			color(11);
			cout<<"冰块     "; 
		}
		
	}
	else if(tx_map[x2][y2]==1)
	{
		color(6);
		cout<<"■"<<cor();
		color(6);
		cout<<"普通宝箱 "; 
	}
	else if(tx_map[x2][y2]==2)
	{
		color(11);
		cout<<"■"<<cor();
		color(11);
		cout<<"高级宝箱 "; 
	}
	else if(tx_map[x2][y2]==3)
	{
		color(7);
		cout<<"▲"<<cor();
		color(7);
		cout<<"营地     "; 
	}
	else if(tx_map[x2][y2]==4)
	{
		color(13);
		cout<<"◆"<<cor();
		color(13);
		cout<<"传送门   "; 
	}
	else if(tx_map[x2][y2]==5)
	{
		if(tx_type==1)
		{
			color(272);
			cout<<"  ";
			color(9);
			cout<<"水塘     "; 
		}	
	}
	else if(tx_map[x2][y2]==7)
	{
		color(12);
		cout<<"■"<<cor();
		color(12);
		cout<<"补给箱   "; 
	}
	else
	{
		color(0);
		cout<<"             ";
	}
	gotoxy(23,6);
	color(15);
	cout<<"收获：";
	gotoxy(23,7);
	color(6);
	cout<<"普通宝箱："<<box01<<"   "; 
	gotoxy(23,8);
	color(11);
	cout<<"高级宝箱："<<box02<<"   "; 
}
void temp1()
{
	if(hometype==1)
	{
		nhome3();
	}
	else
	{
		home3();
	}
}
void tx_move()
{
	int f,drop=0,hdrop=8;
	tx_mapout();
	while(1)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：向前移动\n下移键：向后移动\n左移键：向左移动\n右移键：向右移动\n空格键：互动\nf1键：互动介绍\nf2键：地图介绍\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_F1))
		{ 
			::MessageBox(hwnd,"石头（草地特有）：挡路\n冰块（雪地特有）：挡路\n营地：存放宝箱，度过夜晚\n传送门：进入另一个地图\n水塘（草地特有）：补充口渴值\n补给箱：补充500点饥饿值和口渴值","互动介绍",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_F2))
		{ 
			::MessageBox(hwnd,"草地：水源丰富，适宜生存\n雪地：探险时健康值缓慢下降，口渴值不会消耗且保持在满状态\n沙漠：探险时健康值缓慢下降，口渴值双倍消耗，宝箱数量更多\n幻境：时间消失，口渴值和饥饿值不会消耗，没有营地和补给","地图介绍",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(tx_map[tx_y][tx_x+1]==0&&tx_x<100)
			{
				tx_x++;
			}
			f=2;
		}
		if(GetAsyncKeyState(VK_UP))
		{
			if(tx_map[tx_y][tx_x-1]==0&&tx_x>0)
			{
				tx_x--;
			}
			f=1;
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(tx_map[tx_y-1][tx_x]==0&&tx_y>0)
			{
				tx_y--;
			}
			f=3;		
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(tx_map[tx_y+1][tx_x]==0&&tx_y<100)
			{
				tx_y++;
			}
			f=4;
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			temp1();
		}
		if(f==1)
		{
			x2=tx_y;
			y2=tx_x-1;
		} 
		else if(f==2)
		{
			x2=tx_y;
			y2=tx_x+1;
		} 
		else if(f==3)
		{
			x2=tx_y-1;
			y2=tx_x;
		}
		else if(f==4)
		{
			x2=tx_y+1;
			y2=tx_x;
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(x2>=0&&y2>=0) 
			{
				if(tx_map[x2][y2]==1) 
				{
					tx_map[x2][y2]=0;
					box01++;
				}
				if(tx_map[x2][y2]==2) 
				{
					tx_map[x2][y2]=0;
					box02++;
				}
				if(tx_map[x2][y2]==3) 
				{
					if(t_h>16||t_h<=7)
					{
						system("cls");
						color(15);
						cout<<"     营地"<<endl;
						cout<<"时间："<<endl;
						color(6);
						cout<<"饥饿值："<<endl;
						color(9);
						cout<<"口渴值：";
						if(t_m%2!=0) t_m++;
						while(t_h!=8)
						{
							color(15);
							gotoxy(6,1);
							if(tx_type!=4)
							{
								cout<<t_h<<"时"<<t_m<<"分     ";
							}
							else
							{
								cout<<"??时"<<"??分     ";
							}
							t_m+=2; 
							if(t_m>=60)
							{
								t_m=0;
								t_h++;
							}
							if(t_h==24)
							{
								t_h=0; 
							} 
							if(drop==0)
							{
								hunger--;
								if(tx_type==1)
								{
									thirst-=2;	
								}	
								if(tx_type==3)
								{
									thirst-=4;	
								}
								drop=5;
								if(hunger<=0)
								{
									system("cls");
									color(6);
									cout<<"饥饿值过低，探险结束";
									tx_new=1;
									Sleep(1000);
									temp1();
								}
								if(thirst<=0)
								{
									system("cls");
									color(9);
									cout<<"口渴值过低，探险结束";
									tx_new=1;
									Sleep(1000);
									temp1();
								}
								if(health<=0)
								{
									system("cls");
									color(12);
									cout<<"健康值过低，探险结束";
									tx_new=1;
									Sleep(1000);
									temp1();
								}
							}
							drop--;	
							gotoxy(8,2);
							color(6);
							cout<<hunger<<"/1000     "; 
							gotoxy(8,3);
							color(9);
							cout<<thirst<<"/1000     "; 
							Sleep(10);
						}
					}
					co=1;
					box1+=box01;
					box2+=box02;
					box01=0;
					box02=0;
				}
				if(tx_map[x2][y2]==4) 
				{
					system("cls");
					color(15);
					cout<<"地图生成中…";
					tx_make();
					Sleep(500);
					tx_x=50;
					tx_y=50;
				}
				if(tx_map[x2][y2]==5) 
				{
					if(tx_type==1) 
					{
						thirst+=200;
						if(thirst>1000)
						{
							thirst=1000;
						}
					}
				}
				if(tx_map[x2][y2]==7) 
				{
					tx_map[x2][y2]=0;
					hunger+=500;
					if(hunger>1000)
					{
						hunger=1000;
					}
					thirst+=500;
					if(thirst>1000)
					{
						thirst=1000;
					}
				}
			}
		}
		if(tx_type!=4)
		{
			t_m++;
		}
		if(t_m==60)
		{
			t_m=0;
			t_h++;
		}
		if(t_h==24)
		{
			t_h=0; 
			co++;
		} 
		if(drop==0)
		{
			if(tx_type!=4)
			{
				hunger--;
			}
			if(tx_type==1)
			{
				thirst-=2;	
			}
			if(tx_type==2)
			{
				thirst=1000;	
			}
			if(tx_type==3)
			{
				thirst-=4;	
			}
			if((t_h>21||t_h<5)&&tx_type!=4)
			{
				health-=co; 
			}
			if((tx_type==2||tx_type==3)&&hdrop==0) 
			{
				health-=1; 
				hdrop=8;
			}
			hdrop--;
			if(hunger<=0)
			{ 
				system("cls");
				color(6);
				cout<<"饥饿值过低，探险结束";
				tx_new=1;
				Sleep(1000);
				temp1();
			}
			if(thirst<=0)
			{ 
				system("cls");
				color(9);
				cout<<"口渴值过低，探险结束";
				tx_new=1;
				Sleep(1000);
				temp1();
			}
			if(health<=0)
			{ 
				system("cls");
				color(12);
				cout<<"健康值过低，探险结束";
				tx_new=1;
				Sleep(1000);
				temp1();
			}					
			drop=5;
		}
		drop--;
		tx_mapout();
		Sleep(20);
	}	
}
void tx_make()
{
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			tx_map[i][j]=0;
		}
	}
	tx_type=rand()%4+1;//1草地 2雪地 3沙漠 4幻境 
	//6石头、冰块 
	if(tx_type==1||tx_type==2)
	{
		for(int i=0;i<rand()%20+200;i++)
		{
			tx_map[rand()%100+1][rand()%100+1]=6;
		}
	}
	//1普通宝箱 
	for(int i=0;i<rand()%3+8;i++)
	{
		tx_map[rand()%100+1][rand()%100+1]=1;
	}
	//2高级宝箱 
	for(int i=0;i<rand()%3+3;i++)
	{
		tx_map[rand()%100+1][rand()%100+1]=2;
	}
	if(tx_type==3)
	{
		for(int i=0;i<rand()%3+5;i++)
		{
			tx_map[rand()%100+1][rand()%100+1]=1;
		}
		tx_map[rand()%100+1][rand()%100+1]=2;
	}
	//5水塘
	if(tx_type==1)
	{
		for(int i=0;i<rand()%3+10;i++)
		{
			tx_map[rand()%100+1][rand()%100+1]=5;
		}
	}
	//7补给 
	if(tx_type!=4) 
	{
		for(int i=0;i<rand()%3+10;i++)
		{
			tx_map[rand()%100+1][rand()%100+1]=7;
		}
	}
	//3营地
	if(tx_type!=4) 
	{
		for(int i=0;i<4;i++)
		{
			tx_map[rand()%100+1][rand()%100+1]=3;
		}
	}
	//4传送门
	tx_map[rand()%100+1][rand()%100+1]=4;
	tx_new=0;
	tx_x=50;
	tx_y=50;
}
void tanx()
{
	system("cls");
	if(tx_new==1)
	{
		color(14);
		cout<<"●"<<cor()<<coin<<endl;
		color(15);
		cout<<"   探险"<<endl;
		color(14);
		cout<<"●"<<cor()<<"1000进入";
		Sleep(500);
		while(1) 
		{
			if(GetAsyncKeyState(VK_CONTROL))
			{ 
				::MessageBox(hwnd,"空格键：进入\nesc键：退出","说明",MB_ICONINFORMATION);
			} 
			if(GetAsyncKeyState(VK_SPACE)&&coin>=1000)
			{
				coin-=1000;	
				system("cls");
				color(15);
				cout<<"地图生成中…";
				t_m=0;
				t_h=8;
				co=1;
				hunger=1000;
				thirst=1000;
				health=1000;
				box01=0;
				box02=0;
				tx_make();	
				Sleep(500);
				break;
			}
			if(GetAsyncKeyState(VK_ESCAPE))
			{
				if(hometype==1)
				{
					nhome3();
				}
				else
				{
					home3();
				}
			}
		}
	}
	tx_move();
}
void book_out(int b)
{
	gotoxy(0,16);
	color(15);
	for(int i=0;i<5;i++)
	{
		cout<<"                                                                                  "<<endl;
	}
	gotoxy(0,16);
	if(books[b]==0)
	{
		color(8);
		cout<<b<<".未解锁"<<endl;
		color(14);
		cout<<"●"<<cor();
		if(coin>=5000) color(10);
		else color(4); 
		cout<<"5000购买";
	}
	if(b==1)
	{
		cout<<b<<".《关于【矿城】·其一》"<<endl;
		cout<<"关于书库"<<endl;
		cout<<"第一本书是送你的，其他的书需要你自己购买。"<<endl;
		cout<<"书里都会有各种内容（可能会有关于游戏和作者的秘密）。  "<<endl;
		cout<<"（除了烧钱外没有任何作用）                  "<<endl;
	}
	else if(b==2)
	{
		cout<<b<<".《Never Gonna Give You Up》"<<endl;
	}
	else if(b==3)
	{
		cout<<b<<".《转生成为【矿城】里的NPC，然后帮作者改屎山代码·其一》"<<endl;
	}
	else if(b==4)
	{
		cout<<b<<".《关于【矿城】·其二》"<<endl;
		cout<<"【矿城】原名是【挖矿】，一开始也确实只有挖矿这一个玩法，"<<endl;
		cout<<"但是后来作者逐渐偏题，于是干脆把标题改了…… "<<endl;
		cout<<"【挖矿】的第一个版本诞生于2021年的暑假，从零开始仅一个小时就完成了，"<<endl;
		cout<<"当时的地图大小只有64*64，而且没有存档，挖到一定数量的矿石即为通关。 "<<endl;
	}
	else if(b==5)
	{
		cout<<b<<".《关于【矿城】·其三》"<<endl;
		
	}
}
void book() 
{
	MessageBox(0,"书库尚未建设完成",":(",0);
	if(hometype==1)
	{
		nhome2();
	}
	else
	{
		home4();
	}
	int cx=1,cy=0;
	color(2);
	system("cls");
	cout<<"书库"<<endl;
	for(int i=0;i<8;i++)
	{
		for(int j=1;j<=8;j++)
		{
			if(books[i*8+j]==0) color(143);
			else color(96);
			if((i*8+j)<10) cout<<0;
			cout<<i*8+j;
			color(0);
			cout<<"  ";
		}
		cout<<endl<<endl;
	}
	gotoxy((cx-1)*4,cy*2+1);
	color(106); 
	if((cy*8+cx)<10) cout<<0;
	cout<<cy*8+cx;
	book_out(cy*8+cx);
	for(;;)
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上、下、左、右键：选择\nesc键：退出\n空格键：购买","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			if(hometype==1)
			{
				nhome2();
			}
			else
			{
				home4();
			}
		}
		if(GetAsyncKeyState(VK_SPACE))
		{
			if(books[cy*8+cx]==0&&coin>=5000&&::MessageBox(hwnd,"确定购买？","",1)==1)
			{
				coin-=5000;
				books[cy*8+cx]=1;
				gotoxy((cx-1)*4,cy*2+1);
				color(106);
				if((cy*8+cx)<10) cout<<0;
				cout<<cy*8+cx;
				book_out(cy*8+cx);	
				Sleep(100);
			}
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			gotoxy((cx-1)*4,cy*2+1);
			if(books[cy*8+cx]==0) color(143);
			else color(96);
			if((cy*8+cx)<10) cout<<0;
			cout<<cy*8+cx;
			cx--;
			if(cx==0) cy--,cx=8;
			if(cy==-1) cy=7;
			gotoxy((cx-1)*4,cy*2+1);
			if(books[cy*8+cx]==0) color(140);
			else color(106);
			if((cy*8+cx)<10) cout<<0;
			cout<<cy*8+cx;
			book_out(cy*8+cx);	
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			gotoxy((cx-1)*4,cy*2+1);
			if(books[cy*8+cx]==0) color(143);
			else color(96);
			if((cy*8+cx)<10) cout<<0;
			cout<<cy*8+cx;
			cx++;
			if(cx==9) cy++,cx=1;
			if(cy==8) cy=0;
			gotoxy((cx-1)*4,cy*2+1);
			if(books[cy*8+cx]==0) color(140);
			else color(106);
			if((cy*8+cx)<10) cout<<0;
			cout<<cy*8+cx;
			book_out(cy*8+cx);
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			gotoxy((cx-1)*4,cy*2+1);
			if(books[cy*8+cx]==0) color(143);
			else color(96);
			if((cy*8+cx)<10) cout<<0;
			cout<<cy*8+cx;
			cy++;
			if(cx==9) cy++,cx=1;
			if(cy==8) cy=0;
			gotoxy((cx-1)*4,cy*2+1);
			if(books[cy*8+cx]==0) color(140);
			else color(106);
			if((cy*8+cx)<10) cout<<0;
			cout<<cy*8+cx;
			book_out(cy*8+cx);
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_UP))
		{
			gotoxy((cx-1)*4,cy*2+1);
			if(books[cy*8+cx]==0) color(143);
			else color(96);
			if((cy*8+cx)<10) cout<<0;
			cout<<cy*8+cx;
			cy--;
			if(cx==0) cy--,cx=8;
			if(cy==-1) cy=7;
			gotoxy((cx-1)*4,cy*2+1);
			if(books[cy*8+cx]==0) color(140);
			else color(106);
			if((cy*8+cx)<10) cout<<0;
			cout<<cy*8+cx;
			book_out(cy*8+cx);
			Sleep(100);
		}
	}
}
void cjmenu(int casee)
{
	system("cls");
	color(14);
	cout<<"  成就"<<endl; 
	cout<<casee<<".";
	if(casee==1)
	{
		color(10);
		cout<<"挖草"<<endl;
		cout<<"·在矿洞上面挖掉2000块草"<<endl; 
	}
	else if(casee==2)
	{
		color(8);
		cout<<"爆破专家"<<endl;
		cout<<"·在矿洞里炸碎1000块硬石"<<endl; 
	}
	else if(casee==3)
	{
		color(11);
		cout<<"矿产丰富"<<endl;
		cout<<"·在矿洞里挖掘共2000个矿石"<<endl; 
	}
	else if(casee==4)
	{
		color(6);
		cout<<"园艺师"<<endl;
		cout<<"·在花园里收获2000个材料"<<endl; 
	}
	else if(casee==5)
	{
		color(13);
		cout<<"身经百战"<<endl;
		cout<<"·赢得战斗100次"<<endl; 
	}
	else if(casee==6)
	{
		color(13);
		cout<<"结束了"<<endl;
		cout<<"·完成最终之战"<<endl; 
	}
	else if(casee==7)
	{
		color(10);
		cout<<"药水工厂"<<endl;
		cout<<"·制造100瓶药水"<<endl; 
	}
	else if(casee==8)
	{
		color(14);
		cout<<"时光流逝"<<endl;
		cout<<"·累计进入游戏100天"<<endl; 
	}
	else if(casee==9)
	{
		color(15);
		cout<<"活动达人"<<endl;
		cout<<"·累计参加活动（除抽奖小屋、三点连线）100次"<<endl; 
	}
	else if(casee==10)
	{
		color(4);
		cout<<"原来在这"<<endl;
		cout<<"·找到游戏中的彩蛋"<<endl; 
	}
	color(14);
	cout<<"进度：";
	if(cjf[casee]>=cjgoal[casee])
	{
		color(10);
		cout<<"已完成"; 
	}
	else
	{
		cout<<cjf[casee]<<"/"<<cjgoal[casee];
	}
}
void cj()
{
	system("cls");
	cjmenu(1);
	int casee=1;
	while(!GetAsyncKeyState(VK_ESCAPE))
	{
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"左移键：上一个\n右移键：下一个\nesc键：退出","说明",MB_ICONINFORMATION);
		} 
		if(GetAsyncKeyState(VK_LEFT)&&casee>1)
		{
			casee--;
			cjmenu(casee);	
			Sleep(200);
		}
		if(GetAsyncKeyState(VK_RIGHT)&&casee<10)
		{
			casee++;
			cjmenu(casee);
			Sleep(200);
		}
	}
	if(hometype==1)
	{
		nhome2();
	}
	else
	{
		home4();
	}
}
void zd()
{
	system("cls");
	color(13);
	cout<<"   战斗"<<endl; 
	cout<<"开始战斗↑"<<cor()<<endl; 
	if(sp[1]==-1)
	{
		cout<<"最终之战↓"<<cor()<<endl; 
	}
	else 
	{
		cout<<"碎片收集↓"<<cor()<<endl; 
	} 
	while(1)
	{
		Sleep(200);
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			if(sp[1]!=-1)
			{ 
				::MessageBox(hwnd,"上移键：开始战斗\n下移键：碎片收集\nesc键：退出","说明",MB_ICONINFORMATION);
			}
			else
			{
				::MessageBox(hwnd,"上移键：开始战斗\n下移键：最终之战\nesc键：退出","说明",MB_ICONINFORMATION);
			}
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{ 
			if(hometype==1)
			{
				nhome3();
			}
			else
			{
				home3();
			}
		}
		if(GetAsyncKeyState(VK_UP))
		{
			fight();
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			shj();
		} 
	} 
}
void cd()
{
	system("cls");
	cout<<"这里没有东西";
	gotoxy(0,0);
	int x=0;
	while(1)
	{
		Sleep(200);
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"esc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{ 
			home4(); 
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(x>0)
			{
				x--;
				gotoxy(x*2,0);
			}
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(x<6)
			{
				x++;
				gotoxy(x*2,0);
			}
		}
		if(GetAsyncKeyState(VK_DELETE)&&x==2)
		{
			gotoxy(0,0);
			cout<<"这里有东西   ";
			Sleep(1000);
			if(cdflag)
			{
				cdflag=0;
				cjf[10]=1;
				::MessageBox(hwnd,"金币+1000","彩蛋",0);
				coin+=1000;
				home4(); 
			}
			else
			{
				::MessageBox(hwnd,"一团空气","彩蛋",0);
				home4();
			}
		}
	} 
}
void move()
{
	od=true;
	size=5;
	if(deng<=0)
	{
		system("cls");
		size=1;
		outmap();
	}
	while(1)
	{
		Sleep(clstime);
		if(!od)
		{
			Sleep(100);
		}
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：向上移动\n下移键：向下移动\n左移键：向左移动\n右移键：向右移动\n空格键：挖掘\nshift键：打开/关闭矿灯\ntab键：使用炸药\nenter键：标记/清除标记\nhome键：返回起点\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_SHIFT))
		{
			system("cls");
			od=!od;
			if(od)
			{
				size=5;
				dengn--;
				if(dengn<0&&deng<=0) 
				{
					size=1;
					dengn=0;
				}
			}
			else
			{
				size=1;
			}
			outmap();
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(amap[wy][wx+1]<0&&wx<mapsize)
			{
				wx++;
				if((dengn>0||deng>0)&&od) dengn--;
			}
			fx=2;
			outmap();
		}
		if(GetAsyncKeyState(VK_UP))
		{
			if(amap[wy][wx-1]<0&&wx>0)
			{
				wx--;
				if((dengn>0||deng>0)&&od) dengn--;
			}
			fx=1;
			outmap();
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(amap[wy-1][wx]<0&&wy>0)
			{
				wy--;
				if((dengn>0||deng>0)&&od) dengn--;
			}
			fx=3;
			outmap();			
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(amap[wy+1][wx]<0&&wy<mapsize)
			{
				wy++;
				if((dengn>0||deng>0)&&od) dengn--;
			}
			fx=4;
			outmap();
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			lv+=exp1/100;
			exp1=exp1%100; 
			if(ir+d+b+r+c+go+gr+p!=0)
			{
				lir+=ir;
				ld+=d;
				lb+=b;
				lr+=r;
				lc+=c;
				lgo+=go;
				lgr+=gr;
				lp+=p;
			}
			s=d=ir=r=b=c=gr=go=p=0;
			if(hometype==1)
			{
				nhome1();
			}
			else
			{
				home();
			}	
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			if(amap[wy][wx]==-2)
			{
				amap[wy][wx]=-1;
			}
			else
			{
				amap[wy][wx]=-2;
			}
			outmap();
			Sleep(200);
		}
		if(GetAsyncKeyState(VK_HOME))
		{
			if(MessageBox(0,"确定要返回起点吗？","返回起点",1)==1)
			{
				wx=0;
				wy=mapsize/2;
				outmap();
			}
		}
		if(GetAsyncKeyState(VK_TAB)&&tnt>0)
		{
			tnt--;
			outmap();		
			for(int k=0;k<=3;k++)
			{
				gotoxy(size*2,size);
				if(wx==0) color(daycolor[day]+12);
				else color(12);
				cout<<"■"<<cor(); 
				Sleep(500);
				gotoxy(size*2,size);
				if(wx==0) color(daycolor[day]+15);
				else color(15);
				cout<<"■"<<cor(); 
				Sleep(500);
			} 
			gotoxy(0,0);
			for(int i=wx-size;i<=wx+size;i++)
			{
				color(255);
				for(int j=wy-size;j<=wy+size;j++)
				{
					cout<<"  ";
				}
				color(0);
				cout<<"  ";
				puts("");
			}
			for(int i=wx-10;i<=wx+10;i++)
			{
				for(int j=wy-10;j<=wy+10;j++)
				{
					if(i>=0&&j>=0)
					{
						if(amap[j][i]==5)
						{
							cjf[2]++;
						}
						if(amap[j][i]==6||amap[j][i]==8||amap[j][i]==10||amap[j][i]==5)
						{
							amap[j][i]=-1;		
						}
					}
				}
			}
			Sleep(1000);
			outmap();
			Sleep(200);
		}
 		if(dengn<=0&&deng>0)
		{
			deng--;
			dengn++;
			if(deng<=0)
			{
				deng=0;
				dengn=0;
				system("cls");
				size=1;
				outmap();
			}
			else
			{
				dengn=3000;
				dengn--;
			}
		}
		if(GetAsyncKeyState(VK_SPACE)&&(gaon>0||gao>0))
		{
			if(fx==1)
			{
				jx=wy;
				jy=wx-1;
			} 
			else if(fx==2)
			{
				jx=wy;
				jy=wx+1;
			} 
			else if(fx==3)
			{
				jx=wy-1;
				jy=wx;
			}
			else if(fx==4)
			{
				jx=wy+1;
				jy=wx;
			}
			if(jx>=0&&jy>=0) 
			{
				if(amap[jx][jy]==7) 
				{
					exp1+=1;
					ir++;
					cjf[3]++;
				}
				else if(amap[jx][jy]==11)
				{
					exp1+=2;
					d++;
					cjf[3]++;
				} 
				else if(amap[jx][jy]==8)
				{
					jj[2]++;
					s++;
				}
				else if(amap[jx][jy]==4)
				{
					exp1+=3;
					r++;
					cjf[3]++;
				} 
				else if(amap[jx][jy]==1)
				{
					exp1+=5;
					b++;
					cjf[3]++;
				} 
				else if(amap[jx][jy]==0)
				{
					exp1+=1;
					c++;
					cjf[3]++;
				} 
				else if(amap[jx][jy]==14)
				{
					exp1+=2;
					go++;
					cjf[3]++;
				} 
				else if(amap[jx][jy]==13)
				{
					exp1+=6;
					p++;
					cjf[3]++;
				} 
				else if(amap[jx][jy]==2)
				{
					exp1+=6;
					gr++;
					cjf[3]++;
				} 
				else if(amap[jx][jy]==16)
				{
					star++;
				} 
				else if(amap[jx][jy]==6) jj[4]++;
				else if(amap[jx][jy]==10) 
				{
					jj[5]++;
					cjf[1]++;
				}
				else gaon++;
				if(amap[jx][jy]!=5&&amap[jx][jy]!=-2) 
				{
					amap[jx][jy]=-1;	
				}
				gaon--;
				if(gaon<=0)
				{
					gao--;
					if(gao>0)
					{
						gaon=2000;
						gaon--;
					}
				}
				outmap();
			}
		}
	}	
}
void outmap()
{
	gotoxy(0,0);
	for(int i=wx-size;i<=wx+size;i++)
	{
		for(int j=wy-size;j<=wy+size;j++)
		{
			if(i==wx&&j==wy)
			{
				if(amap[wy][wx]==-2)
				{
					color(96+ccolor);
				}
				else if(wx==0)
				{
					color(daycolor[day]+ccolor);
				}
				else
				{
					color(ccolor);
				}
				cout<<"●"<<cor();
				cor();	
			}
			else if(amap[j][i]==-2)
			{
				color(100);
				cout<<"×"<<cor();
				cor();
			}
			else if(amap[j][i]==16)
			{
				color(142);
				cout<<"★"<<cor();
				cor();
			}
			else if(j<0||i<=0||j>mapsize||i>mapsize)
			{
				if(i==mapsize+1&&j<=mapsize&&j>=0) 
				{
					color(132);
					cout<<"〓";
				}
				else if((j==mapsize+1||j==-1)&&i<=mapsize+1) 
				{
					color(132);
					cout<<"||";
				}
				else
				{
					color(daycolor[day]+ccolor);
					cout<<"  ";
				} 	
			}
			else if(amap[j][i]==-1)
			{
				color(0);
				cout<<"  ";
			}
			else if(amap[j][i]==5)
			{
				color(133);
				cout<<"〓";
			}
			else if(amap[j][i]==6)
			{
				rgb_set(100,60,0);
				cout<<"  ";
			}
			else
			{
				if(amap[j][i]==10) color(170);
				else color(amap[j][i]*16+8);
				outk();
			} 
		}
		color(0);
		cout<<"█"<<endl;
	}
	color(9);
	cout<<endl<<"深度:"<<wx<<"  "<<"镐子x"<<gao<<"("<<gaon<<"/2000)  "<<"矿灯x"<<deng;
	if(od)
	{
		cout<<"("<<dengn<<"/3000)      "<<"         "<<endl;
	}
	else
	{
		cout<<" off(shift)      "<<endl;
	} 
	cout<<"方向："; 
	if(fx==1) cout<<"↑";
	else if(fx==2) cout<<"↓";
	else if(fx==3) cout<<"←";
	else if(fx==4) cout<<"→";
	cout<<"  ";
	color(8*16+8);
	outk();
	color(8);
	cout<<s<<"  ";
	cout<<endl;
	color(0*16+8);
	outk();
	color(8);
	cout<<c<<"  ";
	color(7*16+8);
	outk();
	color(7);
	cout<<ir<<"  ";
	color(11*16+8);
	outk();
	color(11);
	cout<<d<<"  ";
	color(14*16+8);
	outk();
	color(14);
	cout<<go<<"     ";
	cout<<endl;
	color(4*16+8);
	outk();
	color(4);
	cout<<r<<"  ";
	color(1*16+8);
	outk();
	color(1);
	cout<<b<<"  ";
	color(2*16+8);
	outk();
	color(2);
	cout<<gr<<"  ";
	color(13*16+8);
	outk();
	color(13);
	cout<<p<<"  "<<endl;
	color(14);
	cout<<"★"<<cor()<<star<<"  "<<endl; 
	color(9);
	cout<<"炸药x"<<tnt<<"(TAB)    "<<endl;
}
void menu()
{
	system("cls");
	gotoxy(0,0);
	color(14);
	cout<<"      挖矿            "<<endl;
	cout<<" ______________"<<endl;
	cout<<"|              |"<<endl;
	cout<<"|";
	if(choose==1)
	{
		color(12);
	}
	cout<<"    新矿洞    "; 
	color(14);  
	cout<<"|"<<endl; 
	cout<<"|";
	if(choose==2)
	{
		color(12);
	}
	cout<<"   继续挖矿   ";   
	color(14);  
	cout<<"|"<<endl; 
	cout<<"|______________|"<<endl;
}
void ac()
{
	choose=1;
	menu();
	Sleep(100);
	while(!GetAsyncKeyState(VK_SPACE))
	{
		if(GetAsyncKeyState(VK_ESCAPE))
		{ 
			if(hometype==1)
			{
				nhome1();
			}
			else
			{
				home();
			}
		}
		if(GetAsyncKeyState(VK_CONTROL))
		{ 
			::MessageBox(hwnd,"上移键：上一个\n下移键：下一个\n空格键：确认\nesc键：退出","说明",MB_ICONINFORMATION);
		}
		if(GetAsyncKeyState(VK_UP)&&choose==2)
		{
			choose=1;
			menu();
		}
		if(GetAsyncKeyState(VK_DOWN)&&choose==1)
		{
			choose=2;
			menu();
		}
	}
	if(choose==1&&first1==0)
	{
		if(MessageBox(0,"确定要放弃原矿洞吗？","新矿洞",1)!=1)
		{
			ac();
		}
	}
}
void din()
{
	system("cls");
	string temp;
	color(15);
	cout<<"存档读取中..."<<endl;
	cout<<"----------";
	for(int i=0;i<mapsize;i++)
	{
		for(int j=0;j<mapsize;j++)
		{
			amap[i][j]=-1;
		} 
	}
	SetFileAttributes("数据\\d8.dll",FILE_ATTRIBUTE_NORMAL);
	freopen("数据\\d8.dll","r",stdin);
	for(int i=1;i<=64;i++)
	{
		cin>>sp[i];
	}
	for(int i=1;i<=10;i++)
	{
		cin>>cjf[i];
	}
	cin>>star>>dhq>>cdflag;
	for(int i=0;i<3;i++)
	{
		cin>>ys[i];
	}
	cin>>alb;
	for(int i=0;i<5;i++)
	{
		cin>>grow[i]>>plant[i];
		gc[i]=clock()-grow[i]*1000;
	}
	cin>>clstime>>jnc>>blv>>hlv>>alv>>dlv>>attack>>defense>>sj>>lastyear>>lastmon>>lastday>>lv>>exp1>>first>>day>>ccolor>>lc>>lir>>ld>>lgo>>lr>>lb>>lgr>>lp>>gao>>gaon>>deng>>dengn>>tnt>>kuya;
	for(int i=1;i<=15;i++)
	{
		cin>>jj[i];
	}
	cin>>coin;
	for(int k=0;k<6;k++)
	{
		for(int i=1;i<=20;i++)
		{
			for(int j=1;j<=35;j++)
			{
				cin>>jmap[j][i][k];
			}
		}
	}
	cin>>box1>>box2>>hometype;
	for(int i=1;i<=64;i++)
	{
		cin>>books[i];
	}
	cin>>cor1>>cor2>>cor3;
	fclose(stdin);
	SetFileAttributes("数据\\d8.dll",FILE_ATTRIBUTE_READONLY);
	SetFileAttributes("数据\\d8.dll",FILE_ATTRIBUTE_HIDDEN);
	mapin();
	SetFileAttributes("数据\\3f.dll",FILE_ATTRIBUTE_NORMAL);
	freopen("数据\\3f.dll","r",stdin);
	cin>>tx_x>>tx_y>>tx_type>>tx_new>>health>>thirst>>hunger>>t_h>>t_m>>box01>>box02>>co; 
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			cin>>tx_map[j][i];
		}
	}
	SetFileAttributes("数据\\3f.dll",FILE_ATTRIBUTE_READONLY);
	SetFileAttributes("数据\\3f.dll",FILE_ATTRIBUTE_HIDDEN);
	system("cls");
	cout<<"资源加载中…";
	SetFileAttributes("数据\\主页面.dll",FILE_ATTRIBUTE_NORMAL);
	freopen("数据\\主页面.dll","r",stdin);
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<8;j++)
		{
			cin>>home_1[i][j];
		}
	}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<15;j++)
		{
			cin>>home_2[i][j];
		}
	}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<8;j++)
		{
			cin>>home_3[i][j];
		}
	}
	string m;
	for(int i=0;i<6;i++)
	{
		cin>>m;
		for(int j=0;j<16;j++)
		{
			if(m[j]=='a')
			{
				chome_1[i][j]=' '; 
			}
			else
			{
				chome_1[i][j]=m[j]; 
			}
		}
	}
	for(int i=0;i<6;i++)
	{
		cin>>m;
		for(int j=0;j<30;j++)
		{
			if(m[j]=='a')
			{
				chome_2[i][j]=' '; 
			}
			else
			{
				chome_2[i][j]=m[j]; 
			}
		}
	}
	for(int i=0;i<6;i++)
	{
		cin>>m;
		for(int j=0;j<16;j++)
		{
			if(m[j]=='a')
			{
				chome_3[i][j]=' '; 
			}
			else
			{
				chome_3[i][j]=m[j]; 
			}
		}
	}
	SetFileAttributes("数据\\主页面.dll",FILE_ATTRIBUTE_READONLY);
	SetFileAttributes("数据\\主页面.dll",FILE_ATTRIBUTE_HIDDEN);
	system("cls");
	if(first)
	{
		color(15);
		cout<<"初始化...";
		alb=rand()%11;
		for(int k=0;k<6;k++)
		{
			for(int i=1;i<=35;i++)
			{
				jmap[i][10][k]=5;
			}
			for(int i=1;i<=35;i++)
			{	
				for(int j=11;j<=20;j++)
				{
					jmap[i][j][k]=4;
				}
				cout<<endl;
			}
		}
		for(int i=0;i<mapsize;i++)
		{
			for(int j=0;j<mapsize;j++)
			{
				amap[i][j]=-1;
			} 
		}
		system("cls");
		::MessageBox(hwnd,"欢迎来到 矿城 游戏","新手教程",0); 
		::MessageBox(hwnd,"现在需要进行一些初始设置","新手教程",0); 
		cor1=1;
		cor2=2;
		cor3=0;
		if(::MessageBox(hwnd,"您是否正在使用Windows Terminal运行此程序？\n（简单来说：是否在Win11上运行？）","新手教程",4)==6)
		{
			::MessageBox(hwnd,"由于此程序是在Win10环境下制作，在Win11上运行会导致字符的样子不同，\n这会导致画面错位等问题。此程序已经尽最大努力进行调整以适应Win11，\n但仍会出现一些不可避免的问题。\n为了游戏体验，建议在Win10上运行此程序，但在Win11上运行也不会有太大问题","警告",48); 
			cor1=2;
			cor2=1;
			cor3=1;
		}
		::MessageBox(hwnd,"为避免画面错位，现在将进行校准","新手教程",0); 
		color(15);
		cout<<"校准(1/3)"<<endl;
		outputcheck(1);
		color(15);
		cout<<"检查绿条和红条是否对齐"<<endl;
		cout<<"已对齐：空格键确认"<<endl; 
		cout<<"未对齐：TAB键调整"<<endl; 
		while(!GetAsyncKeyState(VK_SPACE))
		{
			if(GetAsyncKeyState(VK_TAB))
			{
				cor2++;
				if(cor2==2) cor2=0;
				gotoxy(0,1);
				outputcheck(1);
				Sleep(500);
			}
		}
		color(0);
		system("cls");
		color(15);
		cout<<"校准(2/3)"<<endl;
		outputcheck(2);
		color(15);
		cout<<"检查绿条和红条是否对齐,以及是否显示完全"<<endl;
		cout<<"已对齐：空格键确认"<<endl; 
		cout<<"未对齐：TAB键调整"<<endl; 
		Sleep(300);
		while(!GetAsyncKeyState(VK_SPACE))
		{
			if(GetAsyncKeyState(VK_TAB))
			{
				cor1++;
				if(cor1==3) cor1=0;
				gotoxy(0,1);
				outputcheck(2);
				Sleep(500);
			}
		}
		color(0);
		system("cls");
		color(15);
		cout<<"校准(3/3)"<<endl;
		outputcheck(3);
		color(15);
		cout<<"检查从上到下是否均匀增长"<<endl;
		cout<<"是：空格键确认"<<endl; 
		cout<<"否：TAB键调整"<<endl; 
		Sleep(300);
		while(!GetAsyncKeyState(VK_SPACE))
		{
			if(GetAsyncKeyState(VK_TAB))
			{
				cor3++;
				if(cor3==2) cor3=0;
				gotoxy(0,1);
				outputcheck(3);
				Sleep(500);
			}
		}
		::MessageBox(hwnd,"已完成校准\n如果在游戏中发现错位的情况，在设置中可以重新校准","新手教程",0);
		::MessageBox(hwnd,"在大多数页面都可以按下ctrl键查看按键操作","新手教程",0);
		if(::MessageBox(hwnd,"稿子*1\n矿灯*1\n\n自选:\n  等级+1,木材+10（是）\n  金币+500,钻石+40（否）","新手礼包",4)==6)
		{
			lv++;
			jj[1]+=10;
		}
		else
		{
			coin+=500;
			ld+=40;
		}
		make();
		first1=1; 
		first=0;
		::MessageBox(hwnd,"已完成新手教程，请重新进入游戏","新手教程",0);
		aexit();
	}
	time_t now=time(0);
	tm*ltm=localtime(&now);
	nowday=ltm->tm_mday;
	nowmon=1+ltm->tm_mon;
	nowyear=1900+ltm->tm_year;
	if(lastday!=nowday||lastmon!=nowmon||lastyear!=nowyear)
	{
		cdflag=1;
		int a=alb;
		cjf[8]++;
		if(a==0)
		{
			::MessageBox(hwnd,"金币+1000","每日礼包",0); 
			coin+=1000;
		}
		else if(a==1)
		{
			::MessageBox(hwnd,"等级+30%","每日礼包",0);
			exp1+=30;
			lv+=exp1/100;
			exp1=exp1%100;
		}
		else if(a==2)
		{
			::MessageBox(hwnd,"木板+10","每日礼包",0);
			jj[1]+=10;
		}
		else if(a==3)
		{
			::MessageBox(hwnd,"金币+500","每日礼包",0);
			coin+=500;
		}
		else if(a==4) 
		{
			::MessageBox(hwnd,"铁+60","每日礼包",0);
			lir+=60;
		}
		else if(a==5) 
		{
			::MessageBox(hwnd,"钻石+30","每日礼包",0);
			ld+=30;
		}
		else if(a==6)
		{
			::MessageBox(hwnd,"攻击碎片+5","每日礼包",0); 
			attack+=5;
		}
		else if(a==7)
		{
			::MessageBox(hwnd,"防御碎片+5","每日礼包",0); 
			defense+=5;
		}
		else if(a==8)
		{
			::MessageBox(hwnd,"战斗水晶+4","每日礼包",0); 
			sj+=4;
		}
		else if(a==9)
		{
			if(::MessageBox(hwnd,"大奖！！！\n\n自选:\n  等级+50%,金币+500,战斗水晶+8（是）\n  炸药+1,铁+80,攻击碎片+5，防御碎片+5（否）","每日礼包",4)==6)
			{
				sj+=8;
				exp1+=50;
				lv+=exp1/100;
				exp1=exp1%100;
				coin+=500;
			}
			else
			{
				attack+=5;
				defense+=5; 
				tnt+=1;
				lir+=80;
			} 
		}
		else
		{
			if(::MessageBox(hwnd,"大奖！！！\n\n自选:\n  等级+1，战斗水晶+16（是）\n  铁+40,钻石+30,红宝石+16,青金石+10,攻击碎片+5，防御碎片+5（否）","每日礼包",4)==6)
			{
				sj+=16;
				lv+=1;
			}
			else
			{
				attack+=5;
				defense+=5; 
				lir+=40;
				ld+=30;
				lr+=16;
				lb+=10;
			}
		}
	}
	books[1]=1;
	if(hometype==1)
	{
		mx=7;
		my=3;
		nhome2();
	}
	else
	{
		home();
	}	
}
void pieces(int type)
{
	if(cor3==0)
	{
		if(type==8)
		{
			cout<<"█";
			if(cor1==1) cout<<" ";
			else if(cor1==2) cout<<"█";
		} 
		if(type==7) cout<<"▉";
		else if(type==6) cout<<"▊";
		else if(type==5) cout<<"▋";
		else if(type==4) cout<<"▌";
		else if(type==3) cout<<"▍";
		else if(type==2) cout<<"▎";
		else if(type==1) cout<<"▏";
		else if(type==0) cout<<"  ";
	}
	else
	{
		if(type==8)
		{
			cout<<"█";
			if(cor1==1) cout<<" ";
			else if(cor1==2) cout<<"█";
		}
		if(type==7)
		{
			if(cor1==1) cout<<" ";
			else if(cor1==2) cout<<"█"; 
			cout<<"▊";
		}
		else if(type==6)
		{
			if(cor1==1) cout<<" ";
			else if(cor1==2) cout<<"█"; 
			cout<<"▌";
		}
		else if(type==5) 
		{
			if(cor1==1) cout<<" ";
			else if(cor1==2) cout<<"█"; 
			cout<<"▎";
		}
		else if(type==4)
		{
			cout<<"█";
			if(cor1==2) cout<<" ";
		} 
		else if(type==3)
		{
			cout<<"▊";
			if(cor1==2) cout<<" ";
		} 
		else if(type==2)
		{
			cout<<"▌";
			if(cor1==2) cout<<" ";
		} 
		else if(type==1)
		{
			cout<<"▎";
			if(cor1==2) cout<<" ";
		} 
		else if(type==0) cout<<"  ";
	}
}
void outputcheck(int type)
{
	if(type==1)
	{
		string test="■‖→◢Φ¤※●○×★◎※◆";
		color(15);
		for(int i=0;i<14;i++)
		{
			cout<<test[i*2]<<test[i*2+1]<<cor();
		}
		color(32);
		cout<<" ";
		color(0);
		cout<<"                                          "<<endl;
		color(15);
		for(int i=0;i<14;i++)
		{
			cout<<"  ";
		}
		color(64);
		cout<<" "<<endl;
	}
	else if(type==2)
	{
		color(8);
		cout<<"▓";
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"▓";
		cout<<"◎"<<cor();
		cout<<"※"<<cor();
		cout<<"█";
		if(cor1==1) cout<<" ";
		else if(cor1==2) cout<<"█";
		cout<<"矿";
		color(32);
		cout<<" ";
		color(0);
		cout<<"                                     "<<endl;
		color(15);
		for(int i=0;i<5;i++)
		{
			cout<<"  ";
		}
		color(64);
		cout<<" "<<endl;
	}
	else
	{
		color(8);
		for(int i=1;i<=8;i++)
		{
			pieces(i);
			cout<<"   "<<endl;
		}
	}
}
void anticheat()
{
	//	int result=stat("数据\\data.dll",&buf);
	//	cout<<ctime(&buf.st_atime);
}

int main()
{
//	if(SetConsoleCtrlHandler((PHANDLER_ROUTINE)Ctrlhandler,true))
	{
		system("title 矿城");
		rgb_init();
		srand((unsigned)time(NULL));
		//DeleteMenu(hmenu,SC_CLOSE,MF_BYCOMMAND);
		EnableMenuItem(hmenu,SC_CLOSE,MF_GRAYED);
		system("cls");
		anticheat();
		din();
	}		
}
