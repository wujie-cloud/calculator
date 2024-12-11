/***
 * @Author       : FeiYehua
 * @Date         : 2024-12-09 18:45:25
 * @LastEditTime : 2024-12-09 20:14:14
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : ToBeCalculatedExpression.cpp
 * @     © 2024 FeiYehua
 */
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include"ToBeCalculatedExpression.hpp"
class ToBeCalculatedExpression
{
public:
    std::string toBeCalculatedString;
    std::vector<std::string> addedItem;
    const std::vector<char> invalidStrings = {'*', '+', '-', '/', '^', ')', '.'};
    const std::vector<std::string> validStrings = {"pi", "e"};

    ToBeCalculatedExpression() : toBeCalculatedString(""), addedItem() {}

    void removeLast()
    {
        if (!addedItem.empty())
        {
            toBeCalculatedString.erase(toBeCalculatedString.length() - addedItem.back().length());
            addedItem.pop_back();
        }
    }

    void addNext(const std::string &addedString)
    {
        std::string mutableAddedString = addedString;
        checkIfMultiplicationIsOmitted(&mutableAddedString);
        addedItem.push_back(mutableAddedString);
        toBeCalculatedString += mutableAddedString;
    }

    void removeAll()
    {
        addedItem.clear();
        toBeCalculatedString = "";
    }
    bool operator+(const std::string &rhs) // const
    {
        // ToBeCalculatedExpression result = lhs;
        this->addNext(rhs);
        return this;
    }
    void operator+=(const std::string &rhs)
    {
        this->addNext(rhs);
    }
    void operator=(const std::string &rhs)
    {
        if (rhs == "")
        {
            this->removeAll();
        }
    }

private:
    bool isDigitsOnly(const std::string &string)
    {
        for (char c : string)
        {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    void checkIfMultiplicationIsOmitted(std::string *addedString)
    {
        if (!addedItem.empty())
        {
            const std::string &lastAddedString = addedItem.back();
            bool isLastValid = validStrings.end() != std::find(validStrings.begin(), validStrings.end(), lastAddedString);
            bool isCurrentInvalid = invalidStrings.end() != std::find(invalidStrings.begin(), invalidStrings.end(), (*addedString).front());
            bool isDigitsOnly = this->isDigitsOnly(lastAddedString);

            if ((isLastValid || isDigitsOnly) && !isCurrentInvalid)
            {
                (*addedString).insert(0, "*");
            }
        }
    }
};

// ToBeCalculatedExpression operator+(const ToBeCalculatedExpression& lhs, const std::string& rhs) {
//     ToBeCalculatedExpression result = lhs;
//     result.addNext(rhs);
//     return result;
// }
#if 0
int main()
{
    ToBeCalculatedExpression expression1;
    expression1.addNext("2");
    expression1.addNext("+");
    expression1.addNext("3");
    // expression1.addNext("sin(");
    expression1 += "sin(";
    // ToBeCalculatedExpression expression2;
    // expression2.addNext("3");

    // ToBeCalculatedExpression finalExpression = expression1 + "3";
    std::cout << expression1.toBeCalculatedString + "3" << std::endl; // 输出 "2*+3"

    return 0;
}
#endif