/***
 * @Author       : FeiYehua
 * @Date         : 2024-12-15 11:48:24
 * @LastEditTime : 2024-12-15 11:48:24
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : DrawExpressionAndResult.cpp
 * @     © 2024 FeiYehua
 */
#include "DrawExpressionAndResult.hpp"
void drawExpression(std::string exp)
{
	TCHAR s[1000];
    swprintf_s(s, _T("%ls"), stringToWString(exp).c_str());
    outtextxy(0, 0, s);
}
void drawResult(std::string res)
{
	TCHAR s[1000];
    swprintf_s(s, _T("%ls"), stringToWString(res).c_str());
    outtextxy(0, 35, s);
}