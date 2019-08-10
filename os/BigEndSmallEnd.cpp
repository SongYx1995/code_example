// figure out bigEnd or smallEnd
#include<iostream>
int main() {
	int a = 0x12345678;
	char* b = reinterpret_cast<char*> (&a);
	std::cout << "begin:" << b[0]-0;
}