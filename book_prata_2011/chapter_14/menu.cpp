#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;


inline void SetCursor(short x, short y)
{
	COORD NewCoord = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), NewCoord);
}

void MyShowCursor(bool bShow);
void DrawMenu(const char * pProgName, const short StartX, short StartY, const short nMenuItems, short nStep = 0);




void Menu(void (*arrTasks[])(), const short TaskNumb, const char * pProgName)
{
	enum {Key_Esc = 27, Key_Enter = 13, Key_Up = 72, Key_Down = 80, Key_1 = 49, Key_2, Key_3, Key_4, Key_5, Key_6, Key_7, Key_8, Key_9};
	
	const short cMenuShift = 2; // space between menu and arrow
	const short StartX = 15, StartY = 5; // coordinates left-top point of menu
	const short StepForY = 1; // step for Y-axis between menu items

	unsigned char chKey = 0;
	short iCurrTask = 0; // index in (*arrTasks[])()
	short CurrY = StartY;


	MyShowCursor(false);
	DrawMenu(pProgName, StartX + cMenuShift, StartY, TaskNumb, StepForY);

	do {
		SetCursor(StartX, CurrY);
		cout<<(char)26;
		
		chKey = _getch();
		if (chKey == 224)
			chKey = _getch();
		
		SetCursor(StartX, CurrY);
		cout<<' ';
		
		switch(chKey)
		{
		case Key_Up:
			if (CurrY > StartY)
			{
				CurrY -= StepForY;
				iCurrTask --;
			}
			else
			{
				CurrY = StartY + (TaskNumb - 1) * StepForY;
				iCurrTask = (TaskNumb - 1);
			}
			break;

		case Key_Down:
			if (CurrY < (StartY + (TaskNumb - 1) * StepForY))
			{
				CurrY += StepForY;
				iCurrTask ++;
			}
			else
			{
				CurrY = StartY;
				iCurrTask = 0;
			}
			break;

		/* these for hotkeys: */
		case Key_1: // 1
		case Key_2: // 2
		case Key_3: // 3
		case Key_4: // 4
		case Key_5: // 5
		case Key_6: // 6
		case Key_7: // 7
		case Key_8: // 8
		case Key_9: // 9
			if (chKey - Key_1 < TaskNumb) // if the Key is in the border of the menu
			{
				iCurrTask = (chKey - Key_1);
				CurrY = StartY + ((chKey - Key_1) * StepForY);
			}
			else
				break;

		case Key_Enter:
			system("cls");
			MyShowCursor(true);

			/* clean the input buffer just in case */
			if (!cin) cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());

			arrTasks[iCurrTask](); // RUN CURRENT TASK ACCORDING TO SELECTED MENU ITEM
			
			/* clean the input buffer just in case */
			if (!cin) cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());

			cout<<"\nPress any key";
			_getch();
			system("cls");
			MyShowCursor(false);
			DrawMenu(pProgName, StartX + cMenuShift, StartY, TaskNumb, StepForY);
			break;

		case Key_Esc:
			MyShowCursor(true);
			break;
		}
		
	} while (chKey != Key_Esc);
}




void MyShowCursor(bool bShow)
{
	static CONSOLE_CURSOR_INFO CursorInfo;
	static bool bFirstCall = true;

	if (bFirstCall)
	{
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
		bFirstCall = false;
	}

	CursorInfo.bVisible = bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}



//	nStep - step for Y-axis
void DrawMenu(const char * pProgName, const short StartX, short StartY, const short nMenuItems, short nStep)
{
	static char NumbOfTask[11] = {0};

	SetCursor(StartX, 1);
	cout<<"-- Press Esc to exit --\n";

	SetCursor(StartX, 2);
	cout<<"PROGRAM NAME: "<<pProgName ? pProgName : "unnamed";

	for (int i = 0; i < nMenuItems; ++i)
	{
		memset(NumbOfTask, 0, sizeof(NumbOfTask));
		_itoa(1 + i, NumbOfTask, 10);

		SetCursor(StartX, StartY);
		cout<<"Task "<<NumbOfTask;
		StartY += nStep;
	}
}

