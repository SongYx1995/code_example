#include<iostream>
#include<mutex>
#include<thread>

std::mutex m;
int max=10;
int num;
void consume(){
    while(true){
    if(num<10){
        std::lock_guard<std::mutex> loc(m);
        // m.lock();
        num++;
        std::cout<<"produce========="<<num<<std::endl;
        // m.unlock();
    }
    }

}
void produce(){
    while(true){
    if(num>0){
        std::lock_guard<std::mutex> loc(m);
        // m.lock();
        num--;
        std::cout<<"consume----------"<<num<<std::endl;
        // m.unlock();
    }
    }
}
int main(){
    std::thread consumer(consume);
    std::thread producer(produce);
    consumer.join();
    producer.join();
}