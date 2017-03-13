#include <iostream>
#include <windows.h>
#include <conio.h>
#include "标头.h"
#include "颜色.h"
#include <fstream>

using namespace std;

#define TRUE 1
#define FALSE 0

#define WALL_LEFT 1
#define WALL_RIGHT 61
#define WALL_UP 1
#define WALL_DOWN 31

#define verticalwall0 1
#define verticalwall1 11
#define verticalwall2 21
#define verticalwall3 31
#define verticalwall4 41
#define verticalwall5 51
#define verticalwall6 61

#define horizontalwall0 1
#define horizontalwall1 6
#define horizontalwall2 11
#define horizontalwall3 16
#define horizontalwall4 21
#define horizontalwall5 26
#define horizontalwall6 31

void gotoxy(int x, int y);

class Wall;
class VerticalWall;
class HorizontalWall;
class Point;
class Character;
class Monster;
class WhiteMummy;
class RedMummy;
class WhiteScropion;
class RedScropion;

void moveMonster(int & MissionCompleted, int & GameOver);
void initialize();
void paintwall();
void drawwall();
void welcome();
void game(int & chapter,int & mission);

void mission1_1();
void mission1_2();
void mission1_3();
void mission1_4();
void mission1_5();
void mission1_6();
void mission1_7();
void mission1_8();
void mission1_9();
void mission1_10();
void mission1_11();
void mission1_12();
void mission1_13();
void mission1_14();
void mission1_15();

void mission2_1();
void mission2_2();
void mission2_3();
void mission2_4();
void mission2_5();
void mission2_6();
void mission2_7();
void mission2_8();
void mission2_9();
void mission2_10();
void mission2_11();
void mission2_12();
void mission2_13();
void mission2_14();
void mission2_15();

void mission3_1();
void mission3_2();
void mission3_3();
void mission3_4();
void mission3_5();
void mission3_6();
void mission3_7();
void mission3_8();
void mission3_9();
void mission3_10();
void mission3_11();
void mission3_12();
void mission3_13();
void mission3_14();
void mission3_15();

void mission4_1();
void mission4_2();
void mission4_3();
void mission4_4();
void mission4_5();
void mission4_6();
void mission4_7();
void mission4_8();
void mission4_9();
void mission4_10();
void mission4_11();
void mission4_12();
void mission4_13();
void mission4_14();
void mission4_15();

void mission5_1();
void mission5_2();
void mission5_3();
void mission5_4();
void mission5_5();
void mission5_6();
void mission5_7();
void mission5_8();
void mission5_9();
void mission5_10();
void mission5_11();
void mission5_12();
void mission5_13();
void mission5_14();
void mission5_15();

void gotoxy(int x, int y)
{
	COORD loc = { x, y };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
}





class Wall
{
public:
	int x, y;
	int isWall;
	int isExit;
	int isDoor;
	int isBar;
};

class VerticalWall :public Wall //竖墙
{
public:
	friend void paint();
	
}verticalwall[7][6];

class HorizontalWall :public Wall //横墙
{
public:
	friend void paint();
}horizontalwall[6][7];

class Point
{
public:

	int x, y;
	int i, j;
	int isTrap;
	int isKey;

	Point(int x1=0, int y1=0)
	{
		x = x1; y = y1;
	}
	
}point[6][6];

class Character
{
public:
	Point start;
	Point currentpoint;
	
	Character(int x1=0,int y1=0)
	{
		start.x = x1;
		start.y = y1;
	}

}character;

class Monster
{
public:
	int isExist;
	int Level;	
	Point start;
	Point currentpoint;
	virtual void move(int & GameOver) = 0;
};

