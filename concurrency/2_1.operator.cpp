// Copyright NULL
// Licience NULL
// Author: syx
// This is hello world code example about c++ concurrency

#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

class BackGroundTask {
public:
	void operator() () {
		cout << "HelloWorld" << endl;
	}

};

int main() {
	BackGroundTask task;
	thread t(task);
	t.join();

	// wrong
	//thread t2(BackGroundTask());
	//t2.join();

}