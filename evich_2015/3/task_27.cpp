#include <iostream>
#include <algorithm> // std::sort
#include <vector>

bool compare(int a, int b) { return (a > b); } // reverse

int main() {
    const double QUALITY_RATE       = 0.05; // 5%
	const int    MIN_PRICE_CATEGORY = 15,
                 MAX_NAME_SIZE      = 20,
                 MAX_CODE_SIZE      = 15;
	      int    N, // by condition: the number of stones
                 stonesInRate, // QUALITY_RATE from all stones; at least one
                 currentPrice,
                 minSuitablePrice;

    std::cin >> N;
    stonesInRate = (QUALITY_RATE*N > 1) ? QUALITY_RATE*N : 1;

    // int *prices = new int[N];
    std::vector<int> prices (N);
    for (int i = 0; i < N; ++i) {
        std::cin.ignore(MAX_NAME_SIZE, ' ');
        std::cin.ignore(MAX_CODE_SIZE, ' ');
        
        std::cin >> currentPrice;
        prices[i] = currentPrice;
        std::cin.clear();
    }

    std::sort(prices.begin(), prices.end());

    auto it = prices.begin();
    for (; it != prices.begin() + stonesInRate; ++it) {
        if (minSuitablePrice < *it) {
            minSuitablePrice = *it;
        }
    }
    
    std::cout << minSuitablePrice;
	return 0;
}