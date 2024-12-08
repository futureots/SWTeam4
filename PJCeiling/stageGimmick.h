#pragma once
#include <windows.h>
#include "stage_tutorial.h"
#include "doubleBuffering.h"
//20 ┤
// 
//21 ├
// 
//22 ┬ 
// 
//23 ┴
// 
//24 ⊂
//25 ⊃
//26 ∪
//27 ∩

// 28
// 29

int isKey = 0;

void changeMapFromPlug(int map[20][30], int curLevel) {

	if (curLevel == 3) {
		for (int i = 1; i < 19; i++) {
			for (int j = 1; j < 29; j++) {
				if (stageIsland[i][j] == 100) {
					map[i][j] = 0;
				}
			}
		}
	}
}

void changeMapFromFan(int x , int y ,int map[20][30], int curLevel) {
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

void plugAndOutlet(int x, int y, int curLevel,int map[20][30]) {
	// ⊂
	if (map[y][x] == 20) {
		if (map[y][x - 1] == 24) {
			changeMapFromPlug(map, curLevel);

		}
	}
	//왼쪽 콘센트
	if (map[y][x] == 21) {
		if (map[y][x + 1] == 25) {
			changeMapFromPlug(map, curLevel);
		}
	}
	//위쪽 콘센트
	if (map[y][x] == 22) {
		if (map[y - 1][x] == 26) {
			changeMapFromPlug(map, curLevel);

		}
	}
	//아래쪽 콘센트
	if (map[y][x] == 23) {
		if (map[y + 1][x] == 27) {
			changeMapFromPlug(map, curLevel);

		}
	}

}

void fanMove(int x, int y, int curLevel, int map[20][30]) {
	if (map[y][x - 1] == 8 || map[y][x + 1] == 8 || map[y-1][x] == 8 || map[y+1][x] == 8) {
		changeMapFromFan(x,y,map, curLevel);
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