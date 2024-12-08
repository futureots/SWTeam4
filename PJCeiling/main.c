#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)
#include "stageNumerInfo.h"
#include "stage_tutorial.h"
#include "numberTexture.h";
#define _CRT_SECURE_NO_WARNINGS


void drawMap(int startX, int startY, HANDLE curBuf);
void drawBox(int startX, int startY, int height, int width);
void save(int k);
int load();

int currentLevel = 0;
int curX, curY;

//��1 ���� �Լ�
#pragma region MainSceneFunc

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 27
void setCursorPosition(int x, int y) {
	COORD pos = { x*2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/*Ŀ�� ���� �Լ�
void eraseCursor() {
	CONSOLE_SCREEN_BUFFER_INFO conScreenInfo;
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &conScreenInfo);
	CONSOLE_CURSOR_INFO curCursorInfo;
	GetConsoleCursorInfo(hConsoleOut, &curCursorInfo);
	curCursorInfo.bVisible = 0;
	SetConsoleCursorInfo(hConsoleOut, &curCursorInfo);
}
*/

// ȭ�� �׵θ� �׸��� �Լ� (���ʿ��� �߾����� �̵��ϸ� �׸���)
void drawBorder() {
	int fullWidth = SCREEN_WIDTH;
	int halfWidth = SCREEN_WIDTH/2;

	// �� ���μ� ���ʿ��� �߾����� �׸���
	for (int i = halfWidth-1; i >=0; i--) {
		setCursorPosition(i, 0);
		if (i == 0) printf("����");
		else	printf("����");
		setCursorPosition(fullWidth - 1 - i, 0);
		if (i == 0) printf("��");
		else printf("����");
		Sleep(5);
	}

	// ���μ� �׸��� (������ �Ʒ��� ���� ���� �׸���)
	for (int i = 1; i < SCREEN_HEIGHT - 1; i++) {
		setCursorPosition(0, i);
		printf("��");
		setCursorPosition(fullWidth - 1, i);
		printf("��");
		Sleep(5);
	}

	// �Ʒ� ���μ� ���ʿ��� �߾����� �׸���
	for (int i = 0; i < halfWidth; i++) {
		setCursorPosition(i, SCREEN_HEIGHT - 1);
		if (i == 0) printf("����");
		else printf("����");
		setCursorPosition(fullWidth - 1 - i, SCREEN_HEIGHT - 1);
		if (i == 0) printf("��");
		else printf("����");
		Sleep(5);
	}
}

// ����ȭ�� �ʱ�ȭ�ϴ� �Լ�
void initializeMainMenu() {
	// ȭ�� Ŭ����
	system("cls");
}

// ����ȭ�� ǥ���ϴ� �Լ�
void displayMainMenu() {
	initializeMainMenu();
	drawBorder();
	// "���� õ��" �ؽ�Ʈ�� Ư�����ڷ� ǥ�� (��Ʈ ũ�� ����)

	setCursorPosition(16 , 10);
	printf(" ������ ��   ������   -��-    �Ѥ� ");
	setCursorPosition(16 , 11);
	printf("  ������            /����    /����");
	setCursorPosition(16 , 12);
	printf("  /��     ��--     ��--      ��");

	int showText = 1;
	while (!_kbhit()) {
		setCursorPosition(17 , 15);

		if (showText) {
			printf("<<�ƹ� ��ư�̳� ��������>>\n");
		}
		else {
			printf("                            ");
		}
		showText = !showText;
		Sleep(500);
	}
}


#pragma endregion
//��2 ���� �Լ�
#pragma region LevelSelectScreenFunction
int clearLv = 0;
int isSelecting = 0;
//���� �̸� ����
void drawLevelNameScreen() {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < stageLength; i++) {

		COORD pos = { 10, i * 2 + 1 };
		SetConsoleCursorPosition(hConsoleOut, pos);
		if (clearLv >= i) printf("%s", stageInfo[i].stageName);
		else printf("???");
	}

	COORD selectPos = { 65, 23 };
	SetConsoleCursorPosition(hConsoleOut, selectPos);
	printf("����");
}
//���� �����ϰ� �ִ� ���� ǥ��
void drawLevelSelectPointer(int b) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 7,currentLevel * 2 + 1 };
	SetConsoleCursorPosition(hConsoleOut, pos);
	if (b) printf(">");
	else printf("  ");
}
void confirmLevel() {
	system("cls");
}
//���� ���ý� ���� ȭ������ �̵��ϱ�
void selectLevel(int k) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos1 = { 63,23 };

	SetConsoleCursorPosition(hConsoleOut, pos1);
	if (k == 1)printf(">");
	else printf(" ");
	pos1.X = 70;
	SetConsoleCursorPosition(hConsoleOut, pos1);
	if (k == 1) printf("<");
	else printf(" ");
	return;
}
int keyInput(int key) {
	switch (key)// w = 119, a = 97, s = 115, d = 100
	{
	case 97:
		isSelecting = isSelecting > 0 ? isSelecting - 1 : 0;
		break;
	case 119:
		if (isSelecting == 0) {
			drawLevelSelectPointer(0);
			currentLevel = currentLevel > 0 ? currentLevel - 1 : 0;
			drawLevelSelectPointer(1);
		}
		break;
	case 115:
		if (isSelecting == 0) {
			drawLevelSelectPointer(0);
			currentLevel = currentLevel < clearLv ? currentLevel + 1 : clearLv;
			drawLevelSelectPointer(1);
		}
		break;
	case 100:
		isSelecting = isSelecting < 2 ? isSelecting + 1 : 2;
		break;
	default:
		break;
	}
	if (isSelecting > 1) {
		confirmLevel();
		return -1;
	}
	else if (isSelecting == 1) {
		return 1;
	}
	else {
		selectLevel(0);
		return 0;
	}
}

