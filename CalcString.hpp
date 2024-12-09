/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-16 08:17:59
 * @LastEditTime : 2024-12-03 09:58:47
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : CalcString.hpp
 * @     © 2024 FeiYehua
 */
//
/*******************************************************************************

        File name:     HandleSwiftInput.h
        Author:        FeiYehua

        Description:   Created for Calculator in 2024

        History:
                2024/10/16: File created.

********************************************************************************/

#ifndef CalcString_hpp
#define CalcString_hpp
extern "C"
{
#include "ParseMathExpression.h"
#include "GetValue.h"
}
#include <sstream>
#include <string>
#include <iostream>
int getStringValue(std::string, std::string *, double, double *);
// //使用该函数：
// 第一个参数是传入的被计算数字符串；
// 第二个参数是一个字符串指针，用于接收结果字符串；
// 第三个参数是表达式中x的取值；如果没有x，传任意一个double即可
// 第四个参数是传出的结果浮点值
// 函数的返回值是函数的执行状态。如果函数执行时出现错误，如除数为0、反三角函数超过定义域，返回-1；正常结束返回0
#endif /* CalcString_h */
