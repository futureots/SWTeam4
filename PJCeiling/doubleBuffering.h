#pragma once
#include <stdio.h>
#include<Windows.h>


static int gIndex;
static HANDLE gScreen[2];

void screenInit()
{
    CONSOLE_CURSOR_INFO cci;

    //ȭ�� ���� 2���� �����.
    gScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    gScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    //Ŀ�� �����
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(gScreen[0], &cci);
    SetConsoleCursorInfo(gScreen[1], &cci);
}

// 1�� ���ۿ� 2�� ���� �ٲٱ�
void screenFlipping()
{
    SetConsoleActiveScreenBuffer(gScreen[gIndex]);
    gIndex = !gIndex;
}

//ȭ�� �����
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

//������ ���ۿ� �׸� �׸���
void Printscreen(int x, int y, char* output, HANDLE curBuf)
{
    DWORD dw;
    COORD CursorPosition = { x, y };

    SetConsoleCursorPosition(curBuf, CursorPosition);
    WriteFile(curBuf, output, strlen(output), &dw, NULL);
}
