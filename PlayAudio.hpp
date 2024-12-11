/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-11 20:16:09
 * @LastEditTime : 2024-12-11 20:17:33
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : PlayAudio.hpp
 * @     © 2024 FeiYehua
 */
#ifndef PlayAudio_HPP
#define PlayAudio_HPP

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <windows.h>
#include <mciapi.h>
#include <map>

class soundPlayPool {
public:
   void playSound(const std::string& soundFileName);
   void join();

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
       {"ln", L".\\Assets\\ln.mp3"}
   };

   int addMusicToThreadPool(const std::wstring& pathToMusic);
};

#endif // PlayAudio_H