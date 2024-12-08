#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)
#include "stageNumberInfo.h"
#include "stageMapInfo.h"
#include "numberTexture.h"
#include "prepareScene.h"
#include "stageGimmick.h"
#include "stageTextHint.h"


#define _CRT_SECURE_NO_WARNINGS
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
void HelpPopUp();

int currentLevel = 0;
int curX, curY;
MousePosition curMousePos;
int isClear = 0;
int hintVisible;//�⺻�� 3, ��Ʈ 5����
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
	Printscreen(34, 17, "Q�� ���� ���۹� Ȯ��", GetStdHandle(STD_OUTPUT_HANDLE));
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
void drawLevelNameScreen(int start) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (start < 0) start = 0;
	else if (start > 9) start = stageLength - 10;
	for (int i = 0; i < 10; i++) {
		COORD pos = { 10, i * 2 + 1 };
		SetConsoleCursorPosition(hConsoleOut, pos);
		printf("                              ");
		if (i + start >= stageLength) break;
		SetConsoleCursorPosition(hConsoleOut, pos);
		if (clearLv >= i+start) {
			printf("%s", stageInfo[i+start].stageName);
			if (clearLv > i+start) printf("��");
		}
		else printf("???");
	}

	COORD selectPos = { 65, 23 };
	SetConsoleCursorPosition(hConsoleOut, selectPos);
	printf("����");
}
//���� �����ϰ� �ִ� ���� ǥ��
void drawSelectPointer(int b) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 7, currentLevel*2+1 };

	if (currentLevel > stageLength - 6) pos.Y -= (stageLength - 10) * 2;
	else if (currentLevel > 5) pos.Y = 11;
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
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (key)// w = 119, a = 97, s = 115, d = 100
	{
	case 'q':
		HelpPopUp();
	case 27:
	case 97:
		isSelecting = isSelecting > 0 ? isSelecting - 1 : 0;
		break;
	case 119:
		if (isSelecting == 0) {
			if (currentLevel > 5 && currentLevel < stageLength-4) {
				currentLevel = currentLevel > 0 ? currentLevel - 1 : 0;
				drawLevelNameScreen(currentLevel - 5);
			}
			else {
				drawSelectPointer(0);
				currentLevel = currentLevel > 0 ? currentLevel - 1 : 0;
				drawSelectPointer(1);
			}
		}
		break;
	case 115:
		if (isSelecting == 0) {
			int accessMax = clearLv >= stageLength - 1 ? stageLength - 1 : clearLv;
			if(currentLevel > 4 && currentLevel < stageLength - 5) {
				currentLevel = currentLevel < accessMax ? currentLevel + 1 : accessMax;
				drawLevelNameScreen(currentLevel - 5);
			}
			else {
				drawSelectPointer(0);
				currentLevel = currentLevel < accessMax ? currentLevel + 1 : accessMax;
				drawSelectPointer(1);
			}
		}
		break;
	case 32:
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
	for (int i = 0; i < 6; i++) {
		deckInfo[i] = 0;
	}
}

#pragma endregion
//��4 ���� �Լ�
#pragma region InGameSceneFunc

char str_text[8][35] = { 0 }; // �ؽ�Ʈ �ڽ� ��� �ؽ�Ʈ
inGameDeckInfo inGameDeck[8];
int currentMap[20][30];
void deckOut();
int turnCountText;

int curDeckCoord[6][2];

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
	drawBox(30, 0, 5, 20, curBuf);

	// ���� �� �� â
	drawBox(30, 5, 12, 20, curBuf);

	//�ؽ�Ʈ �ڽ� â
	drawBox(30, 17, 10, 20, curBuf);


	//�� ���
	deckOut();
}

void textInput(int n, char* text) {
	strcpy_s(str_text[n], 35, text);
}

//�ؽ�Ʈ ��� �Լ�
void textBoxOut(int start, int end, HANDLE curBuf) {
	COORD pos = { 0, 0 };
	int startY = 18;
	pos.X = 62;
	for (int i = start; i < end; i++) {
		if (stageText[currentLevel][i][0] == '\0') // ù ��° ���ڰ� �� ���ڶ�� ����
			break;

		pos.Y = startY + i;

		Printscreen(pos.X, pos.Y, stageText[currentLevel][i], curBuf);
	}
}

