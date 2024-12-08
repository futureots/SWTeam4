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
/////////////////////////////////////추가 내용/////////////////////////////////////////

textInput(int n, char*text) 텍스트 입력 함수
텍스트 출력할 줄 n
입력할 텍스트 text

turnCountInput(int n, int p) 턴 카운트 입력 함수
십의 자리 수 n
일의 자리 수 p

turnCountDown() 턴 카운트 감소 함수

deckOut() 카드 내용 인게임 화면에 보여주는 함수

deckCountDown() 카드 사용시 카운트 감소해주는 함수 (미구현)
*/

void drawMap(int startX, int startY, HANDLE curBuf);
void drawBox(int startX, int startY, int height, int width);
void save(int k);
int load();

int currentLevel = 0;
int curX, curY;

//씬1 관련 함수
#pragma region MainSceneFunc

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 27
void setCursorPosition(int x, int y) {
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/*커서 숨김 함수
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

// 화면 테두리 그리는 함수 (양쪽에서 중앙으로 이동하며 그리기)
void drawBorder() {
	int fullWidth = SCREEN_WIDTH;
	int halfWidth = SCREEN_WIDTH / 2;

	// 윗 가로선 양쪽에서 중앙으로 그리기
	for (int i = halfWidth - 1; i >= 0; i--) {
		setCursorPosition(i, 0);
		if (i == 0) printf("┌─");
		else	printf("──");
		setCursorPosition(fullWidth - 1 - i, 0);
		if (i == 0) printf("┐");
		else printf("──");
		Sleep(5);
	}

	// 세로선 그리기 (위에서 아래로 양쪽 동시 그리기)
	for (int i = 1; i < SCREEN_HEIGHT - 1; i++) {
		setCursorPosition(0, i);
		printf("│");
		setCursorPosition(fullWidth - 1, i);
		printf("│");
		Sleep(5);
	}

	// 아랫 가로선 양쪽에서 중앙으로 그리기
	for (int i = 0; i < halfWidth; i++) {
		setCursorPosition(i, SCREEN_HEIGHT - 1);
		if (i == 0) printf("└─");
		else printf("──");
		setCursorPosition(fullWidth - 1 - i, SCREEN_HEIGHT - 1);
		if (i == 0) printf("┘");
		else printf("──");
		Sleep(5);
	}
}

// 메인화면 초기화하는 함수
void initializeMainMenu() {
	// 화면 클리어
	system("cls");
}

// 메인화면 표시하는 함수
void displayMainMenu() {
	initializeMainMenu();
	drawBorder();
	// "낯선 천장" 텍스트를 특수문자로 표현 (폰트 크기 문제)

	setCursorPosition(16, 10);
	printf(" └── ├   ／＼┤   -┻-    ㅡㅡ ");
	setCursorPosition(16, 11);
	printf("  ─┼─            /＼┤    /＼├");
	setCursorPosition(16, 12);
	printf("  /＼     └--     └--      ○");

	int showText = 1;
	while (!_kbhit()) {
		setCursorPosition(17, 15);

		if (showText) {
			printf("<<아무 버튼이나 누르세요>>\n");
		}
		else {
			printf("                            ");
		}
		showText = !showText;
		Sleep(500);
	}
}


#pragma endregion
//씬2 관련 함수
#pragma region LevelSelectScreenFunction
int clearLv = 0;
int isSelecting = 0;
//레벨 이름 쓰기
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
	printf("선택");
}
//현재 선택하고 있는 레벨 표시
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
//레벨 선택시 다음 화면으로 이동하기
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
//씬3 관련 함수
#pragma region LevelSelectScreenFunction

//마우스 좌표를 저장할 구조체
typedef struct {
	int X;
	int Y;
} MousePosition;

//더블클릭했을 때 마우스 좌표를 반환하는 함수.
//도움말 기능 포함.
MousePosition getMouseClickPosition(HANDLE hConsoleInput) {
	INPUT_RECORD inputRecord;
	DWORD events;
	MousePosition mousePos = { -1, -1 };

	// 콘솔 입력 모드에서 마우스 입력을 활성화.
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

void enableKeyboardInput(HANDLE hConsoleInput) {
	// 콘솔 입력 모드를 키보드 입력으로.
	SetConsoleMode(hConsoleInput, ENABLE_PROCESSED_INPUT | ENABLE_WINDOW_INPUT);
}

void setPrepareOrigininfo() {
	costInfo = stageInfo[currentLevel].cost;
	for (int i = 0; i < 8; i++) {
		//카드 인포는 아직 정해지지 않았으므로 일단 2로 초기화함.
		cardInfo[i] = 2;
		deckInfo[i] = 0;
	}
}

#pragma endregion
//씬4 관련 함수
#pragma region InGameScene

char str_text[8][35] = { 0 }; // 텍스트 박스 출력 텍스트
int tens, ones; // 턴 박스 출력 텍스쳐 번호 // 십의자리, 일의자리
int inGameCardInfo[8]; // 인게임에서 사용 되는 카드 정보
int deckCount; // 카드 종류의 개수
void deckOut();

void levelBoxOut() {
	COORD pos = { 62, 2 };
	Printscreen(pos.X, pos.Y, stageInfo[currentLevel].stageName, gScreen[gIndex]);
}

// 인게임 화면 출력
void drawInGame(HANDLE curBuf) {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int startX = 60;
	int startY = 0;
	COORD pos = { 0,0 };
	drawMap(0, 0, curBuf);

	//스테이지 레벨 창
	drawBox(30, 0, 5, 12);

	// 남은 턴 수 창
	drawBox(30, 5, 12, 20);

	//텍스트 박스 창
	drawBox(30, 17, 10, 20);
	// i 값이 카드 수

	deckOut();
}

//텍스트 삽입 함수
void textInput(int n, char* text) {
	strcpy_s(str_text[n], 35, text);
}
//턴카운트 삽입 함수
void trunCountInut(int n, int p) {
	tens = n;
	ones = p;
}
//텍스트 출력 함수
void textBoxOut(char text[][35]) {
	COORD pos = { 0, 0 };
	int startY = 18;
	pos.X = 62;
	for (int i = 0; i < 8; i++) {
		if (text[i][0] == '\0') // 첫 번째 문자가 널 문자라면 종료
			break;

		pos.Y = startY + i;

		Printscreen(pos.X, pos.Y, text[i], gScreen[gIndex]);
	}
}

//턴 카운트 감소 함수
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
void deckOut() {
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int startX = 60;
	int startY = 0;
	COORD pos = { 0,0 };
	int deckCount = 0;
	int p = 0, idx = 0;

	for (int i = 0; i < 8; i++) {
		if (deckInfo[i] != 0) {
			printf("%d\n", p);
			deckCount++;
			char cardStr[10];
			sprintf(cardStr, "%d 개", deckInfo[i]);  // 정수를 문자열로 변환

			if (i == 0) {
				Printscreen(p * 8 + 1, 22, " 밀기", gScreen[gIndex]);
				Printscreen(p * 8 + 1, 23, "  ─", gScreen[gIndex]);
				Printscreen(p * 8 + 2, 24, cardStr, gScreen[gIndex]);
				inGameCardInfo[idx++] = i;
			}
			else if (i == 1) {
				Printscreen(p * 8 + 1, 22, " 점프", gScreen[gIndex]);
				Printscreen(p * 8 + 1, 23, "  ─", gScreen[gIndex]);
				Printscreen(p * 8 + 2, 24, cardStr, gScreen[gIndex]);
				inGameCardInfo[idx++] = i;
			}
			else if (i == 2) {
				Printscreen(p * 8 + 1, 22, " 로켓", gScreen[gIndex]);
				Printscreen(p * 8 + 1, 23, "  ─", gScreen[gIndex]);
				Printscreen(p * 8 + 2, 24, cardStr, gScreen[gIndex]);
				inGameCardInfo[idx++] = i;
			}
			p++;
		}
	}
	for (int i = 0; i < deckCount; i++) {
		drawBox(i * 4, 21, 5, 4);
	}
}

/*
void deckCountDown(int x, int y) {

	for (int i = 0; i < deckCount; i++) {
		if (y >= 21 && y < 26) {
			if (x >= i * 8 && x < i * 8 + 4) {
				inGameCardInfo[i]--;
			}
		}
	}
}
*/
//더블 버퍼를 이용해서 인게임 화면 그려주는 함수
void screenRender(int numDrawInGame, int numTextBoxOut, int numTurnBoxOut, int numLevelBoxOut) {
	screenClear();
	if (numDrawInGame)
		drawInGame(gScreen[gIndex]); // 임시버퍼에 인게임 화면 그리기
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

	MousePosition mousePos;


	system("mode con: cols=100 lines=27 | title 낮선 천장");
	//씬1
	displayMainMenu(); // 메인화면 표시

	_getch();
	while (1) {

		system("cls");

		//씬2
		isSelecting = 0;
		clearLv = load();
		drawMap(20, 0, hConsoleOut);
		drawLevelNameScreen();
		drawLevelSelectPointer(1);
		int tick = 0, blink = 0;
		int k = 0;
		while (1) {
			// 마우스 클릭 좌표 감지

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

		//씬 3
		system("cls");
		setPrepareOrigininfo();
		drawPrepareBox();
		drawMap(20, 1, hConsoleOut);
		while (1) {
			drawPrepareInfo();
			// 더블클릭 위치 가져오기
			mousePos = getMouseClickPosition(hConsoleInput);
			if (mousePos.X != -1 && mousePos.Y != -1) {
				detectPrepareFunc(mousePos.X, mousePos.Y);
			}
			if (mousePos.Y >= confirmCoord[1] && mousePos.Y <= confirmCoord[1] + 5 && mousePos.X >= confirmCoord[0] && mousePos.X <= confirmCoord[0] + 8) {
				break;
			}
		}
		//다시 키보드 입력으로 바꾸기
		enableKeyboardInput(hConsoleInput);


		//씬 4
		screenInit();
		screenRender(1, 0, 0, 0); // 인게임 화면, 텍스트 박스, 턴 상태창 출력 여부 결정
		Sleep(1000);

		textInput(0, "눈을 뜨니 낯선천장이 보입니다.");
		textInput(1, "일단 여기서 나가야할 것 같습니다.");
		textInput(2, "'★'이 있는 곳까지 이동해봅시다.");

		trunCountInut(2, 0);
		screenRender(1, 1, 1, 1);
		Sleep(1000);
		
		
		for (int i = 0; i < 20; i++) {
			turnCountDown();
			screenRender(1, 1, 1, 1);
			Sleep(1000);
		}
		
		/*
		// 활성화된 버퍼에서 마우스 좌표 받기
		mousePos = getMouseClickPosition(gScreen[!gIndex]);
		if (mousePos.X != -1 && mousePos.Y != -1) {
			deckCountDown(mousePos.X, mousePos.Y);
			screenRender(1, 1, 1, 1);
		}
		enableKeyboardInput(gScreen[!gIndex]);
		*/
		_getch();

		screenRelease();

		//save(load()+1); //다음 레벨 열기
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



