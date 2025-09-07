#include <iostream>
#include <sstream>
#include <string>
int square_concat(int a, int b) {
    std::stringstream stream;
    int result;
    stream << a << b;
    stream.seekg(0);
    stream >> result;
    return result * result;
}

int main() {
    std::cout << square_concat(1, 2); 
}