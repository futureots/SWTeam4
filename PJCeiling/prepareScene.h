#pragma once
#include <stdio.h>
#include<Windows.h>

typedef struct inGameDeckInfo {
	int cardType;
	char cardName[10];
	int cardCount;
}inGameDeckInfo;

int deckCount = 0;
int card_size_x = 8;
int card_size_y = 5;

//상점에서 살 카드의 정보를 저장하는 배열. 현재는 8길이 int배열 하나로 이루어져 있지만,
//스테이지가 추가될 경우 2차원 배열로 초기값을 결정할 예정.
int cardInfo[6];
char* cardText[6] = {
	"블럭을 밉니다.",
	"블럭을 건너뜁니다.",
	"로켓을 발사합니다.",
	"맞은편 블럭을 당깁니다.",
	"앞으로 달립니다."
};
//코스트를 저장하는 int값. 맵으로부터 읽어들인 총 코스트에 따라 변경.
int costInfo;
int costPrice[6] = { 1, 2, 5, 3, 2, 0};

//덱의 카드 수를 저장하는 배열.
int deckInfo[6];

int cardCoord[6][2] = { {0,1},{12,1},{24,1},{0,7},{12,7},{24,7} };
int deckCoord[6][2] = { {10, 21},{18,21},{26,21},{34,21},{42,21},{50,21} };
int costCoord[2] = { 0,21 };
int textBoxCoord[2] = { 2,15 };

int cardInfoCoord[6][2] = { {2,1},{14,1},{26,1},{2,7},{14,7},{26,7} };
int deckInfoCoord[6][2] = { {12, 22},{20,22},{28,22},{36,22},{44,22},{52,22} };
int costInfoCoord[2] = { 2,22 };
int confirmCoord[2] = { 92,21 };


int prepareMap[27][50] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{3,1,1,1,4,0,3,1,1,1,4,0,3,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,1,1,1,5,0,6,1,1,1,5,0,6,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{3,1,1,1,4,0,3,1,1,1,4,0,3,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,1,1,1,5,0,6,1,1,1,5,0,6,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{3,1,1,4,0,3,1,1,1,8,1,1,1,8,1,1,1,8,1,1,1,8,1,1,1,8,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,4},
	{2,0,0,2,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2},
	{2,0,0,2,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2},
	{2,0,0,2,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2},
	{6,1,1,5,0,6,1,1,1,10,1,1,1,10,1,1,1,10,1,1,1,10,1,1,1,10,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,1,5},
};



void drawCardInfo();
void drawDeckInfo();
void drawcostInfo();
COORD getCurrentCursorPos();
void setCurrentCursorPos(int posX, int posY);
void drawPrepareBox();
void printScoreOver(int index);
void printDeckCountOver();
void detectPrepareFunc(int X, int Y,char eventCode);
void drawPrepareInfo();
void drawCardInfo();
void drawDeckInfo();
void drawcostInfo();
void eraseTooltipBox();
void drawTooltip(int X, int Y);



COORD getCurrentCursorPos() {
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;
	return curPoint;
}
//커서의 좌표를 설정하는 함수
void setCurrentCursorPos(int posX, int posY) {
	COORD pos = { posX, posY };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawPrepareBox() {
	int cardCurX = 0;
	int cardCurY = 0;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 50; j++) {
			setCurrentCursorPos(cardCurX + (j * 2), cardCurY + i);
			if (prepareMap[i][j] == 0) {

			}
			if (prepareMap[i][j] == 1) {
				printf("─");
			}
			if (prepareMap[i][j] == 2) {
				printf("│");
			}
			if (prepareMap[i][j] == 3) {
				printf("┌─");
			}
			if (prepareMap[i][j] == 4) {
				printf("┐");
			}
			if (prepareMap[i][j] == 5) {
				printf("┘");
			}
			if (prepareMap[i][j] == 6) {
				printf("└─");
			}
			if (prepareMap[i][j] == 8) {
				printf("┬─");
			}
			if (prepareMap[i][j] == 10) {
				printf("┴─");
			}
		}
		printf("\n");
	}
}

void printScoreOver(int Index) {
	eraseTooltipBox();
	printf("코스트가 부족합니다!");
	setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
	printf("필요한 코스트: %d", costPrice[Index]);
	setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 4);
	printf("남은 코스트: %d", costInfo);
	Sleep(1000);
	eraseTooltipBox();
}

void printDeckCountOver() {
	eraseTooltipBox();
	printf("남은 매수가 없습니다!");
	Sleep(1000);
	eraseTooltipBox();
}

void detectPrepareFunc(int X, int Y, char eventCode) {
	
	if (eventCode == 'M') {	//  입력받은 eventCode가 더블클릭일 경우
		//카드 구매
		for (int i = 0; i < 5; i++) {
			if (Y >= cardCoord[i][1] && Y <= cardCoord[i][1] + 3) {
				if (X >= cardCoord[i][0] && X <= cardCoord[i][0] + 8) {
					if (deckInfo[i] == 0) // 처음 사는 카드면 덱카운트 증가
						deckCount++;
					if (costInfo >= costPrice[i]) {	//코스트는 1
						deckInfo[i]++;
						costInfo = costInfo - costPrice[i];
					}
					else {
						printScoreOver(costPrice[i]);
					}
				}
			}
		}
		//카드 판매
		if (Y >= deckCoord[0][1] && Y <= deckCoord[0][1] + 5) {
			for (int i = 0; i < 6; i++) {
				if (X >= deckCoord[i][0] && X < deckCoord[i][0] + 6) {
					if (deckInfo[i] >= 1) {
						deckInfo[i]--;
						costInfo = costInfo + costPrice[i];
						if (deckInfo[i] == 0) //  다 판매한 카드면 덱카운트 감소
							deckCount--;
					}
					else {
						printDeckCountOver();
					}
				}
			}
		}
	}
	else {
		eventCode = eventCode - '1';
		//  카드 구매(키보드)
		if (eventCode >= 0 && eventCode <= 6) {
			if (deckInfo[eventCode] == 0) //  처음 사는 카드면 덱카운트 증가
				deckCount++;
			if (costInfo >= costPrice[eventCode]) {	//  코스트는 1
				deckInfo[eventCode]++;
				costInfo = costInfo - costPrice[eventCode];
			}
			else {
				printScoreOver(eventCode);
			}
		}
	}


}

