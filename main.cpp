#include<graphics.h>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<iostream>
#include"CalcString.hpp"

using namespace std;
int a=0,b = 0,i=0;
string output;
string result;
string* presult;
double outcome=0.0;
double* poutcome=&outcome;


struct Button
{
	int x;
	int y;
};

void setButton(Button btn, int x,int y, TCHAR text[1000],   string fcolor)
{
	BeginBatchDraw();//暂停绘画
	//设置顶点坐标
	btn.x = x;
	btn.y =y ;
	//设置边框颜色
	if (fcolor == "1")setlinecolor(RGB(192, 192, 192));//设置填充颜色为红色
	else if (fcolor == "2")setlinecolor(RGB(255, 177, 139));//设置填充颜色为红色
	else if (fcolor == "3")setlinecolor(RGB(255, 107, 71));//设置填充颜色为红色

	
	
	//绘制按钮边框
	circle(btn.x,btn.y, 30);
	//设置填充颜色
	if (fcolor == "1")setfillcolor(RGB(230, 230, 230));
	else if (fcolor == "2")setfillcolor(RGB(255, 177, 139));
	else if (fcolor == "3")setfillcolor(RGB(255, 107, 71));
	else if (fcolor == "4")setfillcolor(RGB(191, 255, 216));
	
	fillcircle(x,y,30);
	//设置按钮文字
	setbkmode(TRANSPARENT);//设置透明字体

	//设置文本颜色
	if (fcolor == "1")settextcolor(RGB(92,92,92));//设置填充颜色为红色
	else if (fcolor == "2")settextcolor(RGB(92,92,92));//设置填充颜色为红色
	else if (fcolor == "3")settextcolor(RGB(92,92,92));//设置填充颜色为红色
	else if (fcolor == "4")settextcolor(RGB(92, 92, 92)); 
	
	//settextcolor(BLUE);//设置字体颜色
	settextstyle(30,15, _T("宋体"));//设置字体格式
	outtextxy(x -7.5*_tcslen(text), y - 15, text);//设置显示位置
	EndBatchDraw();

	
	//恢复画线和填充颜色
	setlinecolor(WHITE);
	setfillcolor(WHITE);
}

