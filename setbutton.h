#pragma once
#include<graphics.h>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<iostream>
#include"CalcString.hpp"



struct Button
{
	int x;
	int y;
};

void setButton(Button btn, int x, int y, TCHAR text[1000], string fcolor)
{
	BeginBatchDraw();//暂停绘画
	//设置顶点坐标
	btn.x = x;
	btn.y = y;
	//设置边框颜色
	if (fcolor == "1")setlinecolor(RGB(192, 192, 192));//设置填充颜色为红色
	else if (fcolor == "2")setlinecolor(RGB(255, 177, 139));//设置填充颜色为红色
	else if (fcolor == "3")setlinecolor(RGB(255, 107, 71));//设置填充颜色为红色



	//绘制按钮边框
	circle(btn.x, btn.y, 30);
	//设置填充颜色
	if (fcolor == "1")setfillcolor(RGB(230, 230, 230));
	else if (fcolor == "2")setfillcolor(RGB(255, 177, 139));
	else if (fcolor == "3")setfillcolor(RGB(255, 107, 71));
	else if (fcolor == "4")setfillcolor(RGB(191, 255, 216));

	fillcircle(x, y, 30);
	//设置按钮文字
	setbkmode(TRANSPARENT);//设置透明字体

	//设置文本颜色
	if (fcolor == "1")settextcolor(RGB(92, 92, 92));//设置填充颜色为红色
	else if (fcolor == "2")settextcolor(RGB(92, 92, 92));//设置填充颜色为红色
	else if (fcolor == "3")settextcolor(RGB(92, 92, 92));//设置填充颜色为红色
	else if (fcolor == "4")settextcolor(RGB(92, 92, 92));

	//settextcolor(BLUE);//设置字体颜色
	settextstyle(30, 15, _T("宋体"));//设置字体格式
	outtextxy(x - 7.5 * _tcslen(text), y - 15, text);//设置显示位置
	EndBatchDraw();


	//恢复画线和填充颜色
	setlinecolor(WHITE);
	setfillcolor(WHITE);
}
