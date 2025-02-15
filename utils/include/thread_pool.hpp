#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <queue>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include <future>

class ThreadPool {
public:
    ThreadPool(int thread_num) {};

    ~ThreadPool() {};


    template<typename F , typename... Args>
    auto add_task(F&& f , Args&&... args)
    ->std::future<typename std::result_of<F(Args...)>::type>{};

    

private:
    void worker();

    bool is_available;
    std::condition_variable cv;
    std::mutex mtx;
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> task_queue;


};





#endif // THREAD_POOL_HPP