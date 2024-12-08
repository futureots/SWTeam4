#pragma once
#include <windows.h>
#include "stage_tutorial.h"
#include "doubleBuffering.h"

//20 ∪ -> 활성화 25
//21 ⊂ -> 활성화 26
//22 ∩ -> 활성화 27
//23 ⊃ -> 활성화 28
//24 ※


// 28
// 29

int isKey = 0;
int isPortal = 0;	// 연결 테두리 이외에 포탈을 활용할 변수. 현재 사용 X

void changeMapFromPlugOn(int x, int y, int map[20][30], int curLevel) {

	if (curLevel == 2) {
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
	else if (curLevel == 3) {
		if (x == 8 && y == 4) {
			for (int i = 13; i <= 17; i++) {
				if (map[4][i] == 3)	map[4][i] = 0;
			}
			// x = 15 y = 5 ~ 10
			for (int i = 5; i <= 10; i++) {
				if (map[i][15] == 3)map[i][15] = 0;
			}

		}
	}



}
void changeMapFromPlugOff(int x, int y, int map[20][30], int curLevel) {

	if (curLevel == 2) {
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
	// ⊂
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
	// ⊂
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

	while (idy1 != 0 && idy2 != 0 && idx1 != 0 && idx2 != 0) {
		if (y + idy1 > 0 && y + idy1 < 19 && idy1 != 0) {
			if (map[y + idy1][x] == 30) return 30;
			else if (map[y + idy1][x] == 0 || map[y + idy1][x] == 3) idy1++;
			else idy1 = 0;
		}

		if (y + idy2 > 0 && y + idy2 < 19 && idy2 != 0) {
			if (map[y + idy2][x] == 32) return 32;
			else if (map[y + idy2][x] == 0 || map[y + idy2][x] == 3) idy2--;
			else idy2 = 0;
		}

		if (x + idx1 > 0 && x + idx1 < 29 && idx1 != 0) {
			if (map[y][x + idx1] == 31) return 31;
			else if (map[y][x + idx1] == 0 || map[y][x + idx1] == 3) idx1--;
			else idx1 = 0;
		}

		if (x + idx2 > 0 && x + idx2 < 29 && idx2 != 0) {
			if (map[y][x + idx2] == 33) return 33;
			else if (map[y][x + idx2] == 0 || map[y][x + idx2] == 3) idx2++;
			else idx2 = 0;
		}
	}

	return 0;
}

void fanMove(int x, int y, int map[20][30]) {
	int idY = 0, idX = 0, blockNum;

	blockNum = findFanPos(x, y, map);
	if (blockNum == 0) return;

	map[y][x] = 0;
	while (y + idY < 19 && y + idY > 0 && x + idX < 29 && x + idX > 0)
	{
		if (map[y + idY][x + idX] == 0 || map[y + idY][x + idX] == 3) {
			idX += (blockNum % 2 == 1) ? ((blockNum == 31) ? 1 : ((blockNum == 33) ? -1 : 0)) : 0;
			idY += (blockNum % 2 == 0) ? ((blockNum == 32) ? 1 : ((blockNum == 30) ? -1 : 0)) : 0;
		}
		else if (map[y + idY][x + idX] == 2 && map[y + idY][x + idX] == 24) {
			map[y + idY][x + idX] = 0;
			break;
		}
		else break;
	}
}
void slimeSplit(int x, int y, int map[20][30]) {

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) {
			if (map[y + i][x + j] != 1 && map[y + i][x + j] > -1)
				map[y + i][x + j] = 6;
		}
}

void unlockBox(int x, int y, int map[20][30]) {
	if (map[y][x] == 61) {
		map[y][x] = 0;
		if(isKey > 0)
			isKey--;
	}
}

void switchOn(int map[20][30]) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 30; j++) {
				if (map[i][j] == 41 || map[i][j] == 40) {
					map[i][j] = 0;
				}
			}
		}
}

void outlinePortalOn(int map[20][30]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			switch (map[i][j]) {
			case -1:
				map[i][j] = -11;
				break;
			case -2:
				map[i][j] = -12;
				break;
			case -3:
				map[i][j] = -13;
				break;
			case -4:
				map[i][j] = -14;
				break;
			case -5:
				map[i][j] = -15;
				break;
			case -6:
				map[i][j] = -16;
				break;
			}
		}
	}
}

void outlinePortal(int x, int y, int map[20][30]) {
	//함수화
}