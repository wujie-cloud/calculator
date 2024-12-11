#include <windows.h>
#include <mciapi.h>
#include <iostream>
#include<mmsystem.h>

#pragma comment(lib, "winmm.lib")

DWORD WINAPI PlayMp3Thread(LPVOID lpParam) {
    const char* mp3FilePath = (const char*)lpParam;
    if (!mp3FilePath || strlen(mp3FilePath) == 0) {
        return 1;
    }

    std::string mciString = "open " + std::string(mp3FilePath);
    if (mciSendStringA(mciString.c_str(), NULL, 0, NULL) != 0) {
        std::cerr << "Error opening MP3 file: " << mp3FilePath << std::endl;
        return 1;
    }

    mciString = "play " + std::string(mp3FilePath);
    if (mciSendStringA(mciString.c_str(), NULL, 0, NULL) != 0) {
        std::cerr << "Error playing MP3 file: " << mp3FilePath << std::endl;
        return 1;
    }

    // Wait for the playback to finish
    mciString = "wait " + std::string(mp3FilePath);
    if (mciSendStringA(mciString.c_str(), NULL, 0, NULL) != 0) {
        std::cerr << "Error waiting for MP3 file to finish: " << mp3FilePath << std::endl;
        return 1;
    }

    mciString = "close " + std::string(mp3FilePath);
    if (mciSendStringA(mciString.c_str(), NULL, 0, NULL) != 0) {
        std::cerr << "Error closing MP3 file: " << mp3FilePath << std::endl;
        return 1;
    }
    return 0;
}
int playMusic(std::wstring pathToMusic)
{
    std::wstring sciCommand = L"open " + pathToMusic;
    mciSendString(sciCommand.c_str(), NULL, 0, NULL);
    sciCommand = L"play " + pathToMusic + L" wait";
    mciSendString(sciCommand.c_str(), NULL, 0, NULL);
    sciCommand = L"close " + pathToMusic;
    mciSendString(sciCommand.c_str(), NULL, 0, NULL);
    return 0;
}
int main() {
    const char* mp3FilePath = "C:\\Users\\xiong\\calculator\\Assets\\num1.mp3";

    //HANDLE hThread;
    //DWORD threadId;

    //hThread = CreateThread(NULL, 0, PlayMp3Thread, (LPVOID)mp3FilePath, 0, &threadId);

    //if (hThread == NULL) {
    //    std::cerr << "Failed to create thread: " << GetLastError() << std::endl;
    //    return 1;
    //}

    //// Wait for the thread to finish
    //WaitForSingleObject(hThread, INFINITE);

    //CloseHandle(hThread);
    //mciSendString(L"open C:\\Users\\xiong\\calculator\\Assets\\num1.mp3", NULL, 0, NULL);
    //mciSendString(L"play C:\\Users\\xiong\\calculator\\Assets\\num1.mp3 wait", NULL, 0, NULL);
    ////mciSendString(L"wait", NULL, 0, NULL);
    //mciSendString(L"close C:\\Users\\xiong\\calculator\\Assets\\num1.mp3", NULL, 0, NULL);
    playMusic(L"C:\\Users\\xiong\\calculator\\Assets\\num1.mp3");
    //Sleep(3000);
    return 0;
}
