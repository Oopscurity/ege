// #include <iostream>
// #include <bitset>
// #include <climits>
// #include <string>
// #include <sstream>
// #include <set>

// template <typename T>
// std::string integralToBinaryString(T _byte) {
// 	std::bitset<CHAR_BIT> bs(_byte);
// 	return bs.to_string();
// }

// void read(std::string &_dest, int _bytes) {
// 	unsigned short byte;
// 	for (int i = 0; i < _bytes; ++i) {
// 		std::cin >> byte;
// 		if (i) std::cin.ignore(1);
// 		_dest += integralToBinaryString(byte);
// 	}
// }

// void readIPTillSpace(std::string &_dest, int _bytes) {
// 	std::getline(std::cin, _dest, ' ');
// 	unsigned short byte;
// 	std::istringstream buf(_dest);
// 	for (int i = 0; i < _bytes; ++i) {
// 		if (buf.eof()) byte = 0;
// 		else {
// 			buf >> byte;
// 			if (i) buf.ignore(1);
// 		}
// 		_dest += integralToBinaryString(byte);
// 	}
// }

// int findFirstSetBit(std::string &target) {
// 	std::bitset<32> targetBinary(target);
// 	int bit = 0;
// 	while (!targetBinary.test(bit)) { ++bit; }
// 	return bit;
// }

// int main() {
// 	const int BYTES_PER_IP = 4,
// 			  SURNAME_SIZE_LIMIT = 30;
// 	int N; // by condition: the number of users
// 	std::cin >> N;

// 	std::string reference,
// 				net;
// 	readIPTillSpace(reference, BYTES_PER_IP);
// 	readIPTillSpace(net, BYTES_PER_IP);

// 	int firstSetBit = findFirstSetBit(reference);
// 	std::bitset<BYTES_PER_IP * 8> networkBinary(net);

// 	for (int i = 0; i < firstSetBit; ++i) {
// 		networkBinary[i] = false;
// 	}
// 	unsigned long long min = networkBinary.to_ullong();
// 	for (int i = 0; i < firstSetBit; ++i) {
// 		networkBinary[i] = true;
// 	}
// 	unsigned long long max = networkBinary.to_ullong();

// 	std::cout << reference << ' ' << net << std::endl;
//  	std::cout << min << ' ' << max << std::endl; 

// 	std::string currentUsername,
// 				currentIP;
// 	unsigned long long currentIPNumber;
// 	std::set<std::string> usernames;
// 	for (int i = 0; i < N; ++i) {
// 		std::cin.ignore(SURNAME_SIZE_LIMIT, ' ');
// 		std::cin >> currentUsername;
		
// 		read(currentIP, BYTES_PER_IP);
// 		std::bitset<BYTES_PER_IP * 8> current(currentIP);
// 		currentIPNumber = current.to_ullong();
// 		if ((currentIPNumber >= min) && (currentIPNumber <= max)) {
// 			usernames.insert(currentUsername);
// 		}
// 	}



// 	return 0;
// }