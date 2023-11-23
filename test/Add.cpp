#include "Async/ThreadPool.h"
#include <chrono>
#include <iostream>
#include <thread>
std::atomic<int> a(0);
int b=0;
void task_a(){a++;}
void task_b(){b++;}
int main()
{
    
    ThreadPool threadpool(4);
    for(size_t i=0;i<100000;i++)
    {
        threadpool.enqueue(task_a);
        threadpool.enqueue(task_b);
    }
    
    
    threadpool.shutdown();
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
}