void drawPrepareInfo() {
	drawCardInfo();
	drawDeckInfo();
	drawcostInfo();
	setCurrentCursorPos(confirmCoord[0] + 2, confirmCoord[1] + 2);
	printf("확인");
}

void drawCardInfo() {
	setCurrentCursorPos(cardInfoCoord[0][0], cardInfoCoord[0][1]);
	printf(" 밀기");
	setCurrentCursorPos(cardInfoCoord[0][0], cardInfoCoord[0][1] + 2);
	printf("  Ⅰ ");

	setCurrentCursorPos(cardInfoCoord[1][0], cardInfoCoord[1][1]);
	printf(" 점프");
	setCurrentCursorPos(cardInfoCoord[1][0], cardInfoCoord[1][1] + 2);
	printf("  Ⅱ ");

	setCurrentCursorPos(cardInfoCoord[2][0], cardInfoCoord[2][1]);
	printf(" 로켓");
	setCurrentCursorPos(cardInfoCoord[2][0], cardInfoCoord[2][1] + 2);
	printf("  Ⅲ ");

	setCurrentCursorPos(cardInfoCoord[3][0], cardInfoCoord[3][1]);
	printf(" 그랩");
	setCurrentCursorPos(cardInfoCoord[3][0], cardInfoCoord[3][1] + 2);
	printf("  Ⅳ ");

	setCurrentCursorPos(cardInfoCoord[4][0], cardInfoCoord[4][1]);
	printf(" 질주");
	setCurrentCursorPos(cardInfoCoord[4][0], cardInfoCoord[4][1] + 2);
	printf("  Ⅴ ");
}

void drawDeckInfo() {
	setCurrentCursorPos(deckInfoCoord[0][0], deckInfoCoord[0][1]);
	printf("밀기");
	setCurrentCursorPos(deckInfoCoord[1][0], deckInfoCoord[1][1]);
	printf("점프");
	setCurrentCursorPos(deckInfoCoord[2][0], deckInfoCoord[2][1]);
	printf("로켓");
	setCurrentCursorPos(deckInfoCoord[3][0], deckInfoCoord[3][1]);
	printf("그랩");
	setCurrentCursorPos(deckInfoCoord[4][0], deckInfoCoord[4][1]);
	printf("질주");

	for (int i = 0; i < 5; i++) {
		setCurrentCursorPos(deckInfoCoord[i][0], deckInfoCoord[i][1] + 1);
		printf(" ─");
		setCurrentCursorPos(deckInfoCoord[i][0], deckInfoCoord[i][1] + 2);
		printf("%2d 개", deckInfo[i]);
	}
}

void drawcostInfo() {
	setCurrentCursorPos(costInfoCoord[0], costInfoCoord[1]);
	printf("Cost");
	setCurrentCursorPos(costInfoCoord[0], costInfoCoord[1] + 1);
	printf(" ─");
	setCurrentCursorPos(costInfoCoord[0], costInfoCoord[1] + 2);
	printf("%3d", costInfo);
}

void eraseTooltipBox() {
	setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1]);
	for (int i = 0; i < 6; i++) {
		printf("                                ");
		setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + i);
	}
	setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1]);
}

void drawTooltip(int X, int Y) {
	//카드 정보 툴팁
	for (int i = 0; i < 5; i++) {
		if (Y >= cardCoord[i][1] && Y <= cardCoord[i][1] + 3) {
			if (X >= cardCoord[i][0] && X <= cardCoord[i][0] + 8) {
				eraseTooltipBox();
				printf("%s", cardText[i]);
				setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
				printf("가격은 %d코스트 입니다.", costPrice[i]);
			}
		}
	}
	//덱 정보 툴팁
	if (Y >= deckCoord[0][1] && Y <= deckCoord[0][1] + 5) {
		if (X >= deckCoord[0][0] && X <= deckCoord[5][0] + 8) {
			eraseTooltipBox();
			printf("당신이 구매한 덱입니다.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("더블클릭으로 환불할 수 있습니다.");
		}
	}
	//버튼 정보 툴팁
	if (Y >= costInfoCoord[1] && Y <= costInfoCoord[1] + 5 && X >= costInfoCoord[0] && X <= costInfoCoord[0] + 8) {
		eraseTooltipBox();
		printf("남은 코스트는 %d 입니다.", costInfo);
	}
	if (Y >= confirmCoord[1] && Y <= confirmCoord[1] + 5 && X >= confirmCoord[0] && X <= confirmCoord[0] + 8) {
		eraseTooltipBox();
		printf("더블클릭시 덱을 확정합니다.");
	}
	//맵 툴팁
	if (Y >= 1 && Y < 21 && X >= 40 && X <= 140) {
		eraseTooltipBox();
		printf("이번에 플레이할 맵입니다.");
		setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
		printf("덱을 만들어 미로를 풀어 보세요!");
	}
}