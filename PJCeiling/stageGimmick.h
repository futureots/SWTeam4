#pragma once
#include <windows.h>
#include "stageMapInfo.h"
#include "doubleBuffering.h"

//20 �� -> Ȱ��ȭ 25
//21 �� -> Ȱ��ȭ 26
//22 �� -> Ȱ��ȭ 27
//23 �� -> Ȱ��ȭ 28
//24 ��


// 28
// 29

int isKey = 0;

void changeMapFromPlugOn(int x, int y, int map[20][30], int curLevel) {
	//�μ��� ��ܶ�
	if (curLevel == 4) {
		for (int i = 0; i < stageWidth; i++) if (map[3][i] == 100) map[3][i] = 0;
		for (int i = 5; i < stageHeight; i++) {
			if (map[i][8] == 100) map[i][8] = 0;
			if (map[i][20] == 100) map[i][20] = 0;
		}
		for (int i = 8; i < 21; i++) if (map[5][i] == 100) map[5][i] = 0;
	}
	//���� �� Ż��
	else if (curLevel == 7) {
		if (x == 4 && y == 4) {
			for (int i = 1; i < stageHeight - 1; i++) {
				if (map[i][0] == -6) map[i][0] -= 10;
				if (map[i][stageWidth - 1] == -6) map[i][stageWidth - 1] -= 10;
			}
			for (int j = 0; j < stageWidth - 1; j++) {
				map[0][j] -= 10;
				map[19][j] -= 10;
			}
			map[14][5] = 0;
		}

		else if (x == 27 && y == 16) {
			for (int i = 11; i < 14; i++) {
				map[i][6] = 3;
				map[i][7] = 3;
			}
			for (int i = 11; i < 19; i++) {
				map[i][8] = 3;
			}
			for (int i = 11; i < 19; i++) {
				for (int j = 16; j < 25; j++)
					map[i][j] = 0;
			}
			for (int i = 5; i < 10; i++)
				map[3][i] = 0;
		}
	}
	//�ʿ���
	else if (curLevel == 8) {
		for (int i = 1; i < stageHeight - 1; i++) {
			if (map[i][0] == -6) map[i][0] -= 10;
			if (map[i][stageWidth - 1] == -6) map[i][stageWidth-1] -= 10;
		}
	}
	//�� Ż��
	else if (curLevel == 9) {
		for (int i = 3; i <= 26; i++) {
			map[17][i] = 0;
		}
	}
	//��ǳ�� ��ô
	else if (curLevel == 12) {
		for (int i = 1; i < stageHeight - 1; i++) {
			if (map[i][0] == -6) map[i][0] -= 10;
			if (map[i][stageWidth - 1] == -6) map[i][stageWidth - 1] -= 10;
		}
		for (int j = 1; j < stageWidth - 1; j++) {
			map[0][j] -= 10;
			map[19][j] -= 10;
		}
	}
	//��°� �ϰ� ���
	else if (curLevel == 17) {
		if (x == 2 && y == 11) {
			for (int i = 1; i <= 7; i++) {
				for (int t = 0; t < 2; t++) {
					for (int j = 5; j <= 8; j++) {
						if (map[j][i + t * 10] == 0) map[j][i + t * 10] = 2;
						else if (map[j][i + t * 10] == 3) map[j][i + t * 10] = 0;
					}
					for (int j = 13; j <= 15; j++) {
						if (map[j][i + t * 10] == 0) map[j][i + t * 10] = 2;
						else if (map[j][i + t * 10] == 3) map[j][i + t * 10] = 0;
					}
				}

			}
		}
		else if (x == 4 && y == 2) {
			for (int i = 1; i <= 4; i++) {
				for (int t = 0; t < 2; t++) {
					for (int j = 8; j <= 10; j++) {
						if (map[i][j + t * 10] == 0) map[i][j + t * 10] = 2;
						else if (map[i][j + t * 10] == 3) map[i][j + t * 10] = 0;
					}
				}
			}
		}
		else if (x == 23 && y == 18) {
			for (int i = 1; i <= 4; i++) {
				for (int j = 24; j <= 28; j++) {
					if (map[i][j] == 0) map[i][j] = 2;
					else if (map[i][j] == 3) map[i][j] = 0;
				}
			}
		}
	}
	//��� ������
	else if (curLevel == 13) { 
		map[3][26] = 2;
	}



}
void changeMapFromPlugOff(int x, int y, int map[20][30], int curLevel) {
	//�μ��� ��ܶ�
	if (curLevel == 4) {
		for (int i = 0; i < stageWidth; i++) map[3][i] = 100;
		for (int i = 5; i < stageHeight; i++) {
			map[i][8] = 100;
			map[i][20] = 100;
		}
		for (int i = 8; i < 21; i++) map[5][i] = 100;
	}



	//�ʿ���
	if (curLevel == 8) {
		for (int i = 1; i < stageHeight - 1; i++) {
			if (map[i][0] == -16) map += 10;
			if (map[i][stageWidth - 1] == -16) map += 10;
		}
	}
	//��°� �ϰ� ���
	else if (curLevel == 17) {
		if (x == 2 && y == 11) {
			for (int i = 1; i <= 7; i++) {
				for (int t = 0; t < 2; t++) {
					for (int j = 5; j <= 8; j++) {
						if (map[j][i + t * 10] == 0) map[j][i + t * 10] = 3;
						else if (map[j][i + t * 10] == 2) map[j][i + t * 10] = 0;
					}
					for (int j = 13; j <= 15; j++) {
						if (map[j][i + t * 10] == 0) map[j][i + t * 10] = 3;
						else if (map[j][i + t * 10] == 2) map[j][i + t * 10] = 0;
					}
				}
			}
		}
		else if (x == 4 && y == 2) {
			for (int i = 1; i <= 4; i++) {
				for (int t = 0; t < 2; t++) {
					for (int j = 8; j <= 10; j++) {
						if (map[i][j + t * 10] == 0) map[i][j + t * 10] = 3;
						else if (map[i][j + t * 10] == 2) map[i][j + t * 10] = 0;
					}
				}
			}
		}
		else if (x == 23 && y == 18) {
			for (int i = 1; i <= 4; i++) {
				for (int j = 24; j <= 28; j++) {
					if (map[i][j] == 0) map[i][j] = 3;
					else if (map[i][j] == 2) map[i][j] = 0;
				}
			}
		}
	}

}