#pragma endregion
//��4 ���� �Լ�
#pragma region InGameScene

char str_text[8][35] = { 0 }; // �ؽ�Ʈ �ڽ� ��� �ؽ�Ʈ
int tens, ones; // �� �ڽ� ��� �ؽ��� ��ȣ // �����ڸ�, �����ڸ�

void levelBoxOut() {
	COORD pos = { 62, 2 };
	Printscreen(pos.X, pos.Y, stageInfo[currentLevel].stageName, gScreen[gIndex]);
}

// �ΰ��� ȭ�� ���
void drawInGame(HANDLE curBuf) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int startX = 60;
	int startY = 0;
	COORD pos = { 0,0 };
	drawMap(0, 0, curBuf);

	//�������� ���� â
	drawBox(30, 0, 5, 12);

	// ���� �� �� â
	drawBox(30, 5, 12, 20);

	//�ؽ�Ʈ �ڽ� â
	drawBox(30, 17, 10, 20);
	// i ���� ī�� ��
	for (int i = 0; i < 5; i++) {
		drawBox(i * 4, 21, 5, 4);
	}
}
//�ؽ�Ʈ ��� �Լ�
void textBoxOut(char text[][35]) {
	COORD pos = { 0, 0 };
	int startY = 18;
	pos.X = 62;
	for (int i = 0; i < 8; i++) {
		if (text[i][0] == '\0') // ù ��° ���ڰ� �� ���ڶ�� ����
			break;

		pos.Y = startY + i;

		Printscreen(pos.X, pos.Y, text[i], gScreen[gIndex]);
	}
}

void turnBoxOut(int num1, int num2) {
	COORD pos = { 0, 0 };
	char output[100];
	int startY = 6;
	int startX = 73;
	for (int i = 0; i < 9; i++) {
		pos.Y = startY + i;
		for (int j = 0; j < 5; j++) {
			pos.X = startX + j;
			if (numberTexture[num1][i][j] == 1) {
				strcpy_s(output, 3, "#");
				Printscreen(pos.X, pos.Y, "#", gScreen[gIndex]);
			}
			else {
				strcpy_s(output, 3, " ");
				Printscreen(pos.X, pos.Y, " ", gScreen[gIndex]);
			}
		}
	}
	startX = 82;
	for (int i = 0; i < 9; i++) {
		pos.Y = startY + i;
		for (int j = 0; j < 5; j++) {
			pos.X = startX + j;
			if (numberTexture[num2][i][j] == 1) {
				strcpy_s(output, 3, "#");
				Printscreen(pos.X, pos.Y, "#", gScreen[gIndex]);
			}
			else {
				strcpy_s(output, 3, " ");
				Printscreen(pos.X, pos.Y, " ", gScreen[gIndex]);
			}
		}
	}
}
//���� ���۸� �̿��ؼ� �ΰ��� ȭ�� �׷��ִ� �Լ�
void screenRender(int numDrawInGame, int numTextBoxOut, int numTurnBoxOut, int numLevelBoxOut) {
	screenClear();
	if (numDrawInGame)
		drawInGame(gScreen[gIndex]); // �ӽù��ۿ� �ΰ��� ȭ�� �׸���
	if (numTextBoxOut)
		textBoxOut(str_text);
	if (numTurnBoxOut)
		turnBoxOut(tens, ones);
	if (numLevelBoxOut)
		levelBoxOut();
	screenFlipping();
}



#pragma endregion



