#include <iostream>

int main() {
    const int DEVISOR = 3,
              MIN_TIME_INTERVAL = 5,
              ERROR_CODE = 0;
    int N,
        // lastIndex,
        min = 1001,
        minDivToSelf = 1001,
        minDivToSelfIndex;

    std::cin >> N;

    int current,
        currentIndex;
    for (int i = 0; i < N; ++i) {
	std::cin >> current;
        currentIndex = i;

        if ((current % DEVISOR == 0) && (current < minDivToSelf)) {
            minDivToSelf = current;
            minDivToSelfIndex = i;
        }
        if ((i - minDivToSelfIndex >= MIN_TIME_INTERVAL) && (current < min)) {
             min = current;
        }
    }

    std::cout << ((minDivToSelf < 1001) ? (min * minDivToSelf) : ERROR_CODE);
    return 0;
}
