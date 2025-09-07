#include <fstream>
#include <string>
#include <iostream>

int count_ints(std::string filename) {
    std::ifstream input = std::ifstream(filename); 
    int n;
    int sum = 0;
    while (input >> n) {
        sum += n;
    }
    input.close();
    return sum;
}

int main() {
    std::cout << count_ints("numbers.txt");

}