/***
 * @Author       : FeiYehua
 * @Date         : 2024-12-10 17:11:05
 * @LastEditTime : 2024-12-11 23:50:15
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : PlayAudio.cpp
 * @     © 2024 FeiYehua
 */
#include "PlayAudio.hpp"
#pragma comment(lib, "winmm.lib")

void soundPlayPool::playSound(std::string soundFileName)
{
    soundPlayThread.push_back(std::thread(&soundPlayPool::addMusicToThreadPool, this, pathToFile[soundFileName]));
}
void soundPlayPool::join()
{
    for (auto &thread : soundPlayThread)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }
}

int soundPlayPool::addMusicToThreadPool(std::wstring pathToMusic)
{
    // pathToMusic=L"C:\\Users\\xiong\\Downloads\\target-win64\\Release\\Assets\\divide.mp3";
    std::wstring sciCommand = L"open " + pathToMusic;
    mciSendStringW(sciCommand.c_str(), NULL, 0, NULL);
    sciCommand = L"play " + pathToMusic + L" wait";
    mciSendStringW(sciCommand.c_str(), NULL, 0, NULL);
    sciCommand = L"close " + pathToMusic;
    mciSendStringW(sciCommand.c_str(), NULL, 0, NULL);
    return 0;
}
#ifdef 0
int main(int argc, char *argv[])
{
    // srand(time(NULL));
    soundPlayPool test;
    // std::vector<std::string> str;
    // for(int i=1;i<argc;i++)
    // {
    //     str.push_back(argv[i]);
    // }
    // for(int i=1;i<argc;i++)
    // {
    //     //std::wstring ws(str[i-1].begin(),str[i-1].end());
    //     test.playSound(ws);
    // }
    while (1)
    {
        std::string s;
        std::cin >> s;
        test.playSound(s);
    }
    test.join();
}
#endif