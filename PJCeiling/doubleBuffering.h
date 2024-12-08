#pragma once
#include <stdio.h>
#include<Windows.h>


static int gIndex;
static HANDLE gScreen[2];

void screenInit()
{
    CONSOLE_CURSOR_INFO cci;

    //화면 버퍼 2개를 만든다.
    gScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    gScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    //커서 숨기기
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(gScreen[0], &cci);
    SetConsoleCursorInfo(gScreen[1], &cci);
}

// 1번 버퍼와 2번 버퍼 바꾸기
void screenFlipping()
{
    SetConsoleActiveScreenBuffer(gScreen[gIndex]);
    gIndex = !gIndex;
}

//화면 지우기
void screenClear()
{
    COORD Coor = { 0,0 };
    DWORD dw;
    FillConsoleOutputCharacter(gScreen[gIndex], ' ', 1000 * 1000, Coor, &dw);
}

void screenRelease()
{
    CloseHandle(gScreen[0]);
    CloseHandle(gScreen[1]);
}

//지정된 버퍼에 그림 그리기
void Printscreen(int x, int y, char* output, HANDLE curBuf)
{
    DWORD dw;
    COORD CursorPosition = { x, y };

    SetConsoleCursorPosition(curBuf, CursorPosition);
    WriteFile(curBuf, output, strlen(output), &dw, NULL);
}
