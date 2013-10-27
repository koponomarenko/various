
extern void Menu(void (*arrTasks[])(), const short TaskNumb, const char * pProgName);

extern void task_01();
extern void task_02();
extern void task_03();
extern void task_04();
extern void task_05();


int main()
{
	/* change this two line for new project */
	const char * pProgramName = "Day 26-27";
	void (*arrTasks[])() = {task_01, task_02, task_03, task_04, task_05};


	Menu(arrTasks, (sizeof arrTasks / sizeof arrTasks[0]), pProgramName);
}

