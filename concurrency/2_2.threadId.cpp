#include <iostream>
#include <thread>

std::thread::id main_id;
void Task()
{
    if (std::this_thread::get_id() == main_id)
        std::cout << "main thread\n"
                  << main_id << std::endl;
    else
        std::cout << "sub thread\n"
                  << std::this_thread::get_id() << std::endl;
}
int main()
{
    main_id = std::this_thread::get_id();
    std::thread t(Task);
    Task();
    t.join();
}