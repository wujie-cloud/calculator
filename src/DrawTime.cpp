/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-15 09:10:16
 * @LastEditTime : 2024-12-15 09:17:59
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : drawTime.cpp
 * @     © 2024 FeiYehua
 */
#include "DrawTime.hpp"
void drawtime()
{

    SYSTEMTIME ti;
    GetLocalTime(&ti);
    TCHAR time[256] = {0};
    swprintf_s(time, _T("%u/%u/%u %02d:%02d:%02d"), ti.wYear, ti.wMonth, ti.wDay-8, ti.wHour, ti.wMinute, ti.wSecond);
    outtextxy(40, 180, time);
}