#include<iostream>
#include<ext/hash_map>
#include<ext/hash_set>
int main(){
    __gnu_cxx::hash_set<int> s;
    s.insert(1);
    if(s.find(1)!=s.end())
        std::cout<<"find";
    s.
}