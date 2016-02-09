#include <iostream>
#include <locale>
#include <cstdlib>
#include <string>

int main() {
    std::string message;

    char c;
    while((c = std::cin.get()) != '\n') {
        if ( isalpha(int(c)) ) {
            message += char(toupper(c));
        }
    }
    
    int i = 0, // digit from char
        counter = 0, // the position to insert new character
        currentPosition = 0; // origin of counting
    char elem[2] = { '1', '\0' }; // for atoi
    std::string result(message.size(), '\0');
    
    while((c = std::cin.get()) != '\n') {
        if ( isdigit(c) ) {
            elem[0] = c;
            i = atoi(elem) - 1;

            result[currentPosition + counter] = message[currentPosition + i];
            ++counter;
        } else if ( c == ';' ) {
            currentPosition = counter;
            counter = 0;
        }
    }

    std::cout << result;
    return 0;
}