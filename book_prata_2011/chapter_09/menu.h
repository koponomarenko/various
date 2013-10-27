

void Menu(void (*arrTasks[])(), const short TaskNumb, const char * pProgName);
inline void SetCursor(short x, short y);
void MyShowCursor(bool bShow);
void DrawMenu(const char * pProgName, const short StartX, short StartY, const short nMenuItems, short nStep = 0);
