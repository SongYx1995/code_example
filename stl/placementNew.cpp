#include<iostream>
#include<new>
int main(){
    int *a = new int(1);
    new(a) int(2);
    std::cout<<*a;
}