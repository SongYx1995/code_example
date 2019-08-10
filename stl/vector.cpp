#include<iostream>
#include<vector>
int main(){
    std::vector<int> a=std::vector<int>{1,2,3}; //匿名vector ，列表初始化，OK
    std::cout<<a[0];
}