#pragma once
#include <Windows.h>
#include "doubleBuffering.h"
int direction = 0;
void stageNumber(int x, int y, int num, HANDLE curBuf) {
	char output[100];
	switch (num)
	{
	case -1:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "忙式");
		Printscreen(x, y, output, curBuf);
		break;
	case -2:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "忖");
		Printscreen(x, y, output, curBuf);
		break;
	case -3:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "戌式");
		Printscreen(x, y, output, curBuf);
		break;
	case -4:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "戎");
		Printscreen(x, y, output, curBuf);
		break;
	case -5:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "式式");
		Printscreen(x, y, output, curBuf);
		break;
	case -6:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "弛 ");
		Printscreen(x, y, output, curBuf);
		break;
	case 0:
		strcpy_s(output, 100, "  ");
		Printscreen(x, y, output, curBuf);
		break;
	case 1:
		SetConsoleTextAttribute(curBuf, 13);
		if (direction == 0) strcpy_s(output, 100, "～");
		else if(direction == 1)strcpy_s(output, 100, "Ⅱ");
		else if(direction == 2) strcpy_s(output, 100, "∪");
		else if(direction == 3)strcpy_s(output, 100, "９");
		Printscreen(x, y, output, curBuf);
		break;
	case 2:
		strcpy_s(output, 100, "﹥");
		Printscreen(x, y, output, curBuf);
		break;
	case 3:
		strcpy_s(output, 100, "﹤");
		Printscreen(x, y, output, curBuf);
		break;
	case 4:
		SetConsoleTextAttribute(curBuf, 9);
		strcpy_s(output, 100, "﹥");
		Printscreen(x, y, output, curBuf);
		break;
	case 5:
		SetConsoleTextAttribute(curBuf, 12);
		strcpy_s(output, 100, "卄");
		Printscreen(x, y, output, curBuf);
		break;
	case 6:
		SetConsoleTextAttribute(curBuf, 10);
		strcpy_s(output, 100, "±");
		Printscreen(x, y, output, curBuf);
		break;
	case 8:
		SetConsoleTextAttribute(curBuf, 11);
		strcpy_s(output, 100, "÷");
		Printscreen(x, y, output, curBuf);
		break;
	case 10:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "≠");
		Printscreen(x, y, output, curBuf);
		break;
	case 20:
		strcpy_s(output, 100, "扣");
		Printscreen(x, y, output, curBuf);
		break;
	case 21:
		strcpy_s(output, 100, "戍");
		Printscreen(x, y, output, curBuf);
		break;
	case 22:
		strcpy_s(output, 100, "成");
		Printscreen(x, y, output, curBuf);
		break;
	case 23:
		strcpy_s(output, 100, "扛");
		Printscreen(x, y, output, curBuf);
		break;
	case 24:
		strcpy_s(output, 100, "↖");
		Printscreen(x, y, output, curBuf);
		break;
	case 25:
		strcpy_s(output, 100, "↗");
		Printscreen(x, y, output, curBuf);
		break;
	case 26:
		strcpy_s(output, 100, "↙");
		Printscreen(x, y, output, curBuf);
		break;
	case 27:		
		strcpy_s(output, 100, "↘");
		Printscreen(x, y, output, curBuf);
		break;
	case 60:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "＝");
		Printscreen(x, y, output, curBuf);
		break;
	case 61:
		strcpy_s(output, 100, "〦");
		Printscreen(x, y, output, curBuf);
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(curBuf, 7);
}
