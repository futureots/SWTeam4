#pragma once
#include <stdio.h>
#include<Windows.h>
typedef struct inGameDeckInfo {
	int cardType;
	char cardName[10];
	int cardCount;
}inGameDeckInfo;

int deckCount = 0; // ���õ� ī�� ������ ��
int card_size_x = 8;
int card_size_y = 5;

//�������� �� ī���� ������ �����ϴ� �迭. ����� 8���� int�迭 �ϳ��� �̷���� ������,
//���������� �߰��� ��� 2���� �迭�� �ʱⰪ�� ������ ����.
int cardInfo[8];

//�ڽ�Ʈ�� �����ϴ� int��. �����κ��� �о���� �� �ڽ�Ʈ�� ���� ����.
int costInfo;
int costPrice[8] = { 1, 2, 5, 0, 0, 0, 0, 0 };

//���� ī�� ���� �����ϴ� �迭.
int deckInfo[8];

int cardCoord[8][2] = { {0,1},{10,1},{20,1},{30,1},{0,7},{10,7},{20,7},{30,7} };
int deckCoord[8][2] = { {10, 21},{16,21},{22,21},{28,21},{34,21},{40,21},{46,21},{50,21} };
int costCoord[2] = { 0,21 };
int textBoxCoord[2] = { 2,15 };

int cardInfoCoord[8][2] = { {2,1},{12,1},{22,1},{32,1},{2,7},{12,7},{22,7},{32,7} };
int deckInfoCoord[8][2] = { {12, 22},{18,22},{24,22},{30,22},{36,22},{42,22},{48,22},{54,22} };
int costInfoCoord[2] = { 2,22 };
int confirmCoord[2] = { 92,21 };


int prepareMap[27][50] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{3,1,1,4,0,3,1,1,4,0,3,1,1,4,0,3,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,1,1,5,0,6,1,1,5,0,6,1,1,5,0,6,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{3,1,1,4,0,3,1,1,4,0,3,1,1,4,0,3,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,1,1,5,0,6,1,1,5,0,6,1,1,5,0,6,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
	{3,1,1,4,0,3,1,1,8,1,1,8,1,1,8,1,1,8,1,1,8,1,1,8,1,1,8,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,4},
	{2,0,0,2,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2},
	{2,0,0,2,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2},
	{2,0,0,2,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2},
	{6,1,1,5,0,6,1,1,10,1,1,10,1,1,10,1,1,10,1,1,10,1,1,10,1,1,10,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,1,5},
};



void drawCardInfo();
void drawDeckInfo();
void drawcostInfo();
COORD getCurrentCursorPos();
void setCurrentCursorPos(int posX, int posY);
void drawPrepareBox();
void printScoreOver(int index);
void printDeckCountOver();
void detectPrepareFunc(int X, int Y);
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
//Ŀ���� ��ǥ�� �����ϴ� �Լ�
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
				printf("��");
			}
			if (prepareMap[i][j] == 2) {
				printf("��");
			}
			if (prepareMap[i][j] == 3) {
				printf("��");
			}
			if (prepareMap[i][j] == 4) {
				printf("��");
			}
			if (prepareMap[i][j] == 5) {
				printf("��");
			}
			if (prepareMap[i][j] == 6) {
				printf("��");
			}
			if (prepareMap[i][j] == 8) {
				printf("��");
			}
			if (prepareMap[i][j] == 10) {
				printf("��");
			}
		}
		printf("\n");
	}
}

void printScoreOver(int Index) {
	eraseTooltipBox();
	printf("�ڽ�Ʈ�� �����մϴ�!");
	setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
	printf("�ʿ��� �ڽ�Ʈ: %d", costPrice[Index]);
	setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 4);
	printf("���� �ڽ�Ʈ: %d", costInfo);
	Sleep(1000);
	eraseTooltipBox();
}

void printDeckCountOver() {
	eraseTooltipBox();
	printf("���� �ż��� �����ϴ�!");
	Sleep(1000);
	eraseTooltipBox();
}

void detectPrepareFunc(int X, int Y) {

	//ī�� ����
	if (Y >= cardCoord[0][1] && Y <= cardCoord[0][1] + 5) {
		//ù��° ī��(�б�)
		if (X >= cardCoord[0][0] && X <= cardCoord[0][0] + 8) {
			if (deckInfo[0] == 0) // ó�� ��� ī��� ��ī��Ʈ ����
				deckCount++;
			if (costInfo >= costPrice[0]) {	//�ڽ�Ʈ�� 1
				cardInfo[0]--;
				deckInfo[0]++;
				costInfo--;
			}
			else {
				printScoreOver(costPrice[0]);
			}
		}
		
		//�ι�° ī��(����)
		if (X >= cardCoord[1][0] && X <= cardCoord[1][0] + 8) {
			if (deckInfo[1] == 0) // ó�� ��� ī��� ��ī��Ʈ ����
				deckCount++;
			if (costInfo >= costPrice[1]) {	//�ڽ�Ʈ�� 2
				cardInfo[1]--;
				deckInfo[1]++;
				costInfo = costInfo - 2;
			}
			else {
				printScoreOver(costPrice[1]);
			}
		}
		
		//����° ī��(����)
		if (X >= cardCoord[2][0] && X <= cardCoord[2][0] + 8) {
			if (deckInfo[2] == 0) // ó�� ��� ī��� ��ī��Ʈ ����
				deckCount++;
			if (costInfo >= costPrice[2]) {	//�ڽ�Ʈ�� 3
				cardInfo[2]--;
				deckInfo[2]++;
				costInfo = costInfo - 5;
			}
			else {
				printScoreOver(costPrice[2]);
			}
		}
	}

	//ī�� �Ǹ�
	if (Y >= deckCoord[0][1] && Y <= deckCoord[0][1] + 5) {
		//ù��° ī��(�б�)
		if (X >= deckCoord[0][0] && X < deckCoord[0][0] + 6) {
			if (deckInfo[0] >= 1) {
				cardInfo[0]++;
				deckInfo[0]--;
				costInfo++;
				if (deckInfo[0] == 0) // �� �Ǹ��� ī��� ��ī��Ʈ ����
					deckCount--;
			}
			else {
				printDeckCountOver();
			}
		}
		//�ι�° ī��(����)
		if (X >= deckCoord[1][0] && X < deckCoord[1][0] + 6) {
			if (deckInfo[1] >= 1) {
				cardInfo[1]++;
				deckInfo[1]--;
				costInfo = costInfo  + 2;
				if (deckInfo[0] == 0) // �� �Ǹ��� ī��� ��ī��Ʈ ����
					deckCount--;
			}
			else {
				printDeckCountOver();
			}
		}
		//����° ī��(����)
		if (X >= deckCoord[2][0] && X < deckCoord[2][0] + 6) {
			if (deckInfo[2] >= 1) {
				cardInfo[2]++;
				deckInfo[2]--;
				costInfo = costInfo + 5;
				if (deckInfo[0] == 0) // �� �Ǹ��� ī��� ��ī��Ʈ ����
					deckCount--;
			}
			else {
				printDeckCountOver();
			}
		}
	}

}