void turnCountInOut(int n) {
	turnCountText = n;
}

void turnCountDown() {
	if (turnCountText > 0)
		turnCountText--;
}

void turnBoxOut(int n) {
	COORD pos = { 0, 0 };
	char output[100];
	int startY = 6;
	int startX = 67;

	for (int i = 0; i < 9; i++) {
		pos.Y = startY + i;
		for (int j = 0; j < 5; j++) {
			pos.X = startX + j;
			if (numberTexture[n / 100][i][j] == 1) {
				strcpy_s(output, 3, "#");
				Printscreen(pos.X, pos.Y, "#", gScreen[gIndex]);
			}
			else {
				strcpy_s(output, 3, " ");
				Printscreen(pos.X, pos.Y, " ", gScreen[gIndex]);
			}
		}
	}
	startX = 77;
	for (int i = 0; i < 9; i++) {
		pos.Y = startY + i;
		for (int j = 0; j < 5; j++) {
			pos.X = startX + j;
			if (numberTexture[n % 100 / 10][i][j] == 1) {
				strcpy_s(output, 3, "#");
				Printscreen(pos.X, pos.Y, "#", gScreen[gIndex]);
			}
			else {
				strcpy_s(output, 3, " ");
				Printscreen(pos.X, pos.Y, " ", gScreen[gIndex]);
			}
		}
	}
	startX = 87;
	for (int i = 0; i < 9; i++) {
		pos.Y = startY + i;
		for (int j = 0; j < 5; j++) {
			pos.X = startX + j;
			if (numberTexture[n % 10][i][j] == 1) {
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

/////////////////////////////////////////////////////////////////
void itemInfoOut() {
	COORD pos = { 62, 25 };
	char text[10];
	sprintf(text, "key : %d��", isKey);

	Printscreen(pos.X, pos.Y, text, gScreen[gIndex]);
}

void deckSetting() {
	int idx = 0;

	for (int i = 0; i < 6; i++) {
		if (deckInfo[i] != 0) {
			if (i == 0) {
				inGameDeck[idx].cardCount = deckInfo[i];
				strcpy_s(inGameDeck[idx].cardName, 10, "�б⥰");
				inGameDeck[idx].cardType = 0;
			}
			else if (i == 1) {
				inGameDeck[idx].cardCount = deckInfo[i];
				strcpy_s(inGameDeck[idx].cardName, 10, "������");
				inGameDeck[idx].cardType = 1;
			}
			else if (i == 2) {
				inGameDeck[idx].cardCount = deckInfo[i];
				strcpy_s(inGameDeck[idx].cardName, 10, "���ϥ�");
				inGameDeck[idx].cardType = 2;
			}
			else if (i == 3) {
				inGameDeck[idx].cardCount = deckInfo[i];
				strcpy_s(inGameDeck[idx].cardName, 10, "�׷���");
				inGameDeck[idx].cardType = 3;
			}
			else if (i == 4) {
				inGameDeck[idx].cardCount = deckInfo[i];
				strcpy_s(inGameDeck[idx].cardName, 10, "���֥�");
				inGameDeck[idx].cardType = 4;
			}
			idx++;
		}
	}
}

void resetDeckCoord() {
	for (int i = 0; i < 6; i++) {
		curDeckCoord[i][0] = -1;
		curDeckCoord[i][1] = -1;
	}
}

void setCurDeckCoord(int cardIdx, int X, int Y) {
	curDeckCoord[cardIdx][0] = X;
	curDeckCoord[cardIdx][1] = Y;
}

void deckOut() {
	for (int i = 0; i < deckCount; i++) {
		char cardStr[10];
		sprintf(cardStr, "%d ��", inGameDeck[i].cardCount);  // ������ ���ڿ��� ��ȯ
		Printscreen(i * 8 + 2, 22, inGameDeck[i].cardName, gScreen[gIndex]);
		Printscreen(i * 8 + 1, 23, "  ��", gScreen[gIndex]);
		Printscreen(i * 8 + 2, 24, cardStr, gScreen[gIndex]); // pc���� Ȯ���� ��
		drawBox(i * 4, 21, 5, 5, gScreen[gIndex]);
		setCurDeckCoord(i, i * 8, 21);
	}
}


void MoveBlock(int x, int y, int d);
void JumpPlayer();
void MissileLaunch(int x, int y, int d);
void PullBlock(int x, int y, int d);
void RunPlayer();


void useDeckKeyboard(char eventCode) {
	eventCode = eventCode - '0';
	for (int i = 0; i < deckCount; i++) {
		if (inGameDeck[i].cardType == eventCode - 1) {
			if (inGameDeck[i].cardCount > 0) {
				switch (eventCode) {
				case 1:
					MoveBlock(curX, curY, direction);
					break;
				case 2:
					JumpPlayer();
					break;
				case 3:
					MissileLaunch(curX, curY, direction);
					break;
				case 4:
					PullBlock(curX, curY, direction);
					break;
				case 5:
					RunPlayer();
					break;
				case 6:
					break;
				}
				inGameDeck[i].cardCount--;
				turnCountDown();
			}
		}
	}
}
void useDeckMouse(int X, int Y) {
	for (int i = 0; i < deckCount; i++) {
		if (X >= curDeckCoord[i][0] && X <= curDeckCoord[i][0] + 8
			&& Y >= 21 && Y <= 26) {
			if (inGameDeck[i].cardCount > 0) {
				if (inGameDeck[i].cardType == 0) {
					MoveBlock(curX, curY, direction);
				}
				else if (inGameDeck[i].cardType == 1) {
					JumpPlayer();
				}
				else if (inGameDeck[i].cardType == 2) {
					MissileLaunch(curX, curY, direction);
				}
				else if (inGameDeck[i].cardType == 3) {
					PullBlock(curX, curY, direction);
				}
				else if (inGameDeck[i].cardType == 4) {
					RunPlayer();
				}
				inGameDeck[i].cardCount--;
				turnCountDown();
			}
		}
	}
}

void inGameDeckReset() {
	for (int i = 0; i < 6; i++) {
		deckInfo[i] = 0;
		inGameDeck[i].cardCount = 0;
	}
	deckCount = 0;
}

//���� ���۸� �̿��ؼ� �ΰ��� ȭ�� �׷��ִ� �Լ�
void screenRender(int numDrawInGame, int numTextBoxOut, int numTurnBoxOut, int numLevelBoxOut) {
	screenClear();
	if (numDrawInGame)
		drawInGame(gScreen[gIndex]); // �ӽù��ۿ� �ΰ��� ȭ�� �׸���
	if (numTextBoxOut)
		textBoxOut(0,hintVisible, gScreen[gIndex]);
	if (numTurnBoxOut)
		turnBoxOut(turnCountText);
	if (numLevelBoxOut)
		levelBoxOut();
	if (itemInfoOut)
		itemInfoOut();
	screenFlipping();
}



#pragma endregion


#pragma region PopUpFunc
int ShowPauseAndMenu() { 
	int currentSelectOption = 0;

	for (int i = 0; i < 11; i++) {
		if (_kbhit()) break;
		drawBox(24 - i * 1, 8, 11, 2 + i * 2, gScreen[!gIndex]);
		drawBlank(25 - i * 1, 9, 9, i * 2, gScreen[!gIndex]);
		Sleep(100);
	}
	drawBox(13, 8, 11, 24, gScreen[!gIndex]);
	drawBlank(14, 9, 9, 22, gScreen[!gIndex]);
	//�ɼ� ���
	Printscreen(38, 10, "���", gScreen[!gIndex]);
	Printscreen(38, 12, "�ٽ��ϱ�", gScreen[!gIndex]);
	Printscreen(38, 14, "ī�� ���� �ٽ��ϱ�", gScreen[!gIndex]);
	Printscreen(38, 16, "���� ���� ȭ������ ���ư���", gScreen[!gIndex]);

	Printscreen(34, currentSelectOption * 2 + 10, ">", gScreen[!gIndex]);
	while (1) {
		int key = 0;
		if (_kbhit() != 0) {
			key = _getch();
			switch (key)
			{
			case 27:
				currentSelectOption = 0;
			case 32:
				if (currentSelectOption == 0) {
					screenRender(1, 1, 1, 1);
					return 0;
				}
				else return currentSelectOption;
			case 'w':
				Printscreen(34, currentSelectOption * 2 + 10, "  ", gScreen[!gIndex]);
				currentSelectOption = currentSelectOption > 0 ? currentSelectOption - 1 : 0;
				Printscreen(34, currentSelectOption * 2 + 10, ">", gScreen[!gIndex]);
				break;
			case 's':
				Printscreen(34, currentSelectOption * 2 + 10, "  ", gScreen[!gIndex]);
				currentSelectOption = currentSelectOption < 3 ? currentSelectOption + 1 : 3;
				Printscreen(34, currentSelectOption * 2 + 10, ">", gScreen[!gIndex]);
				break;
			default:
				break;
			}
		}
	}
}
int ShowRestartMenu() {
	int currentSelectOption = 3;

	for (int i = 0; i < 11; i++) {
		if (_kbhit()) break;
		drawBox(24 - i * 1, 8, 11, 2 + i * 2, gScreen[!gIndex]);
		drawBlank(25 - i * 1, 9, 9, i * 2, gScreen[!gIndex]);
		Sleep(100);
	}
	drawBox(13, 8, 11, 24, gScreen[!gIndex]);
	drawBlank(14, 9, 9, 22, gScreen[!gIndex]);
	//�ɼ� ���
	Printscreen(43, 10, "- ���� ���� -", gScreen[!gIndex]);
	Printscreen(38, 12, "�ٽ��ϱ�", gScreen[!gIndex]);
	Printscreen(38, 14, "ī�� ���� �ٽ��ϱ�", gScreen[!gIndex]);
	Printscreen(38, 16, "���� ���� ȭ������ ���ư���", gScreen[!gIndex]);

	Printscreen(34, currentSelectOption * 2 + 10, ">", gScreen[!gIndex]);
	while (1) {
		int key = 0;
		if (_kbhit() != 0) {
			key = _getch();
			switch (key)
			{
			case 27:
				currentSelectOption = 1;
			case 32:
				return currentSelectOption;
			case 'w':
				Printscreen(34, currentSelectOption * 2 + 10, "  ", gScreen[!gIndex]);
				currentSelectOption = currentSelectOption > 1 ? currentSelectOption - 1 : 1;
				Printscreen(34, currentSelectOption * 2 + 10, ">", gScreen[!gIndex]);
				break;
			case 's':
				Printscreen(34, currentSelectOption * 2 + 10, "  ", gScreen[!gIndex]);
				currentSelectOption = currentSelectOption < 3 ? currentSelectOption + 1 : 3;
				Printscreen(34, currentSelectOption * 2 + 10, ">", gScreen[!gIndex]);
				break;
			default:
				break;
			}
		}
	}
}
void LevelClear() { 
	//�ؽ�Ʈ �ڽ� ��� �ִϸ��̼�
	for (int i = 0; i < 11; i++) {
		if (_kbhit()) break;
		drawBox(24 - i * 1, 11, 5, 2 + i * 2, gScreen[!gIndex]);
		drawBlank(25 - i * 1, 12, 3, i * 2, gScreen[!gIndex]);
		Sleep(100);
	}
	drawBox(13, 11, 5, 24, gScreen[!gIndex]);
	drawBlank(14, 12, 3, 22, gScreen[!gIndex]);
	//Ŭ���� �ؽ�Ʈ ���
	Printscreen(44, 13, "LEVEL CLEAR!!", gScreen[!gIndex]);
	if (load() <= currentLevel) save(currentLevel + 1);//���� ������ �ִ� Ŭ���� �������� ũ�� ���� �ƴϸ� ����X
	
	Sleep(1000);

	return;

}
void HelpPopUp() {//����� �� ȭ�� ���� �� ���۹�, ��ȣ�ۿ� ���� ������ ����
	HANDLE menu; //�� ���� ����
	CONSOLE_CURSOR_INFO cci;
	menu = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(menu, &cci);

	drawBox(0, 0, 27, 50, menu);
	Printscreen(10, 2, "- �⺻ ���۹� -", menu);
	Printscreen(10, 4, "W, A, S ,D : �÷��̾� �̵� �� ���� ����", menu);
	Printscreen(10, 5, "E : ��Ʈ", menu);
	Printscreen(10, 6, "Space : ����", menu);
	Printscreen(10, 7, "ESC : ���", menu);
	Printscreen(10, 8, "���콺 �Ǵ� ����Ű 1, 2, 3, 4, 5 : ī�� ����, ī�� ���", menu);
	Printscreen(10, 10, "- �ൿ ī�� ���� -", menu);
	Printscreen(10, 12, "�б� : �÷��̾� �ٷ� ���� ����� ��ĭ �ڷ� �Ӵϴ�.", menu);
	Printscreen(10, 13, "�׷� : �ٶ󺸴� ������ ù��° ����� ��ĭ ������ ���ϴ�.", menu);

	Printscreen(10, 14, "���̵� ������ ��� : ", menu);
	stageNumber(29, 14, 2, menu);
	stageNumber(31, 14, 4, menu);
	stageNumber(33, 14, 24, menu);
	Printscreen(10, 16, "���� : ������ �߻��Ͽ� �ٶ󺸴� ������ ù��° ����� �ı��մϴ�.", menu);
	Printscreen(10, 17, "���ı� ������ ��� : ", menu);
	int canBreak[10] = { 2,4,24,6,5,30,41 };
	for (int i = 0; i < 10; i++) {
		stageNumber(29 + i * 2, 17, canBreak[i], menu);
	}
	Printscreen(10, 19, "���� : �׵θ��� ������ ��� ���� �پ�Ѿ� �� ĭ�� �̵��մϴ�.", menu);
	Printscreen(17, 20, "���������� ���� ������ �̵����� �ʽ��ϴ�.", menu);
	Printscreen(10, 21, "���� : �տ� �������̳� ����� ���� �� ���� �̵��մϴ�.", menu);
	
	
	SetConsoleActiveScreenBuffer(menu);

	_getch();

	CloseHandle(menu);
}
void EndingScreen() {
	system("cls");
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curCursorInfo;
	GetConsoleCursorInfo(hConsoleOut, &curCursorInfo);
	curCursorInfo.bVisible = 0;
	SetConsoleCursorInfo(hConsoleOut, &curCursorInfo);

	COORD pos = { 0,0 };
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		pos.Y = i;
		SetConsoleCursorPosition(hConsoleOut, pos);
		printf("%s",endingImage[i]);
		for (int i = 0; i < 50; i++) {
			Sleep(10);
			if (_kbhit() != 0) _getch();
		}
	}
	pos.X = 60;
	pos.Y = 20;
	SetConsoleCursorPosition(hConsoleOut, pos);
	printf("�ƾ�...");
	pos.Y++;
	SetConsoleCursorPosition(hConsoleOut, pos);
	printf("�ͼ��� õ���̴�...");

	_getch();
	system("cls");
	return;
}
#pragma endregion

#pragma region InGameFunc
void MovePlayer(int x, int y);
//�⺻ �� �̵�
void MoveBlock(int x, int y, int d) {
	//direction���� �̵����� ���
	int moveX = d % 2 == 0 ? 0 : d > 2 ? -1 : 1;
	int moveY = d % 2 == 1 ? 0 : d > 1 ? 1 : -1;

	//������ �� ��ġ
	int blockNum = currentMap[y + moveY][x + moveX];
	if (blockNum != 2 && blockNum != 4 && blockNum != 24) return;
	//�̵��� ���� ������
	int destinationNum = currentMap[y + 2 * moveY][x + 2 * moveX];

	if (destinationNum != 0 && destinationNum != 3 && destinationNum != 5 && destinationNum != 6) return;

	//�������� ������̸� �̵�
	if (destinationNum == 0) {
		currentMap[y + 2 * moveY][x + 2 * moveX] = blockNum;
		currentMap[y + moveY][x + moveX] = 0;
	}
	// �������� �����϶� �����̴� ���� �⺻ ���̸� ���� ��ü
	else if (destinationNum == 3) {
		currentMap[y + moveY][x + moveX] = 0;
		currentMap[y + 2 * moveY][x + 2 * moveX] = 0;
	}
	//�������� �뱤���϶� �⺻ ���� �ܴ��� ������� ���׷��̵�
	else if (destinationNum == 5 && blockNum == 2) {
		currentMap[y + moveY][x + moveX] = 0;
		currentMap[y + 2 * moveY][x + 2 * moveX] = 4;
		blockNum = 4;
	}
	else if (destinationNum == 6 && blockNum == 4)
	{
		currentMap[y + moveY][x + moveX] = 0;
		currentMap[y + 2 * moveY][x + 2 * moveX] = 4;
	}

	//��� üũ
	if (blockNum == 24) {
		plugAndOutletOff(x + moveX, y + moveY, currentLevel, currentMap);
		plugAndOutletOn(x + 2 * moveX, y + 2 * moveY, currentLevel, currentMap);
	}
	if (blockNum == 2 || blockNum == 24) {
		fanMove(x + 2 * moveX, y + 2 * moveY, currentMap, blockNum);
	}

	if (blockNum == 4) {
		fanMove(x + moveX, y + moveY, currentMap, blockNum);
	}
	return;
}
void JumpPlayer() {
	//direction���� �̵����� ���
	int moveX = direction % 2 == 0 ? 0 : direction > 2 ? -1 : 1;
	int moveY = direction % 2 == 1 ? 0 : direction > 1 ? 1 : -1;
	//�ǳʶ� ��(�׵θ��� �ǳʶ��� ����)
	int blockNum = currentMap[curY + moveY][curX + moveX];
	if ((blockNum <= -1 && blockNum >= -6) || (blockNum <= -11 && blockNum>=-16)) return;
	//�÷��̾��� ���� ��ġ ���� �Ұ��� �ϸ� ��ȯ
	MovePlayer(moveX * 2, moveY * 2);
	return;
}
void MissileLaunch(int x, int y, int d) {
	//direction���� �̵����� ���
	int moveX = d % 2 == 0 ? 0 : d > 2 ? -1 : 1;
	int moveY = d % 2 == 1 ? 0 : d > 1 ? 1 : -1;

	stageNumber(x*2, y, d%10+90, gScreen[!gIndex]);
	Sleep(30);
	stageNumber(x*2, y, currentMap[y][x], gScreen[!gIndex]);
	//�ش� �������� ��ĭ �տ� �ִ� �� Ȯ��
	int blockNum = currentMap[y + moveY][x + moveX];

	// �ش� ��ġ�� ��ĭ�̸� ����Լ��� ����ĭ Ȯ��, ���� ������ �ı� �� ����Լ� ����, �ı� �Ұ��� �� �ƹ��͵� �����ʰ� ����
	if (blockNum == 0 || blockNum == 3 || blockNum == 60 || blockNum == 40) { 
		//�������� �׸��� ����� �Լ� �ʿ�
		MissileLaunch(x + moveX, y + moveY, d);
	}
	else if (blockNum == 2 || blockNum == 4 || blockNum == 24 || blockNum == 6 || blockNum == 5 || (blockNum >= 30 && blockNum <= 33) || blockNum == 41) {
		currentMap[y + moveY][x + moveX] = 0;
	}
	return;
}
void PullBlock(int x, int y, int d) {
	//direction���� �̵����� ���
	int moveX = d % 2 == 0 ? 0 : d > 2 ? -1 : 1;
	int moveY = d % 2 == 1 ? 0 : d > 1 ? 1 : -1;

	//�ش� �������� ��ĭ �տ� �ִ� �� Ȯ��
	int blockNum = currentMap[y + moveY][x + moveX];
	// �ش� ��ġ�� ��ĭ�̸� ����Լ��� ����ĭ Ȯ��, ���� ������ ��ĭ ������ ��� �� ����Լ� ����
	if (blockNum == 0 || blockNum == 3 || blockNum == 5) {
		PullBlock(x + moveX, y + moveY, d);
	}
	else if (blockNum <= -1 && blockNum >= -6 || blockNum == 10 || (blockNum >= 20 && blockNum <= 23) 
			|| blockNum == 5 || blockNum == 6) return;
	else {
		MoveBlock(x + 2 * moveX, y + 2 * moveY, d % 2 + (1 - d / 2) * 2);// ���� �ݴ���⿡�� �̴� �Լ�
	}
	return;
}
void RunPlayer() {
	int moveX = direction % 2 == 0 ? 0 : direction > 2 ? -1 : 1;
	int moveY = direction % 2 == 1 ? 0 : direction > 1 ? 1 : -1;
	int blockNum = currentMap[curY + moveY][curX + moveX];
	//�տ� �ƹ��͵� ���� ���� �̵�
	if (blockNum == 0) {
		int prevX = curX;
		int prevY = curY;
		MovePlayer(moveX, moveY);
		stageNumber(prevX * 2, prevY, currentMap[prevY][prevX], gScreen[!gIndex]);
		stageNumber(curX * 2, curY, currentMap[curY][curX], gScreen[!gIndex]);
		Sleep(30);
		RunPlayer();
	}
	return;
}

//�÷��̾� �̵�
void MovePlayer(int x, int y) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int blockNum = currentMap[curY + y][curX + x];

	switch (blockNum) {
	case 10: //������
		isClear = 1;
	case 0: //��ĭ
		currentMap[curY][curX] = 0;
		currentMap[curY + y][curX + x] = 1;
		curY += y;
		curX += x;
		break;
	case 6:
		slimeSplit(curX, curY, currentMap);
		break;
	case 40:
		ClearSwitch(currentMap);
		currentMap[curY][curX] = 0;
		currentMap[curY + y][curX + x] = 1;
		curY += y;
		curX += x;
		break;
	case 60:
		currentMap[curY][curX] = 0;
		currentMap[curY + y][curX + x] = 1;
		isKey += 1;
		curY += y;
		curX += x;
		break;
	case 61:
		if (isKey) {
			isKey--;
			currentMap[curY][curX] = 0;
			currentMap[curY + y][curX + x] = 1;
			curY += y;
			curX += x;
		}
		break;
		//unlockBox(curX + x,curY + y, currentMap);
	case -15: 
		if (curY > 10) MovePlayer(0, 1 - curY);
		else MovePlayer(0, stageHeight - curY - 2);
		break;
	case -16: //�����׵θ�
		if (curX > 15) MovePlayer(1 - curX,0);
		else MovePlayer(stageWidth - curX - 2, 0);
		break;
	}

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
			case '1': return '1';
			case '2': return '2';
			case '3': return '3';
			case '4': return '4';
			case '5': return '5';
			case 'W': case 'w': return 'w';
			case 'A': case 'a': return 'a';
			case 'S': case 's': return 's';
			case 'D': case 'd': return 'd';
			case 'Q': case'q': return 'q';
			case 'E': case'e': return 'e';
			case 27: return 27;
			}
		}
		else if (inputRecord.EventType == MOUSE_EVENT) {
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
int prepareProcessInputs(HANDLE hConsoleInput) {
	INPUT_RECORD inputRecord;
	DWORD events;

	// �ܼ� �Է� ��忡�� ���콺�� Ű���� ��� �Է¹���
	SetConsoleMode(hConsoleInput, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	while (1) {
		ReadConsoleInput(hConsoleInput, &inputRecord, 1, &events);

		if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
			// Ű���� �Է�
			switch (inputRecord.Event.KeyEvent.wVirtualKeyCode) {
			case '1': return '1';
			case '2': return '2';
			case '3': return '3';
			case '4': return '4';
			case '5': return '5';
			case 'Q': case 'q': return 'q';
			}
		}
		else if (inputRecord.EventType == MOUSE_EVENT) {
			// ���콺 �Է�
			MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;
			if (mouseEvent.dwEventFlags == MOUSE_MOVED) {
				curMousePos.X = mouseEvent.dwMousePosition.X;
				curMousePos.Y = mouseEvent.dwMousePosition.Y;
				drawTooltip(curMousePos.X, curMousePos.Y);
			}
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

	system("mode con: cols=100 lines=27 | title ���� õ��");
	//��1
	displayMainMenu(); // ����ȭ�� ǥ��
	_getch();
	int currentOption = 3;
	hintVisible = 3;
	while (1) {
		switch (currentOption) {
		case 3:
			system("cls");

			//��2
			isSelecting = 0;
			clearLv = load();

			mapCopy();// �� ����

			drawMap(20, 0, hConsoleOut);
			drawLevelNameScreen(currentLevel - 5);
			drawSelectPointer(1);
			int tick = 0, blink = 0;
			int k = 0;
			while (1) {
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
			setPrepareOrigininfo();
			deckCount = 0;
			//ī�� ����ȭ�� ����� ��ġ
		case 2:
			system("cls");
			if (currentLevel < 3)
			{
				if (currentLevel == 0) {
					deckInfo[0] = 2;
					deckInfo[1] = 1;
					deckCount = 2;
				}
				else if (currentLevel == 1) {
					deckInfo[2] = 4;
					deckInfo[3] = 5;
					deckInfo[4] = 7;
					deckCount = 3;
				}
				else if (currentLevel == 2) {
					deckInfo[0] = 12;
					deckInfo[1] = 3;
					deckInfo[2] = 2;
					deckCount = 3;
				}
			}
			else if (currentLevel == stageLength -1) deckCount = 0;
			else
			{
				drawPrepareBox();
				drawMap(20, 1, hConsoleOut);
				while (1) {
					drawPrepareInfo();
					// ����Ŭ�� ��ġ ��������
					int eventCode = prepareProcessInputs(hConsoleInput);	//Ű����, ���콺 �̺�Ʈ ó��.
					if (eventCode == 'q') HelpPopUp();
					detectPrepareFunc(curMousePos.X, curMousePos.Y, eventCode);
					if (eventCode == 'M' && curMousePos.Y >= confirmCoord[1] &&
						curMousePos.Y <= confirmCoord[1] + 5 &&
						curMousePos.X >= confirmCoord[0] &&
						curMousePos.X <= confirmCoord[0] + 8) {
						break;
					}
				}
			}

			
			//�� 4
		case 1:
			mapCopy();// �� ����
			direction = 0;
			isKey = 0;
			isClear = 0;
			screenInit();
			screenRender(1, 0, 0, 0); // �ΰ��� ȭ��, �ؽ�Ʈ �ڽ�, �� ����â ��� ���� ����
			Sleep(100);
			strcpy_s(str_text[0], 35, "���� �ߴ� ����õ���� ���Դϴ�.");
			strcpy_s(str_text[1], 35, "�ϴ� ���⼭ �������� �� �����ϴ�.");
			strcpy_s(str_text[2], 35, "'��'�� �ִ� ������ �̵��غ��ô�.");

			deckSetting();// �������� �� ī�� ������ �ΰ��ӿ� ������Ʈ �ϴ� �Լ�
			turnCountInOut(stageInfo[currentLevel].maxActionCount);


			curX = stageInfo[currentLevel].spawnX;
			curY = stageInfo[currentLevel].spawnY;
			screenRender(1, 1, 1, 1);

			while (1) {
				int eventCode = processInputs(hConsoleInput);	//Ű����, ���콺 �̺�Ʈ ó��.
				if (eventCode >= '1' && eventCode <= '5') {
					useDeckKeyboard(eventCode);
				}
				else if (eventCode == 'M') {
					useDeckMouse(curMousePos.X, curMousePos.Y);
				}
				else if (eventCode == 'q') HelpPopUp();
				else if (eventCode == 'e') hintVisible = 6;
				switch (eventCode) {
				case 27://ESC
					currentOption = ShowPauseAndMenu();
					if (currentOption > 0) goto Game;
					continue;
				case 'w': // ���� �̵�
					direction = 0;
					MovePlayer(0, -1);//�ش� ��ġ�� ���������̸� 1, �ƴϸ� 0;
					turnCountDown();
					break;
				case 'd': // ���������� �̵�
					direction = 1;
					MovePlayer(1, 0);
					turnCountDown();
					break;
				case 's': // �Ʒ��� �̵�
					direction = 2;
					MovePlayer(0, 1);
					turnCountDown();
					break;
				case 'a': // �������� �̵�
					direction = 3;
					MovePlayer(-1, 0);
					turnCountDown();
					break;
				}
				screenRender(1, 1, 1, 1);
				
				if (isClear)break;
				if (turnCountText == 0) {
					currentOption = ShowRestartMenu();
					goto Game;
				}
				
			}
			if (isClear) {
				LevelClear();
				inGameDeckReset();
				currentOption = 3;
			}
			int t =_getch();
		Game:
			direction = 0;
			hintVisible = 3;
			screenRelease();
			if (currentLevel == stageLength - 1 && isClear) {
				Sleep(1000);
				EndingScreen();
			}
		}
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
}// ���� ����, Ŭ������ ����, ��� ����
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






