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

//�ڽ�Ʈ�� �����ϴ� int��. �����κ��� �о���� �� �ڽ�Ʈ�� ���� ����.
int costInfo;
int costPrice[8] = { 1, 2, 5, 3, 2, 0, 0, 0 };
//���� ī�� ���� �����ϴ� �迭.
int deckInfo[8];

int cardCoord[6][2] = { {0,0},{12,0},{24,0},{0,6},{12,6},{24,6}};
int deckCoord[6][2] = { {10, 21},{18,21},{26,21},{34,21},{42,21},{50,21} };
int costCoord[2] = { 0,21 };
int textBoxCoord[2] = { 2,15 };

int cardInfoCoord[6][2] = { {2,1},{14,1},{26,1},{2,7},{14,7},{26,7}};
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
	Sleep(500);
	eraseTooltipBox();
}

void printDeckCountOver() {
	eraseTooltipBox();
	printf("���� �ż��� �����ϴ�!");
	Sleep(1000);
	eraseTooltipBox();
}

void detectPrepareFunc(int X, int Y, char detect) {

	detect = detect - '1';
	

	//ī�� ����(���콺)
	if (Y >= cardCoord[0][1] && Y < cardCoord[0][1] + 5) {
		//ù��° ī��(�б�)
		if (X >= cardCoord[0][0] && X <= cardCoord[0][0] + 10) {
			if (costInfo >= costPrice[0]) {	
				deckInfo[0]++;
				costInfo = costInfo - costPrice[0];
			}
		}
		//�ι�° ī��(����)
		if (X >= cardCoord[1][0] && X <= cardCoord[1][0] + 10) {
			if (costInfo >= costPrice[1]) {	
				deckInfo[1]++;
				costInfo = costInfo - costPrice[1];
			}
		}
		//����° ī��(����)
		if (X >= cardCoord[2][0] && X <= cardCoord[2][0] + 10) {
			if (costInfo >= costPrice[2]) {	
				deckInfo[2]++;
				costInfo = costInfo - costPrice[2];
			}
		}
	}

	if (Y >= cardCoord[3][1] && Y < cardCoord[3][1] + 5) {
		//�׹�° ī��(�׷�)
		if (X >= cardCoord[3][0] && X <= cardCoord[3][0] + 10) {
			if (costInfo >= costPrice[3]) {	
				deckInfo[3]++;
				costInfo = costInfo - costPrice[3];
			}
		}
		//�ټ���° ī��(����)
		if (X >= cardCoord[4][0] && X <= cardCoord[4][0] + 10) {
			if (costInfo >= costPrice[4]) {	
				deckInfo[4]++;
				costInfo = costInfo - costPrice[4];
			}
		}
		//������° ī��(����)
		if (X >= cardCoord[5][0] && X <= cardCoord[5][0] + 10) {
			if (costInfo >= costPrice[5]) {	
				deckInfo[5]++;
				costInfo = costInfo - costPrice[5];
			}
		}
	}

	//ī�� ����(Ű����)
	if (detect >= 0 && detect <= 6) {
		if (deckInfo[detect] == 0) // ó�� ��� ī��� ��ī��Ʈ ����
			deckCount++;
		if (costInfo >= costPrice[detect]) {	//�ڽ�Ʈ�� 1
			deckInfo[detect]++;
			costInfo = costInfo - costPrice[detect];
		}
		else {
			printScoreOver(detect);
		}
	}

	//ī�� �Ǹ�
	if (Y >= deckCoord[0][1] && Y <= deckCoord[0][1] + 5) {
		for (int i = 0; i < 6; i++) {
			if (X >= deckCoord[i][0] && X < deckCoord[i][0] + 6) {
				if (deckInfo[i] >= 1) {
					deckInfo[i]--;
					costInfo = costInfo + costPrice[i];
					if (deckInfo[i] == 0) // �� �Ǹ��� ī��� ��ī��Ʈ ����
						deckCount--;
				}
				else {
					printDeckCountOver();
				}
			}
		}
		//ù��° ī��(�б�)
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
	printf(" �б�");
	setCurrentCursorPos(cardInfoCoord[0][0], cardInfoCoord[0][1] + 2);
	printf("  �� ");

	setCurrentCursorPos(cardInfoCoord[1][0], cardInfoCoord[1][1]);
	printf(" ����");
	setCurrentCursorPos(cardInfoCoord[1][0], cardInfoCoord[1][1] + 2);
	printf("  �� ");

	setCurrentCursorPos(cardInfoCoord[2][0], cardInfoCoord[2][1]);
	printf(" ����");
	setCurrentCursorPos(cardInfoCoord[2][0], cardInfoCoord[2][1] + 2);
	printf("  �� ");

	setCurrentCursorPos(cardInfoCoord[3][0], cardInfoCoord[3][1]);
	printf(" �׷�");
	setCurrentCursorPos(cardInfoCoord[3][0], cardInfoCoord[3][1] + 2);
	printf("  �� ");

	setCurrentCursorPos(cardInfoCoord[4][0], cardInfoCoord[4][1]);
	printf(" ����");
	setCurrentCursorPos(cardInfoCoord[4][0], cardInfoCoord[4][1] + 2);
	printf("  �� ");
}

void drawDeckInfo() {
	setCurrentCursorPos(deckInfoCoord[0][0], deckInfoCoord[0][1]);
	printf(" �б�");
	setCurrentCursorPos(deckInfoCoord[1][0], deckInfoCoord[1][1]);
	printf(" ����");
	setCurrentCursorPos(deckInfoCoord[2][0], deckInfoCoord[2][1]);
	printf(" ����");
	setCurrentCursorPos(deckInfoCoord[3][0], deckInfoCoord[3][1]);
	printf(" �׷�");
	setCurrentCursorPos(deckInfoCoord[4][0], deckInfoCoord[4][1]);
	printf(" ����");

	for (int i = 0; i < 6; i++) {
		setCurrentCursorPos(deckInfoCoord[i][0], deckInfoCoord[i][1] + 1);
		printf("  ��");
		setCurrentCursorPos(deckInfoCoord[i][0], deckInfoCoord[i][1] + 2);
		printf(" %d", deckInfo[i]);
		setCurrentCursorPos(deckInfoCoord[i][0] + 3, deckInfoCoord[i][1] + 2);
		printf("��");
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
		if (X >= cardCoord[0][0] && X <= cardCoord[0][0] + 10) {
			eraseTooltipBox();
			printf("���� �Ӵϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("������ %d�ڽ�Ʈ �Դϴ�.", costPrice[0]);
		}
		//�ι�° ī��(����)
		if (X >= cardCoord[1][0] && X <= cardCoord[1][0] + 10) {
			eraseTooltipBox();
			printf("���� �ǳʶݴϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("������ %d�ڽ�Ʈ �Դϴ�.", costPrice[1]);
		}
		//����° ī��(����)
		if (X >= cardCoord[2][0] && X <= cardCoord[2][0] + 10) {
			eraseTooltipBox();
			printf("������ �߻��մϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("������ %d�ڽ�Ʈ �Դϴ�.", costPrice[2]);
		}
		
	}
	if (Y >= cardCoord[3][1] && Y <= cardCoord[3][1] + 5) {
		//�׹�° ī��(�׷�)
		if (X >= cardCoord[3][0] && X <= cardCoord[3][0] + 10) {
			eraseTooltipBox();
			printf("������ ���� ���ϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("������ %d�ڽ�Ʈ �Դϴ�.", costPrice[3]);
		}
		if (X >= cardCoord[4][0] && X <= cardCoord[4][0] + 10) {
			eraseTooltipBox();
			printf("���̴� ������ ������ �޸��ϴ�.");
			setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
			printf("������ %d�ڽ�Ʈ �Դϴ�.", costPrice[4]);
		}
	}

	//�� ���� ����
	if (Y >= deckCoord[0][1] && Y <= deckCoord[0][1] + 5) {
		if (X >= deckCoord[0][0] && X <= deckCoord[5][0] + 8) {
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
	if (Y >= 1 && Y < 21 && X >= 40 && X <= 140) {
		eraseTooltipBox();
		printf("�̹��� �÷����� ���Դϴ�.");
		setCurrentCursorPos(textBoxCoord[0], textBoxCoord[1] + 2);
		printf("���� ����� �̷θ� Ǯ�� ������!");
	}
}