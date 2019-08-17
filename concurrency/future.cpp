#include <future>
#include <iostream>
#include <thread>

bool is_prime(long int n){
    for(long int i=2;i<n;i++){
        if(n==i+1)
            return false;
    }
    return true;
}


int main(){
    std::future<bool> fut = std::async(is_prime,70000001L);
    std::cout<<"Please wait";
    std::chrono::milliseconds span(100);
    while(fut.wait_for(span)!=std::future_status::ready)
        std::cout<<".";
    std::cout<<std::endl;
    bool ret=fut.get();
    std::cout<<"final result: "<<ret<<std::endl;
    return 0;
}