#include <iostream>

int main() {
	const int DIVISOR = 14;
		  int current,
		  	  firstFactor = 0,
		  	  secondFactor = 0;
	long 	  N, // by condition: all numbers
			  declControlValue, // declared, R by condition
		 	  trueControlValue = 0; // at least zero

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> current;
		if (current > firstFactor) {
			firstFactor = current;
		}
		else if (current > secondFactor) {
			secondFactor = current;
		}

		if ((firstFactor * secondFactor % DIVISOR) == 0) {
			trueControlValue = firstFactor * secondFactor;
		}
	}

	std::cin.clear();
	std::cin >> declControlValue;

	std::cout << "Вычисленное контрольное значение: " << trueControlValue << '\n';
	std::cout << "Контроль" << ((trueControlValue == declControlValue) ? " " : " не ") << "пройден";
	return 0;
}