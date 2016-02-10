#include <iostream>
#include <bitset>
#include <type_traits>
#include <string>

struct Packet {
	std::bitset<32> src;
	std::bitset<32> dest;
	std::bitset<7> time[3];
};

int main() {
	int N;
	std::cin >> N;

	Packet current;
	for (int i = 0; i < N; ++i) {

	}

	return 0;
}