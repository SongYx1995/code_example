#include<iostream>
int main() {
	try {
		throw std::exception("123");
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}