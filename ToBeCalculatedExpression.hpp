/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-09 20:12:13
 * @LastEditTime : 2024-12-12 09:08:39
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

class ToBeCalculatedExpression {
public:
    std::string toBeCalculatedString;
    std::vector<std::string> addedItem;
    const std::vector<char> invalidStrings = {'*', '+', '-', '/', '^', ')', '.'};
    const std::vector<std::string> validStrings = {"pi", "e"};
    soundPlayPool soundPlayPool;
    ToBeCalculatedExpression() : toBeCalculatedString(""), addedItem() {}

    void removeLast();
    void addNext(const std::string &addedString);
    void removeAll();
    void join();
    
    void operator+(const std::string &rhs);
    void operator+=(const std::string &rhs);
    void operator=(const std::string &rhs);

private:
    bool isDigitsOnly(const std::string &string);
    void checkIfMultiplicationIsOmitted(std::string *addedString);
};
#endif