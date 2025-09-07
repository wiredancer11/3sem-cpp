#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

double sum_double(std::string filename) {
    double sum = 0;
    double a;
    std::ifstream input = std::ifstream(filename, std::ios::binary);
    while (input.read((char*) &a, sizeof(double))) {
        sum +=a;
    } 
    return sum;
}

int main() {
    double arr[3] = {1.1, 1.9, 2.0};
    std::cout << sum_double("f.dat");

}