// task B
#include <iostream>
#include <string>

int main() {
    const int YEAR_LIMIT = 1980,
              PAGE_LIMIT = 400,
              AUTHOR_NAME_LIMIT = 20,
              BOOK_NAME_LIMIT = 40;
    int N; // by condition: the number of books
    std::cin >> N;
    if (N <= 0) {
        return -1;
    }

    int currentYear,
        currentPageNum,
        suitableBooks = 0,
        shortestNameSize = BOOK_NAME_LIMIT + 1;
    std::string currentName,
                shortestName;

    for (int i = 0; i < N; ++i) {
        std::cin.ignore(AUTHOR_NAME_LIMIT, ' ');
        
        std::cin >> currentYear;
        std::cin.clear();
        std::cin >> currentPageNum;
        std::cin.clear();
        if (currentYear >= YEAR_LIMIT || currentPageNum < PAGE_LIMIT) {
            std::cin.ignore(BOOK_NAME_LIMIT + 1, '\n'); // +1 -- with space before book name
            continue;
        }

        ++suitableBooks;
        std::cin.ignore(1, ' ');
        std::getline(std::cin, currentName, '\n');
        if (currentName.size() < shortestNameSize) {
            shortestName = currentName;
            shortestNameSize = currentName.size();
        }
    }

    std::cout << suitableBooks << '\n' << shortestName;
    return 0;
}