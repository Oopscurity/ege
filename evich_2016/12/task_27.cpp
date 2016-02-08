#include <iostream>
#include <unordered_map>

struct price {
    long minPrice = 500000;
    int where = 0;
};

int main() {
    const int MAX_COMPANY_NAME_SIZE = 20,
              MAX_SHOP_NAME_SIZE = 20,
              MIN_POSSIBLE_PRICE = 1000;
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
        if ((currentPrice >= MIN_POSSIBLE_PRICE) && (currentPrice < current->minPrice)) {
            current->minPrice = currentPrice;
            current->where = 1;
        } else if (currentPrice == current->minPrice) {
            ++current->where;
        }
    }
    delete current;

    // not (auto x: y) because of the order (the last inserted is in the begin)
    // TODO: to set correct order without using char literals
    for (char c = 'A'; c <= 'D'; ++c) {
        std::cout << categories[c].where << ' ';
    }
    return 0;
}