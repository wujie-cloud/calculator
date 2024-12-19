/***
 * @Author       : FeiYehua
 * @Date         : 2024-12-15 10:10:53
 * @LastEditTime : 2024-12-15 10:10:55
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : IdleMonitor.hpp
 * @     © 2024 FeiYehua
 */
#ifndef IDLEMONITOR_HPP
#define IDLEMONITOR_HPP
// 考虑封装计时与绘制时间模块。
#include <thread>
#include <atomic>
#include <ctime>
#include "DrawTime.hpp"
// 为了实现在无操作60秒后开始绘制时间，需要另外拉一个线程出来计时，
// 因为显然如果没有动作，就会卡在getmessage那一句话。
// 每次获取到消息后，就将计时器停止。
class IdleMonitor
{
public:
    IdleMonitor(int);//类初始化函数，主要是设置类stopFlag的值
    std::atomic<bool> stopFlag;
    ~IdleMonitor()//析构函数，安全结束线程
    {
        join();
    }
    
private:
    std::thread thread; // 线程池
    int idleTime;
    int startTime;
    void join();//线程结束函数
    void timeKeeper(); // 计时器，此函数会drawTime函数绘制时间
};

#endif // IDLEMONITOR_HPP
