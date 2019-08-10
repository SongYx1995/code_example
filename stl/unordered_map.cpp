#include<iostream>
#include<unordered_map>
int main() {
	std::unordered_map<int, int> m;
	m.insert(std::pair<int, int>(1, 1));
	m.insert(std::pair<int, int>(1, 2));
	auto it = m.find(1);
	std::cout << it->second;
}