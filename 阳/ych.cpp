#include "stdafx.h"
#include "ych.h"
extern HINSTANCE  hInst;
extern HDC         mdc;
extern HBITMAP     hbmp;
extern HPEN        hpen;
extern const int SS;
extern int a, b, c, d, e, f, g, h, i, l;
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	static TCHAR szClassName[] = TEXT("HelloWin");  //��������
	HWND     hwnd;  //���ھ��
	WNDCLASS wndclass;  //������
	HDC         hdc;
	/**********�ڢٲ���ע�ᴰ����**********/
	//Ϊ������ĸ����ֶθ�ֵ
	wndclass.style = CS_HREDRAW | CS_VREDRAW;  //���ڷ��
	wndclass.lpfnWndProc = WndProc; //���ڹ���
	wndclass.cbClsExtra = 0;  //��ʱ����Ҫ����
	wndclass.cbWndExtra = 0;  //��ʱ����Ҫ����
	wndclass.hInstance = hInstance;  //��ǰ���ھ��
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //����ͼ��
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  //�����ʽ
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //���ڱ�����ˢ
	wndclass.lpszMenuName = NULL;  //���ڲ˵�
	wndclass.lpszClassName = szClassName;  //��������
	//ע�ᴰ��
	return RegisterClass(&wndclass);
}

