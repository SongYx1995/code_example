#include <list>
#include <algorithm>
#include <mutex>
#include <thread>

std::list<int> m_list;
std::mutex m_mutex;

void AddToList(int new_value) {
    std::lock_guard<std::mutex> guard(m_mutex);
    m_list.push_back(new_value);
}

bool FindValue(int value_to_find) {
    std::lock_guard<std::mutex> guard(m_mutex);
    return find(m_list.begin(), m_list.end(), value_to_find) != m_list.end();
}

int main() {
    std::thread t1(AddToList, 3);
    std::thread t2(FindValue, 3);
    t1.join();
    t2.join();

}