#include<iostream>
#include<vector>
template<typename T>
class autoptr {
	T* pointer;
public:
	autoptr(T* p) {
		this->pointer = p;
	}
	~autoptr() {
		delete pointer;
		std::cout << "delete";
	}
};
int main() {
	autoptr<int> p(new int(3));
}