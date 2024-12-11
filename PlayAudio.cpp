/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-10 17:11:05
 * @LastEditTime : 2024-12-10 17:11:05
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : PlayAudio.cpp
 * @     © 2024 FeiYehua
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

// ���设我们有一个音频播放库，例如SDL或OpenAL
// ��里我们使用一个简单的示例函数来模拟音频播放
void playAudio(const std::string& filePath) {
    // ���拟音频播放操作
    std::cout << "Playing audio file: " << filePath << std::endl;
    // ��里可以添加实际的音频播放代码，例如使用SDL或OpenAL
    // 为了模拟播放时间，我们暂停一段时间
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

class AudioPlayer {
public:
    void addAudio(const std::string& filePath) {
        std::lock_guard<std::mutex> lock(mutex_);
        audioFiles_.push_back(filePath);
        conditionVariable_.notify_one();
    }

    void start() {
        if (thread_.joinable()) {
            thread_.join();
        }
        thread_ = std::thread(&AudioPlayer::worker, this);
    }

private:
    void worker() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex_);
            conditionVariable_.wait(lock, [this] { return !audioFiles_.empty(); });

            if (audioFiles_.empty()) {
                break;
            }

            std::string filePath = audioFiles_.front();
            audioFiles_.pop_front();

            lock.unlock();
            playAudio(filePath);
        }
    }

    std::vector<std::string> audioFiles_;
    std::thread thread_;
    std::mutex mutex_;
    std::condition_variable conditionVariable_;
};

int main() {
    AudioPlayer player;
    player.start();

    // 添加音频文件
    player.addAudio("audio1.mp3");
    player.addAudio("audio2.mp3");
    player.addAudio("audio3.mp3");

    // ���待一段时间，让音频播放完成
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}
