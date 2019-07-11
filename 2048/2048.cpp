# include <iostream>
# include <Windows.h>
# include <time.h>
# include <conio.h>
# include "2048.h"
using namespace std;
 
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);    //获取句柄
void gotoxy(HANDLE hOut, int x, int y)            //输出位置的函数
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}
void New2048::make_frame()                       //打印框架
{
	gotoxy(hOut, 0, 0);
	cout << "         得分" << endl;
	cout << "┏━━┳━━┳━━┳━━┓" << endl;
	cout << "┃    ┃    ┃    ┃    ┃" << endl;
	cout << "┣━━╋━━╋━━╋━━┫" << endl;
	cout << "┃    ┃    ┃    ┃    ┃" << endl;
	cout << "┣━━╋━━╋━━╋━━┫" << endl;
	cout << "┃    ┃    ┃    ┃    ┃" << endl;
	cout << "┣━━╋━━╋━━╋━━┫" << endl;
	cout << "┃    ┃    ┃    ┃    ┃" << endl;
	cout << "┗━━┻━━┻━━┻━━┛" << endl;
}
void New2048::clean()
{
	int k = 0, l = 0;
	for (int i = 2; i < 21, k < 4; i = i + 6)    //找到对应的框，输入空格
	{
		l = 0;
		for (int j = 2; j < 9; j = j + 2)
		{
			gotoxy(hOut, i, j);
			printf("    ");
			l++;
		}
		k++;
	}
}
void New2048::display_num()                          //打印数字
{
	int k = 0, l = 0;
	for (int i = 2; i < 21, k < 4; i = i + 6)    //找到对应的框，输入数字，这个尝试了好久，才搞定了。
	{
		l = 0;
		for (int j = 2; j < 9; j = j + 2)
		{
			gotoxy(hOut, i, j);          //找到各个位置并输出数字
			a[l][k] == 0 ? printf(" ") : printf("%d", a[l][k]);
			l++;
		}
		k++;
	}
	gotoxy(hOut, 13, 0);
	cout << num * 100;
	gotoxy(hOut, 0, 10);
}
void New2048::creat_num()                     //随机产生坐标位置和该位置的数 2 或 4
{
	int i, j, num;
	srand((unsigned)time(NULL));             //随机数产生初始化，不然产生的数一直相同        
	i = (rand() % (4)) + 0;
	j = (rand() % (4)) + 0;
	while (a[i][j])                           //该位置上的数不是0，重新产生
	{
		i = (rand() % (4)) + 0;
		j = (rand() % (4)) + 0;
	}
	num = (rand() % (4)) + 1;                //产生的是1就自增，是3便自减或自增，都可以的
	if (num == 1)
		++num;
	if (num == 3)
		--num;
	a[i][j] = num;
}
int New2048::cheak()
{
	int i, j, flag = 0, tag = 0;
	for (i = 0; i < 4; i++)                  //检查是否还有位置，有，tag = 1。
	{
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)
			{
				tag = 1;
				break;
			}
		}
		if (tag == 1)
			break;
	}
	if (tag)                               //有，返回1。
		return 1;
	for (i = 0; i < 4; i++)                //检查左右的相邻是否有相等，是，flag = 1，退出循环
	{
		for (j = 0; j < 3; j++)
		{
			if (a[i][j] == a[i][j + 1])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	for (j = 0; j < 4; j++)                //检查上下的相邻是否有想等，是，flag = 1，退出循环
	{
		for (i = 0; i < 3; i++)
		{
			if (a[i][j] == a[i + 1][j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (tag == 0 && flag == 0)            //flag = 0 和 tag = 0，游戏结束。
		return 0;
	else                                  //否则，继续游戏
		return 1;
}
void New2048::DownMove()                  //下移的情况
{
	int k, tag = 0;
	for (int i = 0; i < 4; i++)           //从每一列开始
	{
		int b[4] = { 0 };				 //定义一个临时数组来存储相加之后的情况
		k = 3;
		for (int j = 3; j > 0; j--)
		{
			if (a[j][i] != 0)
			{
				int flag = 0;
				for (int l = j - 1; l >= 0; l--)    //找是否有相同的数
				{
					if (a[l][i] != 0)
					{
						flag = 1;
						if (a[l][i] == a[j][i])
						{
							b[k--] = 2 * a[j][i];
							num++;         
							a[l][i] = a[j][i] = 0;
							break;
						}
						else
						{
							b[k--] = a[j][i];
							break;
						}
					}
				}
				if (flag == 0)
					b[k--] = a[j][i];
			}
		}
		b[k] = a[0][i];                 //最后一个没有检查，赋值过去，不管是否为0，都无所谓的
		for (int j = 0; j < 4; j++)     //检查是否有移动
		{
			if (a[j][i] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)    //将结果覆盖回去
			a[j][i] = b[j];
	}
	if (tag)                          //存在移动，产生新的数
		creat_num();
}
void New2048::LeftMove()                 //同上
{
	int k, tag = 0;
	for (int i = 0; i < 4; i++)
	{
		int b[4] = { 0 };
		k = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != 0)
			{
				int flag = 0;
				for (int l = j + 1; l < 4; l++)
				{
					if (a[i][l] != 0)
					{
						flag = 1;
						if (a[i][l] == a[i][j])
						{
							b[k++] = 2 * a[i][j];
							num++;
							a[i][j] = a[i][l] = 0;
							break;
						}
						else
						{
							b[k++] = a[i][j];
							break;
						}
					}
				}
				if (flag == 0)
					b[k++] = a[i][j];
			}
		}
		b[k] = a[i][3];
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)
			a[i][j] = b[j];
	}
	if (tag)
		creat_num();
}
void New2048::RightMove()              //同上
{
	int k, tag = 0;
	for (int i = 0; i < 4; i++)
	{
		int b[4] = { 0 };
		k = 3;
		for (int j = 3; j > 0; j--)
		{
			if (a[i][j] != 0)
			{
				int flag = 0;
				for (int l = j - 1; l >= 0; l--)
				{
					if (a[i][l] != 0)
					{
						flag = 1;
						if (a[i][l] == a[i][j])
						{
							b[k--] = 2 * a[i][j];
							num++;
							a[i][j] = a[i][l] = 0;
							break;
						}
						else
						{
							b[k--] = a[i][j];
							break;
						}
					}
				}
				if (flag == 0)
					b[k--] = a[i][j];
			}
		}
		b[k] = a[i][0];
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)
			a[i][j] = b[j];
	}
	if (tag)
		creat_num();
}
void New2048::UpMove()
{
	int k, tag = 0;
	for (int i = 0; i < 4; i++)
	{
		int b[4] = { 0 };                 //定义一个临时数组来存储相加之后的情况
		k = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a[j][i] != 0)
			{
				int flag = 0;
				for (int l = j + 1; l < 4; l++)    //找是否有相同的数
				{
					if (a[l][i] != 0)
					{
						flag = 1;
						if (a[l][i] == a[j][i])
						{
							b[k++] = 2 * a[j][i];
							num++;
							a[l][i] = a[j][i] = 0;
							break;
						}
						else
						{
							b[k++] = a[j][i];
							break;
						}
					}
				}
				if (flag == 0)
					b[k++] = a[j][i];
			}
		}
		b[k] = a[3][i];
		for (int j = 0; j < 4; j++)
		{
			if (a[j][i] != b[j])
			{
				tag = 1;
				break;
			}
		}
		for (int j = 0; j < 4; j++)      //将结果覆盖回去
			a[j][i] = b[j];
	}
	if (tag)
		creat_num();
}
