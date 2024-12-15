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
        soundPlayPool.addMusicToThreadPool("CLC");
        toBeCalculatedString.erase(toBeCalculatedString.length() - addedItem.back().length());
        addedItem.pop_back();
    }
}

void ToBeCalculatedExpression::addNext(const std::string &addedString)
{
    std::string mutableAddedString = addedString;
    checkIfMultiplicationIsOmitted(&mutableAddedString);
    soundPlayPool.addMusicToThreadPool(addedString);
    addedItem.push_back(mutableAddedString);
    toBeCalculatedString += mutableAddedString;
}

void ToBeCalculatedExpression::removeAll()
{
    soundPlayPool.addMusicToThreadPool("AC");
    addedItem.clear();
    toBeCalculatedString = "";
}
void ToBeCalculatedExpression::join()
{
    soundPlayPool.join();
}

void ToBeCalculatedExpression::operator+(const std::string &rhs) // const
{
    // ToBeCalculatedExpression result = lhs;
    this->addNext(rhs);
    //return this;
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

        if ((isLastValid || isDigitsOnly) && !isCurrentInvalid && !this->isDigitsOnly(*addedString))
        {
            soundPlayPool.addMusicToThreadPool("*");
            (*addedString).insert(0, "*");
        }
    }
}

// ToBeCalculatedExpression operator+(const ToBeCalculatedExpression& lhs, const std::string& rhs) {
//     ToBeCalculatedExpression result = lhs;
//     result.addNext(rhs);
//     return result;
// }