int main() {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO conScreenInfo;
	GetConsoleScreenBufferInfo(hConsoleOut, &conScreenInfo);

	CONSOLE_CURSOR_INFO curCursorInfo;
	GetConsoleCursorInfo(hConsoleOut, &curCursorInfo);
	curCursorInfo.bVisible = 0;
	SetConsoleCursorInfo(hConsoleOut, &curCursorInfo);

	
	system("mode con: cols=100 lines=27 | title ���� õ��");
	//��1
	displayMainMenu(); // ����ȭ�� ǥ��

	_getch();
	while (1) {

		system("cls");

		//��2
		isSelecting = 0;
		clearLv = load();
		drawMap(20, 0, hConsoleOut);
		drawLevelNameScreen();
		drawLevelSelectPointer(1);
		int tick = 0, blink = 0;
		int k = 0;
		while (1) {
			// ���콺 Ŭ�� ��ǥ ����

			int key = 0;
			if (_kbhit() != 0) {
				key = _getch();
				k = keyInput(key);
				if (k == -1) break;
				drawMap(20, 0, hConsoleOut);
			}
			Sleep(10);
			if (k == 1) {
				if (tick % 50 == 0) {
					blink = !blink;
					tick = 0;
					selectLevel(blink);
				}
				tick++;
			}

		}

		//�� 4
		screenInit();
		screenRender(1, 0, 0, 0); // �ΰ��� ȭ��, �ؽ�Ʈ �ڽ�, �� ����â ��� ���� ����
		Sleep(1000);
		strcpy_s(str_text[0], 35, "���� �ߴ� ����õ���� ���Դϴ�.");
		strcpy_s(str_text[1], 35, "�ϴ� ���⼭ �������� �� �����ϴ�.");
		strcpy_s(str_text[2], 35, "'��'�� �ִ� ������ �̵��غ��ô�.");

		tens = 4, ones = 8; // �� ����â ���� ����
		screenRender(1, 1, 1, 1);
		Sleep(1000);

		_getch();

		screenRelease();
		
		//save(load()+1); //���� ���� ����
	}
	system("cls");

	return 0;
}

#pragma region CMFunction

void drawMap(int startX, int startY, HANDLE curBuf) {
	//CONSOLE_SCREEN_BUFFER_INFO csbi;
	//GetConsoleScreenBufferInfo(curBuf, &csbi);
	COORD pos = { 0,0 };
	for (int i = 0; i < stageHeight; i++) {
		pos.Y = startY + i;
		for (int j = 0; j < stageWidth; j++) {
			int value = stageMap[currentLevel][i][j];
			pos.X = (startX + j) * 2;
			stageNumber(pos.X, pos.Y, value, curBuf);
		}
	}
}
void drawBox(int startX, int startY, int height, int width) {
	COORD pos = { 0,0 };
	pos.Y = startY;
	for (int i = 0; i < width; i++) { //top line
		pos.X = (startX + i) * 2;
		if (i == 0) stageNumber(pos.X, pos.Y, -1, gScreen[gIndex]);
		else if (i == width - 1)stageNumber(pos.X, pos.Y, -2, gScreen[gIndex]);
		else stageNumber(pos.X, pos.Y, -5, gScreen[gIndex]);
	}
	for (int i = 1; i < height - 1; i++) { // middle side line
		pos.Y = startY + i;
		pos.X = startX * 2;
		stageNumber(pos.X, pos.Y, -6, gScreen[gIndex]);
		pos.X = (startX + width - 1) * 2;
		stageNumber(pos.X, pos.Y, -6, gScreen[gIndex]);
	}
	pos.Y = startY + height - 1;
	for (int i = 0; i < width; i++) { //bottom line
		pos.X = (startX + i) * 2;
		if (i == 0) stageNumber(pos.X, pos.Y, -3, gScreen[gIndex]);
		else if (i == width - 1) stageNumber(pos.X, pos.Y, -4, gScreen[gIndex]);
		else stageNumber(pos.X, pos.Y, -5, gScreen[gIndex]);
	}

}
void save(int k) {
	FILE* fp;
	fp = fopen("data.bin", "wb");
	fwrite(&k, sizeof(int), 1, fp);
	fclose(fp);
	return;
}
int load() {
	int data=0;
	FILE* fp;
	fp = fopen("data.bin", "rb");
	if (fp == NULL) {
		save(0);
		fp = fopen("data.bin", "rb");
	}
	fread(&data, sizeof(int), 1, fp);
	fclose(fp);
	return data;
}
#pragma endregion

#pragma region InGameFunction

/*void MovePlayer(int x, int y) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int** stage = stageMap[currentLevel];
	if (stage[curY + y][curX + x] != 0) {
		MoveBlock(curX + x, curY + y, x, y);
		return;
	}
	stage[curY][curX] = 0;
	stage[curY + y][curX + x] = 1;
	curY += y;
	curX += x;


	return;
}
void MoveBlock(int blockX, int blockY, int x, int y) {
	int blockNum = stageMap[blockY][blockX];
	switch (blockNum)
	{
	case 2:
		MoveNormalBlock(blockX, blockY, x, y);
		break;
	default:
		break;
	}


}
void MoveNormalBlock(int blockX, int blockY, int x, int y) {
	if (stageMap[blockY + y][blockX + x] != 0) return;
	stageMap[blockY + y][blockX + x] = stageMap[blockY][blockX];
	stageMap[blockY][blockX] = 0;
	return;
}*/

#pragma endregion



