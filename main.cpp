#include <graphics.h>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <iostream>
#include <ctime>
#include "ToBeCalculatedExpression.hpp"
#include "CalcString.hpp"
#include "SetButtons.hpp"
#include "DrawPicture.hpp"
#include "DrawTime.hpp"
#include "IdleMonitor.hpp"
#include "StringToWString.hpp"
#include "DrawExpressionAndResult.hpp"
using namespace std;
int a = 0, b = 0;
ToBeCalculatedExpression output;
string result;
string *presult;
double outcome = 0.0;
double *poutcome = &outcome;



int main()
{
	
	drawpicture();
	drawtime();
	
	// 数字
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
	// 运算符
	TCHAR texjia[10] = _T("+");
	TCHAR texjian[10] = _T("-");
	TCHAR texcheng[10] = _T("*");
	TCHAR texchu[10] = _T("/");
	TCHAR texdeng[10] = _T("=");
	TCHAR texf[10] = _T(".");
	// 操作符
	TCHAR texqingli[10] = _T("CLC");
	TCHAR texac[10] = _T("AC");
	TCHAR texzuokuo[10] = _T("(");
	TCHAR texyoukuo[10] = _T(")");
	// 函数
	TCHAR texsin[10] = _T("sin");
	TCHAR texcos[10] = _T("cos");
	TCHAR textan[10] = _T("tan");
	TCHAR texarctan[10] = _T("arctan");
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
	ExMessage m,n;
	
	
	while (true)
	{
		//DWORD currenttime = GetTickCount();
		IdleMonitor idleMonitor;
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE |EX_KEY);
		idleMonitor.stopFlag.store(true);
		idleMonitor.join();
		switch (m.message)
		{
		case WM_LBUTTONDOWN:
			
			// 第一行
			
			if (m.x >= 10 && m.x <= 70)
			{
				if (m.y >= 225 && m.y <= 285)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(40, 255, 30);
					b += 15;
					if (b > 410)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, texmi);
					output += "^";
					for (int p = 0; p < 100000000; p++)
						;
					setButton( 40, 255, texmi, "1");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x >=80 && m.x <= 140)
			{
				if (m.y >= 225 && m.y <= 285)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(110, 255, 30);
					b += 30;
					if (b > 410)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 30;
					outtextxy(b, a, texln);
					output += "ln(";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(110, 255, texln, "1");
					
					b += 30;
				}
				m.message = 0;
			}
			if (m.x > 150 && m.x < 210)
			{
				if (m.y >= 225 && m.y <= 285)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(180, 255, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, texzuokuo);
					output += "(";
					for (int p = 0; p < 100000000; p++);
					setButton(180, 255, texzuokuo, "1");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 220 && m.x < 280)
			{
				if (m.y >= 225 && m.y <= 285)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(250, 255, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, texyoukuo);
					output += ")";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(250, 255, texyoukuo, "1");
					

					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 290 && m.x < 350)
			{
				if (m.y >= 225 && m.y <= 285)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(320, 255, 30);
					clearrectangle(0, 0, 600, 225);
					output = "";//这里是清空输入的内容吗？
					
					for (int p = 0; p < 100000000; p++)//这句话是干什么的？
						;
					setButton(320, 255, texac, "3");
					
					a = 0;
					b = 0;
					
				}
				m.message = 0;
			}
			if (m.x > 360 && m.x < 420)
			{
				if (m.y >= 225 && m.y <= 285)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(390, 255, 30);
					clearrectangle(b - 15, a, b, a + 30);
					// clear(output);//清楚已存字符串的最后一个字符，而非最后一次输入
					output.removeLast();
					for (int p = 0; p < 100000000; p++);
					setButton(390, 255, texqingli, "3");
					
					b -= 15;
					if (b < 0)
					{
						a -= 35;
						b = 410;
					}
				}
				m.message = 0;
			}
			// 第二行
			
			if (m.x > 10 && m.x < 70)
			{
				if (m.y >= 295 && m.y <= 355)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(40, 325, 30);
					b += 45;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 45;
					outtextxy(b, a, texsin);
					output += "sin(";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(40, 325, texsin, "1");
					
					b += 45;
				}
				m.message = 0;
			}
			if (m.x > 80 && m.x < 140)
			{
				if (m.y >= 295 && m.y <= 355)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(110, 325, 30);
					b += 45;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 45;
					outtextxy(b, a, texcos);
					output += "cos(";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(110, 325, texcos, "1");
					
					b += 45;
				}
				m.message = 0;
			}
			if (m.x > 150 && m.x < 210)
			{
				if (m.y >= 295 && m.y <= 355)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(180, 325, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, tex7);
					output += "7";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(180, 325, tex7, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 220 && m.x < 280)
			{
				if (m.y >= 295 && m.y <= 355)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(250, 325, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, tex8);
					output += "8";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(250, 325, tex8, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 290 && m.x < 350)
			{
				if (m.y >= 295 && m.y <= 355)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(320, 325, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, tex9);
					output += "9";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(320, 325, tex9, "4");
					
					b += 15;

					m.message = 0;
				}
			}
			if (m.x > 360 && m.x < 420)
			{
				if (m.y >= 295 && m.y <= 355)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(390, 325, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, texjia);
					output += "+";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(390, 325, texjia, "2");
					
					b += 15;
				}
				m.message = 0;
			}
			// 第三行
			
			if (m.x > 10 && m.x < 70)
			{
				if (m.y >= 365 && m.y <= 425)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(40, 395, 30);
					b += 90;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 90;
					outtextxy(b, a, texarcsin);
					output += "sin";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(40, 395, tex, "1");
					settextstyle(15, 8, _T("宋体")); // 设置字体格式
					outtextxy(40 - 4 * _tcslen(texarcsin), 395 - 7, texarcsin);
					settextstyle(30, 15, _T("宋体")); // 设置字体格式
					
					b += 90;
				}
				m.message = 0;
			}
			if (m.x > 80 && m.x < 140)
			{
				if (m.y >= 365 && m.y <= 425)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(110, 395, 30);
					b += 90;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 90;
					outtextxy(b, a, texarccos);
					output += "arccos";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(110, 395, tex, "1");
					settextstyle(15, 8, _T("宋体")); // 设置字体格式
					outtextxy(110 - 4 * _tcslen(texarccos), 395 - 7, texarccos);
					settextstyle(30, 15, _T("宋体")); // 设置字体格式
					
					b += 90;
				}
				m.message = 0;
			}
			if (m.x > 150 && m.x < 220)
			{
				if (m.y >= 365 && m.y <= 425)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(180, 395, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, tex4);
					output += "4";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(180, 395, tex4, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 220 && m.x < 280)
			{
				if (m.y >= 365 && m.y <= 425)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(250, 395, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, tex5);
					output += "5";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(250, 395, tex5, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 290 && m.x < 350)
			{
				if (m.y >= 365 && m.y <= 425)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(320, 395, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, tex6);
					output += "6";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(320, 395, tex6, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 360 && m.x < 420)
			{
				if (m.y >= 365 && m.y <= 425)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(390, 395, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, texjian);
					output += "-";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(390, 395, texjian, "2");
					
					b += 15;
				}
				m.message = 0;
			}
			// 第四行
			
			if (m.x > 10 && m.x < 70)
			{
				if (m.y >= 435 && m.y <= 495)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(40, 465, 30);
					b += 30;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 30;
					output += "tan(";
					outtextxy(b, a, textan);
					for (int p = 0; p < 100000000; p++);
						
					setButton(40, 465, textan, "1");
					
					b += 30;
				}
				m.message = 0;
			}
			if (m.x > 80 && m.x < 140)
			{
				if (m.y >= 435 && m.y <= 495)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(110, 465, 30);
					b += 90;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 90;
					 outtextxy(b, a, texarctan);
					
					output += "arctan(";
					for (int p = 0; p < 100000000; p++);
						
					setButton(110, 465, tex, "1");
					settextstyle(15, 8, _T("宋体")); // 设置字体格式
					outtextxy(110 - 4 * _tcslen(texarctan), 465 - 7, texarctan);
					settextstyle(30, 15, _T("宋体"));
					
					b += 90;
				}
				m.message = 0;
			}
			if (m.x > 150 && m.x < 210)
			{
				if (m.y >= 435 && m.y <= 495)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(180, 465, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;

					outtextxy(b, a, tex1);
					output += "1";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(180, 465, tex1, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 220 && m.x < 280)
			{
				if (m.y >= 435 && m.y <= 495)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(250, 465, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, tex2);
					output += "2";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(250, 465, tex2, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 290 && m.x < 350)
			{
				if (m.y >= 435 && m.y <= 495)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(320, 465, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, tex3);
					output += "3";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(320, 465, tex3, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 360 && m.x < 420)
			{
				if (m.y >= 435 && m.y <= 495)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(390, 465, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 15;
					outtextxy(b, a, texcheng);
					output += "*";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(390, 465, texcheng, "2");
					
					b += 15;
				}
				m.message = 0;
			}
			// 第五行
			
			if (m.x > 10 && m.x < 70)
			{
				if (m.y >= 505 && m.y <= 565)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(40, 535, 30);
					b += 30;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}

					else
						b -= 30;
					outtextxy(b, a, tex2);
					b += 15;
					outtextxy(b, a, texmi);
					output += "2^";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(40, 535, tex2, "1");
					settextstyle(18, 10, _T("宋体")); // 设置字体格式
					outtextxy(40 + 10, 535 - 15, texping);
					settextstyle(30, 15, _T("宋体"));
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 80 && m.x < 140)
			{
				if (m.y >= 505 && m.y <= 565)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(110, 535, 30);
					b += 30;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 30;
					outtextxy(b, a, tex3);
					b += 15;
					outtextxy(b, a, texmi);
					output += "3^";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(110, 535, tex3, "1");
					settextstyle(18, 10, _T("宋体")); // 设置字体格式
					outtextxy(110 + 10, 535 - 15, texping);
					settextstyle(30, 15, _T("宋体"));
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 150 && m.x < 220)
			{
				if (m.y >= 505 && m.y <= 535)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(180, 535, 30);

					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					outtextxy(b, a, texpi);
					output += "pi";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(180, 535, texpi, "4");
					
					b += 30;
				}
				m.message = 0;
			}
			if (m.x > 220 && m.x < 280)
			{
				if (m.y >= 505 && m.y <= 565)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(250, 535, 30);

					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					outtextxy(b, a, tex0);
					output += "0";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(250, 535, tex0, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 290 && m.x < 350)
			{
				if (m.y >= 505 && m.y <= 565)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(320, 535, 30);

					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					outtextxy(b, a, texf);
					output += ".";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(320, 535, texf, "4");
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 360 && m.x < 420)
			{
				if (m.y >= 505 && m.y <= 565)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(390, 535, 30);

					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					outtextxy(b, a, texchu);
					output += "/";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(390, 535, texchu, "2");
					
					b += 15;
				}
				m.message = 0;
			}
			// 第六行
			if (m.x > 10 && m.x < 70)
			{
				if (m.y >= 575 && m.y <= 635)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(40, 605, 30);
					b += 30;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 30;
					// outtextxy(b, a, texping);
					settextstyle(18, 10, _T("宋体")); // 设置字体格式
					outtextxy(b, a, tex2);
					settextstyle(30, 15, _T("宋体"));
					output += "^2";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(40, 605, texping, "1");
					settextstyle(18, 10, _T("宋体")); // 设置字体格式
					outtextxy(40 + 10, 605 - 10, tex2);
					settextstyle(30, 15, _T("宋体"));
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 80 && m.x < 140)
			{
				if (m.y >= 575 && m.y <= 635)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(110, 605, 30);
					b += 30;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 30;
					// outtextxy(b, a, texmi);
					settextstyle(18, 10, _T("宋体")); // 设置字体格式
					outtextxy(b, a, tex3);
					settextstyle(30, 15, _T("宋体"));
					output += "^3";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(110, 605, texli, "1");
					settextstyle(18, 10, _T("宋体")); // 设置字体格式
					outtextxy(110 + 10, 605 - 10, tex3);
					settextstyle(30, 15, _T("宋体"));
					
					b += 15;
				}
				m.message = 0;
			}
			if (m.x > 150 && m.x < 210)
			{
				if (m.y >= 575 && m.y <= 635)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(180, 605, 30);
					
					b += 60;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else
						b -= 60;
					outtextxy(b, a, texsqrt);
				
					output += "sqrt";
					for (int p = 0; p < 100000000; p++)
						;
					setButton(180, 605, tex, "1");
					settextstyle(18, 10, _T("宋体")); // 设置字体格式
					outtextxy(180 - 5 * _tcslen(texsqrt), 605 - 9, texsqrt);
					settextstyle(30, 15, _T("宋体"));
					
					b += 75;
				}
				m.message = 0;
			}
			if (m.x > 220 && m.x < 280)
			{
				if (m.y >= 575 && m.y <= 635)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(250, 605, 30);
					b += 30;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else b -= 30;
					outtextxy(b, a, texe);
					b += 15;
					outtextxy(b, a, texmi);

					output += "e^";
					
					for (int p = 0; p < 100000000; p++);
					setButton(250, 605, texe, "1");
					settextstyle(18, 10, _T("宋体")); // 设置字体格式
					outtextxy(250 + 10, 605 - 10, texping);
					settextstyle(30, 15, _T("宋体"));
					
					b += 15;
					
				}
				m.message = 0;
			}
			
			if (m.x > 290 && m.x < 350)
			{
				if (m.y >= 575 && m.y <= 635)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(320, 605, 30);
					b += 15;
					if (b > 420)
					{
						a += 35;
						b = 0;
					}
					else b -= 15;
					outtextxy(b, a, texjiecheng);
					
					output += "!";
					for (int p = 0; p < 100000000; p++);
					setButton(320, 605, texjiecheng, "1");
				
					b += 15;
					
				}
				m.message = 0;
			}
			
			if (m.x > 360 && m.x < 420)
			{
				if (m.y >= 575 && m.y <= 635)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(460, 605, 30);

					for (int p = 0; p < 100000000; p++)
						;
					setButton(390, 605, texdeng, "3");
					presult = &result;
					// 在这里加入对getStringValue返回值的处理：
					// 如果返回值是0，那么计算正常，更新显示，否则报错
					if (getStringValue(output.toBeCalculatedString, presult, 1.0, poutcome) == 0)
					{
						// clearrectangle(0, 0, 600, 225);
						// // strcpy(s1, result.c_str());
						// swprintf_s(s, _T("%ls"), stringToWString(result).c_str());
						// outtextxy(0, 0, s);
						drawResult("="+result);
						a = 0;
						b = 0;
					}
					else // 发生了数学错误，如除数为0、反三角函数超过定义域
					{
						int x = MessageBox(GetForegroundWindow(), TEXT("发生数学错误"), TEXT("请重新输入！"), 1);
						cout << x;
					}
				}
				m.message = 0;
			}

			if (a >= 175 && b >= 360 || a > 175)
			{
				int x;
				x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
				cout << x;
			}
			break;
		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
			{
				output.join();
				return 0; // 按 ESC 键退出程序
			}
			break;
		}
		
	}
	
	getchar(); // 等待用户输入
	closegraph();

	return 0;
}