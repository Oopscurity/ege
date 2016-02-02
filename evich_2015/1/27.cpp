#include <iostream>
#include <string>

int main() {
    const int   AUTHOR_LIMIT = 20,
                YEAR_LIMIT   = 1980,
                PAGES_LIMIT  = 300;
          int   N,
                bookYear,
                bookPages,
                suitableBooks = 0;
    size_t      shortestNameLength = 3000; 
    std::string bookName = "",
                shortestNameString = "";
    
    std::cin >> N;

    while (N--) {
        std::cin.ignore(AUTHOR_LIMIT, ' ');
        
        std::cin >> bookYear;
        std::cin.clear();
        if (bookYear >= YEAR_LIMIT) {
            std::cin.ignore(256, '\n');
            continue;
        }
        
        std::cin >> bookPages;
        std::cin.clear();
        if (bookPages < PAGES_LIMIT) {
            std::cin.ignore(256, '\n');
            continue;
        }
        
        ++suitableBooks;
        std::getline(std::cin, bookName);
        std::cin.clear();
        if (bookName.size() < shortestNameLength) {
            shortestNameString = bookName;
            shortestNameLength = bookName.size();
        }
    }
    
    std::cout << suitableBooks << ' ' << shortestNameString;
    return 0;
}