#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)
#include "stageNumerInfo.h"
#include "stage_tutorial.h"
#include "numberTexture.h";
#include "prepareScene.h"

#define _CRT_SECURE_NO_WARNINGS

/*
/////////////////////////////////////�߰� ����/////////////////////////////////////////
prepareScene.h
ī�� ���� ��� ����ü �߰� inGameDeckInfo
ī�� ���� �� ��� ���� deckCount �߰�
�������� ī�� ����, �Ǹ� deckCount�� �ݿ��ϴ� �ڵ� �߰�


deckSetting() deckInfo�迭�� �̿��ؼ� inGameDeck�� ī�� ���� �������ִ� �Լ�

mayCopy() currentMap�� stageMap�� ������ �������ִ� �Լ�
		  �� ���� ��� �� currentMap���

deckCountDown() ī�� ���� ī��Ʈ �������ִ� �Լ� 

*/


//���콺 ��ǥ�� ������ ����ü
typedef struct {
	int X;
	int Y;
} MousePosition;


void drawMap(int startX, int startY, HANDLE curBuf);
void drawBox(int startX, int startY, int height, int width, HANDLE curBuf);
void drawBlank(int startX, int startY, int height, int width, HANDLE curBuf);
void save(int k);
int load();

int currentLevel = 0;
int curX, curY;
int direction = 0;
MousePosition curMousePos;

