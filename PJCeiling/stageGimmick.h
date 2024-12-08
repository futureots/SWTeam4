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

void changeMapFromPlugOn(int x, int y, int map[20][30], int curLevel) {

	if (curLevel == 3) {
		for (int i = 1; i < 19; i++) {
			for (int j = 1; j < 29; j++) {
				if (stageIsland[i][j] == 100) {
					map[i][j] = 0;
				}
			}
		}
	}
	else if (curLevel == 2) {
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
		else if (x == 2 && y == 2) {
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
		else if (x == 2 && y == 2) {
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

void changeMapFromFan(int x, int y, int map[20][30], int curLevel) {
	map[y][x] = 0;
	if (curLevel == 3) {
		for (int i = 1; i < 19; i++) {
			for (int j = 1; j < 29; j++) {
				if (stageIsland2[i][j] == 100) {
					map[i][j] = 0;
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
void fanMove(int x, int y, int curLevel, int map[20][30]) {
	if (map[y][x - 1] == 8 || map[y][x + 1] == 8 || map[y - 1][x] == 8 || map[y + 1][x] == 8) {
		changeMapFromFan(x, y, map, curLevel);
	}
}

void slimeSplit(int x, int y, int map[20][30]) {

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) {
			if (map[y + i][x + j] != 1)
				map[y + i][x + j] = 6;
		}
}

void unlockBox(int x, int y, int map[20][30]) {
	if (map[y][x] == 61) {
		map[y][x] = 0;
		isKey = 0;
	}
}