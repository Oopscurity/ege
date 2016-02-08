#include <iostream>
#include <map> // to be sorted

int main() {
    const double MIN_DEBT_RATE = 0.8,
                 EQ_SELECTION_RATE = 0.6;
    const int MAX_SURNAME_SIZE = 20,
              MAX_NAME_SIZE = 15;
    int N; // by condition: the number of flats
    std::cin >> N;
    if (N <= 0) {
        return -1;
    }

    int currentFlatNum;
    double currentDebt,
           maxDebt = 0,
           allDebt = 0;
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
        }

        allDebt += currentDebt;
        debtors.insert(std::pair<int, double>(currentFlatNum, currentDebt));
    }

    double averageDebt = allDebt / debtors.size();
    if (averageDebt < maxDebt) {
        for (auto &debtor: debtors) {
            if (debtor.second > maxDebt * MIN_DEBT_RATE) {
                std::cout << debtor.first << '\n';
            }
        }
    } else if (averageDebt == maxDebt) {
        int printed = 0;

        for (auto &debtor: debtors) {
            if (++printed > debtors.size() * EQ_SELECTION_RATE) {
                break;
            }

            std::cout << debtor.first << '\n';
        }
    }
    return 0;
}