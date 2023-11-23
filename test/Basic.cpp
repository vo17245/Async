#include "Async/ThreadPool.h"
#include <chrono>
#include <iostream>
#include <thread>
void task(int val)
{
    std::cout<<"val="<<val<<std::endl;;
}
int main()
{
    ThreadPool threadpool(4);
    threadpool.enqueue([](){task(0);});
    threadpool.enqueue([](){task(1);});
    threadpool.enqueue([](){task(2);});
    threadpool.enqueue([](){task(3);});
    threadpool.enqueue([](){task(4);});
    threadpool.enqueue([](){task(5);});
    threadpool.shutdown();


}