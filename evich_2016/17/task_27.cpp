#include <iostream>
#include <string>
#include <set>
#include <climits> // CHAR_BIT
#include <bitset>
#include <sstream>

template <typename T>
std::string integralToBinaryString(T& _data) {
    std::bitset<CHAR_BIT> bitset(_data);
    return bitset.to_string();
}

template <typename T>
unsigned long long bitsetToUll(T& _data) {
    unsigned long long result = 0;
    unsigned long long mask = 1;
    for (int i = 0; i < _data.size(); ++i) {
        if (_data.test(i)) {
            result |= mask;
        }
        mask <<= 1;
    }
    return result;
}

template <typename T>
int findFirstSet(T& data) {
    int bit = -1;
    for (int i = 0; i < data.size(); ++i) {
        if (data.test(i)) {
            bit = i;
            break;
        }
    }
    return bit;
}

template <typename T>
T& setTill(T& data, int end, bool value = true) {
    end = (end >= data.size()) ? data.size() : end; 
    for (int i = 0; i <= end; ++i) {
        data[i] = value;
    }
    return data;
}

void readIP(std::string& _dest, const char _delim = ' ', const int _bytes = 4) {
    std::getline(std::cin, _dest, _delim);
    std::istringstream buf(_dest);
    _dest.clear();
    unsigned short byte;
    for (int i = _bytes; i > 0; --i) {
        if (buf.eof()) byte = 0;
        else {
            buf >> byte;
            if (i != 1) buf.ignore(1);
        }
        _dest += integralToBinaryString(byte);
    }
}

std::string readIP(const char _delim = ' ', const int _bytes = 4) {
    std::string result;
    std::getline(std::cin, result, _delim);
    std::istringstream buf(result);
    result.clear();
    unsigned short byte;
    for (int i = _bytes; i > 0; --i) {
        if (buf.eof()) byte = 0;
        else {
            buf >> byte;
            if (i != 1) buf.ignore(1);
        }
        result += integralToBinaryString(byte);
    }
    return result;
}

int main() {
    const int BYTES_PER_IP = 4,
              SURNAME_SIZE_LIMIT = 30;

    std::bitset<BYTES_PER_IP * 8> network(readIP());
    std::bitset<BYTES_PER_IP * 8> reference(readIP('\n'));
    
    int bit = findFirstSet(reference);
    unsigned long long min = bitsetToUll( setTill(network, bit, false) );
    unsigned long long max = bitsetToUll( setTill(network, bit) );

    int N; // by condition: the number of users
    std::cin >> N;

    unsigned long long currentUll;
    std::string login, currentIP;
    std::set<std::string> users;
    for (int i = 0; i < N; ++i) {
        std::cin.ignore(SURNAME_SIZE_LIMIT, ' ');
        std::cin >> login;
        readIP(currentIP, '\n');
        std::bitset<BYTES_PER_IP * 8> currentBin(currentIP);
        currentUll = bitsetToUll(currentBin);
        if (( currentUll >= min ) && ( currentUll <= max )) {
            users.insert(login);
        }
    }

    for (auto it = users.begin(); it != users.end(); ++it) {
        std::cout << *it << '\n';
    }
    return 0;
}