//��1 ���� �Լ�
#pragma region MainSceneFunc

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 27
void setCursorPosition(int x, int y) {
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


// ȭ�� �׵θ� �׸��� �Լ� (���ʿ��� �߾����� �̵��ϸ� �׸���)
void drawBorder() {
	int fullWidth = SCREEN_WIDTH;
	int halfWidth = SCREEN_WIDTH / 2;

	// �� ���μ� ���ʿ��� �߾����� �׸���
	for (int i = halfWidth - 1; i >= 0; i--) {
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

	setCursorPosition(16, 10);
	printf(" ������ ��   ������   -��-    �Ѥ� ");
	setCursorPosition(16, 11);
	printf("  ������            /����    /����");
	setCursorPosition(16, 12);
	printf("  /��     ��--     ��--      ��");

	int showText = 1;
	while (!_kbhit()) {
		setCursorPosition(17, 15);

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
#pragma region LevelSelectSceneFunction
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
			int accessMax = clearLv >= stageLength - 1 ? stageLength - 1 : clearLv;
			currentLevel = currentLevel < accessMax ? currentLevel + 1 : accessMax;
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
//��3 ���� �Լ�
#pragma region CardSelectSceneFunction

void enableKeyboardInput(HANDLE hConsoleInput) {
	// �ܼ� �Է� ��带 Ű���� �Է�����.
	SetConsoleMode(hConsoleInput, ENABLE_PROCESSED_INPUT | ENABLE_WINDOW_INPUT);
}

//����Ŭ������ �� ���콺 ��ǥ�� ��ȯ�ϴ� �Լ�.
//���� ��� ����.
MousePosition getMouseClickPosition(HANDLE hConsoleInput) {
	INPUT_RECORD inputRecord;
	DWORD events;
	MousePosition mousePos = { -1, -1 };

	// �ܼ� �Է� ��忡�� ���콺 �Է��� Ȱ��ȭ.
	SetConsoleMode(hConsoleInput, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	while (1) {
		ReadConsoleInput(hConsoleInput, &inputRecord, 1, &events);

		if (inputRecord.EventType == MOUSE_EVENT) {
			MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;
			if (mouseEvent.dwEventFlags == MOUSE_MOVED) {
				mousePos.X = mouseEvent.dwMousePosition.X;
				mousePos.Y = mouseEvent.dwMousePosition.Y;
				drawTooltip(mousePos.X, mousePos.Y);
			}
			if (mouseEvent.dwEventFlags == DOUBLE_CLICK) {
				mousePos.X = mouseEvent.dwMousePosition.X;
				mousePos.Y = mouseEvent.dwMousePosition.Y;
				return mousePos;
			}
		}
	}
}

void setPrepareOrigininfo() {
	costInfo = stageInfo[currentLevel].cost;
	for (int i = 0; i < 8; i++) {
		deckInfo[i] = 0;
	}
}

#pragma endregion
//��4 ���� �Լ�
#pragma region InGameSceneFunc

char str_text[8][35] = { 0 }; // �ؽ�Ʈ �ڽ� ��� �ؽ�Ʈ
int tens, ones; // �� �ڽ� ��� �ؽ��� ��ȣ // �����ڸ�, �����ڸ�
inGameDeckInfo inGameDeck[8];
int currentMap[20][30];
void deckOut();

void mapCopy() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++)
			currentMap[i][j] = stageMap[currentLevel][i][j];
	}
}

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
	drawBox(30, 0, 5, 12, curBuf);

	// ���� �� �� â
	drawBox(30, 5, 12, 20,curBuf);

	//�ؽ�Ʈ �ڽ� â
	drawBox(30, 17, 10, 20,curBuf);

	//�� ���
	deckOut();
}
void textInput(int n, char* text) {
	strcpy_s(str_text[n], 35, text);
}
void turnCountInOut(int n, int p) {
	tens = n;
	ones = p;
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

void turnCountDown() {
	if (ones == 0 && tens > 0) {
		tens--;
		ones = 9;
	}
	else {
		ones--;
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
void deckSetting() {
	int idx = 0;
	
	for (int i = 0; i < 8; i++) {
		if (deckInfo[i] != 0) {
			if (i == 0) {
				inGameDeck[idx].cardCount = deckInfo[i];
				strcpy_s(inGameDeck[idx].cardName, 10, "�б�");
				inGameDeck[idx].cardType = 0;
			}
			else if (i == 1) {
				inGameDeck[idx].cardCount = deckInfo[i];
				strcpy_s(inGameDeck[idx].cardName, 10, "����");
				inGameDeck[idx].cardType = 1;
			}
			else if (i == 2) {
				inGameDeck[idx].cardCount = deckInfo[i];
				strcpy_s(inGameDeck[idx].cardName, 10, "����");
				inGameDeck[idx].cardType = 2;
			}
			idx++;
		}
	}
}

void deckOut() {
	int startX = 60;
	int startY = 0;
	COORD pos = { 0,0 };

	for (int i = 0; i < deckCount; i++) {
		char cardStr[10];
		sprintf(cardStr, "%d ��", inGameDeck[i].cardCount);  // ������ ���ڿ��� ��ȯ
		Printscreen(i * 8 + 2, 22, inGameDeck[i].cardName, gScreen[gIndex]);
		Printscreen(i * 8 + 1, 23, "  ��", gScreen[gIndex]);
		Printscreen(i * 8 + 2, 24, cardStr, gScreen[gIndex]); // pc���� Ȯ���� ��
		drawBox(i * 4, 21, 5, 4,gScreen[gIndex]);

	}
}

void deckCountDown(int x, int y) {
	for (int i = 0; i < deckCount; i++) {
		if (y >= 21 && y <= 25 && x >= i * 8 + 1 && x < i * 8 + 8) {
			if(inGameDeck[i].cardCount > 0)
				inGameDeck[i].cardCount--;
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


#pragma region InGameFunc
void InitPlayer() {
	for (int i = 0; i < stageHeight; i++) {
		for (int j = 0; j < stageWidth; j++) {
			if (stageMap[currentLevel][i][j] == 1) {
				curX = j;
				curY = i;
				break;
			}
		}
	}
}
//�÷��̾� �̵�
int MovePlayer(int x, int y) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int blockNum = currentMap[curY + y][curX + x];

	int result = 0;

	switch (blockNum) {
	case 10: //������
		result = 1;
	case 0: //��ĭ
		currentMap[curY][curX] = 0;
		currentMap[curY + y][curX + x] = 1;
		curY += y;
		curX += x;
		break;
	case -11: case -12: case -13: case -14: case -15: case -16: //�����׵θ�
		//�ݴ��� ��ġ�� �̵��ϴ� �Լ�
		break;

	case 30://�ൿȽ�� �ø��� ������ 
		//�ൿī�� ���� �ø��� �Լ�
		break;

	case 3: // ����
		//�Լ�
		break;

	case -1: case -2: case -3: case -4: case -5: case -6: //fix�׵θ�
		//�Լ�
		break;

	case 20: case 21: case 22: case 23: case 24: // ���͸� �÷��� ���
		//�Լ�
		break;

	default:
		break;

	}
	return result;
}

void LevelClear() {
	for (int i = 0; i < 12; i++) {
		if (_kbhit()) break;
		drawBox(24 - i * 1, 11, 5, 2 + i * 2, gScreen[!gIndex]);
		drawBlank(25 - i * 1, 12, 3, i * 2, gScreen[!gIndex]);
		Sleep(100);
	}
	drawBox(13, 11, 5, 24, gScreen[!gIndex]);
	drawBlank(14, 12, 3, 22, gScreen[!gIndex]);
	Printscreen(44, 13, "LEVEL CLEAR!!", gScreen[!gIndex]);
	if (load() <= currentLevel) save(currentLevel + 1);
	Sleep(1000);

	return;

}

#pragma endregion
#pragma region inGameProcessInput
int processInputs(HANDLE hConsoleInput) {
    INPUT_RECORD inputRecord;
    DWORD events;
    
    // �ܼ� �Է� ��忡�� ���콺�� Ű���� ��� �Է¹���
    SetConsoleMode(hConsoleInput, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    
    while (1) {
        ReadConsoleInput(hConsoleInput, &inputRecord, 1, &events);

        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
            // Ű���� �Է�
            switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
                case 'W': case 'w': return 'w';
                case 'A': case 'a': return 'a';
                case 'S': case 's': return 's';
                case 'D': case 'd': return 'd';
            }
        } else if (inputRecord.EventType == MOUSE_EVENT) {
            // ���콺 �Է�
            MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;
            if (mouseEvent.dwEventFlags == DOUBLE_CLICK) {
                curMousePos.X = mouseEvent.dwMousePosition.X;
                curMousePos.Y = mouseEvent.dwMousePosition.Y;
                return 'M';	//����Ŭ�� �߻��� M��ȯ. �������� main���� ó��.
            }
        }
    }
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

	MousePosition mousePos;
	save(2);

	system("mode con: cols=100 lines=27 | title ���� õ��");
	//��1
	displayMainMenu(); // ����ȭ�� ǥ��

	_getch();
	while (1) {

		system("cls");

		//��2
		isSelecting = 0;
		clearLv = load();
		mapCopy();// �� ����
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
				mapCopy();
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
			else if (k == 0) {
				tick = 0; 
				blink = 0;
			}

		}

		//�� 3
		system("cls");
		setPrepareOrigininfo();
		drawPrepareBox();
		drawMap(20, 1, hConsoleOut);
		deckCount = 0;
		while (1) {
			drawPrepareInfo();
			// ����Ŭ�� ��ġ ��������
			mousePos = getMouseClickPosition(hConsoleInput);
			if (mousePos.X != -1 && mousePos.Y != -1) {
				detectPrepareFunc(mousePos.X, mousePos.Y);
			}
			if (mousePos.Y >= confirmCoord[1] && mousePos.Y <= confirmCoord[1] + 5 && mousePos.X >= confirmCoord[0] && mousePos.X <= confirmCoord[0] + 8) {
				break;
			}
		}
		//�ٽ� Ű���� �Է����� �ٲٱ�
		enableKeyboardInput(hConsoleInput);


		//�� 4
		int currentMap[20][30] = { 0, }; // ���� Ŭ���� �� ���� �ʱ�ȭ �Ǿ���

		screenInit();
		screenRender(1, 0, 0, 0); // �ΰ��� ȭ��, �ؽ�Ʈ �ڽ�, �� ����â ��� ���� ����
		Sleep(100);
		strcpy_s(str_text[0], 35, "���� �ߴ� ����õ���� ���Դϴ�.");
		strcpy_s(str_text[1], 35, "�ϴ� ���⼭ �������� �� �����ϴ�.");
		strcpy_s(str_text[2], 35, "'��'�� �ִ� ������ �̵��غ��ô�.");

		deckSetting();// �������� �� ī�� ������ �ΰ��ӿ� ������Ʈ �ϴ� �Լ�
		turnCountInOut(3, 0);
		InitPlayer();
		screenRender(1, 1, 1, 1);

		
		//�ΰ��� ī��ī��Ʈ ���� 
		while (1) {
			mousePos = getMouseClickPosition(hConsoleInput);
			if (mousePos.X != -1 && mousePos.Y != -1) {
				deckCountDown(mousePos.X, mousePos.Y);
				screenRender(1, 1, 1, 1);
			}
			if (inGameDeck[0].cardCount == 0 && inGameDeck[1].cardCount == 0 && inGameDeck[2].cardCount == 0)
				break;
		}
		enableKeyboardInput(hConsoleInput);
		
		while (1) {
			int eventCode = processInputs(hConsoleInput);	//Ű����, ���콺 �̺�Ʈ ó��.
			int clear = 0;

			switch (eventCode) {
			case 'w':
				clear = MovePlayer(0, -1);
				direction = 0;
				break;
			case 's':
				clear = MovePlayer(0, 1);
				direction = 1;
				break;
			case 'a':
				clear = MovePlayer(-1, 0);
				direction = 2;
				break;
			case 'd':
				clear = MovePlayer(1, 0);
				direction = 3;
				break;
			case 'M':  // ���콺 ����Ŭ�� �̺�Ʈ �ڵ�
				//return;
				break;
			}

			if (clear)break;
			if (eventCode != 'M') {
				turnCountDown();
			}
			screenRender(1, 1, 1, 1);
		}

		tens = 4, ones = 8; // �� ����â ���� ����
		//Sleep(1000);
		screenRender(1, 1, 1, 1);
		LevelClear();
		

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
			int value = currentMap[i][j];
			pos.X = (startX + j) * 2;
			stageNumber(pos.X, pos.Y, value, curBuf);
		}
	}
}
void drawBox(int startX, int startY, int height, int width, HANDLE curBuf) {
	COORD pos = { 0,0 };
	pos.Y = startY;
	for (int i = 0; i < width; i++) { //top line
		pos.X = (startX + i) * 2;
		if (i == 0) stageNumber(pos.X, pos.Y, -1, curBuf);
		else if (i == width - 1)stageNumber(pos.X, pos.Y, -2, curBuf);
		else stageNumber(pos.X, pos.Y, -5, curBuf);
	}
	for (int i = 1; i < height - 1; i++) { // middle side line
		pos.Y = startY + i;
		pos.X = startX * 2;
		stageNumber(pos.X, pos.Y, -6, curBuf);
		pos.X = (startX + width - 1) * 2;
		stageNumber(pos.X, pos.Y, -6, curBuf);
	}
	pos.Y = startY + height - 1;
	for (int i = 0; i < width; i++) { //bottom line
		pos.X = (startX + i) * 2;
		if (i == 0) stageNumber(pos.X, pos.Y, -3, curBuf);
		else if (i == width - 1) stageNumber(pos.X, pos.Y, -4, curBuf);
		else stageNumber(pos.X, pos.Y, -5, curBuf);
	}
}
void drawBlank(int startX, int startY, int height, int width, HANDLE curBuf) {
	COORD pos = { 0,0 };
	for (int i = 0; i < height; i++) {
		pos.Y = startY + i;
		for (int j = 0; j < width; j++) {
			pos.X = (startX + j) * 2;
			stageNumber(pos.X, pos.Y, 0, curBuf);
		}
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
	int data = 0;
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






