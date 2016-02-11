#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <unordered_map>
#include <climits> // CHAR_BIT

template<class T>
std::string integralToBinaryString(T byte) {
    std::bitset</*sizeof(T) * */CHAR_BIT> bs(byte);
    return bs.to_string();
}

template<class T>  // to convert from bitsets with different size
unsigned int octet_to_uint(T &bitset, int order) {
    unsigned int mask = 1;
    unsigned int result = 0;

    for (size_t i = (bitset.size() - 8) - 8*order; i < bitset.size() - 8*order; ++i) {
        if ( bitset.test(i) ) {
            result |= mask;
        }
        mask <<= 1;
    }
    return result;
}

void clear(std::unordered_map<std::string, std::pair<std::string, int>> &data) {
    for (auto &elem: data) {
        elem.second.first.clear(); // clear strings with binary code
    }
}

void read(std::pair<std::string, int> &dest) {
    short byte;
    int it = dest.second; // not to be dependent from data you get
    while (it--) {
        std::cin >> byte;
        dest.first += integralToBinaryString(byte);
        if (it)
            std::cin.ignore(1); // to parse dotted such as 192.168.1.1
    }
}

struct Packet {
    std::bitset<32> src; // IPv4
    std::bitset<32> dest;
    std::bitset<24> time; // hh:mm:ss
    Packet(std::string _src,
           std::string _dest,
           std::string _time) : src(_src), dest(_dest), time(_time) {}
};

int main() {
    const int BYTES_PER_TIME = 3,
              BYTES_PER_IP = 4;
    int N;
    std::cin >> N;

    std::vector<Packet> packets;
    packets.reserve(N);

    std::string head[3] {
        "time", "src", "dest"
    };
    std::unordered_map<
        std::string,
        std::pair<std::string, int>> data ({
            { head[0], std::pair<std::string, int>("", BYTES_PER_TIME) },
            { head[1], std::pair<std::string, int>("", BYTES_PER_IP) },
            { head[2], std::pair<std::string, int>("", BYTES_PER_IP) } 
    });
    for (int i = 0; i < N; ++i) {
        clear(data);
        for (int j = 0; j < data.size(); ++j) {
            read(data[ head[j] ]);
            std::cin.ignore(1);
        }
        packets.push_back({ Packet(data["src"].first, data["dest"].first, data["time"].first) });
    }

    clear(data);
    char c;
    std::string request;
    while ((c = std::cin.get()) != '\n') {
        if (c != ' ')
            request += c;
        while ((c = std::cin.get()) != '=') {
            request += c;
        }
        read(data[request]);
        request.clear();
    }

    for (auto &packet: packets) {

        if ( ((data[ head[0] ].first.empty()) || std::bitset<BYTES_PER_TIME * 8> (data[ head[0] ].first) == packet.time) && 
             ((data[ head[1] ].first.empty()) || std::bitset<BYTES_PER_IP * 8>(data[ head[1] ].first) == packet.src) &&
             ((data[ head[2] ].first.empty()) || std::bitset<BYTES_PER_IP * 8>(data[ head[2] ].first) == packet.dest)
            )
        {
            for (int i = 0; i < BYTES_PER_TIME; ++i) {
                std::cout << octet_to_uint(packet.time, i);
                if (i != BYTES_PER_TIME - 1) std::cout << ':';
            }
            std::cout << ' ';
            for (int i = 0; i < BYTES_PER_IP; ++i) {
                std::cout << octet_to_uint(packet.src, i);
                if (i != BYTES_PER_IP - 1) std::cout << '.';
            }
            std::cout << ' ';
            for (int i = 0; i < BYTES_PER_IP; ++i) {
                std::cout << octet_to_uint(packet.dest, i);
                if (i != BYTES_PER_IP - 1) std::cout << '.';
            }
            std::cout << '\n';
        }
    }
    return 0;
}