int main()
{
	//string aa, bb;
	//aa = "((5/7*8-90)*6^5-4)/7";
	//double cc=0;
	//getStringValue(aa, &bb, 0, &cc);
	//cout << bb << endl;
	int i = 0;
	Button btns[30]; //初始化按钮结构体数组

	initgraph(500, 640);//初始化界面
	setbkcolor(RGB(255, 255, 255));//界面颜色
	cleardevice();
	//数字
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
	//运算符
	TCHAR texjia[10] = _T("+");
	TCHAR texjian[10] = _T("-");
	TCHAR texcheng[10] = _T("*");
	TCHAR texchu[10] = _T("/");
	TCHAR texdeng[10] = _T("=");
	TCHAR texf[10] = _T(".");
	//操作符
	TCHAR texqingli[10] = _T("CLC");
	TCHAR texac[10] = _T("AC");
	TCHAR texzuokuo[10] = _T("(");
	TCHAR texyoukuo[10] = _T(")");
	//函数
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

	
	
		//第一行

		setButton(btns[0], 40,255, texjiecheng,  "1");

		setButton(btns[1], 110, 255, texmi,  "1");

		setButton(btns[2], 180,  255, texln, "1");
		
		setButton(btns[3], 250, 255, texzuokuo, "1");

		setButton(btns[4], 320, 255, texyoukuo, "1");

		setButton(btns[5], 390, 255, texac, "3");
		
		setButton(btns[6], 460, 255, texqingli, "3");
		
		//第二行
		
		setButton(btns[7], 40, 325, texsin, "1");
		
		setButton(btns[8], 110, 325, texcos, "1");
		
		setButton(btns[9], 180, 325, textan, "1");

		setButton(btns[10], 250, 325, tex7, "4");

		setButton(btns[11], 320, 325, tex8, "4");

		setButton(btns[12], 390, 325, tex9, "4");

		setButton(btns[13], 460, 325, texjia, "2");

		//第三行
		
		setButton(btns[14], 40, 395, texcot, "1");
		
		setButton(btns[15], 110, 395, tex, "1");
		settextstyle(15, 8, _T("宋体"));//设置字体格式
		outtextxy(110 - 4 * _tcslen(texarcsin), 395 - 7, texarcsin); 
		setButton(btns[16], 180, 395, tex, "1");
		settextstyle(15, 8, _T("宋体"));//设置字体格式
		outtextxy(180 - 4 * _tcslen(texarccos), 395 - 7, texarccos);
		setButton(btns[17], 250, 395, tex4, "4");

		setButton(btns[18], 320, 395, tex5, "4");

		setButton(btns[19], 390, 395, tex6, "4");

		setButton(btns[20], 460, 395, texjian, "2");

		//第4行
		setButton(btns[21], 40, 465, texe, "1");
		settextstyle(18, 10, _T("宋体"));//设置字体格式
		outtextxy(40 +10, 465 -10, texping);

		setButton(btns[22], 110, 465, texping, "1");
		settextstyle(18, 10, _T("宋体"));//设置字体格式
		outtextxy(110+10, 465 -10, tex2);

		setButton(btns[22], 180, 465, texli, "1");
		settextstyle(18, 10, _T("宋体"));//设置字体格式
		outtextxy(180+10, 465-10, tex3);

		setButton(btns[22], 250, 465, tex1, "4");

		setButton(btns[22], 320, 465, tex2, "4");

		setButton(btns[22], 390, 465, tex3, "4");

		setButton(btns[22], 460, 465, texcheng, "2");
		//第5行
		setButton(btns[21], 40, 535, tex, "1");
		settextstyle(18, 10, _T("宋体"));//设置字体格式
		outtextxy(40 - 5 * _tcslen(texsqrt), 535 - 9, texsqrt);

		setButton(btns[22], 110, 535, tex2, "1");
		settextstyle(18, 10, _T("宋体"));//设置字体格式
		outtextxy(110 + 10, 535 - 15, texping);

		setButton(btns[22], 180, 535, tex3, "1");
		settextstyle(18, 10, _T("宋体"));//设置字体格式
		outtextxy(180 + 10, 535 - 15, texping);

		setButton(btns[22], 250, 535, texpi, "4");

		setButton(btns[22], 320, 535, tex0, "4");

		setButton(btns[22], 390, 535, texf, "4");

		setButton(btns[22], 460, 535, texchu, "2");
		//第6行
		setButton(btns[21], 40, 605, tex, "1");

		setButton(btns[22], 110, 605, tex, "1");

		setButton(btns[22], 180, 605, tex, "1");

		setButton(btns[22], 250, 605, tex, "1");

		setButton(btns[22], 320, 605, tex, "1");

		setButton(btns[22], 390, 605, tex, "1");

		setButton(btns[22], 460, 605, texdeng, "3");

		ExMessage m;
	while(true)
	{

		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);

		switch (m.message)
		{
		

		case WM_LBUTTONDOWN:
			//第一行
			if (m.x >= 10 && m.x <= 70)
			{
				if (m.y >= 225 && m.y <= 285)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(40, 255, 30);
					b += 15;
					if (b > 480)
					{
						a += 40;
						b = 0;
					}
					else b -= 15;
					outtextxy(b, a, texjiecheng);
					output += "!";
					for (int p = 0; p < 100000000; p++);//延时
					setButton(btns[0], 40, 255, texjiecheng, "1");
					if (i >= 360)
					{
						int x;
						x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
						cout << x;
					}
					b += 15;

					

				}
				m.message = 0;
				
			}
						if (m.x >= 80 && m.x <= 140)
			{
				if (m.y >= 225 && m.y <= 285)
				{
					setfillcolor(RGB(145, 145, 145));
					fillcircle(110, 255, 30);
					b += 15;
					if (b > 480)
					{
						a += 40;
						b = 0;
					}
					else b -= 15;
					outtextxy(b, a, texmi);
					output += "^";
					for (int p = 0; p< 100000000; p++);
					setButton(btns[1], 110, 255, texmi, "1");
					if (i >= 360)
					{
						int x;
						x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
						cout << x;
					}
					b += 15;
				}
				m.message = 0;
			}
						if (m.x > 150&& m.x <210 )
						{
							if (m.y >= 225 && m.y <= 285)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(180, 255, 30);
								b += 30;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 30;
								outtextxy(b, a, texln);
								output += "ln";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 180, 255, texln, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 30;
							}
							m.message = 0;
						}
						if (m.x > 220&& m.x < 280)
						{
							if (m.y >= 225 && m.y <= 285)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(250, 255, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, texzuokuo);
								output +="(";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 250, 255, texzuokuo, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						if (m.x >290 && m.x <350 )
						{
							if (m.y >= 225 && m.y <= 285)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(320, 255, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, texyoukuo);
								output += ")";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 320, 255, texyoukuo, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								
								b += 15;
							}
							m.message = 0;
						}
						if (m.x > 360&& m.x <420 )
						{
							if (m.y >= 225 && m.y <= 285)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(390, 255, 30);
								clearrectangle(0, 0, 600, 225);
								output = "";
								i = 0;
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 390, 255, texac, "3");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								a = 0;
								b = 0;
								if (b >480)
								{
									a += 40;
									b = 0;
								}
							}
							m.message = 0;
						}
						if (m.x > 430&& m.x < 490)
						{
							if (m.y >= 225 && m.y <= 285)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(460, 255, 30);
								clearrectangle(b - 15, a, b, a + 30);
								//clear(output);//清楚已存字符串的最后一个字符，而非最后一次输入
								
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 460, 255, texqingli, "3");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b -= 15;
								if (b <0)
								{
									a -= 40;
									b = 480;
								}
							}
							m.message = 0;
						}
						//第二行
						if (m.x >10 && m.x <70)
						{
							if (m.y >=295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(40, 325, 30);
								b += 45;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 45;
								outtextxy(b, a, texsin);
								output += "sin";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 40, 325, texsin, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 45;
							}
							m.message = 0;
						}
						if (m.x > 80&& m.x <140 )
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(110, 325, 30);
								b += 45;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 45;
								outtextxy(b, a, texcos);
								output += "cos";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 110, 325, texcos, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 45;
							}
							m.message = 0;
						}
						if (m.x >150 && m.x < 210)
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(180, 325, 30);
								b += 45;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 45;
								outtextxy(b, a, textan);
								output += "tan";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 180, 325, textan, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}b += 45;
								
							}
							m.message = 0;
						}
						if (m.x >220 && m.x < 280)
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(250, 325, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, tex7);
								output += "7";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 250, 325, tex7, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						if (m.x >290 && m.x <350 )
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(320, 325, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, tex8);
								output += "8";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 320, 325, tex8, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}	
								b += 15;
								
							}
							m.message = 0;
						}
						if (m.x >360 && m.x <420 )
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(390, 325, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								 else b -= 15;
								outtextxy(b, a, tex9);
								output += "9";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 390, 325, tex9, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
									;
								}
								b += 15;

									m.message = 0;
							}
						}
						if (m.x > 430&& m.x <490 )
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(460, 325, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, texjia);
								output+="+";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 460, 325, texjia, "2");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						//第三行
						if (m.x > 10 && m.x < 70)
						{
							if (m.y >= 365 && m.y <= 425)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(40, 395, 30);
								b += 45;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 45;
								outtextxy(b, a, texcot);
								output += "cot";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 40, 395, texcot, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 45;
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
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 90;
								outtextxy(b, a, texarcsin);
								output += "sin";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 110, 395, tex, "1");
								settextstyle(15, 8, _T("宋体"));//设置字体格式
								outtextxy(110 - 4 * _tcslen(texarcsin), 395 - 7, texarcsin);
								settextstyle(30, 15, _T("宋体"));//设置字体格式
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 90;
							}
							m.message = 0;
						}
						if (m.x > 150 && m.x < 210)
						{
							if (m.y >= 365 && m.y <= 425)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(180, 395, 30);
								b += 90;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 90;
								outtextxy(b, a, texarccos);
								output += "arccos";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 180, 395, tex, "1");
								settextstyle(15, 8, _T("宋体"));//设置字体格式
								outtextxy(180 - 4 * _tcslen(texarccos), 395 - 7, texarccos);
								settextstyle(30, 15, _T("宋体"));//设置字体格式
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 90;
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
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, tex4);
								output += "4";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 250, 395, tex4, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
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
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, tex5);
								output += "5";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 320, 395, tex5, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
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
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, tex6);
								output += "6";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 390, 395, tex6, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						if (m.x > 430 && m.x < 490)
						{
							if (m.y >= 365 && m.y <= 425)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(460, 395, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, texjian);
								output += "-";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 460, 395, texjian, "2");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						//第四行
						if (m.x > 10 && m.x < 70)
						{
							if (m.y >= 435 && m.y <= 495)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(40, 465, 30);
								
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								outtextxy(b, a, texe);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								outtextxy(b,a, texmi);
								
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								settextstyle(30, 15, _T("宋体"));
								output += "e^";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 40, 465, texe, "1");
								settextstyle(18, 10, _T("宋体"));//设置字体格式
								outtextxy(40 + 10, 465 - 10, texping);
								settextstyle(30, 15, _T("宋体"));
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						if (m.x > 80 && m.x < 140)
						{
							if (m.y >= 435&& m.y <= 495)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(110, 465, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								//outtextxy(b, a, texping);
								settextstyle(18, 10, _T("宋体"));//设置字体格式
								outtextxy(b,a, tex2);
								settextstyle(30, 15, _T("宋体"));
								output += "^2";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 110, 465, texping, "1");
								settextstyle(18, 10, _T("宋体"));//设置字体格式
								outtextxy(110 + 10, 465 - 10, tex2);
								settextstyle(30, 15, _T("宋体"));
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
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
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								//outtextxy(b, a, texmi);
								settextstyle(18, 10, _T("宋体"));//设置字体格式
								outtextxy(b, a, tex3);
								settextstyle(30, 15, _T("宋体"));
								output += "^3";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 180, 465, texli, "1");
								settextstyle(18, 10, _T("宋体"));//设置字体格式
								outtextxy(180 + 10, 465 - 10, tex3);
								settextstyle(30, 15, _T("宋体"));
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
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
								if (b == 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;

								outtextxy(b, a, tex1);
								output += "1";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 250, 465, tex1, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
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
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, tex2);
								output += "2";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 320, 465, tex2, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
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
								b+=15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, tex3);
								output += "3";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 390, 465, tex3, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						if (m.x > 430 && m.x < 490)
						{
							if (m.y >= 435 && m.y <= 495)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(460, 465, 30);
								b += 15;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 15;
								outtextxy(b, a, texcheng);
								output += "*";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 460, 465, texcheng, "2");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						//第五行
						if (m.x > 10 && m.x < 70)
						{
							if (m.y >= 505 && m.y <= 565)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(40, 535, 30);
								b += 60;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 60;
								outtextxy(b, a, texsqrt);
								output += "^0.5";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 40, 535, tex, "1");
								settextstyle(18, 10, _T("宋体"));//设置字体格式
								outtextxy(40 - 5 * _tcslen(texsqrt), 535 - 9, texsqrt);
								settextstyle(30, 15, _T("宋体"));
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 75;
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
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								
								else b -= 30;
								outtextxy(b, a, tex2);
								b += 15;
								outtextxy(b, a, texmi);
								output += "2^";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 110, 535, tex2, "1");
								settextstyle(18, 10, _T("宋体"));//设置字体格式
								outtextxy(110+ 10, 535 - 15, texping);
								settextstyle(30, 15, _T("宋体"));
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						if (m.x > 150 && m.x < 210)
						{
							if (m.y >= 505 && m.y <= 565)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(180, 535, 30);
								b += 30;
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								else b -= 30;
								outtextxy(b, a, tex3);
								b += 15;
								outtextxy(b, a, texmi);
								output += "3^";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 180, 535, tex3, "1");
								settextstyle(18, 10, _T("宋体"));//设置字体格式
								outtextxy(180+ 10,535 - 15, texping);
								settextstyle(30, 15, _T("宋体"));
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						if (m.x > 220 && m.x < 280)
						{
							if (m.y >= 505 && m.y <= 535)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(250, 535, 30);
								
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								outtextxy(b, a, texpi);
								output += "pi";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 250, 535, texpi, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 30;
							}
							m.message = 0;
						}
						if (m.x > 290 && m.x < 350)
						{
							if (m.y >= 505 && m.y <= 565)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(320, 535, 30);
								
								if (b >480)
								{
									a += 40;
									b = 0;
								}
								outtextxy(b, a, tex0);
								output += "0";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 320, 535, tex0, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
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
								
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								outtextxy(b, a, texf);
								output += ".";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 390, 535, texf, "4");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						if (m.x > 430 && m.x < 490)
						{
							if (m.y >= 505 && m.y <= 565)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(460, 535, 30);
								
								if (b > 480)
								{
									a += 40;
									b = 0;
								}
								outtextxy(b, a, texchu);
								output += "/";
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 460, 535, texchu, "2");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
							}
							m.message = 0;
						}
						//第六行
						/*if (m.x > 10 && m.x < 70)
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(40, 325, 30);
								outtextxy(b, a, texsin);
								output[i] = *texsin;
								i++;
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 40, 325, texsin, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 45;
								if (b == 480)
								{
									a += 40;
									b = 0;
								}
							}
							m.message = 0;
						}
						if (m.x > 80 && m.x < 140)
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(110, 325, 30);
								outtextxy(b, a, texcos);
								output[i] = *texcos;
								i++;
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 110, 325, texcos, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 45;
								if (b == 480)
								{
									a += 40;
									b = 0;
								}
							}
							m.message = 0;
						}
						if (m.x > 150 && m.x < 210)
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(180, 325, 30);
								outtextxy(b, a, textan);
								output[i] = *textan;
								i++;
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 180, 325, textan, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 45;
								if (b == 480)
								{
									a += 40;
									b = 0;
								}
							}
							m.message = 0;
						}
						if (m.x > 220 && m.x < 280)
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(250, 325, 30);
								outtextxy(b, a, tex7);
								output[i] = *tex7;
								i++;
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 250, 325, tex7, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
								if (b == 480)
								{
									a += 40;
									b = 0;
								}
							}
							m.message = 0;
						}
						if (m.x > 290 && m.x < 350)
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(320, 325, 30);
								outtextxy(b, a, tex8);
								output[i] = *tex8;
								i++;
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 320, 325, tex8, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
								if (b == 480)
								{
									a += 40;
									b = 0;
								}
							}
							m.message = 0;
						}
						if (m.x > 360 && m.x < 420)
						{
							if (m.y >= 295 && m.y <= 355)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(390, 325, 30);
								outtextxy(b, a, tex9);
								output[i] = *tex9;
								i++;
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 390, 325, tex9, "1");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								b += 15;
								if (b == 480)
								{
									a += 40;
									b = 0;
								}
							}
							m.message = 0;
						}
						*/
						if (m.x > 430 && m.x < 490)
						{
							if (m.y >= 575 && m.y <= 635)
							{
								setfillcolor(RGB(145, 145, 145));
								fillcircle(460, 605, 30);
								
								for (int p = 0; p < 100000000; p++);
								setButton(btns[1], 460, 605, texdeng, "3");
								if (i >= 360)
								{
									int x;
									x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
									cout << x;
								}
								presult = &result;
								//在这里加入对getStringValue返回值的处理：
								//如果返回值是0，那么计算正常，更新显示，否则报错
								if (getStringValue(output, presult, 1.0, poutcome) == 0)
								{
									clearrectangle(0, 0, 600, 225);
									// strcpy(s1, result.c_str());
									swprintf_s(s, _T("%lf"), outcome);
									outtextxy(0, 0, s);
									a = 0;
									b = 0;
								}
								else //发生了数学错误，如除数为0、反三角函数超过定义域
								{
									int x = MessageBox(GetForegroundWindow(), TEXT("发生数学错误"), TEXT("请重新输入！"), 1);
									cout << x;
								}
							}
							m.message = 0;
						}
						
						
			if (a >= 200&&b>=390||a>200 )
			{
				int x;
				x = MessageBox(GetForegroundWindow(), TEXT("输入数据已达上限！"), TEXT("请重新输入！"), 1);
				cout << x;
			}
			break;
		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				return 0;	// 按 ESC 键退出程序
		}
	}

	

	getchar();//等待用户输入
	closegraph();

	return 0;
}