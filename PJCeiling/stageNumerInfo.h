#pragma once
#include <Windows.h>
#include "doubleBuffering.h"

int direction = 0;

enum ColorType {
	BLACK = 0,  	//0
	darkBlue = 1,	//1
	DarkGreen = 2,	//2
	darkSkyBlue = 3,//3
	DarkRed = 4,  	//4
	DarkPurple = 5,	//5
	DarkYellow = 6,	//6
	GRAY = 7,		//7
	DarkGray = 8,	//8
	BLUE = 9,		//9
	GREEN = 10,		//10
	SkyBlue = 11,	//11
	RED = 12,		//12
	PURPLE = 13,		//13
	YELLOW = 14,		//14
	WHITE = 15		//15
} COLOR;

void textColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void stageNumber(int x, int y, int num, HANDLE curBuf) {
	char output[100];
	switch (num)
	{
	case -11:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		textColor(darkBlue);
		strcpy_s(output, 100, "┌");
		Printscreen(x, y, output, curBuf);
		break;
	case -12:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		textColor(darkBlue);
		strcpy_s(output, 100, "┐");
		Printscreen(x, y, output, curBuf);
		break;
	case -13:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		textColor(darkBlue);
		strcpy_s(output, 100, "└─");
		Printscreen(x, y, output, curBuf);
		break;
	case -14:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		textColor(darkBlue);
		strcpy_s(output, 100, "┘");
		Printscreen(x, y, output, curBuf);
		break;
	case -15:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		textColor(darkBlue);
		strcpy_s(output, 100, "──");
		Printscreen(x, y, output, curBuf);
		break;
	case -16:
		//SetConsoleTextAttribute(gScreen[gIndex], 9);
		textColor(darkBlue);
		strcpy_s(output, 100, "│");
		Printscreen(x, y, output, curBuf);
		break;
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
		SetConsoleTextAttribute(curBuf, 2);
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
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "▥");
		Printscreen(x, y, output, curBuf);
		break;
	case 100:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "▩ ");	//부술 수 없는 블록
		Printscreen(x, y, output, curBuf);
		break;
	case 40:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "◇");	//자물쇠블록.
		Printscreen(x, y, output, curBuf);
		break;
	case 41:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "◆");	//열쇠
		Printscreen(x, y, output, curBuf);
		break;
	case 42:
		SetConsoleTextAttribute(curBuf, 14);
		strcpy_s(output, 100, "▣");	//맵 연결 아이템.
		Printscreen(x, y, output, curBuf);
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(curBuf, 7);
}
