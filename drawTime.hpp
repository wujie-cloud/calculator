#pragma once
#include <graphics.h>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <iostream>

void drawtime()
{

  

      
                SYSTEMTIME ti;
                GetLocalTime(&ti);
                TCHAR time[256] = { 0 };
                swprintf_s(time, _T("%u/%u/%u %u:%u:%u"), ti.wYear, ti.wMonth, ti.wDay, ti.wHour, ti.wMinute, ti.wSecond);
                outtextxy(40, 200, time);
              
    }


