#include <graphics.h>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <iostream>
#include "ToBeCalculatedExpression.hpp"
#include "CalcString.hpp"
#include"SetButtons.hpp"
using namespace std;
void drawpicture()
{// string aa, bb;
	// aa = "((5/7*8-90)*6^5-4)/7";
	// double cc=0;
	// getStringValue(aa, &bb, 0, &cc);
	// cout << bb << endl;
	int i = 0;
	//��ʼ����ť�ṹ������

	initgraph(430, 640);			// ��ʼ������
	setbkcolor(RGB(255, 255, 255)); // ������ɫ
	cleardevice();
	// ����
	TCHAR tex0[10] = _T("0");
	TCHAR tex1[10] = _T("1");
	TCHAR tex2[10] = _T("2");
	TCHAR tex3[10] = _T("3");
	TCHAR tex4[10] = _T("4");
	TCHAR tex5[10] = _T("5");
	TCHAR tex6[10] = _T("6");
	TCHAR tex7[10] = _T("7");
	TCHAR tex8[10] = _T("8");
	TCHAR tex9[10] = _T("9");
	TCHAR texpi[10] = _T("pi");
	// �����
	TCHAR texjia[10] = _T("+");
	TCHAR texjian[10] = _T("-");
	TCHAR texcheng[10] = _T("*");
	TCHAR texchu[10] = _T("/");
	TCHAR texdeng[10] = _T("=");
	TCHAR texf[10] = _T(".");
	// ������
	TCHAR texqingli[10] = _T("CLC");
	TCHAR texac[10] = _T("AC");
	TCHAR texzuokuo[10] = _T("(");
	TCHAR texyoukuo[10] = _T(")");
	// ����
	TCHAR texsin[10] = _T("sin");
	TCHAR texcos[10] = _T("cos");
	TCHAR textan[10] = _T("tan");
	TCHAR texcot[10] = _T("cot");
	TCHAR texarcsin[10] = _T("arcsin");
	TCHAR texarccos[10] = _T("arccos");
	TCHAR texjiecheng[10] = _T("!");
	TCHAR texmi[10] = _T("^");
	TCHAR texln[10] = _T("ln");
	TCHAR texlog[10] = _T("log");
	TCHAR tex[10] = _T(" ");
	TCHAR texe[10] = _T("e");
	TCHAR texsqrt[10] = _T(" sqrt");
	TCHAR texping[10] = _T("x");
	TCHAR texli[10] = _T("x");
	TCHAR s[100];

	// ��һ��

	//setButton(btns[0], 40, 255, texjiecheng, "1");

	setButton(40, 255, texmi, "1");

	setButton( 110, 255, texln, "1");

	setButton( 180, 255, texzuokuo, "1");

	setButton( 250, 255, texyoukuo, "1");

	setButton( 320, 255, texac, "3");

	setButton( 390, 255, texqingli, "3");

	// �ڶ���

	//setButton( 40, 325, texsin, "1");

	setButton( 40, 325, texcos, "1");

	setButton( 110, 325, textan, "1");

	setButton( 180, 325, tex7, "4");

	setButton( 250, 325, tex8, "4");

	setButton(320, 325, tex9, "4");

	setButton( 390, 325, texjia, "2");

	// ������

	//setButton( 40, 395, texcot, "1");

	setButton(40, 395, tex, "1");
	settextstyle(15, 8, _T("����")); // ���������ʽ
	outtextxy(40 - 4 * _tcslen(texarcsin), 395 - 7, texarcsin);
	setButton(110, 395, tex, "1");
	settextstyle(15, 8, _T("����")); // ���������ʽ
	outtextxy(110 - 4 * _tcslen(texarccos), 395 - 7, texarccos);
	setButton(180, 395, tex4, "4");

	setButton(250, 395, tex5, "4");

	setButton(320, 395, tex6, "4");

	setButton(390, 395, texjian, "2");

	// ��4��
//	setButton( 40, 465, texe, "1");
	//settextstyle(18, 10, _T("����")); // ���������ʽ
	//outtextxy(40 + 10, 465 - 10, texping);

	setButton(40, 465, texping, "1");
	settextstyle(18, 10, _T("����")); // ���������ʽ
	outtextxy(40+ 10, 465 - 10, tex2);

	setButton(110, 465, texli, "1");
	settextstyle(18, 10, _T("����")); // ���������ʽ
	outtextxy(110+ 10, 465 - 10, tex3);

	setButton(180, 465, tex1, "4");

	setButton(250, 465, tex2, "4");

	setButton(320, 465, tex3, "4");

	setButton(390, 465, texcheng, "2");
	// ��5��
	//setButton(btns[21], 40, 535, tex, "1");
	//settextstyle(18, 10, _T("����")); // ���������ʽ
	//outtextxy(40 - 5 * _tcslen(texsqrt), 535 - 9, texsqrt);

	setButton(40, 535, tex2, "1");
	settextstyle(18, 10, _T("����")); // ���������ʽ
	outtextxy(40 + 10, 535 - 15, texping);

	setButton(110, 535, tex3, "1");
	settextstyle(18, 10, _T("����")); // ���������ʽ
	outtextxy(110 + 10, 535 - 15, texping);

	setButton(180, 535, texpi, "4");

	setButton(250, 535, tex0, "4");

	setButton(320, 535, texf, "4");

	setButton(390, 535, texchu, "2");
	// ��6��
	//setButton(btns[21], 40, 605, tex, "1");

	setButton(40, 605, tex, "1");

	setButton(110, 605, tex, "1");

	setButton(180, 605, tex, "1");

	setButton(250, 605, tex, "1");

	setButton(320, 605, tex, "1");

	setButton(390, 605, texdeng, "3");
}