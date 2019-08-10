#include<iostream>

class allocator{
public:
	allocator();
	~allocator();
};
allocator::allocator() {
	std::cout << "construct";
}
allocator::~allocator() {
	std::cout << "destory";
}
int main() {
	allocator a;
}