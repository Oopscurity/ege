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
    if (!N) {
        return -1;
    }

    int minAverage = MAX_RATE * EXAMS_NUM + 1,
        currentRate,
        currentAverage = 0;

    Name current;
    std::vector<Name> minimals;
    for (int i = 0; i < N; ++i, currentAverage = 0) {
        std::getline(std::cin, current.surname, ' ');
        std::getline(std::cin, current.initials, ' ');

        for (int j = 0; j < EXAMS_NUM; ++j) {
            std::cin >> currentRate;
            currentAverage += currentRate;
        }

        if (currentAverage > minAverage)
            continue;

        if (currentAverage < minAverage) {
            minimals.clear();
            minimals.push_back(current);
            minAverage = currentAverage;
        } else { // currentAverage == minAverage
            minimals.push_back(current);
        }
    }

    for (auto it = minimals.begin(); it != minimals.end(); ++it) {
        std::cout << it->surname << ' ' << it->initials << ' ' << minAverage / 3; // probably '\n' is required
    }
    return 0;
}