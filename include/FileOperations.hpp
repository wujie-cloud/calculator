/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-10 16:22:05
 * @LastEditTime : 2024-12-10 16:22:07
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : FileOperations.hpp
 * @     © 2024 FeiYehua
 */
#ifndef FILE_OPERATIONS_HPP
#define FILE_OPERATIONS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void writeToFile(const std::string &filename, const std::string &content);//将conten的内容写入到文件filename
void readFromFile(const std::string &filename, std::vector<std::string> *targetList);//将filename的内容读取到targetList中

#endif // FILE_OPERATIONS_H