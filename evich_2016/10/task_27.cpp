#include <iostream>
#include <cmath>
#include <map>

int main() {
    const double MIN_DEBT_RATIO = 1.6,
                 EQ_SELECTION_RATE = 0.5,
                 MAX_POSSIBLE_DEBT = 3000;
    const int MAX_SURNAME_SIZE = 20,
              MAX_NAME_SIZE = 15;
    int N; // by condition: the number of flats
    std::cin >> N;
    if (N <= 0) {
        return -1;
    }

    int currentFlatNum;
    double minDebt = MAX_POSSIBLE_DEBT,
           allDebt = 0,
           currentDebt;
    std::map<int, double> debtors;
    for (int i = 0; i < N; ++i) {
        std::cin.ignore(MAX_SURNAME_SIZE, ' ');
        std::cin.ignore(MAX_NAME_SIZE, ' ');
        std::cin >> currentFlatNum;
        std::cin >> currentDebt;

        if (currentDebt == 0) {
            continue;
        }

        if (currentDebt < minDebt) {
            minDebt = currentDebt;
        }

        allDebt += currentDebt;
        debtors.insert(std::pair<int, double>(currentFlatNum, currentDebt));
    }

    double averageDebt = allDebt / debtors.size();
    if (averageDebt > minDebt) {
        
        for (auto &debtor: debtors) {
            if ((debtor.second > averageDebt) || ((debtor.second == averageDebt) && (averageDebt > minDebt * MIN_DEBT_RATIO))) {
                std::cout << debtor.first << '\n';
            }
        }
    } else if (averageDebt == minDebt) { // all debtors have equal debts
        int printed = 0;
        
        for (auto &debtor: debtors) {
            if (++printed > ceil(debtors.size() * EQ_SELECTION_RATE)) {
                break;
            }

            std::cout << debtor.first << '\n';
        }
    }

    return 0;
}