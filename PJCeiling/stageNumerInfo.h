#pragma once
#include <Windows.h>
#include "doubleBuffering.h"

void stageNumber(int x, int y, int num, HANDLE curBuf) {
	char output[100];
	switch (num)
	{

	case -1:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "����");
		Printscreen(x, y, output, curBuf);
		break;
	case -2:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "��");
		Printscreen(x, y, output, curBuf);
		break;
	case -3:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "����");
		Printscreen(x, y, output, curBuf);
		break;
	case -4:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "��");
		Printscreen(x, y, output, curBuf);
		break;
	case -5:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "����");
		Printscreen(x, y, output, curBuf);
		break;
	case -6:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "��");
		Printscreen(x, y, output, curBuf);
		break;
	case 0:
		strcpy_s(output, 100, "  ");
		Printscreen(x, y, output, curBuf);
		break;
	case 1:
		SetConsoleTextAttribute(curBuf, 13);
		strcpy_s(output, 100, "��");
		Printscreen(x, y, output, curBuf);
		break;
	case 2:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "��");
		Printscreen(x, y, output, curBuf);
		break;
	case 3:
		SetConsoleTextAttribute(curBuf, 9);
		strcpy_s(output, 100, "��");
		Printscreen(x, y, output, curBuf);
		break;
	case 10:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "��");
		Printscreen(x, y, output, curBuf);
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(curBuf, 7);
}
