#include <iostream>

int main() {
    const int PRICE_LIMIT = 240,
              PROPOSAL_NAME_LIMIT = 4;
    int N; // by condition: the number of proposals
    std::cin >> N;
    if (N <= 0) {
        return -1;
    }

    int actionsDone = 0;
    char currentAction;
    double currentPrice,
           allSpent = 0,
           averagePrice = 0;
    for (int i = 0; i < N; ++i) {
        std::cin.ignore(PROPOSAL_NAME_LIMIT, ' ');
        std::cin >> currentAction;
        std::cin >> currentPrice;

        if ((currentAction == 'b') && (currentPrice <= PRICE_LIMIT)) {
            allSpent += currentPrice;
            ++actionsDone;
        }
    }

    averagePrice = allSpent / actionsDone;
    std::cout << "совершено " << actionsDone << " операций по покупке акций\n"
              << "средняя стоимость 1 приобретенной акции " << averagePrice << " долл.";
    return 0;
}