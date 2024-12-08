#pragma once
#include <Windows.h>
#include "doubleBuffering.h"
int direction = 0;
void stageNumber(int x, int y, int num, HANDLE curBuf) {
	char output[100];
	switch (num)
	{
	case -1:
		strcpy_s(output, 100, "┌─");
		Printscreen(x, y, output, curBuf);
		break;
	case -2:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "┐ ");
		Printscreen(x, y, output, curBuf);
		break;
	case -3:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		strcpy_s(output, 100, "└─");
		Printscreen(x, y, output, curBuf);
		break;
	case -4:
		strcpy_s(output, 100, "┘ ");
		Printscreen(x, y, output, curBuf);
		break;
	case -15:
		SetConsoleTextAttribute(curBuf, 9);
	case -5:
		//SetConsoleTextAttribute(curBuf, 9);
		strcpy_s(output, 100, "──");
		Printscreen(x, y, output, curBuf);
		break;
	case -16:
		SetConsoleTextAttribute(curBuf, 9);
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
		SetConsoleTextAttribute(curBuf, 2);
		strcpy_s(output, 100, "∂");
		Printscreen(x, y, output, curBuf);
		break;
	case 10:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "★");
		Printscreen(x, y, output, curBuf);
		break;
	case 25:
		SetConsoleTextAttribute(curBuf, 14);
	case 20:
		strcpy_s(output, 100, "∪");
		Printscreen(x, y, output, curBuf);
		break;
	case 26:
		SetConsoleTextAttribute(curBuf, 14);
	case 21:
		strcpy_s(output, 100, "⊂");
		Printscreen(x, y, output, curBuf);
		break;
	case 27:
		SetConsoleTextAttribute(curBuf, 14);
	case 22:
		strcpy_s(output, 100, "∩");
		Printscreen(x, y, output, curBuf);
		break;
	case 28:
		SetConsoleTextAttribute(curBuf, 14);
	case 23:
		strcpy_s(output, 100, "⊃");
		Printscreen(x, y, output, curBuf);
		break;
	case 24:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "※");
		Printscreen(x, y, output, curBuf);
		break;
	case 30:
		SetConsoleTextAttribute(curBuf, 11);
		strcpy_s(output, 100, "↑");
		Printscreen(x, y, output, curBuf);
		break;
	case 31:
		SetConsoleTextAttribute(curBuf, 11);
		strcpy_s(output, 100, "→");
		Printscreen(x, y, output, curBuf);
		break;
	case 32:
		SetConsoleTextAttribute(curBuf, 11);
		strcpy_s(output, 100, "↓");
		Printscreen(x, y, output, curBuf);
		break;
	case 33:
		SetConsoleTextAttribute(curBuf, 11);
		strcpy_s(output, 100, "←");
		Printscreen(x, y, output, curBuf);
		break;
	case 60:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "§");
		Printscreen(x, y, output, curBuf);
		break;
	case 61:
		SetConsoleTextAttribute(curBuf, 8);
		strcpy_s(output, 100, "▥");
		Printscreen(x, y, output, curBuf);
		break;
	case 100:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "▩ ");	//부술 수 없는 블록
		Printscreen(x, y, output, curBuf);
		break;
	case 40:
		SetConsoleTextAttribute(curBuf, 10);
		strcpy_s(output, 100, "◆");	//열쇠
		Printscreen(x, y, output, curBuf);
		break;
	case 41:
		SetConsoleTextAttribute(curBuf, 10);
		strcpy_s(output, 100, "◇");	//자물쇠블록.
		Printscreen(x, y, output, curBuf);
		break;
	case 90:
		SetConsoleTextAttribute(curBuf, 4);
		strcpy_s(output, 100, "▲");	//자물쇠블록.
		Printscreen(x, y, output, curBuf);
		break;
	case 91:
		SetConsoleTextAttribute(curBuf, 4);
		strcpy_s(output, 100, "▶");	//자물쇠블록.
		Printscreen(x, y, output, curBuf);
		break;
	case 92:
		SetConsoleTextAttribute(curBuf, 4);
		strcpy_s(output, 100, "▼");	//자물쇠블록.
		Printscreen(x, y, output, curBuf);
		break;
	case 93:
		SetConsoleTextAttribute(curBuf, 4);
		strcpy_s(output, 100, "◀");	//자물쇠블록.
		Printscreen(x, y, output, curBuf);
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(curBuf, 7);
}
