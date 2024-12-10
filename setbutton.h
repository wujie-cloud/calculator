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
	BeginBatchDraw();//��ͣ�滭
	//���ö�������
	btn.x = x;
	btn.y = y;
	//���ñ߿���ɫ
	if (fcolor == "1")setlinecolor(RGB(192, 192, 192));//���������ɫΪ��ɫ
	else if (fcolor == "2")setlinecolor(RGB(255, 177, 139));//���������ɫΪ��ɫ
	else if (fcolor == "3")setlinecolor(RGB(255, 107, 71));//���������ɫΪ��ɫ



	//���ư�ť�߿�
	circle(btn.x, btn.y, 30);
	//���������ɫ
	if (fcolor == "1")setfillcolor(RGB(230, 230, 230));
	else if (fcolor == "2")setfillcolor(RGB(255, 177, 139));
	else if (fcolor == "3")setfillcolor(RGB(255, 107, 71));
	else if (fcolor == "4")setfillcolor(RGB(191, 255, 216));

	fillcircle(x, y, 30);
	//���ð�ť����
	setbkmode(TRANSPARENT);//����͸������

	//�����ı���ɫ
	if (fcolor == "1")settextcolor(RGB(92, 92, 92));//���������ɫΪ��ɫ
	else if (fcolor == "2")settextcolor(RGB(92, 92, 92));//���������ɫΪ��ɫ
	else if (fcolor == "3")settextcolor(RGB(92, 92, 92));//���������ɫΪ��ɫ
	else if (fcolor == "4")settextcolor(RGB(92, 92, 92));

	//settextcolor(BLUE);//����������ɫ
	settextstyle(30, 15, _T("����"));//���������ʽ
	outtextxy(x - 7.5 * _tcslen(text), y - 15, text);//������ʾλ��
	EndBatchDraw();


	//�ָ����ߺ������ɫ
	setlinecolor(WHITE);
	setfillcolor(WHITE);
}
