/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-10 17:11:05
 * @LastEditTime : 2024-12-11 20:17:17
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : PlayAudio.cpp
 * @     © 2024 FeiYehua
 */
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <windows.h>
#include <mciapi.h>
#include <map>
#include"PlayAudio.hpp"
#pragma comment(lib, "winmm.lib")

class soundPlayPool
{
public:
    void playSound(std::string soundFileName)
    {
        soundPlayThread.push_back(std::thread(&soundPlayPool::addMusicToThreadPool,this, pathToFile[soundFileName]));
    }
    void join()
    {
        for (auto &thread : soundPlayThread)
        {
            if (thread.joinable())
            {
                thread.join();
            }
        }
    }

private:
    std::vector<std::thread> soundPlayThread;
    std::map<std::string, std::wstring> pathToFile = {
        {"1", L".\\Assets\\num1.mp3"},
        {"2", L".\\Assets\\num2.mp3"},
        {"3", L".\\Assets\\num3.mp3"},
        {"4", L".\\Assets\\num4.mp3"},
        {"5", L".\\Assets\\num5.mp3"},
        {"6", L".\\Assets\\num6.mp3"},
        {"7", L".\\Assets\\num7.mp3"},
        {"8", L".\\Assets\\num8.mp3"},
        {"9", L".\\Assets\\num9.mp3"},
        {"0", L".\\Assets\\num0.mp3"},
        {"+", L".\\Assets\\plus.mp3"},
        {"-", L".\\Assets\\minus.mp3"},
        {"*", L".\\Assets\\multiply.mp3"},
        {"/", L".\\Assets\\divide.mp3"},
        {"sin", L".\\Assets\\sin.mp3"},
        {"cos", L".\\Assets\\cos.mp3"},
        {"arcsin", L".\\Assets\\arcsin.mp3"},
        {"arccos", L".\\Assets\\arccos.mp3"},
        {"^", L".\\Assets\\power.mp3"},
        {"pi", L".\\Assets\\pi.mp3"},
        {".", L".\\Assets\\point.mp3"},
        {"=", L".\\Assets\\equal.mp3"},
        {"AC", L".\\Assets\\AC.mp3"},
        {"CLC", L".\\Assets\\CLC.mp3"},
        {"ln", L".\\Assets\\ln.mp3"},
        
    };
    int addMusicToThreadPool(std::wstring pathToMusic)
    {
        //pathToMusic=L"C:\\Users\\xiong\\Downloads\\target-win64\\Release\\Assets\\divide.mp3";
        std::wstring sciCommand = L"open " + pathToMusic;
        mciSendStringW(sciCommand.c_str(), NULL, 0, NULL);
        sciCommand = L"play " + pathToMusic + L" wait";
        mciSendStringW(sciCommand.c_str(), NULL, 0, NULL);
        sciCommand = L"close " + pathToMusic;
        mciSendStringW(sciCommand.c_str(), NULL, 0, NULL);
        return 0;
    }
};
#if 0
int main(int argc,char* argv[])
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
    while(1)
    {
        std::string s;
        std::cin>>s;
        test.playSound(s);
    }
    test.join();
}
#endif