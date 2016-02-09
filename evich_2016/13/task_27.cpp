#include <iostream>
#include <fstream>
#include <locale>
#include <string>

int main() {
    std::string gamma;
    std::cin >> gamma;
    if (gamma == "") {
        return -1;
    }

    const int step = 26;
    const std::string INPUT_FILE_NAME = "message.txt";
    std::fstream fin (INPUT_FILE_NAME, std::fstream::in);
    if (!fin.is_open()) {
        return -1;
    }

    int counter = 0;
    char rawChar,
         cipheredChar;
    std::string result;
    while(fin.get(rawChar)) {
        if ( isalpha(int(rawChar)) ) {
            cipheredChar = 'A' + char((toupper(int(rawChar)) + int(gamma[counter++ % gamma.length()])) % 26);
            result += cipheredChar;
        }
    }
    fin.close();

    const std::string OUTPUT_FILE_NAME = "cipher.txt";
    std::fstream fout (OUTPUT_FILE_NAME, std::fstream::out);
    if (!fout.is_open()) {
        return -1;
    }
    fout << result;
    fout.close();
    return 0;
}