class WhiteMummy :public Monster
{
public:
	WhiteMummy(int x1 = 0, int y1 = 0)
	{
		start.x = x1;
		start.y = y1;
	}
	void move(int & GameOver)
	{	
		

		for (int times = 0; times<2; times++)
		{

			//原地不动
			int nomove = 0;
			int nomovepointi = currentpoint.i;
			int nomovepointj = currentpoint.j;

			Sleep(150);

			if (point[currentpoint.i][currentpoint.j].isTrap == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}

			gotoxy(currentpoint.x-4, currentpoint.y);
			cout << "        ";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			if (currentpoint.x > character.currentpoint.x)//木乃伊x坐标比人大
			{
				if (verticalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断左边是否有墙
				{
					currentpoint.x -= 10;
					currentpoint.i--;
				}
				else
				{
					if (currentpoint.y > character.currentpoint.y)
					{
						if (horizontalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断上边是否有墙
						{
							currentpoint.y -= 5;
							currentpoint.j--;
						}
					}
					else if (currentpoint.y < character.currentpoint.y)
					{
						if (horizontalwall[currentpoint.i][currentpoint.j + 1].isWall == FALSE)//判断下面
						{
							currentpoint.y += 5;
							currentpoint.j++;
						}
					}
					else if (currentpoint.y == character.currentpoint.y){ ; }
						
				}
			}
			else if (currentpoint.x < character.currentpoint.x)//比人小
			{
				if (verticalwall[currentpoint.i + 1][currentpoint.j].isWall == FALSE)//右边
				{
					currentpoint.x += 10;
					currentpoint.i++;
				}
				else
				{
					if (currentpoint.y > character.currentpoint.y)
					{
						if (horizontalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断上边是否有墙
						{
							currentpoint.y -= 5;
							currentpoint.j--;
						}
					}
					else if (currentpoint.y < character.currentpoint.y)
					{
						if (horizontalwall[currentpoint.i][currentpoint.j + 1].isWall == FALSE)//判断下面
						{
							currentpoint.y += 5;
							currentpoint.j++;
						}
					}
					else if (currentpoint.y == character.currentpoint.y){ ; }
				}
			}
			else if (currentpoint.x == character.currentpoint.x)
			{
				if (currentpoint.y > character.currentpoint.y)
				{
					if (horizontalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断上边是否有墙
					{
						currentpoint.y -= 5;
						currentpoint.j--;
					}
				}
				else if (currentpoint.y < character.currentpoint.y)
				{
					if (horizontalwall[currentpoint.i][currentpoint.j + 1].isWall == FALSE)//判断下面
					{
						currentpoint.y += 5;
						currentpoint.j++;
					}
				}
			}

			if (point[currentpoint.i][currentpoint.j].isTrap == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			
			if (nomovepointi == currentpoint.i&&nomovepointj == currentpoint.j)
			{
				nomove = 1;
			}

			if (point[currentpoint.i][currentpoint.j].isKey == TRUE&&nomove == FALSE)
			{
				//mark 钥匙触发;
				for (int i = 0; i < 7; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						if (verticalwall[i][j].isBar == TRUE)
						{
							verticalwall[i][j].isWall = !verticalwall[i][j].isWall;
						}
					}
				}
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						if (horizontalwall[i][j].isBar == TRUE)
						{
							horizontalwall[i][j].isWall = !horizontalwall[i][j].isWall;
						}
					}
				}
			}

			gotoxy(currentpoint.x-4, currentpoint.y);
			switch (Level)
			{
			case 4:cout << " 木乃伊"; break;
			case 3:cout << "红木乃伊"; break;
			case 2:cout << " 蝎子"; break;
			case 1:cout << " 红蝎子"; break;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			if (currentpoint.i == character.currentpoint.i&&currentpoint.j == character.currentpoint.j)
			{
				GameOver = 1;
			}
		}

		
	}

	friend void moveMonster();
}whitemummy1,whitemummy2;

class RedMummy :public Monster
{
public:

	RedMummy(int x1 = 0, int y1 = 0)
	{
		start.x = x1;
		start.y = y1;
	}
	void move(int & GameOver)
	{
		
		for (int times = 0; times < 2; times++)
		{

			//原地不动
			int nomove = 0;
			int nomovepointi = currentpoint.i;
			int nomovepointj = currentpoint.j;


			Sleep(150);

			if (point[currentpoint.i][currentpoint.j].isTrap == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}


			gotoxy(currentpoint.x - 4, currentpoint.y);
			cout << "        ";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			if (currentpoint.y > character.currentpoint.y)
			{
				if (horizontalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断上边是否有墙
				{
					currentpoint.y -= 5;
					currentpoint.j--;
				}
				else
				{
					if (currentpoint.x > character.currentpoint.x)
					{
						if (verticalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断左边是否有墙
						{
							currentpoint.x -= 10;
							currentpoint.i--;
						}
					}
					else if (currentpoint.x < character.currentpoint.x)//比人小
					{
						if (verticalwall[currentpoint.i + 1][currentpoint.j].isWall == FALSE)//右边
						{
							currentpoint.x += 10;
							currentpoint.i++;
						}
					}
					else if (currentpoint.x == character.currentpoint.x){ ; }
				}
			}
			else if (currentpoint.y < character.currentpoint.y)
			{
				if (horizontalwall[currentpoint.i][currentpoint.j + 1].isWall == FALSE)//判断下面
				{
					currentpoint.y += 5;
					currentpoint.j++;
				}
				else
				{
					if (currentpoint.x > character.currentpoint.x)
					{
						if (verticalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断左边是否有墙
						{
							currentpoint.x -= 10;
							currentpoint.i--;
						}
					}
					else if (currentpoint.x < character.currentpoint.x)//比人小
					{
						if (verticalwall[currentpoint.i + 1][currentpoint.j].isWall == FALSE)//右边
						{
							currentpoint.x += 10;
							currentpoint.i++;
						}
					}
					else if (currentpoint.x == character.currentpoint.x){ ; }
				}
			}
			else if (currentpoint.y == character.currentpoint.y)
			{
				if (currentpoint.x > character.currentpoint.x)
				{
					if (verticalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断左边是否有墙
					{
						currentpoint.x -= 10;
						currentpoint.i--;
					}
				}
				else if (currentpoint.x < character.currentpoint.x)
				{
					if (verticalwall[currentpoint.i + 1][currentpoint.j].isWall == FALSE)//右边
					{
						currentpoint.x += 10;
						currentpoint.i++;
					}
				}
			}

			if (point[currentpoint.i][currentpoint.j].isTrap == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}

			if (nomovepointi == currentpoint.i&&nomovepointj == currentpoint.j)
			{
				nomove = 1;
			}

			if (point[currentpoint.i][currentpoint.j].isKey == TRUE&&nomove == FALSE)
			{
				//mark 钥匙触发;
				for (int i = 0; i < 7; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						if (verticalwall[i][j].isBar == TRUE)
						{
							verticalwall[i][j].isWall = !verticalwall[i][j].isWall;
						}
					}
				}
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						if (horizontalwall[i][j].isBar == TRUE)
						{
							horizontalwall[i][j].isWall = !horizontalwall[i][j].isWall;
						}
					}
				}
			}

			

			gotoxy(currentpoint.x - 4, currentpoint.y);
			switch (Level)
			{
			case 4:cout << " 木乃伊"; break;
			case 3:cout << "红木乃伊"; break;
			case 2:cout << " 蝎子"; break;
			case 1:cout << " 红蝎子"; break;
			}


			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


			if (currentpoint.i == character.currentpoint.i&&currentpoint.j == character.currentpoint.j)
			{
				GameOver = 1;
			}
		}


		
	}


	friend void moveMonster();
}redmummy1, redmummy2;

class WhiteScorpion :public Monster
{
public:

	WhiteScorpion(int x1 = 0, int y1 = 0)
	{
		start.x = x1;
		start.y = y1;
	}
	void move(int & GameOver)
	{

		//原地不动
		int nomove = 0;
		int nomovepointi = currentpoint.i;
		int nomovepointj = currentpoint.j;

		Sleep(150);

		if (point[currentpoint.i][currentpoint.j].isTrap == TRUE)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}

		gotoxy(currentpoint.x - 4, currentpoint.y);
		cout << "        ";


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


		if (currentpoint.x > character.currentpoint.x)//木乃伊x坐标比人大
		{
			if (verticalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断左边是否有墙
			{
				currentpoint.x -= 10;
				currentpoint.i--;
			}
			else
			{
				if (currentpoint.y > character.currentpoint.y)
				{
					if (horizontalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断上边是否有墙
					{
						currentpoint.y -= 5;
						currentpoint.j--;
					}
				}
				else if (currentpoint.y < character.currentpoint.y)
				{
					if (horizontalwall[currentpoint.i][currentpoint.j + 1].isWall == FALSE)//判断下面
					{
						currentpoint.y += 5;
						currentpoint.j++;
					}
				}
				else if (currentpoint.y == character.currentpoint.y){ ; }

			}
		}
		else if (currentpoint.x < character.currentpoint.x)//比人小
		{
			if (verticalwall[currentpoint.i + 1][currentpoint.j].isWall == FALSE)//右边
			{
				currentpoint.x += 10;
				currentpoint.i++;
			}
			else
			{
				if (currentpoint.y > character.currentpoint.y)
				{
					if (horizontalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断上边是否有墙
					{
						currentpoint.y -= 5;
						currentpoint.j--;
					}
				}
				else if (currentpoint.y < character.currentpoint.y)
				{
					if (horizontalwall[currentpoint.i][currentpoint.j + 1].isWall == FALSE)//判断下面
					{
						currentpoint.y += 5;
						currentpoint.j++;
					}
				}
				else if (currentpoint.y == character.currentpoint.y){ ; }
			}
		}
		else if (currentpoint.x == character.currentpoint.x)
		{
			if (currentpoint.y > character.currentpoint.y)
			{
				if (horizontalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断上边是否有墙
				{
					currentpoint.y -= 5;
					currentpoint.j--;
				}
			}
			else if (currentpoint.y < character.currentpoint.y)
			{
				if (horizontalwall[currentpoint.i][currentpoint.j + 1].isWall == FALSE)//判断下面
				{
					currentpoint.y += 5;
					currentpoint.j++;
				}
			}
		}

		if (point[currentpoint.i][currentpoint.j].isTrap == TRUE)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED|FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}

		if (nomovepointi == currentpoint.i&&nomovepointj == currentpoint.j)
		{
			nomove = 1;
		}

		if (point[currentpoint.i][currentpoint.j].isKey == TRUE&&nomove == FALSE)
		{
			//mark 钥匙触发;
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (verticalwall[i][j].isBar == TRUE)
					{
						verticalwall[i][j].isWall = !verticalwall[i][j].isWall;
					}
				}
			}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					if (horizontalwall[i][j].isBar == TRUE)
					{
						horizontalwall[i][j].isWall = !horizontalwall[i][j].isWall;
					}
				}
			}
		}

		gotoxy(currentpoint.x - 4, currentpoint.y);
		switch (Level)
		{
		case 4:cout << " 木乃伊"; break;
		case 3:cout << "红木乃伊"; break;
		case 2:cout << " 蝎子"; break;
		case 1:cout << " 红蝎子"; break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		if (currentpoint.i == character.currentpoint.i&&currentpoint.j == character.currentpoint.j)
		{
			GameOver = 1;
		}
	}


	friend void moveMonster();
}whitescorpion1, whitescorpion2;

class RedScorpion :public Monster
{
public:

	RedScorpion(int x1 = 0, int y1 = 0)
	{
		start.x = x1;
		start.y = y1;
	}

	void move(int & GameOver)
	{

		//原地不动
		int nomove = 0;
		int nomovepointi = currentpoint.i;
		int nomovepointj = currentpoint.j;

		Sleep(150);

		if (point[currentpoint.i][currentpoint.j].isTrap == TRUE)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}


		gotoxy(currentpoint.x - 4, currentpoint.y);
		cout << "        ";


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		if (currentpoint.y > character.currentpoint.y)
		{
			if (horizontalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断上边是否有墙
			{
				currentpoint.y -= 5;
				currentpoint.j--;
			}
			else
			{
				if (currentpoint.x > character.currentpoint.x)
				{
					if (verticalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断左边是否有墙
					{
						currentpoint.x -= 10;
						currentpoint.i--;
					}
				}
				else if (currentpoint.x < character.currentpoint.x)//比人小
				{
					if (verticalwall[currentpoint.i + 1][currentpoint.j].isWall == FALSE)//右边
					{
						currentpoint.x += 10;
						currentpoint.i++;
					}
				}
				else if (currentpoint.x == character.currentpoint.x){ ; }
			}
		}
		else if (currentpoint.y < character.currentpoint.y)
		{
			if (horizontalwall[currentpoint.i][currentpoint.j + 1].isWall == FALSE)//判断下面
			{
				currentpoint.y += 5;
				currentpoint.j++;
			}
			else
			{
				if (currentpoint.x > character.currentpoint.x)
				{
					if (verticalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断左边是否有墙
					{
						currentpoint.x -= 10;
						currentpoint.i--;
					}
				}
				else if (currentpoint.x < character.currentpoint.x)//比人小
				{
					if (verticalwall[currentpoint.i + 1][currentpoint.j].isWall == FALSE)//右边
					{
						currentpoint.x += 10;
						currentpoint.i++;
					}
				}
				else if (currentpoint.x == character.currentpoint.x){ ; }
			}
		}
		else if (currentpoint.y == character.currentpoint.y)
		{
			if (currentpoint.x > character.currentpoint.x)
			{
				if (verticalwall[currentpoint.i][currentpoint.j].isWall == FALSE)//判断左边是否有墙
				{
					currentpoint.x -= 10;
					currentpoint.i--;
				}
			}
			else if (currentpoint.x < character.currentpoint.x)
			{
				if (verticalwall[currentpoint.i + 1][currentpoint.j].isWall == FALSE)//右边
				{
					currentpoint.x += 10;
					currentpoint.i++;
				}
			}
		}

		if (point[currentpoint.i][currentpoint.j].isTrap == TRUE)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}

		if (nomovepointi == currentpoint.i&&nomovepointj == currentpoint.j)
		{
			nomove = 1;
		}

		if (point[currentpoint.i][currentpoint.j].isKey == TRUE&&nomove == FALSE)
		{
			//mark 钥匙触发;
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (verticalwall[i][j].isBar == TRUE)
					{
						verticalwall[i][j].isWall = !verticalwall[i][j].isWall;
					}
				}
			}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					if (horizontalwall[i][j].isBar == TRUE)
					{
						horizontalwall[i][j].isWall = !horizontalwall[i][j].isWall;
					}
				}
			}
		}

		gotoxy(currentpoint.x - 4, currentpoint.y);
		switch (Level)
		{
		case 4:cout << " 木乃伊"; break;
		case 3:cout << "红木乃伊"; break;
		case 2:cout << " 蝎子"; break;
		case 1:cout << " 红蝎子"; break;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		if (currentpoint.i == character.currentpoint.i&&currentpoint.j == character.currentpoint.j)
		{
			GameOver = 1;
		}
	}

	friend void moveMonster();
}redscorpion1, redscorpion2;

void moveMonster(int & MissionCompleted, int & GameOver)
{
	Monster * monster[8];
	monster[0] = &whitemummy1;
	monster[1] = &whitemummy2;
	monster[2] = &redmummy1;
	monster[3] = &redmummy2;
	monster[4] = &whitescorpion1;
	monster[5] = &whitescorpion2;
	monster[6] = &redscorpion1;
	monster[7] = &redscorpion2;

	for (int a = 7; a >= 0; a--)
	{
		if (monster[a]->isExist)
		{
			monster[a]->move(GameOver);
		}
	}

	for (int a = 1; a <= 7; a++)
	{
		for (int b = 0; b < a; b++)
		{
			if (monster[a]->currentpoint.x == monster[b]->currentpoint.x&&monster[a]->currentpoint.y == monster[b]->currentpoint.y&&monster[a]->isExist == TRUE&&monster[b]->isExist == TRUE)
			{
				if (monster[a]->Level >= monster[b]->Level)
				{
					monster[b]->isExist = FALSE;
				}
				else
				{
					monster[a]->isExist = FALSE;
				}
			}
		}
	}

}

void initialize()
{
	//初始化怪物设置
	whitemummy1.isExist = FALSE;
	whitemummy2.isExist = FALSE;
	redmummy1.isExist = FALSE;
	redmummy2.isExist = FALSE;
	whitescorpion1.isExist = FALSE;
	whitescorpion2.isExist = FALSE;
	redscorpion1.isExist = FALSE;
	redscorpion2.isExist = FALSE;
	whitemummy1.Level = 4;
	whitemummy2.Level = 4;
	redmummy1.Level = 3;
	redmummy2.Level = 3;
	whitescorpion1.Level = 2;
	whitescorpion2.Level = 2;
	redscorpion1.Level = 1;
	redscorpion2.Level = 1;

	for (int i = 0; i < 6; i++)//初始化point
	{
		for (int j = 0; j < 6; j++)
		{
			point[i][j].i = i;
			point[i][j].j = j;
			point[i][j].x = 6 + i * 10;
			point[i][j].y = 3 + j * 5;
			point[i][j].isTrap = FALSE;
			point[i][j].isKey = FALSE;
		}
	}

	for (int i = 0; i < 7; i++)//初始化verticalwall
	{
		for (int j = 0; j < 6; j++)
		{
			verticalwall[i][j].x = 1 + i * 10;
			verticalwall[i][j].y = 3 + j * 5;
		}
	}

	for (int i = 0; i < 6; i++)//初始化horizontalwall
	{
		for (int j = 0; j < 7; j++)
		{
			horizontalwall[i][j].x = 6 + i * 10;
			horizontalwall[i][j].y = 1 + j * 5;
		}
	}

	for (int i = 0; i < 7; i++)//初始化edge
	{
		for (int j = 0; j < 6; j++)
		{
			if (verticalwall[i][j].x == WALL_LEFT || verticalwall[i][j].x == WALL_RIGHT)
			{
				verticalwall[i][j].isWall = TRUE;
				verticalwall[i][j].isExit = FALSE;
				verticalwall[i][j].isDoor = FALSE;
				verticalwall[i][j].isBar = FALSE;
			}
		}
	}
	for (int i = 0; i < 6; i++)//初始化edge
	{
		for (int j = 0; j < 7; j++)
		{
			if (horizontalwall[i][j].y == WALL_UP || horizontalwall[i][j].y == WALL_DOWN)
			{
				horizontalwall[i][j].isWall = TRUE;
				horizontalwall[i][j].isExit = FALSE;
				horizontalwall[i][j].isDoor = FALSE;
				horizontalwall[i][j].isBar = FALSE;
			}
		}
	}

	for (int i = 0; i <= 5; i++)//初始化horizontalwall
	{
		for (int j = 1; j <= 5; j++)
		{
			horizontalwall[i][j].isBar = FALSE;
			horizontalwall[i][j].isDoor = FALSE;
			horizontalwall[i][j].isWall = FALSE;
			horizontalwall[i][j].isExit = FALSE;
		}
	}

	for (int i = 1; i <= 5; i++)//初始化verticalwall
	{
		for (int j = 0; j <= 5; j++)
		{
			verticalwall[i][j].isWall = FALSE;
			verticalwall[i][j].isDoor = FALSE;
			verticalwall[i][j].isBar = FALSE;
			verticalwall[i][j].isExit = FALSE;
		}
	}

	//测试部分

	//测试部分
	

}

void paint()
{
	//画角色
	character.start.x = character.start.i * 10 + 6;
	character.start.y = character.start.j * 5 + 3;
	character.currentpoint.x = character.start.x;
	character.currentpoint.y = character.start.y;
	character.currentpoint.i = character.start.i;
	character.currentpoint.j = character.start.j;
	gotoxy(character.start.x-3, character.start.y);
	cout << "哈里森";

	//画边界
	for (int x = WALL_LEFT; x <= WALL_RIGHT; x++)
	{
		for (int y = WALL_UP; y <= WALL_DOWN; y++)
		{
			if (x == WALL_LEFT || x == WALL_RIGHT || y == WALL_UP || y == WALL_DOWN)
			{
				gotoxy(x, y);
				cout << "M";
			}
		}
	}

	//画墙
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (verticalwall[i][j].isWall == TRUE)
			{
				for (int j1 = verticalwall[i][j].y - 2; j1 <= verticalwall[i][j].y + 3; j1++)
				{
					gotoxy(verticalwall[i][j].x, j1);
					cout << "M";
				}
			}
			if (verticalwall[i][j].isExit == TRUE)
			{
				for (int j1 = verticalwall[i][j].y - 1; j1 <= verticalwall[i][j].y + 4; j1++)
				{
					gotoxy(verticalwall[i][j].x, j1);
					cout << " ";
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				gotoxy(verticalwall[i][j].x, verticalwall[i][j].y);
				cout << "出口";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (horizontalwall[i][j].isWall == TRUE)
			{
				for (int i1 = horizontalwall[i][j].x - 5; i1 <= horizontalwall[i][j].x + 5; i1++)
				{
					gotoxy(i1, horizontalwall[i][j].y);
					cout << "M";
				}
			}
			if (horizontalwall[i][j].isExit == TRUE)
			{
				for (int i1 = horizontalwall[i][j].x - 4; i1 <= horizontalwall[i][j].x + 6; i1++)
				{
					gotoxy(i1, horizontalwall[i][j].y);
					cout << " ";
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				gotoxy(horizontalwall[i][j].x - 1, horizontalwall[i][j].y);
				cout << "出口";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		}
	}
	//画陷阱
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY |	BACKGROUND_RED);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (point[i][j].isTrap == TRUE)
			{
				gotoxy(point[i][j].x - 4, point[i][j].y - 1);
				cout << "        ";
				gotoxy(point[i][j].x - 4, point[i][j].y);
				cout << "        ";
				gotoxy(point[i][j].x - 4, point[i][j].y + 1);
				cout << "        ";
				gotoxy(point[i][j].x - 4, point[i][j].y + 2);
				cout << "        ";
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (point[i][j].isKey == TRUE) //画钥匙
			{
				gotoxy(point[i][j].x-2, point[i][j].y);
				cout << "钥匙";
			}
		}
	}

	//画怪物
	Monster * monster[8];
	monster[0] = &whitemummy1;
	monster[1] = &whitemummy2;
	monster[2] = &redmummy1;
	monster[3] = &redmummy2;
	monster[4] = &whitescorpion1;
	monster[5] = &whitescorpion2;
	monster[6] = &redscorpion1;
	monster[7] = &redscorpion2;

	

	for (int a = 0; a <= 7; a++)
	{
		if (monster[a]->isExist)
		{
			if (point[monster[a]->start.i][monster[a]->start.j].isTrap == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			monster[a]->start.x = monster[a]->start.i * 10 + 6;
			monster[a]->start.y = monster[a]->start.j * 5 + 3;
			monster[a]->currentpoint.x = monster[a]->start.x;
			monster[a]->currentpoint.y = monster[a]->start.y;
			monster[a]->currentpoint.i = monster[a]->start.i;
			monster[a]->currentpoint.j = monster[a]->start.j;
			gotoxy(monster[a]->currentpoint.x - 4, monster[a]->currentpoint.y);
			switch (monster[a]->Level)
			{
			case 4:cout << " 木乃伊"; break;
			case 3:cout << "红木乃伊"; break;
			case 2:cout << " 蝎子"; break;
			case 1:cout << " 红蝎子"; break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}

	//画Bar
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (verticalwall[i][j].isBar == TRUE&&verticalwall[i][j].isWall == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				for (int j1 = verticalwall[i][j].y - 2; j1 <= verticalwall[i][j].y + 2; j1++)
				{
					gotoxy(verticalwall[i][j].x, j1);
					cout << "M";
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			if (verticalwall[i][j].isBar == TRUE&&verticalwall[i][j].isWall == FALSE)
			{
				for (int j1 = verticalwall[i][j].y - 2; j1 <= verticalwall[i][j].y + 2; j1++)
				{
					gotoxy(verticalwall[i][j].x, j1);
					cout << " ";
				}
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (horizontalwall[i][j].isBar == TRUE&&horizontalwall[i][j].isWall == TRUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				for (int i1 = horizontalwall[i][j].x - 4; i1 <= horizontalwall[i][j].x + 4; i1++)
				{
					gotoxy(i1, horizontalwall[i][j].y);
					cout << "M";
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			if (horizontalwall[i][j].isBar == TRUE&&horizontalwall[i][j].isWall == FALSE)
			{
				for (int i1 = horizontalwall[i][j].x - 4; i1 <= horizontalwall[i][j].x + 4; i1++)
				{
					gotoxy(i1, horizontalwall[i][j].y);
					cout << " ";
				}
			}
		}
	}
}

void welcome()
{
	gotoxy(0, 16);
	cout << blue;
	cout << " M      M    U      U    M      M    M      M    Y    Y" << endl;
	cout << " M M  M M    U      U    M M  M M    M M  M M     Y  Y" << endl;
	cout << " M  M   M    U      U    M  M   M    M  M   M      Y" << endl;
	cout << " M      M    U      U    M      M    M      M      Y" << endl;
	cout << " M      M     UUUUUU     M      M    M      M      Y" << endl << endl << endl;

	cout << " M      M        A       ZZZZZZZ     EEEEEEE" << endl;
	cout << " M M  M M       A A          Z       E" << endl;
	cout << " M  M   M      A   A        Z        EEEEEE" << endl;
	cout << " M      M     AAAAAAA      Z         E" << endl;
	cout << " M      M    A       A    ZZZZZZZ    EEEEEEE" << endl;
	Sleep(250);

	system("cls");
	gotoxy(0, 11);
	cout << purple;
	cout << " M      M    U      U    M      M    M      M    Y    Y" << endl;
	cout << " M M  M M    U      U    M M  M M    M M  M M     Y  Y" << endl;
	cout << " M  M   M    U      U    M  M   M    M  M   M      Y" << endl;
	cout << " M      M    U      U    M      M    M      M      Y" << endl;
	cout << " M      M     UUUUUU     M      M    M      M      Y" << endl << endl << endl;

	cout << " M      M        A       ZZZZZZZ     EEEEEEE" << endl;
	cout << " M M  M M       A A          Z       E" << endl;
	cout << " M  M   M      A   A        Z        EEEEEE" << endl;
	cout << " M      M     AAAAAAA      Z         E" << endl;
	cout << " M      M    A       A    ZZZZZZZ    EEEEEEE" << endl;
	Sleep(250);

	system("cls");
	gotoxy(0, 6);
	cout << yellow;
	cout << " M      M    U      U    M      M    M      M    Y    Y" << endl;
	cout << " M M  M M    U      U    M M  M M    M M  M M     Y  Y" << endl;
	cout << " M  M   M    U      U    M  M   M    M  M   M      Y" << endl;
	cout << " M      M    U      U    M      M    M      M      Y" << endl;
	cout << " M      M     UUUUUU     M      M    M      M      Y" << endl << endl << endl;

	cout << " M      M        A       ZZZZZZZ     EEEEEEE" << endl;
	cout << " M M  M M       A A          Z       E" << endl;
	cout << " M  M   M      A   A        Z        EEEEEE" << endl;
	cout << " M      M     AAAAAAA      Z         E" << endl;
	cout << " M      M    A       A    ZZZZZZZ    EEEEEEE" << endl;
	Sleep(250);

	system("cls");
	gotoxy(0, 1);
	cout << green;
	cout << " M      M    U      U    M      M    M      M    Y    Y" << endl;
	cout << " M M  M M    U      U    M M  M M    M M  M M     Y  Y" << endl;
	cout << " M  M   M    U      U    M  M   M    M  M   M      Y" << endl;
	cout << " M      M    U      U    M      M    M      M      Y" << endl;
	cout << " M      M     UUUUUU     M      M    M      M      Y" << endl << endl << endl;

	cout << " M      M        A       ZZZZZZZ     EEEEEEE" << endl;
	cout << " M M  M M       A A          Z       E" << endl;
	cout << " M  M   M      A   A        Z        EEEEEE" << endl;
	cout << " M      M     AAAAAAA      Z         E" << endl;
	cout << " M      M    A       A    ZZZZZZZ    EEEEEEE" << endl;
	Sleep(500);

	gotoxy(0, 14);
	cout << lightblue;
	cout << " 1.新游戏" << endl << endl;
	cout << " 2.读取进度" << endl << endl;
	cout << " 3.选择关卡" << endl << endl;
	cout << " 4.游戏说明（第一次玩必看）" << endl << endl;
	cout << " 5.关于作者" << endl << endl;

	cout << white;

}

void game(int & chapter,int & mission)
{	//undo参数
	
	int monsterexist[8][200];
	int monsterpointi[8][200];
	int monsterpointj[8][200];
	int characterpointi[200];
	int characterpointj[200];
	int bar[200];

	Monster * monster[8];
	monster[0] = &whitemummy1;
	monster[1] = &whitemummy2;
	monster[2] = &redmummy1;
	monster[3] = &redmummy2;
	monster[4] = &whitescorpion1;
	monster[5] = &whitescorpion2;
	monster[6] = &redscorpion1;
	monster[7] = &redscorpion2;


	//游戏部分
RESET:
	int undo = 0;
	int step = 0;
UNDO:
	system("cls");
	gotoxy(1, 35);
	cout << "操作说明：↑↓←→方向键移动，空格键原地不动，R键重新开始本关，U键返回上一步。"<<endl<<endl;
	cout << " 本关是第 " << chapter << " 章第 " << mission << " 关";
	int MissionCompleted = 0;
	int GameOver = 0;
	initialize();
	//导入关卡
	switch (chapter)
	{
	case 1:
	{
			  switch (mission)
			  {
			  case 1:mission1_1(); break;
			  case 2:mission1_2(); break;
			  case 3:mission1_3(); break;
			  case 4:mission1_4(); break;
			  case 5:mission1_5(); break;
			  case 6:mission1_6(); break;
			  case 7:mission1_7(); break;
			  case 8:mission1_8(); break;
			  case 9:mission1_9(); break;
			  case 10:mission1_10(); break;
			  case 11:mission1_11(); break;
			  case 12:mission1_12(); break;
			  case 13:mission1_13(); break;
			  case 14:mission1_14(); break;
			  case 15:mission1_15(); break;
			  default:{; }
			  }
	}break;
	case 2:
	{
			  switch (mission)
			  {
			  case 1:mission2_1(); break;
			  case 2:mission2_2(); break;
			  case 3:mission2_3(); break;
			  case 4:mission2_4(); break;
			  case 5:mission2_5(); break;
			  case 6:mission2_6(); break;
			  case 7:mission2_7(); break;
			  case 8:mission2_8(); break;
			  case 9:mission2_9(); break;
			  case 10:mission2_10(); break;
			  case 11:mission2_11(); break;
			  case 12:mission2_12(); break;
			  case 13:mission2_13(); break;
			  case 14:mission2_14(); break;
			  case 15:mission2_15(); break;
			  default:{; }
			  }
	}break;
	case 3:
	{
			  switch (mission)
			  {
			  case 1:mission3_1(); break;
			  case 2:mission3_2(); break;
			  case 3:mission3_3(); break;
			  case 4:mission3_4(); break;
			  case 5:mission3_5(); break;
			  case 6:mission3_6(); break;
			  case 7:mission3_7(); break;
			  case 8:mission3_8(); break;
			  case 9:mission3_9(); break;
			  case 10:mission3_10(); break;
			  case 11:mission3_11(); break;
			  case 12:mission3_12(); break;
			  case 13:mission3_13(); break;
			  case 14:mission3_14(); break;
			  case 15:mission3_15(); break;
			  default:{; }
			  }
	}break;
	case 4:
	{
			  switch (mission)
			  {
			  case 1:mission4_1(); break;
			  case 2:mission4_2(); break;
			  case 3:mission4_3(); break;
			  case 4:mission4_4(); break;
			  case 5:mission4_5(); break;
			  case 6:mission4_6(); break;
			  case 7:mission4_7(); break;
			  case 8:mission4_8(); break;
			  case 9:mission4_9(); break;
			  case 10:mission4_10(); break;
			  case 11:mission4_11(); break;
			  case 12:mission4_12(); break;
			  case 13:mission4_13(); break;
			  case 14:mission4_14(); break;
			  case 15:mission4_15(); break;
			  default:{; }
			  }
	}break;
	case 5:
	{
			  switch (mission)
			  {
			  case 1:mission5_1(); break;
			  case 2:mission5_2(); break;
			  case 3:mission5_3(); break;
			  case 4:mission5_4(); break;
			  case 5:mission5_5(); break;
			  case 6:mission5_6(); break;
			  case 7:mission5_7(); break;
			  case 8:mission5_8(); break;
			  case 9:mission5_9(); break;
			  case 10:mission5_10(); break;
			  case 11:mission5_11(); break;
			  case 12:mission5_12(); break;
			  case 13:mission5_13(); break;
			  case 14:mission5_14(); break;
			  case 15:mission5_15(); break;
			  default:{; }
			  }
	}break;
	}
	if (undo == 1&&step>1&&step<200)
	{
		//undo
		step--;
		//bar
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (verticalwall[i][j].isBar == TRUE)
				{
					verticalwall[i][j].isWall = bar[step];
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (horizontalwall[i][j].isBar == TRUE)
				{
					horizontalwall[i][j].isWall = bar[step];
				}
			}
		}
		//character
		character.start.i = characterpointi[step];
		character.start.j = characterpointj[step];
		//monster
		for (int a = 0; a < 8; a++)
		{
			monster[a]->isExist = monsterexist[a][step];
			monster[a]->start.i = monsterpointi[a][step];
			monster[a]->start.j = monsterpointj[a][step];
		}
		undo = 0;
	}
	paint();
	while (!MissionCompleted&&!GameOver)
	{
	J:

		char move;
		move = _getch();
		if (move == 32){ ; }//空格
		else if (move == 114 || move == 82){ goto RESET; }
		else if (move == 85 || move == 117)//U键undo
		{
			undo = 1;
			goto UNDO;
		}
		else
		{
			gotoxy(character.currentpoint.x-4, character.currentpoint.y);
			cout << "        ";
			if (move)
			{
				move = _getch();
				if (move == 72)//上键
				{
					if (horizontalwall[character.currentpoint.i][character.currentpoint.j].isExit == TRUE)
					{
						MissionCompleted = 1;
					}
					if (!MissionCompleted)
					{
						if (horizontalwall[character.currentpoint.i][character.currentpoint.j].isWall == TRUE)
						{
							gotoxy(character.currentpoint.x-3, character.currentpoint.y);
							cout << "哈里森";
							goto J;
						}
						else if (horizontalwall[character.currentpoint.i][character.currentpoint.j].isWall == FALSE)
						{
							character.currentpoint.y -= 5;
							character.currentpoint.j--;
						}
					}
				}
				if (move == 80)//下键
				{
					if (horizontalwall[character.currentpoint.i][character.currentpoint.j + 1].isExit == TRUE)
					{
						MissionCompleted = 1;
					}
					if (!MissionCompleted)
					{
						if (horizontalwall[character.currentpoint.i][character.currentpoint.j + 1].isWall == TRUE)
						{
							gotoxy(character.currentpoint.x-3, character.currentpoint.y);
							cout << "哈里森";
							goto J;
						}
						else if (horizontalwall[character.currentpoint.i][character.currentpoint.j + 1].isWall == FALSE)
						{
							character.currentpoint.y += 5;
							character.currentpoint.j++;
						}
					}
				}
				if (move == 75)//左键
				{
					if (verticalwall[character.currentpoint.i][character.currentpoint.j].isExit == TRUE)
					{
						MissionCompleted = 1;
					}
					if (!MissionCompleted)
					{
						if (verticalwall[character.currentpoint.i][character.currentpoint.j].isWall == TRUE)
						{
							gotoxy(character.currentpoint.x-3, character.currentpoint.y);
							cout << "哈里森";
							goto J;
						}
						else if (verticalwall[character.currentpoint.i][character.currentpoint.j].isWall == FALSE)
						{
							character.currentpoint.x -= 10;
							character.currentpoint.i--;
						}
					}
				}
				if (move == 77)//右键
				{
					if (verticalwall[character.currentpoint.i + 1][character.currentpoint.j].isExit == TRUE)
					{
						MissionCompleted = 1;
					}
					if (!MissionCompleted)
					{
						if (verticalwall[character.currentpoint.i + 1][character.currentpoint.j].isWall == TRUE)
						{
							gotoxy(character.currentpoint.x-3, character.currentpoint.y);
							cout << "哈里森";
							goto J;
						}
						else if (verticalwall[character.currentpoint.i + 1][character.currentpoint.j].isWall == FALSE)
						{
							character.currentpoint.x += 10;
							character.currentpoint.i++;
						}
					}
				}
				gotoxy(character.currentpoint.x-3, character.currentpoint.y);
				cout << "哈里森";

				if (point[character.currentpoint.i][character.currentpoint.j].isTrap == TRUE)
				{
					GameOver = 1;
				}
				else if (point[character.currentpoint.i][character.currentpoint.j].isKey == TRUE)
				{
					//mark 钥匙触发;
					for (int i = 0; i < 7; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (verticalwall[i][j].isBar == TRUE)
							{
								verticalwall[i][j].isWall = !verticalwall[i][j].isWall;
							}
						}
					}
					for (int i = 0; i < 6; i++)
					{
						for (int j = 0; j < 7; j++)
						{
							if (horizontalwall[i][j].isBar == TRUE)
							{
								horizontalwall[i][j].isWall = !horizontalwall[i][j].isWall;
							}
						}
					}
				}

			}
		}
		if (!MissionCompleted&&!GameOver)
		{
			moveMonster(MissionCompleted, GameOver);
		}
		
		step++;//为了显眼

		//bar
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (verticalwall[i][j].isBar == TRUE)
				{
					bar[step] = verticalwall[i][j].isWall;
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (horizontalwall[i][j].isBar == TRUE)
				{
					bar[step] = horizontalwall[i][j].isWall;
				}
			}
		}
		//character
		characterpointi[step] = character.currentpoint.i;
		characterpointj[step] = character.currentpoint.j;
		//monster
		for (int a = 0; a < 8; a++)
		{
			monsterexist[a][step] = monster[a]->isExist;
			monsterpointi[a][step] = monster[a]->currentpoint.i;
			monsterpointj[a][step] = monster[a]->currentpoint.j;
		}

		//画出口
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (verticalwall[i][j].isExit == TRUE)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					gotoxy(verticalwall[i][j].x, verticalwall[i][j].y);
					cout << "出口";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				
				if (horizontalwall[i][j].isExit == TRUE)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					gotoxy(horizontalwall[i][j].x - 1, horizontalwall[i][j].y);
					cout << "出口";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
			}
		}
		for (int i = 0; i < 6; i++) //画钥匙
		{
			for (int j = 0; j < 6; j++)
			{
				if (point[i][j].isKey == TRUE&&point[character.currentpoint.i][character.currentpoint.j].isKey == FALSE)
				{
					int paintKEY = 1;
					for (int a = 0; a < 7; a++)
					{
						if (point[monster[a]->currentpoint.i][monster[a]->currentpoint.j].isKey == TRUE&&monster[a]->isExist == TRUE){paintKEY=0;}
					}
					if (paintKEY == 1)
					{
						gotoxy(point[i][j].x-2, point[i][j].y);
						cout << "钥匙";
					}
				}
			}
		}

		//画墙
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (verticalwall[i][j].isBar == TRUE&&verticalwall[i][j].isWall == TRUE)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					for (int j1 = verticalwall[i][j].y - 2; j1 <= verticalwall[i][j].y + 2; j1++)
					{
						gotoxy(verticalwall[i][j].x, j1);
						cout << "M";
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				if (verticalwall[i][j].isBar == TRUE&&verticalwall[i][j].isWall == FALSE)
				{
					for (int j1 = verticalwall[i][j].y - 2; j1 <= verticalwall[i][j].y + 2; j1++)
					{
						gotoxy(verticalwall[i][j].x, j1);
						cout << " ";
					}
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (horizontalwall[i][j].isBar == TRUE&&horizontalwall[i][j].isWall == TRUE)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					for (int i1 = horizontalwall[i][j].x - 4; i1 <= horizontalwall[i][j].x + 4; i1++)
					{
						gotoxy(i1, horizontalwall[i][j].y);
						cout << "M";
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				if (horizontalwall[i][j].isBar == TRUE&&horizontalwall[i][j].isWall == FALSE)
				{
					for (int i1 = horizontalwall[i][j].x - 4; i1 <= horizontalwall[i][j].x + 4; i1++)
					{
						gotoxy(i1, horizontalwall[i][j].y);
						cout << " ";
					}
				}
			}
		}


	}


	if (MissionCompleted)
	{
		if (chapter == 5 && mission == 15)
		{
			system("cls");
			gotoxy(0, 1);
			cout << "   A     L        L" << endl;
			cout << "  A A    L        L" << endl;
			cout << " A   A   L        L" << endl;
			cout << "AAAAAAA  L        L" << endl;
			cout << "A     A  LLLLLLL  LLLLLLL" << endl << endl;

			cout << "M     M  IIIIIII  SSSSSSS  SSSSSSS  IIIIIII  OOOOOOO  N     N  SSSSSSS" << endl;
			cout << "M M M M     I     S        S           I     O     O  N N   N  S" << endl;
			cout << "M  M  M     I     SSSSSSS  SSSSSSS     I     O     O  N  N  N  SSSSSSS" << endl;
			cout << "M     M     I           S        S     I     O     O  N   N N        S" << endl;
			cout << "M     M  IIIIIII  SSSSSSS  SSSSSSS  IIIIIII  OOOOOOO  N     N  SSSSSSS" << endl << endl;

			cout << "CCCCCCC  OOOOOOO  M     M  PPPPPPP  L        EEEEEEE  TTTTTTT  EEEEEEE   ||" << endl;
			cout << "C        O     O  M M M M  P     P  L        E           T     E         ||" << endl;
			cout << "C        O     O  M  M  M  PPPPPPP  L        EEEEEE      T     EEEEEE    ||" << endl;
			cout << "C        O     O  M     M  P        L        E           T     E           " << endl;
			cout << "CCCCCCC  OOOOOOO  M     M  P        LLLLLLL  EEEEEEE     T     EEEEEEE   []" << endl << endl;

			cout << "恭喜！你已经完成所有关卡。按任意键返回主菜单。" << endl;
			char fuck3;
			fuck3 = _getch();
			if (fuck3){ ; }

		}
		else
		{
			system("cls");
			gotoxy(0, 1);
			cout << "M     M  IIIIIII  SSSSSSS  SSSSSSS  IIIIIII  OOOOOOO  N     N" << endl;
			cout << "M M M M     I     S        S           I     O     O  N N   N" << endl;
			cout << "M  M  M     I     SSSSSSS  SSSSSSS     I     O     O  N  N  N" << endl;
			cout << "M     M     I           S        S     I     O     O  N   N N" << endl;
			cout << "M     M  IIIIIII  SSSSSSS  SSSSSSS  IIIIIII  OOOOOOO  N     N" << endl << endl;

			cout << "CCCCCCC  OOOOOOO  M     M  PPPPPPP  L        EEEEEEE  TTTTTTT  EEEEEEE   ||" << endl;
			cout << "C        O     O  M M M M  P     P  L        E           T     E         ||" << endl;
			cout << "C        O     O  M  M  M  PPPPPPP  L        EEEEEE      T     EEEEEE    ||" << endl;
			cout << "C        O     O  M     M  P        L        E           T     E           " << endl;
			cout << "CCCCCCC  OOOOOOO  M     M  P        LLLLLLL  EEEEEEE     T     EEEEEEE   []" << endl << endl;

			cout << "按ENTER进入下一关，按R重新开始本关，按S保存进度，按B返回主菜单。" << endl;
		NEXT1:
			char next1;
			next1 = _getch();
			if (next1 == 13)//回车ENTER的ASCII码是13
			{
				if (chapter <= 5 && mission <= 14){ mission++; game(chapter, mission); }
				else if (chapter <= 4 && mission == 15){ chapter++; mission = 1; game(chapter, mission); }
			}
			else if (next1 == 66 || next1 == 98){ ; }//B键
			else if (next1 == 114 || next1 == 82){ game(chapter, mission); }//R键
			else if (next1 == 83 || next1 == 115)//S键
			{
				ofstream File;
				File.open("save.txt");
				if (chapter <= 5 && mission <= 14){ File << chapter << " " << mission + 1; }
				else if (chapter <= 4 && mission == 15){ File << chapter + 1 << " " << 1; }
				else if (chapter == 5 && mission == 15){ File << 5 << " " << 15; }
				File.close();
				cout << "记录保存成功！" << endl;
				goto NEXT1;
			}
			else { goto NEXT1; }
		}
		
	}

	else if (GameOver)
	{
		system("cls");
		gotoxy(0, 1);
		cout << "GGGGGGG     A     M     M  EEEEEEE" << endl;
		cout << "G          A A    M M M M  E" << endl;
		cout << "G  GGGG   A   A   M  M  M  EEEEEE" << endl;
		cout << "G     G  AAAAAAA  M     M  E" << endl;
		cout << "GGGGGGG  A     A  M     M  EEEEEEE" << endl << endl;

		cout << "OOOOOOO  V     V  EEEEEEE  RRRRRRR" << endl;
		cout << "O     O  V     V  E        R     R" << endl;
		cout << "O     O   V   V   EEEEEE   RRRRRRR" << endl;
		cout << "O     O    V V    E        R  R" << endl;
		cout << "OOOOOOO     V     EEEEEEE  R    RR" << endl << endl;

		cout << "按R重新开始本关，按S保存进度，按B返回主菜单。" << endl;
	NEXT2:
		char next2;
		next2 = _getch();
		if (next2 == 114 || next2 == 82){ game(chapter, mission); }
		else if (next2 == 66 || next2 == 98){ ; }
		else if (next2 == 83 || next2 == 115)
		{
			ofstream File;
			File.open("save.txt");
			File << chapter <<" "<< mission; 
			File.close();
			cout << "记录保存成功！" << endl;
			goto NEXT2;
		}
		else { goto NEXT2; }
	}
}

void main()
{
	int chapter=-1, mission=-1;
WELCOME:
	system("cls");
	welcome();
WELCOME1:
	char choose;
	choose = _getch();
	switch (choose)
	{
	case 49://新游戏 数字1=>ASCII 49
		{
			  chapter = 1;
			  mission = 1;
			  game(chapter,mission);
			  goto WELCOME;

		}break;
	case 50://读取进度 数字2=>ASCII 52
		{
				ifstream File;
				File.open("save.txt");
				File >> chapter >> mission;
				File.close();
				if (chapter == -1 || mission == -1)
				{
					system("cls"); cout << "找不到可读取的进度！按任意键返回主菜单。"; 
					char fuck4;
					fuck4 = _getch();
					if (fuck4){ goto WELCOME; }
				}
				else { game(chapter, mission); }

				goto WELCOME;
		}break;
	case 51://选择关卡 数字3=>ASCII 51
		{
			  system("cls");
			  cout << "请选择章节（1-5）" << endl;
			  cin >> chapter;
			  while (chapter > 5 || chapter < 0){ cout << "输入错误，请重新输入章节（1-5）。" << endl; cin >> chapter; }
			  cout << "请选择关卡（1-15）" << endl;
			  cin >> mission;
			  while (mission > 15 || mission < 0){ cout << "输入错误，请重新输入关卡（1-15）。" << endl; cin >> mission; }
			  game(chapter, mission);
			  goto WELCOME;

		}break;
	case 52://游戏说明 数字3=>ASCII 52
		{
				system("cls");
				cout << "游戏说明：" << endl;
				cout << "Mummy Maze是一款有探索色彩的休闲游戏，游戏中探险家哈里森囚徒孤身来到埃及，在满是陷阱和木乃伊的金字塔中寻找失落的宝藏。" << endl << endl;

				cout << "游戏目标：躲过木乃伊和红色陷阱到达出口即完成当前关卡。" << endl << endl;

				cout << "探险家只能上下左右移动或停留在原地，每次移动1格。" << endl;
				cout << "白色木乃伊：总是先尝试在水平方向接近探险家，每次移动2格。" << endl;
				cout << "红色木乃伊：总是先尝试在垂直方向接近探险家，每次移动2格。" << endl;
				cout << "白色蝎子：总是先尝试在水平方向接近玩家，每次移动1格。" << endl;
				cout << "红色蝎子：总是先尝试在垂直方向接近玩家，每次移动1格。" << endl;
				cout << "红色陷阱：陷阱会杀死探险家，但木乃伊和蝎子可以安全的通过。" << endl;
				cout << "绿色铁闸：可以通过钥匙来打开或关闭。" << endl;
				cout << "钥匙：探险家，木乃伊或蝎子经过钥匙所在的位置时，都会改变门的状态。" << endl<<endl;

				cout << endl << "按任意键返回主菜单。" << endl;
				char fuck1;
				fuck1 = _getch();
				if (fuck1){ goto WELCOME; }
		}break;
	case 53://关于作者 数字4=>ASCII 53
		{
			   system("cls");
			   code();
			   cout << endl << "请关注作者的微信获取最新动态！" << endl;
			   cout << endl << "按任意键返回主菜单。"<<endl;
			   char fuck2;
			   fuck2 = _getch();
			   if (fuck2){ goto WELCOME; }
		}break;
	default:goto WELCOME1;
	}
}




//关卡
void mission1_1()
{
	character.start.i = 0;
	character.start.j = 1;
	verticalwall[6][2].isExit = TRUE;

	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;

	verticalwall[3][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 5;
}

void mission1_2()
{
	character.start.i = 2;
	character.start.j = 4;
	horizontalwall[5][0].isExit = TRUE;

	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;

	verticalwall[1][0].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 3;
	whitemummy1.start.j = 1;

}

void mission1_3()
{
	character.start.i = 1;
	character.start.j = 4;
	verticalwall[0][0].isExit = TRUE;


	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;

	verticalwall[1][0].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 1;

}

void mission1_4()
{
	character.start.i = 1;
	character.start.j = 3;
	verticalwall[6][5].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;


	verticalwall[2][2].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 2;

}

void mission1_5()
{
	character.start.i = 2;
	character.start.j = 2;
	horizontalwall[4][0].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;

	verticalwall[1][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 0;
	whitemummy1.start.j = 0;

}

void mission1_6()
{
	character.start.i = 5;
	character.start.j = 1;
	horizontalwall[1][0].isExit = TRUE;


	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;

	verticalwall[4][0].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 5;

}

void mission1_7()
{
	character.start.i = 0;
	character.start.j = 4;
	verticalwall[0][0].isExit = TRUE;

	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;


	verticalwall[3][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[1][3].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 2;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 0;
	whitescorpion1.start.j = 1;

	point[2][5].isTrap = TRUE;


}

void mission1_8()
{
	character.start.i = 5;
	character.start.j = 3;
	verticalwall[0][4].isExit = TRUE;


	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;

	verticalwall[4][0].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;

	point[3][1].isTrap = TRUE;

	redmummy1.isExist = TRUE;
	redmummy1.start.i = 2;
	redmummy1.start.j = 4;

}

void mission1_9()
{
	character.start.i = 2;
	character.start.j = 2;
	verticalwall[6][3].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;

	verticalwall[1][0].isWall = TRUE;
	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 3;

}

void mission1_10()
{
	character.start.i = 4;
	character.start.j = 4;
	horizontalwall[3][0].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;

	verticalwall[3][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 3;
	whitemummy1.start.j = 1;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 4;
	whitemummy2.start.j = 1;

}

void mission1_11()
{
	character.start.i = 0;
	character.start.j = 0;
	horizontalwall[3][6].isExit = TRUE;


	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;

	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 4;
	whitemummy1.start.j = 5;

}

void mission1_12()
{
	character.start.i = 3;
	character.start.j = 2;
	verticalwall[6][3].isExit = TRUE;


	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;

	verticalwall[2][0].isWall = TRUE;
	verticalwall[5][0].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 0;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 4;
	whitescorpion1.start.j = 5;

	point[0][3].isTrap = TRUE;
	point[2][1].isKey = TRUE;
	horizontalwall[4][3].isBar = TRUE;
	horizontalwall[4][3].isWall = TRUE;

}

void mission1_13()
{
	character.start.i = 1;
	character.start.j = 1;
	horizontalwall[2][6].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;

	verticalwall[2][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[1][3].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[3][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 3;

}

void mission1_14()
{
	character.start.i = 1;
	character.start.j = 0;
	verticalwall[6][4].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;

	verticalwall[1][2].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 5;

	point[4][4].isTrap = TRUE;

}

void mission1_15()
{
	character.start.i = 2;
	character.start.j = 2;
	verticalwall[0][4].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;


	verticalwall[2][1].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[3][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 3;

	point[0][0].isTrap = TRUE;

}


void mission2_1()
{
	character.start.i = 5;
	character.start.j = 2;
	verticalwall[6][3].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;


	verticalwall[2][0].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 4;

	point[2][0].isTrap = TRUE;

}

void mission2_2()
{
	character.start.i = 4;
	character.start.j = 4;
	horizontalwall[0][6].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;
	


	verticalwall[1][2].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 0;
	whitemummy1.start.j = 4;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 2;
	whitescorpion1.start.j = 3;

	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[5][2].isBar = TRUE;
	point[3][4].isKey = TRUE;

}

void mission2_3()
{
	character.start.i = 1;
	character.start.j = 4;
	horizontalwall[2][6].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;



	verticalwall[2][1].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;
	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 3;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 4;
	whitemummy2.start.j = 5;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 0;
	whitescorpion1.start.j = 1;

	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[2][3].isBar = TRUE;
	point[1][5].isKey = TRUE;

	point[0][1].isTrap = TRUE;

}

void mission2_4()
{
	character.start.i = 0;
	character.start.j = 1;
	horizontalwall[0][0].isExit = TRUE;


	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;



	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 3;
	whitemummy1.start.j = 0;

}

void mission2_5()
{
	character.start.i = 2;
	character.start.j = 1;
	verticalwall[0][0].isExit = TRUE;


	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;



	verticalwall[1][0].isWall = TRUE;
	verticalwall[5][0].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 1;


}

void mission2_6()
{
	character.start.i = 1;
	character.start.j = 5;
	verticalwall[6][3].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;


	horizontalwall[4][5].isWall = TRUE;
	horizontalwall[4][5].isBar = TRUE;
	point[4][3].isKey = TRUE;



	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 3;
	whitemummy1.start.j = 3;


}

void mission2_7()
{
	character.start.i = 2;
	character.start.j = 3;
	horizontalwall[0][6].isExit = TRUE;


	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;


	verticalwall[1][0].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 0;
	whitemummy1.start.j = 4;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 1;
	whitemummy2.start.j = 5;

	point[3][1].isTrap = TRUE;


}

void mission2_8()
{
	character.start.i = 4;
	character.start.j = 0;
	verticalwall[6][3].isExit = TRUE;


	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;


	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;
	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 4;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 3;
	whitescorpion1.start.j = 5;

	point[4][3].isTrap = TRUE;


}

void mission2_9()
{
	character.start.i = 5;
	character.start.j = 5;
	verticalwall[0][1].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;


	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[5][0].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 0;

	point[3][2].isTrap = TRUE;

	horizontalwall[3][3].isBar = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	point[0][3].isKey = TRUE;


}

void mission2_10()
{
	character.start.i = 1;
	character.start.j = 1;
	horizontalwall[2][6].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;


	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[1][3].isWall = TRUE;
	verticalwall[3][5].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 3;


}

void mission2_11()
{
	character.start.i = 3;
	character.start.j = 1;
	verticalwall[0][3].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;



	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[5][0].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;



	redmummy1.isExist = TRUE;
	redmummy1.start.i = 3;
	redmummy1.start.j = 4;
	redscorpion1.isExist = TRUE;
	redscorpion1.start.i = 0;
	redscorpion1.start.j = 2;

	point[1][4].isTrap = TRUE;
}

void mission2_12()
{
	character.start.i = 3;
	character.start.j = 0;
	horizontalwall[3][6].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;

	verticalwall[1][0].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;

	redmummy1.isExist = TRUE;
	redmummy1.start.i = 1;
	redmummy1.start.j = 2;

	point[1][2].isTrap = TRUE;
}

void mission2_13()
{
	character.start.i = 5;
	character.start.j = 3;
	horizontalwall[4][6].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;



	verticalwall[1][1].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 3;
	whitemummy1.start.j = 5;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 5;
	whitemummy2.start.j = 5;

	point[3][5].isTrap = TRUE;
}

void mission2_14()
{
	character.start.i = 0;
	character.start.j = 3;
	horizontalwall[1][0].isExit = TRUE;


	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;



	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 0;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 3;
	whitemummy2.start.j = 0;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 0;
	whitescorpion1.start.j = 1;


	point[5][4].isTrap = TRUE;

	point[5][3].isKey = TRUE;
	horizontalwall[4][5].isBar = TRUE;
	horizontalwall[4][5].isWall = TRUE;

}

void mission2_15()
{
	character.start.i = 5;
	character.start.j = 5;
	horizontalwall[1][6].isExit = TRUE;


	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;

	verticalwall[1][5].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;
	point[3][1].isTrap = TRUE;
	redmummy1.isExist = TRUE;
	redscorpion1.isExist = TRUE;
	redmummy1.start.i = 0;
	redmummy1.start.j = 0;
	redscorpion1.start.i = 1;
	redscorpion1.start.j = 1;
}


void mission3_1()
{
	character.start.i = 5;
	character.start.j = 0;
	verticalwall[0][4].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;



	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 0;
	whitemummy1.start.j = 1;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 2;
	whitescorpion1.start.j = 1;


	point[3][3].isTrap = TRUE;

}

void mission3_2()
{
	character.start.i = 2;
	character.start.j = 1;
	verticalwall[0][0].isExit = TRUE;


	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;


	verticalwall[1][0].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][0].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 1;


}

void mission3_3()
{
	character.start.i = 2;
	character.start.j = 1;
	verticalwall[0][5].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;



	verticalwall[1][0].isWall = TRUE;
	verticalwall[1][2].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;

	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 0;
	whitemummy1.start.j = 4;
	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 3;


	point[0][3].isTrap = TRUE;

}

void mission3_4()
{
	character.start.i = 0;
	character.start.j = 3;
	verticalwall[0][0].isExit = TRUE;


	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;


	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;

	redmummy1.isExist = TRUE;
	redmummy1.start.i = 0;
	redmummy1.start.j = 1;



	point[5][0].isTrap = TRUE;
	point[2][3].isTrap = TRUE;

}

void mission3_5()
{
	character.start.i = 5;
	character.start.j = 0;
	horizontalwall[1][0].isExit = TRUE;


	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;


	verticalwall[2][0].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 0;



	point[0][0].isTrap = TRUE;
	point[2][1].isTrap = TRUE;

	horizontalwall[1][2].isBar = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	point[0][4].isKey = TRUE;


}

void mission3_6()
{
	character.start.i = 5;
	character.start.j = 3;
	verticalwall[6][1].isExit = TRUE;


	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;


	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 0;

}

void mission3_7()
{
	character.start.i = 5;
	character.start.j = 4;
	horizontalwall[0][6].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;


	verticalwall[1][2].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][5].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 0;
	whitemummy1.start.j = 5;

	point[0][0].isTrap = TRUE;
	point[4][5].isTrap = TRUE;
}

void mission3_8()
{
	character.start.i = 2;
	character.start.j = 3;
	verticalwall[6][1].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;


	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 3;
	whitemummy1.start.j = 0;

	point[0][0].isTrap = TRUE;
	point[1][2].isTrap = TRUE;

	point[2][1].isKey = TRUE;
	horizontalwall[1][4].isBar = TRUE;
	horizontalwall[1][4].isWall = TRUE;
}

void mission3_9()
{
	character.start.i = 3;
	character.start.j = 0;
	horizontalwall[3][6].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;


	verticalwall[1][0].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;


	redmummy1.isExist = TRUE;
	redmummy1.start.i = 1;
	redmummy1.start.j = 2;

	point[1][2].isTrap = TRUE;

}

void mission3_10()
{
	character.start.i = 4;
	character.start.j = 3;
	horizontalwall[3][0].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;


	verticalwall[1][3].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 0;

	point[2][0].isTrap = TRUE;

}

void mission3_11()
{
	character.start.i = 0;
	character.start.j = 1;
	horizontalwall[1][0].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	

	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 0;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 3;
	whitemummy2.start.j = 4;

	point[3][3].isKey = TRUE;
	horizontalwall[3][2].isBar = TRUE;
	horizontalwall[3][2].isWall = TRUE;

}

void mission3_12()
{
	character.start.i = 4;
	character.start.j = 2;
	horizontalwall[3][0].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;


	verticalwall[1][4].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;



	redmummy1.isExist = TRUE;
	redmummy1.start.i = 1;
	redmummy1.start.j = 0;
	redscorpion1.isExist = TRUE;
	redscorpion1.start.i = 2;
	redscorpion1.start.j = 0;

	point[1][4].isTrap = TRUE;


}

void mission3_13()
{
	character.start.i = 3;
	character.start.j = 2;
	verticalwall[6][3].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;


	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 5;
	whitemummy1.start.j = 4;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 1;
	whitemummy2.start.j = 5;

	point[3][5].isKey = TRUE;
	horizontalwall[3][4].isBar = TRUE;
	horizontalwall[3][4].isWall = TRUE;


}

void mission3_14()
{
	character.start.i = 4;
	character.start.j = 0;
	verticalwall[6][5].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;


	verticalwall[1][2].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 5;


}

void mission3_15()
{
	character.start.i = 5;
	character.start.j = 5;
	horizontalwall[5][0].isExit = TRUE;


	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;


	verticalwall[1][2].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][0].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 0;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 3;
	whitescorpion1.start.j = 1;

	point[0][1].isKey = TRUE;
	horizontalwall[4][5].isBar = TRUE;
	horizontalwall[4][5].isWall = TRUE;
}


void mission4_1()
{
	character.start.i = 5;
	character.start.j = 1;
	verticalwall[6][5].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;


	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;



	redmummy1.isExist = TRUE;
	redmummy1.start.i = 2;
	redmummy1.start.j = 4;
	redmummy2.isExist = TRUE;
	redmummy2.start.i = 3;
	redmummy2.start.j = 3;

	point[3][0].isTrap = TRUE;

}

void mission4_2()
{
	character.start.i = 4;
	character.start.j = 2;
	horizontalwall[4][6].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;


	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 4;
	whitemummy1.start.j = 4;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 2;
	whitemummy2.start.j = 5;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 0;
	whitescorpion1.start.j = 5;

	point[0][5].isTrap = TRUE;

	point[0][1].isKey = TRUE;
	horizontalwall[4][5].isBar = TRUE;
	horizontalwall[4][5].isWall = TRUE;

}

void mission4_3()
{
	character.start.i = 1;
	character.start.j = 2;
	horizontalwall[4][0].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;


	verticalwall[1][0].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[3][5].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 4;
	whitemummy1.start.j = 0;

	point[0][4].isTrap = TRUE;

	point[1][4].isKey = TRUE;
	horizontalwall[5][4].isBar = TRUE;
	horizontalwall[5][4].isWall = TRUE;

}

void mission4_4()
{
	character.start.i = 3;
	character.start.j = 3;
	verticalwall[0][2].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;


	verticalwall[1][1].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][0].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 1;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 3;
	whitemummy2.start.j = 1;


	point[3][0].isTrap = TRUE;

}

void mission4_5()
{
	character.start.i = 1;
	character.start.j = 3;
	horizontalwall[5][6].isExit = TRUE;


	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;


	verticalwall[1][2].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;




	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 5;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 4;
	whitemummy2.start.j = 3;


	point[0][2].isTrap = TRUE;

}

void mission4_6()
{
	character.start.i = 3;
	character.start.j = 0;
	horizontalwall[5][0].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;



	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;




	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 4;
	whitemummy1.start.j = 1;

	point[0][0].isTrap = TRUE;
	point[4][3].isTrap = TRUE;

}

void mission4_7()
{
	character.start.i = 1;
	character.start.j = 4;
	verticalwall[6][1].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;



	verticalwall[1][3].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 0;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 3;
	whitemummy2.start.j = 0;

	point[1][2].isKey = TRUE;
	horizontalwall[2][3].isBar = TRUE;
	horizontalwall[2][3].isWall = TRUE;

}

void mission4_8()
{
	character.start.i = 1;
	character.start.j = 5;
	verticalwall[6][3].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;



	verticalwall[1][2].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 3;
	whitemummy1.start.j = 3;

	point[4][3].isKey = TRUE;
	horizontalwall[4][5].isBar = TRUE;
	horizontalwall[4][5].isWall = TRUE;

}

void mission4_9()
{
	character.start.i = 0;
	character.start.j = 0;
	verticalwall[0][2].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;



	verticalwall[1][0].isWall = TRUE;
	verticalwall[1][3].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;


	redmummy1.isExist = TRUE;
	redmummy1.start.i = 0;
	redmummy1.start.j = 5;
	redmummy2.isExist = TRUE;
	redmummy2.start.i = 1;
	redmummy2.start.j = 4;

	point[0][4].isTrap = TRUE;


}

void mission4_10()
{
	character.start.i = 0;
	character.start.j = 0;
	horizontalwall[1][6].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;



	verticalwall[1][2].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 0;
	whitemummy1.start.j = 2;

	point[0][4].isTrap = TRUE;

	point[1][4].isKey = TRUE;
	horizontalwall[3][3].isBar = TRUE;
	horizontalwall[3][3].isWall = TRUE;


}

void mission4_11()
{
	character.start.i = 1;
	character.start.j = 1;
	horizontalwall[3][6].isExit = TRUE;


	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;



	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 4;

	point[1][3].isTrap = TRUE;

	point[0][0].isKey = TRUE;
	horizontalwall[4][3].isBar = TRUE;
	horizontalwall[4][3].isWall = TRUE;


}

void mission4_12()
{
	character.start.i = 5;
	character.start.j = 3;
	horizontalwall[1][0].isExit = TRUE;


	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;

	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 4;

	point[0][0].isTrap = TRUE;
	point[2][1].isTrap = TRUE;

	point[3][5].isKey = TRUE;
	horizontalwall[3][2].isBar = TRUE;
	horizontalwall[3][2].isWall = TRUE;


}

void mission4_13()
{
	character.start.i = 3;
	character.start.j = 3;
	verticalwall[6][3].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;

	verticalwall[1][0].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;



	redmummy1.isExist = TRUE;
	redmummy1.start.i = 3;
	redmummy1.start.j = 4;
	redmummy2.isExist = TRUE;
	redmummy2.start.i = 5;
	redmummy2.start.j = 4;

	point[0][5].isTrap = TRUE;


}

void mission4_14()
{
	character.start.i = 5;
	character.start.j = 5;
	verticalwall[0][1].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[2][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;

	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][5].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[5][0].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 0;

	point[3][2].isTrap = TRUE;

	point[0][3].isKey = TRUE;
	horizontalwall[3][3].isBar = TRUE;
	horizontalwall[3][3].isWall = TRUE;


}

void mission4_15()
{
	character.start.i = 4;
	character.start.j = 0;
	horizontalwall[4][6].isExit = TRUE;


	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;

	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;




	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 2;
	whitemummy1.start.j = 5;

	point[4][3].isTrap = TRUE;

	point[2][0].isKey = TRUE;
	horizontalwall[2][5].isBar = TRUE;
	horizontalwall[2][5].isWall = TRUE;

	
}


void mission5_1()
{
	character.start.i = 4;
	character.start.j = 5;
	verticalwall[0][4].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;

	verticalwall[1][2].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[3][0].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 2;

	point[2][5].isTrap = TRUE;

	point[2][3].isKey = TRUE;
	horizontalwall[3][1].isBar = TRUE;
	horizontalwall[3][1].isWall = TRUE;


}

void mission5_2()
{
	character.start.i = 5;
	character.start.j = 2;
	verticalwall[0][0].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;

	verticalwall[1][3].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 0;
	whitemummy1.start.j = 0;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 4;
	whitescorpion1.start.j = 0;

	point[1][3].isTrap = TRUE;



}

void mission5_3()
{
	character.start.i = 0;
	character.start.j = 4;
	verticalwall[6][2].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;

	verticalwall[2][5].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;



	redmummy1.isExist = TRUE;
	redmummy1.start.i = 4;
	redmummy1.start.j = 2;

	point[4][3].isTrap = TRUE;



}

void mission5_4()
{
	character.start.i = 2;
	character.start.j = 4;
	horizontalwall[0][0].isExit = TRUE;


	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[0][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;

	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;



	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 4;
	whitemummy1.start.j = 2;

	point[2][1].isTrap = TRUE;



}

void mission5_5()
{
	character.start.i = 5;
	character.start.j = 1;
	verticalwall[6][5].isExit = TRUE;


	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;

	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][0].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][0].isWall = TRUE;
	verticalwall[4][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;



	redmummy1.isExist = TRUE;
	redmummy1.start.i = 3;
	redmummy1.start.j = 3;
	redmummy2.isExist = TRUE;
	redmummy2.start.i = 2;
	redmummy2.start.j = 4;

	point[3][0].isTrap = TRUE;



}

void mission5_6()
{
	character.start.i = 5;
	character.start.j = 4;
	verticalwall[0][3].isExit = TRUE;


	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;

	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 4;
	whitemummy1.start.j = 5;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 1;
	whitescorpion1.start.j = 5;

	point[0][4].isTrap = TRUE;

	point[0][2].isKey = TRUE;
	horizontalwall[4][4].isBar = TRUE;
	horizontalwall[4][4].isWall = TRUE;

}

void mission5_7()
{
	character.start.i = 1;
	character.start.j = 0;
	verticalwall[6][4].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[5][4].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;

	verticalwall[1][0].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	redmummy1.isExist = TRUE;
	redmummy1.start.i = 5;
	redmummy1.start.j = 4;

	point[5][0].isTrap = TRUE;
	point[1][5].isTrap = TRUE;


}

void mission5_8()
{
	character.start.i = 4;
	character.start.j = 1;
	horizontalwall[2][6].isExit = TRUE;


	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[3][1].isWall = TRUE;
	horizontalwall[5][3].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[1][3].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[2][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;

	verticalwall[1][4].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[3][5].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 4;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 1;
	whitemummy2.start.j = 5;


	point[3][5].isTrap = TRUE;


}

void mission5_9()
{
	character.start.i = 5;
	character.start.j = 2;
	horizontalwall[4][6].isExit = TRUE;


	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[4][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;

	verticalwall[1][0].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	redmummy1.isExist = TRUE;
	redmummy1.start.i = 1;
	redmummy1.start.j = 5;
	redscorpion1.isExist = TRUE;
	redscorpion1.start.i = 2;
	redscorpion1.start.j = 5;


	point[2][1].isTrap = TRUE;


}

void mission5_10()
{
	character.start.i = 2;
	character.start.j = 1;
	horizontalwall[0][6].isExit = TRUE;


	horizontalwall[0][1].isWall = TRUE;
	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[3][3].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;

	verticalwall[1][3].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;


	redmummy1.isExist = TRUE;
	redmummy1.start.i = 0;
	redmummy1.start.j = 3;
	redscorpion1.isExist = TRUE;
	redscorpion1.start.i = 2;
	redscorpion1.start.j = 4;


	point[1][1].isTrap = TRUE;


}

void mission5_11()
{
	character.start.i = 3;
	character.start.j = 5;
	horizontalwall[2][6].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[0][2].isWall = TRUE;
	horizontalwall[3][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[3][4].isWall = TRUE;

	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][2].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[3][5].isWall = TRUE;
	verticalwall[3][4].isWall = TRUE;
	verticalwall[4][1].isWall = TRUE;
	verticalwall[4][5].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	redmummy1.isExist = TRUE;
	redmummy1.start.i = 0;
	redmummy1.start.j = 4;
	redmummy2.isExist = TRUE;
	redmummy2.start.i = 1;
	redmummy2.start.j = 4;


}

void mission5_12()
{
	character.start.i = 0;
	character.start.j = 0;
	horizontalwall[0][6].isExit = TRUE;


	horizontalwall[1][1].isWall = TRUE;
	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[2][4].isWall = TRUE;
	horizontalwall[0][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;

	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[3][1].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;


	redmummy1.isExist = TRUE;
	redmummy1.start.i = 0;
	redmummy1.start.j = 5;

	point[1][0].isTrap = TRUE;
	point[5][0].isTrap = TRUE;



}

void mission5_13()
{
	character.start.i = 5;
	character.start.j = 5;
	verticalwall[0][2].isExit = TRUE;


	horizontalwall[4][1].isWall = TRUE;
	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[5][2].isWall = TRUE;
	horizontalwall[1][4].isWall = TRUE;
	horizontalwall[4][4].isWall = TRUE;

	verticalwall[2][0].isWall = TRUE;
	verticalwall[2][1].isWall = TRUE;
	verticalwall[2][5].isWall = TRUE;
	verticalwall[3][3].isWall = TRUE;
	verticalwall[4][4].isWall = TRUE;
	verticalwall[5][4].isWall = TRUE;


	redmummy1.isExist = TRUE;
	redmummy1.start.i = 2;
	redmummy1.start.j = 0;

	point[5][2].isTrap = TRUE;



}

void mission5_14()
{
	character.start.i = 5;
	character.start.j = 4;
	verticalwall[0][4].isExit = TRUE;


	horizontalwall[5][1].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[0][5].isWall = TRUE;
	horizontalwall[5][5].isWall = TRUE;

	verticalwall[1][1].isWall = TRUE;
	verticalwall[1][4].isWall = TRUE;
	verticalwall[2][3].isWall = TRUE;
	verticalwall[2][4].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][3].isWall = TRUE;


	whitemummy1.isExist = TRUE;
	whitemummy1.start.i = 1;
	whitemummy1.start.j = 2;
	whitemummy2.isExist = TRUE;
	whitemummy2.start.i = 1;
	whitemummy2.start.j = 3;
	whitescorpion1.isExist = TRUE;
	whitescorpion1.start.i = 1;
	whitescorpion1.start.j = 0;


	point[0][0].isTrap = TRUE;

	point[5][2].isKey = TRUE;
	horizontalwall[4][5].isBar = TRUE;
	horizontalwall[4][5].isWall = TRUE;

}

void mission5_15()
{

	character.start.i = 5;
	character.start.j = 5;
	horizontalwall[1][6].isExit = TRUE;


	horizontalwall[1][2].isWall = TRUE;
	horizontalwall[2][2].isWall = TRUE;
	horizontalwall[4][2].isWall = TRUE;
	horizontalwall[2][3].isWall = TRUE;
	horizontalwall[1][5].isWall = TRUE;
	horizontalwall[3][5].isWall = TRUE;
	horizontalwall[4][5].isWall = TRUE;

	verticalwall[1][5].isWall = TRUE;
	verticalwall[3][2].isWall = TRUE;
	verticalwall[4][2].isWall = TRUE;
	verticalwall[5][1].isWall = TRUE;
	verticalwall[5][2].isWall = TRUE;
	verticalwall[5][5].isWall = TRUE;
	point[3][1].isTrap = TRUE;
	redmummy1.isExist = TRUE;
	redscorpion1.isExist = TRUE;
	redmummy1.start.i = 0;
	redmummy1.start.j = 0;
	redscorpion1.start.i = 1;
	redscorpion1.start.j = 1;

}