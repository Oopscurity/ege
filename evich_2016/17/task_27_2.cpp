#include <iostream>
#include <string>
#include <set>

int main() {
	std::set<std::string> users ({ "vasya", "artyom", "petya" });
	for (auto it = users.begin(); it != users.end(); ++it) {
		std::cout << *it << '\n';
	}
	return 0;
}