void drawPrepareInfo() {
	drawCardInfo();
	drawDeckInfo();
	drawcostInfo();
	setCurrentCursorPos(confirmCoord[0] + 2, confirmCoord[1] + 2);
	printf("Ȯ��");
}

void drawCardInfo() {
	setCurrentCursorPos(cardInfoCoord[0][0], cardInfoCoord[0][1]);
	printf("�б�");

	setCurrentCursorPos(cardInfoCoord[1][0], cardInfoCoord[1][1]);
	printf("����");

	setCurrentCursorPos(cardInfoCoord[2][0], cardInfoCoord[2][1]);
	printf("����");

	setCurrentCursorPos(cardInfoCoord[3][0], cardInfoCoord[3][1]);
	printf("etc");
}

void drawDeckInfo() {
	setCurrentCursorPos(deckInfoCoord[0][0], deckInfoCoord[0][1]);
	printf("�б�");
	setCurrentCursorPos(deckInfoCoord[1][0], deckInfoCoord[1][1]);
	printf("����");
	setCurrentCursorPos(deckInfoCoord[2][0], deckInfoCoord[2][1]);
	printf("����");
	setCurrentCursorPos(deckInfoCoord[3][0], deckInfoCoord[3][1]);
	printf("etc");

	for (int i = 0; i < 4; i++) {
		setCurrentCursorPos(deckInfoCoord[i][0], deckInfoCoord[i][1] + 1);
		printf(" ��");
		setCurrentCursorPos(deckInfoCoord[i][0], deckInfoCoord[i][1] + 2);
		printf("%d ��", deckInfo[i]);
	}
}

void drawcostInfo() {
	setCurrentCursorPos(costInfoCoord[0], costInfoCoord[1]);
	printf("Cost");
	setCurrentCursorPos(costInfoCoord[0], costInfoCoord[1] + 1);
	printf(" ��");
	setCurrentCursorPos(costInfoCoord[0], costInfoCoord[1] + 2);
	printf(" %d ", costInfo);
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
	//ī�� ���� ����
	if (Y >= cardCoord[0][1] && Y <= cardCoord[0][1] + 5) {
		//ù��° ī��(�б�)
		if (X >= cardCoord[0][0] && X <= cardCoord[0][0] + 8) {
			eraseTooltipBox();
			printf("���� �Ӵϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("������ %d�ڽ�Ʈ �Դϴ�.", costPrice[0]);
		}
		//�ι�° ī��(����)
		if (X >= cardCoord[1][0] && X <= cardCoord[1][0] + 8) {
			eraseTooltipBox();
			printf("���� �ǳʶݴϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("������ %d�ڽ�Ʈ �Դϴ�.", costPrice[1]);
		}
		//����° ī��(����)
		if (X >= cardCoord[2][0] && X <= cardCoord[2][0] + 8) {
			eraseTooltipBox();
			printf("������ �߻��մϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("������ %d�ڽ�Ʈ �Դϴ�.", costPrice[2]);
		}
	}
	//�� ���� ����
	if (Y >= deckCoord[0][1] && Y <= deckCoord[0][1] + 5) {
		if (X >= deckCoord[0][0] && X <= deckCoord[7][0] + 8) {
			eraseTooltipBox();
			printf("����� ������ ���Դϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("����Ŭ������ ȯ���� �� �ֽ��ϴ�.");
		}
	}
	//��ư ���� ����
	if (Y >= costInfoCoord[1] && Y <= costInfoCoord[1] + 5 && X >= costInfoCoord[0] && X <= costInfoCoord[0] + 8) {
		eraseTooltipBox();
		printf("���� �ڽ�Ʈ�� %d �Դϴ�.", costInfo);
	}
	if (Y >= confirmCoord[1] && Y <= confirmCoord[1] + 5 && X >= confirmCoord[0] && X <= confirmCoord[0] + 8) {
		eraseTooltipBox();
		printf("����Ŭ���� ���� Ȯ���մϴ�.");
	}
	//�� ����
	if (Y >= 1 && Y < 21 && X >= 40 && X <= 140 ){
		eraseTooltipBox();
		printf("�̹��� �÷����� ���Դϴ�.");
		setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
		printf("���� ����� �̷θ� Ǯ�� ������!");
	}
}

