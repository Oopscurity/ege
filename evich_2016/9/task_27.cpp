#include <iostream>
#include <map> // to be sorted

int main() {
    const double MIN_DEBT_RATE = 0.8;
    const int EQ_SELECTION_RATE = 60,
              MAX_SURNAME_SIZE = 20,
              MAX_NAME_SIZE = 15;
    int N; // by condition: the number of flats
    std::cin >> N;
    if (N <= 0) {
        return -1;
    }

    int currentFlatNum,
        equalsMax = 0;
    double currentDebt,
           maxDebt = 0.0;
    std::map<int, double> debtors;
    for (int i = 0; i < N; ++i) {
        std::cin.ignore(MAX_SURNAME_SIZE, ' ');
        std::cin.ignore(MAX_NAME_SIZE, ' ');
        std::cin >> currentFlatNum;
        std::cin >> currentDebt;

        if (currentDebt == 0) { // because we are looking for debtors
            continue;
        }

        if (currentDebt > maxDebt) {
            maxDebt = currentDebt;
            equalsMax = 0;
        } else if (currentDebt == maxDebt) {
            ++equalsMax;
        }
        debtors.insert(std::pair<int, double>(currentFlatNum, currentDebt));
    }

    if (equalsMax != debtors.size() - 1) {
        for (auto &debtor: debtors) {
            if (debtor.second > maxDebt * MIN_DEBT_RATE) {
                std::cout << debtor.first << '\n';
            }
        }
    } else if (equalsMax == debtors.size() - 1) {
        int printed = 0;

        for (auto &debtor: debtors) {
            if (++printed > equalsMax * EQ_SELECTION_RATE / 100) {
                break;
            }

            std::cout << debtor.first << '\n';
        }
    }
    return 0;
}