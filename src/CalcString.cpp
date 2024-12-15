#define _CRT_SECURE_NO_WARNINGS
/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-16 08:17:59
 * @LastEditTime : 2024-12-03 09:59:17
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : CalcString.cpp
 * @     © 2024 FeiYehua
 */
//
/*******************************************************************************

 File name:     HandleSwiftInput.c
 Author:        FeiYehua

 Description:   Created for Calculator in 2024

 History:
 2024/10/16: File created.

 ********************************************************************************/

#include "CalcString.hpp"

using namespace std;
int getStringValue(string toBeCalculatedString, string *resultString, double x, double *resultDouble) // 通过一个C++函数调用parseMathExpression函数，方便操作
{
    double result = 0L;
    double mathExpression[1000];
    memset(mathExpression, 0, sizeof(mathExpression));
    int locOfPri[1000], numCount = 0;
    memset(locOfPri, 0, sizeof(locOfPri));
    char toBeCalculatedCString[1000] = "";
#ifdef DEBUG
    cout << toBeCalculatedString << endl;
#endif
    strcpy(toBeCalculatedCString, toBeCalculatedString.c_str());
    parseMathExpression(toBeCalculatedCString, mathExpression, &numCount, locOfPri, x);
    getValue(mathExpression, locOfPri, numCount, &result);
    *resultDouble = result;
    if (!isinf(*resultDouble) && !isnan(*resultDouble))
    {
        // 创建 ostringstream 对象，将double转换为string
        std::ostringstream oss;

        // 设置浮点数的精度
        oss.precision(15); // 控制精度为 15 位
        oss << result;     // 将 double 写入流中

        // 获取转换后的字符串
        *resultString = oss.str();
        return 0;
    }
    else
    {
        return -1;
    }
}
