#include <iostream>

int main() {
    const int DEVISOR_SELF = 14,
              DEVISOR_FIRST = 7,
              DEVISOR_SECOND = 2;
    long N;
    std::cin >> N;

    int current,
        max = 0,
        maxDivSelf = 0,
        maxDivFirst = 0,
        maxDivSecond = 0,
        indexMaxDivSelf;
    for (long i = 0; i < N; ++i) {
        std::cin >> current;
        if (!(current % DEVISOR_SELF) && (current > maxDivSelf)) {
            maxDivSelf = current;
            indexMaxDivSelf = i;
        } else if (!(current % DEVISOR_FIRST) && (current > maxDivFirst)) {
            maxDivFirst = current;
        } else if (!(current % DEVISOR_SECOND) && (current > maxDivSecond)) {
            maxDivSecond = current;
        }
        if ((current > max) && (i != indexMaxDivSelf)) {
            max = current;
        }
    }
    long R;
    std::cin >> R;
    // std::cout << "max: " << max << '\t' << "maxDivSelf: " << maxDivSelf << '\t' << "maxDivFirst: " << maxDivFirst << '\t' << "maxDivSecond: " << maxDivSecond << '\n';

    long multiply = 0;
    if ( maxDivSelf || (maxDivFirst && maxDivSecond) ) {
        multiply = (max * maxDivSelf > maxDivFirst * maxDivSecond)
        ? max * maxDivSelf : maxDivFirst * maxDivSecond;
    }
    std::cout << "Вычисленное контрольное значение: " << multiply << '\n';
    std::cout << "Контроль" << ((multiply != R) ? " не " : " ") << "пройден";
    return 0;
}