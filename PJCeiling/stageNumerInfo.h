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
		strcpy_s(output, 100, "┌─");
		Printscreen(x, y, output, curBuf);
		break;
	case -2:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "┐");
		Printscreen(x, y, output, curBuf);
		break;
	case -3:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "└─");
		Printscreen(x, y, output, curBuf);
		break;
	case -4:
		strcpy_s(output, 100, "┘");
		Printscreen(x, y, output, curBuf);
		break;
	case -5:
		strcpy_s(output, 100, "──");
		Printscreen(x, y, output, curBuf);
		break;
	case -6:
		strcpy_s(output, 100, "│ ");
		Printscreen(x, y, output, curBuf);
		break;
	case 0:
		strcpy_s(output, 100, "  ");
		Printscreen(x, y, output, curBuf);
		break;
	case 1:
		SetConsoleTextAttribute(curBuf, 13);
		if (direction == 0) strcpy_s(output, 100, "▲");
		else if(direction == 1)strcpy_s(output, 100, "▶");
		else if(direction == 2) strcpy_s(output, 100, "▼");
		else if(direction == 3)strcpy_s(output, 100, "◀");
		Printscreen(x, y, output, curBuf);
		break;
	case 2:
		strcpy_s(output, 100, "■");
		Printscreen(x, y, output, curBuf);
		break;
	case 3:
		strcpy_s(output, 100, "□");
		Printscreen(x, y, output, curBuf);
		break;
	case 4:
		SetConsoleTextAttribute(curBuf, 9);
		strcpy_s(output, 100, "■");
		Printscreen(x, y, output, curBuf);
		break;
	case 5:
		SetConsoleTextAttribute(curBuf, 12);
		strcpy_s(output, 100, "♨");
		Printscreen(x, y, output, curBuf);
		break;
	case 6:
		SetConsoleTextAttribute(curBuf, 11);
		strcpy_s(output, 100, "∂");
		Printscreen(x, y, output, curBuf);
		break;
	case 10:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "★");
		Printscreen(x, y, output, curBuf);
		break;
	case 20:
	case 25:
		strcpy_s(output, 100, "∪");
		Printscreen(x, y, output, curBuf);
		break;
	case 21:
	case 26:
		strcpy_s(output, 100, "⊂");
		Printscreen(x, y, output, curBuf);
		break;
	case 22:
		
	case 27:
		strcpy_s(output, 100, "∩");
		Printscreen(x, y, output, curBuf);
		break;
	case 23:
	case 28:
		strcpy_s(output, 100, "⊃");
		Printscreen(x, y, output, curBuf);
		break;
	case 24:
		strcpy_s(output, 100, "※");
		Printscreen(x, y, output, curBuf);
		break;
	case 60:
		strcpy_s(output, 100, "①");
		Printscreen(x, y, output, curBuf);
		break;
	case 61:
		strcpy_s(output, 100, "②");
		Printscreen(x, y, output, curBuf);
		break;
	case 100:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "▩ ");	//부술 수 없는 블록
		Printscreen(x, y, output, curBuf);
		break;
	case 101:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "◆");	//열쇠
		Printscreen(x, y, output, curBuf);
		break;
	case 102:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "◇");	//자물쇠블록.
		Printscreen(x, y, output, curBuf);
		break;
	case 103:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "▣ ");	//맵 연결 아이템.
		Printscreen(x, y, output, curBuf);
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(curBuf, 7);
}