BOOL InitInstance(HINSTANCE hInstance, int iCmdShow)
{
	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����
	HDC hdc;
	static TCHAR szClassName[] = TEXT("HelloWin");  //��������
	TCHAR szText[20] = TEXT("��һ��");
	TCHAR BB[20] = TEXT("����");
	/*****�ڢڲ�����������(���ô�����ʾ����)*****/
	HWND hwnd = CreateWindow(
		szClassName,  //�����������
		TEXT("��Ϸ"),  //���ڱ��⣨�����ڱ�������
		WS_OVERLAPPEDWINDOW,  //���ڷ��
		CW_USEDEFAULT,  //��ʼ��ʱx���λ��
		CW_USEDEFAULT,  //��ʼ��ʱy���λ��
		416,  //���ڿ���
		550,  //���ڸ߶�
		NULL,  //�����ھ��
		NULL,  //���ڲ˵����
		hInstance,  //��ǰ���ڵľ��
		NULL  //��ʹ�ø�ֵ
	);
	if (!hwnd) {
		return FALSE;
	}
	//��ʾ����
	ShowWindow(hwnd, iCmdShow);
	//���£����ƣ�����
	UpdateWindow(hwnd);
	hpen = CreatePen(PS_SOLID, 1, RGB(112, 197, 205));
	hdc = GetDC(hwnd);
	mdc = CreateCompatibleDC(hdc);
	hbmp = (HBITMAP)LoadImage(NULL, TEXT("1.bmp"), IMAGE_BITMAP, 300, 300, LR_LOADFROMFILE);
	SelectObject(mdc, hbmp);
	SelectObject(hdc, hpen);
	srand((unsigned int)time(NULL));
	a = rand() % 8;
	b = rand() % 8; while (b == a) { b = rand() % 8; }
	c = rand() % 8; while (c == a || c == b) { c = rand() % 8; }
	d = rand() % 8; while (d == c || d == b || d == a) { d = rand() % 8; }
	e = rand() % 8; while (e == a || e == b || e == c || e == d) { e = rand() % 8; }
	f = rand() % 8; while (f == a || f == b || f == c || f == d || f == e) { f = rand() % 8; }
	g = rand() % 8; while (g == a || g == b || g == c || g == d || g == e || g == f) { g = rand() % 8; }
	h = rand() % 8; while (h == a || h == b || h == c || h == d || h == e || h == f || h == g) { h = rand() % 8; }
	myPaint(hdc, mdc, hpen, a, b, c, d, e, f, g, h, i);
	TextOut(hdc, 177, 18, szText, wcslen(szText));
	TextOut(hdc, 85, 420, BB, wcslen(BB));
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC         hdc; //�豸�������
	PAINTSTRUCT ps;
	RECT        rect;
	TCHAR AA[20] = TEXT("�ɹ�");
	TCHAR BB[20] = TEXT("����");
	TCHAR CC[20] = TEXT("ʧ��");
	TCHAR DD[20] = TEXT("��һ��");
	int         x, y, z = 0;
	switch (message) {
		//���ڻ�����Ϣ
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		if (x >= 50 && x <= 150 && y >= 50 && y <= 150) {
			if (c == 9) { c = a; a = 9; z++; }
			else if (d == 9) { d = a; a = 9; z++; }
		}
		if (x >= 150 && x <= 250 && y >= 150 && y <= 250) {
			if (c == 9) { c = b; b = 9; z++; }
			else if (d == 9) { d = b; b = 9; z++; }
			else if (g == 9) { g = b; b = 9; z++; }
			else if (h == 9) { h = b; b = 9; z++; }
		}
		if (x >= 150 && x <= 250 && y >= 50 && y <= 150) {
			if (a == 9) { a = c; c = 9; z++; }
			else if (b == 9) { b = c; c = 9; z++; }
			else if (e == 9) { e = c; c = 9; z++; }
		}
		if (x >= 50 && x <= 150 && y >= 150 && y <= 250) {
			if (a == 9) { a = d; d = 9; z++; }
			else if (b == 9) { b = d; d = 9; z++; }
			else if (f == 9) { f = d; d = 9; z++; }
		}
		if (x >= 250 && x <= 350 && y >= 50 && y <= 150) {
			if (c == 9) { c = e; e = 9; z++; }
			else if (h == 9) { h = e; e = 9; z++; }
		}
		if (x >= 50 && x <= 150 && y >= 250 && y <= 350) {
			if (d == 9) { d = f; f = 9; z++; }
			else if (g == 9) { g = f; f = 9; z++; }
		}
		if (x >= 150 && x <= 250 && y >= 250 && y <= 350) {
			if (f == 9) { f = g; g = 9; z++; }
			else if (b == 9) { b = g; g = 9; z++; }
			else if (i == 9) { i = g; g = 9; z++; }
		}
		if (x >= 250 && x <= 350 && y >= 150 && y <= 250) {
			if (e == 9) { e = h; h = 9; z++; }
			else if (b == 9) { b = h; h = 9; z++; }
			else if (i == 9) { i = h; h = 9; z++; }
		}
		if (x >= 250 && x <= 350 && y >= 250 && y <= 350) {
			if (h == 9) { h = i; i = 9; z++; }
			else if (g == 9) { g = i; i = 9; z++; }
		}
		if (x >= 50 && x <= 150 && y >= 380 && y <= 480) {
			a = 0; b = 4; c = 3; d = 1; e = 6; f = 2; g = 5; h = 7; l = 1, i = 8;
			TextOut(hdc, 185, 420, CC, wcslen(CC));
			TextOut(hdc, 177, 18, DD, wcslen(DD));

		}
		if (a == 0 && b == 4 && c == 3 && d == 1 && e == 6 && f == 2 && g == 5 && h == 7 && i == 9 && l == 0) {
			TextOut(hdc, 185, 420, AA, wcslen(AA));
			TextOut(hdc, 177, 18, DD, wcslen(DD));
			i = 8;
		}
		myPaint(hdc, mdc, hpen, a, b, c, d, e, f, g, h, i);

		if (i == 8) {
			Sleep(2000);
			DestroyWindow(hwnd);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		myPaint(hdc, mdc, hpen, a, b, c, d, e, f, g, h, i);
		if (l == 1) {
			TextOut(hdc, 185, 420, CC, wcslen(CC));
		}
		EndPaint(hwnd, &ps);
		break;
		//����������Ϣ
	case WM_DESTROY:
		DeleteDC(mdc);
		DeleteObject(hbmp);
		DeleteObject(hpen);
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
