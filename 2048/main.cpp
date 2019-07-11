# include <iostream>
# include <conio.h>
# include "2048.h"
using namespace std;
 
int main()
{
	while (1)
	{
		char ch;
		system("cls");                        //清屏
		system("color 3B");                   //改变背景和字体颜色
		New2048 s;
		s.make_frame();                       //打印框架
		s.creat_num();
		s.creat_num();                        //产生两个随机数
		s.display_num();                      //显示数字
		while (1)
		{
			ch = _getch();                   //如果不是VS的，_getch应该改成getch
			if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' || 
				ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
				break;
		}
p:		switch (ch)
		{
		case 's':
		case 'S':
		{
					while (s.cheak())
					{
						s.DownMove();             //下移
						s.clean();                //清理
						s.display_num();          //显示数字
						while (1)
						{
							ch = _getch();
							if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' ||
								ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
								break;
						}
						goto p;
					}
		}break;
		case 'd':
		case 'D':
		{
					while (s.cheak())
					{
						s.RightMove();                //右移
						s.clean();                    //清理
						s.display_num();              //显示数字
						while (1)
						{
							ch = _getch();
							if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' || 
								ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
								break;
						}
						goto p;
					}
		}break;
		case 'a':
		case 'A':
		{
					while (s.cheak())
					{
						s.LeftMove();              //左移
						s.clean();                 //清理
						s.display_num();           //显示数字
						while (1)
						{
							ch = _getch();
							if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' || 
								ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
								break;
						}
						goto p;
					}
		}break;
		case 'w':
		case 'W':
		{
					while (s.cheak())
					{
						s.UpMove();               //上移
						s.clean();                //清理
						s.display_num();          //显示数字
						while (1)
						{
							ch = _getch();
							if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w' || ch == ' ' || 
								ch == 'A' || ch == 'S' || ch == 'D' || ch == 'W')
								break;
						}
						goto p;
					}
		}break;
		default:
			break;
		}                            //退出switch，游戏结束
		system("cls");               //清屏
		cout << "               PLAY AGAIN ? YES(Y) : NO(N)" << endl;
		while (1)
		{
			ch = _getch();
			if (ch == 'y' || ch == 'n' || ch == 'Y' || ch == 'N')
				break;
		}
		if (ch == 'y' || ch == 'Y')          //Y继续
			continue;
		else                                 //否则退出
			break;
	}
	return 0;
}
