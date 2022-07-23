#pragma once
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

// 用于（多线程）异步写日志的队列
template <typename T>
class LockQueue {
  public:
    // 可能存在多个worker线程都会（Push）写queue
    void Push(const T &data) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(data);
        m_condvar.notify_one();                //唤醒写日志文件的线程进行Pop
    }

    // 单线程读日志queue，写日志文件
    T Pop() {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_queue.empty())
            m_condvar.wait(lock);

        T data = m_queue.front();
        m_queue.pop();
        return data;
    }

  private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condvar;
};
