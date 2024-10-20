#include "ThreadPool.hpp"

#include <memory>

namespace utils {

  ThreadPool::~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(queue_mutex);
      stop = true;
    }
    condition.notify_all();
    for (std::thread& worker : workers) {
      worker.join();
    }
  }

  ThreadPool& ThreadPool::instance() {
    static std::unique_ptr<ThreadPool> instance(new ThreadPool);

    return *instance;
  }

  void ThreadPool::worker_thread() {
    while (true) {
      std::function<void()> task;

      {
        std::unique_lock<std::mutex> lock(queue_mutex);
        condition.wait(lock, [this] { return stop || !tasks.empty(); });
        if (stop && tasks.empty())
          return;
        task = std::move(tasks.front());
        tasks.pop();
      }

      task();
    }
  }

  std::int32_t ThreadPool::worker_threads_count() const {
    return workers.size();
  }

  ThreadPool::ThreadPool() {
    auto max_thread_count = std::thread::hardware_concurrency();
    if (max_thread_count - 2 <= 0) {
      max_thread_count = 1;
    } else {
      max_thread_count -= 2;
    }

    workers.reserve(max_thread_count);
    for (std::size_t i = 0; i < max_thread_count; ++i) {
      workers.emplace_back(&ThreadPool::worker_thread, this);
    }
  }

} // utils