/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-09 20:12:13
 * @LastEditTime : 2024-12-16 21:32:04
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : ToBeCalculatedExpression.hpp
 * @     © 2024 FeiYehua
 */
#ifndef ToBeCalculatedExpression_hpp
#define ToBeCalculatedExpression_hpp
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "PlayAudio.hpp"
//管理将要计算表达式的类。
class ToBeCalculatedExpression {
public:
    std::string toBeCalculatedString;
    ToBeCalculatedExpression() : toBeCalculatedString(""), addedItem() {}//类初始化函数

    void removeLast();//移除上一个添加的字符串
    void addNext(const std::string &addedString);//加入一个新字符
    void removeAll();//清空表达式函数
    void join();
    bool canBeCalculated();

    void operator+(const std::string &rhs);//重载相关运算符，方便操作
    void operator+=(const std::string &rhs);
    void operator=(const std::string &rhs);

private:
    std::vector<std::string> addedItem;
    const std::vector<char> invalidStrings = { '*', '+', '-', '/', '^', ')', '.' };
    const std::vector<std::string> validStrings = { "pi", "e" ,"("};
    const std::vector<std::string> invalidEndString = { "(","*","+","-","/",".","^" };
    soundPlayPool soundPlayPool;
    bool isDigitsOnly(const std::string &string);//判断添加的字符是否仅为数字组成
    void checkIfMultiplicationIsOmitted(std::string *addedString);//检查是否有被忽略的*乘号。如果有，则自动补上。
};
#endif