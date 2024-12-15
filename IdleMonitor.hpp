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
// 在这个类中，
#include <thread>
#include <atomic>
#include <ctime>
#include "DrawTime.hpp"
class IdleMonitor
{
public:
    IdleMonitor();
    std::atomic<bool> stopFlag(false);
    void join();
private:
    std::thread thread; // 线程池
    int startTime;
    void timeKeeper();//计时器与绘画函数
}

#endif // IDLEMONITOR_HPP