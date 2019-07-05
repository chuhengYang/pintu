#include "stdafx.h"
#include"myPaint.h"
void myPaint(HDC hdc, HDC mdc, HPEN hpen,int a, int b, int c, int d, int e,int f,int g,int h, int i)
{
	const int SS[10][2] = { {0,0} ,{0,100} ,{0,200} ,{100,0}, {100,100} ,{100,200} ,{200,0}, {200,100},{200,200},{300,300} };
	TCHAR BB[20] = TEXT("����");
	SelectObject(hdc, hpen);
	Rectangle(hdc, 50, 50, 150, 150);
	Rectangle(hdc, 150, 150, 250, 250);
	Rectangle(hdc, 250, 250, 350, 350);
	Rectangle(hdc, 50, 150, 150, 250);
	Rectangle(hdc, 150, 50, 250, 150);
	Rectangle(hdc, 50, 250, 150, 350);
	Rectangle(hdc, 250, 50, 350, 150);
	Rectangle(hdc, 250, 150, 350, 250);
	Rectangle(hdc, 150, 250, 250, 350);
	Rectangle(hdc, 50, 380, 150, 480);
	TextOut(hdc, 85, 420, BB, wcslen(BB));
	BitBlt(hdc, 50, 50, 100, 100, mdc, SS[a][0], SS[a][1], SRCCOPY);
	BitBlt(hdc, 150, 150, 100, 100, mdc, SS[b][0], SS[b][1], SRCCOPY);
	BitBlt(hdc, 150, 50, 100, 100, mdc, SS[c][0], SS[c][1], SRCCOPY);
	BitBlt(hdc, 50, 150, 100, 100, mdc, SS[d][0], SS[d][1], SRCCOPY);
	BitBlt(hdc, 250, 50, 100, 100, mdc, SS[e][0], SS[e][1], SRCCOPY);
	BitBlt(hdc, 50, 250, 100, 100, mdc, SS[f][0], SS[f][1], SRCCOPY);
	BitBlt(hdc, 150, 250, 100, 100, mdc, SS[g][0], SS[g][1], SRCCOPY);
	BitBlt(hdc, 250, 150, 100, 100, mdc, SS[h][0], SS[h][1], SRCCOPY);
	BitBlt(hdc, 250, 250, 100, 100, mdc, SS[i][0], SS[i][1], SRCCOPY);
	BitBlt(hdc, 250, 380, 100, 100, mdc, 200, 200, SRCCOPY);
}
