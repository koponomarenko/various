
#include "menu.h"

extern void task_01();
extern void task_02();
extern void task_03();
extern void task_04();


int main()
{
	/* change this two line for new project */
	const char * pProgramName = "Day 16-17";
	void (*arrTasks[])() = {task_01, task_02, task_03, task_04};


	Menu(arrTasks, (sizeof arrTasks / sizeof arrTasks[0]), pProgramName);
}

