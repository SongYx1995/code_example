#include <iostream>
#include <thread>
#include <shared_mutex>
#include <unistd.h>

std::shared_mutex m;

void read__(const char *name)
{
    while (1)
    {
    
        m.lock_shared();
        std::cout << "read_process_" << name << " enter" << std::endl;
        sleep(2);
        std::cout << "read_process_" << name << " exit" << std::endl;
    }
}

void write__(const char *name)
{
    while (1)
    {
        m.lock();
        std::cout << "write_process_" << name << " enter" << std::endl;
        sleep(2);
        std::cout << "write_process_" << name << " exit" << std::endl;
    }
}



int main()
{
    std::thread t1(read__,"reader1");
    std::thread t2(read__,"reader2");
    std::thread t3(write__,"writer1");
    std::thread t4(write__,"writer2");

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}