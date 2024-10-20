#ifndef __TECHTASK_SOURCES_UTILS_THREADPOOL_HPP__
#define __TECHTASK_SOURCES_UTILS_THREADPOOL_HPP__

#include <functional>
#include <future>
#include <queue>
#include <thread>
#include <vector>
#include <cinttypes>

namespace utils {

  class ThreadPool {
  public:
    ~ThreadPool();

    static ThreadPool& instance();

    template <class F> void enqueue(F&& f) {
      {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.emplace(std::forward<F>(f));
      }
      condition.notify_one();
    }

    std::int32_t worker_threads_count() const;

  private:
    ThreadPool();

  private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;

    void worker_thread();
  };

} // utils

#endif // __TECHTASK_SOURCES_UTILS_THREADPOOL_HPP__