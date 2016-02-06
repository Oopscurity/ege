// task B; C++11

#include <iostream>
#include <vector>
#include <string>

struct Name {
    std::string surname;
    std::string initials;
};

int main() {
    const int MAX_RATE = 100,
              EXAMS_NUM = 3;

    int N; // by condition: the number of students
    std::cin >> N;
    if (N <= 0) {
        return -1;
    }

    int maxRateSum = -1,
        currentRate,
        currentRateSum;

    Name current;
    std::vector<Name> best;
    for (int i = 0; i < N; ++i) {
        currentRateSum = 0;
        std::getline(std::cin, current.surname, ' ');
        std::getline(std::cin, current.initials, ' ');

        for (int j = 0; j < EXAMS_NUM; ++j) {
            std::cin >> currentRate;
            currentRateSum += currentRate;
        }

        if (currentRateSum < maxRateSum)
            continue;

        if (currentRateSum > maxRateSum) {
            best.clear();
            best.push_back(current);
            maxRateSum = currentRateSum;
        } else { // currentRateSum == maxRateSum
            best.push_back(current);
        }
    }

    for (auto it = best.begin(); it != best.end(); ++it) {
        std::cout << it->surname << ' ' << it->initials << ' ' << maxRateSum; // probably '\n' is required
    }
    return 0;
}