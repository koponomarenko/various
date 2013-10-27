
#include "menu.h"

extern void task_01();
extern void task_02();
extern void task_03();
extern void task_04();
extern void task_05();
extern void task_06();
extern void task_07();
extern void task_08();
extern void task_09();
extern void task_10();


int main()
{
	/* change this two line for new project */
	const char * pProgramName = "Day 12-13";
	void (*arrTasks[])() = {task_01, task_02, task_03, task_04, task_05, task_06, task_07, task_08, task_09, task_10};


	Menu(arrTasks, (sizeof arrTasks / sizeof arrTasks[0]), pProgramName);
}

