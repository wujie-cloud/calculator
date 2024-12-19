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

void soundPlayPool::addMusicToThreadPool(const std::string& soundFileName)//将需要播放的音频添加到线程池中
{
    soundPlayThread.push_back(std::thread(&soundPlayPool::playSound, this, pathToFile[soundFileName]));
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
    for(auto &thread:stringPlayThread)
    {
        if(thread.joinable())
        {
            thread.join();
        }
    }
}

void soundPlayPool::playString(const std::string& string)
{

    //std::queue<char> soundPlayQueue；
    //将整个字符串中每一个数逐个取出播放
    stringPlayThread.push_back(std::thread(&soundPlayPool::playSoundThread,this,string));
}
void soundPlayPool::playSoundThread(const std::string& string)
{
    for(char c:string)
    {
        std::string tstr(1,c);
        //std::wstring ws = pathToFile[tstr];
        if(tstr=="-")
        {
            soundPlayThread.push_back(std::thread(&soundPlayPool::playSound, this, pathToFile["--"]));
            continue;
        }
        soundPlayThread.push_back(std::thread(&soundPlayPool::playSound, this, pathToFile[tstr]));
        // playSound(ws);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        if(tstr=="=")
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
}
int soundPlayPool::playSound(const std::wstring& pathToMusic)
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

#if 0
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