#include <iostream>

int main() {
	const int DIVISOR              = 14,
		  DIVISOR_FIRST_FACT   = 2,
		  DIVISOR_SEC_FACT     = 7;
	      int current,
		  maxNumber            = 0,
		  maxDivToSelf         = 0, // divided to DIVISOR itself
		  maxDivToFirstFactor  = 0,
		  maxDivToSecondFactor = 0;
	     long N, // by condition: all numbers
		  maxDivToSelfIndex    = 0;

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> current;
		
		if ((current % DIVISOR == 0) && (current > maxDivToSelf)) {
			maxDivToSelf = current;
			maxDivToSelfIndex = i;
		} else
			if ((current % DIVISOR_FIRST_FACT == 0) && (current > maxDivToFirstFactor)) {
				maxDivToFirstFactor = current;
			} else
				if ((current % DIVISOR_SEC_FACT == 0) && (current > maxDivToSecondFactor)) {
					maxDivToSecondFactor = current;
				}

		if ((maxDivToSelfIndex != i) && (current > maxNumber)) { // to prevent dublicates of one element
			maxNumber = current;
		}
	}

	long possibleByFactors,
	     possibleByMultiply,
	     declControlValue, // declared, R by condition
	     trueControlValue = 0; // countable; at least zero

	possibleByFactors = maxDivToFirstFactor * maxDivToSecondFactor;
	possibleByMultiply = maxDivToSelf * maxNumber;
	trueControlValue = (possibleByFactors > possibleByMultiply) ? possibleByFactors : possibleByMultiply;

	std::cin.clear();
	std::cin >> declControlValue;

	std::cout << "Вычисленное контрольное значение: " << trueControlValue << '\n';
	std::cout << "Контроль" << ((trueControlValue == declControlValue) ? " " : " не ") << "пройден";
	return 0;
}