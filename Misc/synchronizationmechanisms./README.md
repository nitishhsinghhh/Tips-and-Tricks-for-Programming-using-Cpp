# Running Dependent Processes in Parallel Using C++ Threads and Synchronization
In modern software development, it is often necessary to run processes in parallel to improve performance and efficiency. This can be particularly challenging when processes are dependent on each other's outputs. This article demonstrates how to achieve this in C++ using the Standard Library's std::thread and std::condition_variable for inter-thread communication and synchronization.

## Introduction
Consider a scenario where Process A produces an output that is used as the input for Process B, and Process B's output is subsequently used as the input for Process C. Running these processes in parallel while ensuring that the correct sequence is maintained requires careful synchronization.

### Thread-Safe Queue
To facilitate communication between these processes, a thread-safe queue is essential. The ThreadSafeQueue template class, demonstrated below, provides thread-safe push and pop operations using std::mutex and std::condition_variable.

```Cpp

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
public:
    void push(const T& value) {
        std::lock_guard<std::mutex> lock(mtx_);
        queue_.push(value);
        cond_var_.notify_one();
    }

    T wait_and_pop() {
        std::unique_lock<std::mutex> lock(mtx_);
        cond_var_.wait(lock, [this] { return !queue_.empty(); });
        T value = queue_.front();
        queue_.pop();
        return value;
    }

private:
    std::queue<T> queue_;
    std::mutex mtx_;
    std::condition_variable cond_var_;
};
```
Processes
The processes (functions) are defined to perform their respective tasks and use the ThreadSafeQueue for communication:

Process A: Produces output and pushes it to queue_ab.
Process B: Waits for input from queue_ab, processes it, and pushes the result to queue_bc.
Process C: Waits for input from queue_bc, processes it, and prints the result.

```Cpp

void process_a(ThreadSafeQueue<std::string>& output_queue) {
    std::string output = "output_from_A";
    std::cout << "Process A finished" << std::endl;
    output_queue.push(output);
}

void process_b(ThreadSafeQueue<std::string>& input_queue, ThreadSafeQueue<std::string>& output_queue) {
    std::string input = input_queue.wait_and_pop();
    std::string output = "output_from_B_based_on_" + input;
    std::cout << "Process B finished" << std::endl;
    output_queue.push(output);
}

void process_c(ThreadSafeQueue<std::string>& input_queue) {
    std::string input = input_queue.wait_and_pop();
    std::string output = "output_from_C_based_on_" + input;
    std::cout << "Process C finished" << std::endl;
    std::cout << output << std::endl;
}
```
Main Function
The main function sets up the queues for inter-thread communication and starts the threads for each process:

```Cpp

int main() {
    ThreadSafeQueue<std::string> queue_ab;
    ThreadSafeQueue<std::string> queue_bc;

    std::thread thread_a(process_a, std::ref(queue_ab));
    std::thread thread_b(process_b, std::ref(queue_ab), std::ref(queue_bc));
    std::thread thread_c(process_c, std::ref(queue_bc));

    thread_a.join();
    thread_b.join();
    thread_c.join();

    return 0;
}
```
## Explanation
Thread-Safe Queue: The ThreadSafeQueue class uses std::mutex and std::condition_variable to ensure thread safety. The push method adds an item to the queue and notifies a waiting thread, while wait_and_pop waits until an item is available in the queue before retrieving and removing it.

### Processes:
- process_a simulates some processing and pushes the result to queue_ab.
process_b waits for input from queue_ab, processes it, and pushes the result to queue_bc.
process_c waits for input from queue_bc, processes it, and prints the result.

### Threads:
- thread_a, thread_b, and thread_c run the respective process functions.
- std::ref is used to pass the queues by reference to the threads.

### Synchronization:

Each process waits for its input to be available using wait_and_pop(). This ensures that processes run in the correct sequence even though they are started simultaneously.

## Conclusion
By utilizing std::thread, std::mutex, and std::condition_variable, we can run dependent processes in parallel while maintaining the correct sequence of execution. The ThreadSafeQueue class ensures safe and synchronized communication between threads, making this approach both efficient and robust. This method can be extended to handle more complex inter-process dependencies and is a valuable tool for modern C++ developers.
