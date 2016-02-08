#include <iostream>
#include <unordered_map>

struct price {
    long maxPrice = 2000;
    int where = 0;
};

int main() {
    const int MAX_COMPANY_NAME_SIZE = 20,
              MAX_SHOP_NAME_SIZE = 20;
    int N; // by condition: the number of proposals
    std::cin >> N;
    if (N <= 0) {
        return -1;
    }

    char currentCategory;
    long currentPrice;
    std::unordered_map<char, price> categories ({
        {'A', {}}, {'B', {}}, {'C', {}}, {'D', {}}
    });
    auto *current = &categories['A'];
    for (int i = 0; i < N; ++i) {
        std::cin.ignore(MAX_COMPANY_NAME_SIZE, ' ');
        std::cin.ignore(MAX_SHOP_NAME_SIZE, ' ');
        std::cin >> currentCategory;
        std::cin >> currentPrice;

        current = &categories[currentCategory];
        if (currentPrice > current->maxPrice) {
            current->maxPrice = currentPrice;
            current->where = 1;
        } else if (currentPrice == current->maxPrice) {
            ++current->where;
        }
    }

    // not (auto x: y) because of the order (the last inserted is in the begin)
    // TODO: to set correct order without using char literals
    for (char current = 'A'; current <= 'D'; ++current) {
        std::cout << categories[current].where << ' ';
    }
    return 0;
}