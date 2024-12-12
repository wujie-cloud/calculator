/***
 * @Author       : FeiYehua
 * @Date         : 2024-12-09 18:45:25
 * @LastEditTime : 2024-12-09 20:14:14
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : ToBeCalculatedExpression.cpp
 * @     © 2024 FeiYehua
 */
#include "ToBeCalculatedExpression.hpp"

void ToBeCalculatedExpression::removeLast()
{
    if (!addedItem.empty())
    {
        soundPlayPool.playSound("CLC");
        toBeCalculatedString.erase(toBeCalculatedString.length() - addedItem.back().length());
        addedItem.pop_back();
    }
}

void ToBeCalculatedExpression::addNext(const std::string &addedString)
{
    std::string mutableAddedString = addedString;
    checkIfMultiplicationIsOmitted(&mutableAddedString);
    soundPlayPool.playSound(addedString);
    addedItem.push_back(mutableAddedString);
    toBeCalculatedString += mutableAddedString;
}

void ToBeCalculatedExpression::removeAll()
{
    soundPlayPool.playSound("AC");
    addedItem.clear();
    toBeCalculatedString = "";
}
bool ToBeCalculatedExpression::operator+(const std::string &rhs) // const
{
    // ToBeCalculatedExpression result = lhs;
    this->addNext(rhs);
    return this;
}
void ToBeCalculatedExpression::operator+=(const std::string &rhs)
{
    this->addNext(rhs);
}
void ToBeCalculatedExpression::operator=(const std::string &rhs)
{
    if (rhs == "")
    {
        this->removeAll();
    }
}

bool ToBeCalculatedExpression::isDigitsOnly(const std::string &string)
{
    for (char c : string)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

void ToBeCalculatedExpression::checkIfMultiplicationIsOmitted(std::string *addedString)
{
    if (!addedItem.empty())
    {
        const std::string &lastAddedString = addedItem.back();
        bool isLastValid = validStrings.end() != std::find(validStrings.begin(), validStrings.end(), lastAddedString);
        bool isCurrentInvalid = invalidStrings.end() != std::find(invalidStrings.begin(), invalidStrings.end(), (*addedString).front());
        bool isDigitsOnly = this->isDigitsOnly(lastAddedString);

        if ((isLastValid || isDigitsOnly) && !isCurrentInvalid)
        {
            soundPlayPool.playSound("*");
            (*addedString).insert(0, "*");
        }
    }
}

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