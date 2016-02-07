#include <iostream>
#include <string>
#include <unordered_map>

struct routeInfo {
    std::string owner;
    int delay;
    int latest = 0;
    int penalty = 0;
};

int main() {
    const int MINS_PER_HOUR = 60,
              MAX_DELAY = 2;

    int N; // by condition: the number of routes
    std::cin >> N;
    if (N <= 0) {
        return -1;
    }

    int currentRouteNumber;
    routeInfo currentRoute;
    std::unordered_map<int, routeInfo> routes;
    for (int i = 0; i < N; ++i) {
        std::cin >> currentRouteNumber;
        std::cin >> currentRoute.delay;
        std::cin.ignore(1, ' ');
        std::getline(std::cin, currentRoute.owner);

        routes.insert(std::pair<int, routeInfo>(currentRouteNumber, currentRoute));
    }

    int M; // by condition: the number of buses
    std::cin >> M;
    if (M <= 0) {
        return -1;
    }

    int arrivalTime,
        arrivalTimeLimit;
    for (int i = 0; i < M; ++i) {
        std::cin >> arrivalTime;
        std::cin >> currentRouteNumber;

        routeInfo &route = routes[currentRouteNumber];
        arrivalTimeLimit = route.latest + route.delay + MAX_DELAY;
        route.latest = arrivalTime;

        if (arrivalTime > arrivalTimeLimit) {
            for (int i = 1; arrivalTime >= arrivalTimeLimit + i; ++i) {
                ++route.penalty;
            }
        }
    }

    for (auto &route: routes) {
        if (route.second.penalty > 0) {
            std::cout << route.first << ' ' << route.second.owner << ' ' << route.second.penalty << '\n';
        }
    } 
    return 0;
}