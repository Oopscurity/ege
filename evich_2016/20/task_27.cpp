#include <iostream>

int main() {
    const double SELECTION_RATE = 0.1;
    const int MAX_POSSIBLE_RATE = 30,
              STONE_NAME_LIMIT = 20,
              STONE_CODE_LIMIT = 15;
    int N; // by condition: the number of stones
    int stonesPerRate[MAX_POSSIBLE_RATE] = { 0 };
    std::cin >> N;

    int currentRate;
    for (int i = 0; i < N; ++i) {
        std::cin.ignore(STONE_NAME_LIMIT, ' ');
        std::cin.ignore(STONE_CODE_LIMIT, ' ');
        std::cin >> currentRate;
        ++stonesPerRate[currentRate - 1];
    }

    int minRate = MAX_POSSIBLE_RATE,
        allSuitableStones = (N * SELECTION_RATE > 1) ? N * SELECTION_RATE : 1,
        already = 0;
    do {
        while ((already < allSuitableStones) && (stonesPerRate[minRate - 1] != 0)) {
            ++already;
            --stonesPerRate[minRate - 1];
        }
    } while ((already < allSuitableStones) && --minRate);

    std::cout << minRate;
    return 0;
}