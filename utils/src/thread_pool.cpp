#ifndef THREAD_POOL_CPP
#define THREAD_POOL_CPP

#include "thread_pool.hpp"

ThreadPool::ThreadPool(int thread_num):is_available(true){
    for(int i=0;i<thread_num;i++){
        workers.emplace_back([this](){
            this->worker();
        });
    }
}

template <typename F, typename... Args>
auto ThreadPool::add_task(F&& f, Args&&... args)
->std::future<typename std::result_of<F(Args...)>::type>{
    using functype = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<functype()>>
    (std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<functype> res = task->get_future();
    
    {
        std::lock_guard<std::mutex> lockguard(this->mtx);
        if(!is_available){
            throw std::runtime_error("ThreadPool is not available");
        }

        task_queue.emplace([task](){
            (*task)();
        });
    }

    cv.notify_one();
    return res;
}


void ThreadPool::worker(){
    
    std::function<void()> task;

    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock,[this]{
            return !is_available || !task_queue.empty();
        });
        if (!is_available && task_queue.empty()){
            return;
        }
        task = std::move(task_queue.front());
        task_queue.pop();
    }
    task();


}
ThreadPool::~ThreadPool(){
    {
        std::unique_lock<std::mutex> lock(mtx);
        is_available = false;
    }
    cv.notify_all();
    for(auto &worker:workers){
        worker.join();
    }
}


#endif // THREAD_POOL_CPP