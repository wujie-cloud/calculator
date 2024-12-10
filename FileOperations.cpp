/***
 * @Author       : FeiYehua
 * @Date         : 2024-12-10 11:38:52
 * @LastEditTime : 2024-12-10 16:14:49
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : FileOperations.cpp
 * @     © 2024 FeiYehua
 */
#include "FileOperations.hpp"
void writeToFile(const std::string &filename, const std::string &content)
{
    std::ofstream outfile(filename, std::ios::app); // 以追加模式打开文件
    if (outfile.is_open())
    {
        outfile << content << std::endl; // 将需要写入的内容写入文件，并换行
        outfile.close();
        std::cout << "Content written to file successfully." << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void readFromFile(const std::string &filename, std::vector<std::string> *targetList)
{
    std::ifstream infile(filename); // 以读取模式打开文件
    if (infile.is_open())
    {
        std::string line;
        (*targetList).clear();
        while (getline(infile, line))
        { // 逐行读取内容
            (*targetList).push_back(line);
        }
        infile.close();
    }
    else
    {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}
#ifdef TEST
int main()
{
    std::string filename = "example.txt";
    std::string content;

    // 添加内容到文件
    content = "This is the first line.";
    writeToFile(filename, content);

    content = "This is the second line.";
    writeToFile(filename, content);

    // 从文件中读取内容
    std::vector<std::string> a;
    readFromFile(filename,&a);
    for(auto it:a)
    {
        std::cout<<it<<std::endl;
    }

    return 0;
}
#endif