void plugAndOutletOn(int x, int y, int curLevel, int map[20][30]) {
	// ��
	if (map[y + 1][x] == 20) {
		map[y + 1][x] = 25;
		changeMapFromPlugOn(x, y + 1, map, curLevel);
	}
	if (map[y][x - 1] == 21) {
		map[y][x - 1] = 26;
		changeMapFromPlugOn(x - 1, y, map, curLevel);
	}
	if (map[y - 1][x] == 22) {
		map[y - 1][x] = 27;
		changeMapFromPlugOn(x, y - 1, map, curLevel);
	}
	if (map[y][x + 1] == 23) {
		map[y][x + 1] = 28;
		changeMapFromPlugOn(x + 1, y, map, curLevel);
	}
}
void plugAndOutletOff(int x, int y, int curLevel, int map[20][30]) {
	// ��
	if (map[y + 1][x] == 25) {
		map[y + 1][x] = 20;
		changeMapFromPlugOff(x, y + 1, map, curLevel);
	}
	if (map[y][x - 1] == 26) {
		map[y][x - 1] = 21;
		changeMapFromPlugOff(x - 1, y, map, curLevel);
	}
	if (map[y - 1][x] == 27) {
		map[y - 1][x] = 22;
		changeMapFromPlugOff(x, y - 1, map, curLevel);
	}
	if (map[y][x + 1] == 28) {
		map[y][x + 1] = 23;
		changeMapFromPlugOff(x + 1, y, map, curLevel);
	}
}
int findFanPos(int x, int y, int map[20][30]) {
	int idy1 = 1, idx1 = -1, idy2 = -1, idx2 = 1;

	while (idy1 || idy2 || idx1 || idx2) {
		if (y + idy1 > 0 && y + idy1 < 19 || idy1 != 0) {
			if (map[y + idy1][x] == 30) return 30;
			else if (map[y + idy1][x] == 0 || map[y + idy1][x] == 3 || map[y + idy1][x] == 1) idy1++;
			else idy1 = 0;
		}

		if (y + idy2 > 0 && y + idy2 < 19 || idy2 != 0) {
			if (map[y + idy2][x] == 32) return 32;
			else if (map[y + idy2][x] == 0 || map[y + idy2][x] == 3 || map[y + idy2][x] == 1) idy2--;
			else idy2 = 0;
		}

		if (x + idx1 > 0 && x + idx1 < 29 || idx1 != 0) {
			if (map[y][x + idx1] == 31) return 31;
			else if (map[y][x + idx1] == 0 || map[y][x + idx1] == 3 || map[y][x + idx1] == 1) idx1--;
			else idx1 = 0;
		}

		if (x + idx2 > 0 && x + idx2 < 29 || idx2 != 0) {
			if (map[y][x + idx2] == 33) return 33;
			else if (map[y][x + idx2] == 0 || map[y][x + idx2] == 3 || map[y][x + idx2] == 1) idx2++;
			else idx2 = 0;
		}
	}

	return 0;
}

void fanMove(int x, int y, int map[20][30], int blockNum) {
	int idY = 0, idX = 0, fanNum, cnt = 0;
	fanNum = findFanPos(x, y, map);
	if (fanNum == 0) return;
	idX += (fanNum % 2 == 1) ? ((fanNum == 31) ? 1 : ((fanNum == 33) ? -1 : 0)) : 0;
	idY += (fanNum % 2 == 0) ? ((fanNum == 32) ? 1 : ((fanNum == 30) ? -1 : 0)) : 0;
	while (y + idY < 19 && y + idY > 0 && x + idX < 29 && x + idX > 0)
	{
		if (map[y + idY][x + idX] == 0 || map[y + idY][x + idX] == 3 || map[y + idY][x + idX] == 1) {
			idX += (fanNum % 2 == 1) ? ((fanNum == 31) ? 1 : ((fanNum == 33) ? -1 : 0)) : 0;
			idY += (fanNum % 2 == 0) ? ((fanNum == 32) ? 1 : ((fanNum == 30) ? -1 : 0)) : 0;
		}
		else if (map[y + idY][x + idX] == 4) return;
		else if (map[y + idY][x + idX] == 100) return;
		else if (map[y + idY][x + idX] == 2 || map[y + idY][x + idX] == 24) {
			map[y][x] = 0;
			map[y + idY][x + idX] = 0;

			if (blockNum == 4) fanMove(x, y, map, 2);
			return;
		}
		else {
			map[y][x] = 0;
			return;
		}
	}
}
void slimeSplit(int x, int y, int map[20][30]) {

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) {
			if (map[y + i][x + j] != 1 && map[y + i][x + j] > -1)
				map[y + i][x + j] = 6;
		}
}
void ClearSwitch(int map[20][30]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			if (map[i][j] == 41 || map[i][j] == 40) map[i][j] = 0;
		}
	}
}
void unlockBox(int x, int y, int map[20][30]) {
	if (map[y][x] == 61) {
		map[y][x] = 0;
		if(isKey > 0)
			isKey--;
	}
}