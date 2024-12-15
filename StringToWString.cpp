/***
 * @Author       : FeiYehua
 * @Date         : 2024-12-15 11:36:57
 * @LastEditTime : 2024-12-15 11:39:43
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : StringToWString.cpp
 * @     © 2024 FeiYehua
 */
// convert_from_char.cpp
// compile with: /clr /Zc:twoPhase- /link comsuppw.lib
#include "StringToWString.hpp"

using namespace std;
// using namespace System;

std::wstring stringToWString(std::string a)
{
    // Create and display a C-style string, and then use it
    // to create different kinds of strings.
    const char *orig = a.c_str();
    // cout << orig << " (char *)" << endl;

    // newsize describes the length of the
    // wchar_t string called wcstring in terms of the number
    // of wide characters, not the number of bytes.
    size_t newsize = strlen(orig) + 1;

    // The following creates a buffer large enough to contain
    // the exact number of characters in the original string
    // in the new format. If you want to add more characters
    // to the end of the string, increase the value of newsize
    // to increase the size of the buffer.
    wchar_t *wcstring = new wchar_t[newsize];

    // Convert char* string to a wchar_t* string.
    size_t convertedChars = 0;
    mbstowcs_s(&convertedChars, wcstring, newsize, orig, _TRUNCATE);
    // Display the result and indicate the type of string that it is.
    // wcout << wcstring << L" (wchar_t *)" << endl;
    wstring res(wcstring);
    // wcout << res << endl;
    delete[] wcstring;
    return res;
}