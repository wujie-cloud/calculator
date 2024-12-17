/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-15 10:10:43
 * @LastEditTime : 2024-12-15 16:31:36
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : IdleMonitor.cpp
 * @     © 2024 FeiYehua
 */

#include"IdleMonitor.hpp"
IdleMonitor::IdleMonitor()
{
    startTime=time(NULL);
    stopFlag.store(false);
    thread=std::thread(&IdleMonitor::timeKeeper,this);
}
void IdleMonitor::timeKeeper()
{
    while(!stopFlag.load()&&time(NULL)-startTime<5)//60秒无操作后进入显示时间模式
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    while(!stopFlag.load())//显示当前时间，每隔一秒更新一次
    {
        clearrectangle(0, 0, 600, 225);
        drawtime();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    clearrectangle(0, 200, 600, 225);
    return;
}
void IdleMonitor::join()
{
    if(thread.joinable())
    {
        thread.join();
    }
}