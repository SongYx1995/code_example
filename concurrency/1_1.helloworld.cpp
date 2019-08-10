// Copyright NULL
// Licience NULL
// Author: syx
// This is hello world code example about c++ concurrency

#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

void PrintHelloWorld() {
	cout << "Hello Concurrency World" << endl;
}

int main() {
	thread t(PrintHelloWorld);
	t.join();
}