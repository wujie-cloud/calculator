/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-15 10:10:43
 * @LastEditTime : 2024-12-15 10:26:52
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : IdleMonitor.cpp
 * @     © 2024 FeiYehua
 */

#include"IdleMonitor.hpp"
IdleMonitor::IdleMonitor()
{
    startTime=time(NULL);
    thread=std::thread(timeKeeper,this);
}
IdleMonitor::timeKeeper()
{
    while(!stopFlag.load()&&time(NULL)-startTime<60)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    while(!stopFlag.load())
    {
        drawtime();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return;
}
IdleMonitor::join()
{
    if(thread.joinable())
    {
        thread.join();
    }
}