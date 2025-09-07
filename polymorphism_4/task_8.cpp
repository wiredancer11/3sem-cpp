#include <fstream>
#include <string>
#include <iostream>

void replace_zeroes(std::string filename) {
    std::ifstream input = std::ifstream(filename, std::ios::binary);
    std::ofstream output;
    int numbers[10];
    input.read((char*)numbers, sizeof(numbers));
    for (int i = 0; i < 10; i++) {
        if (numbers[i] == 0) {
            numbers[i] = 5;
        }
    }
    input.close();
    
    output.open(filename, std::ios::binary);
    output.write((char *) numbers, sizeof(numbers));
}

int main() {
    int numbers[10] = {0, 1, 2, 3, 1, 1, 1, 1, 1, 1};
    std::ofstream output = std::ofstream("f.dat", std::ios::binary);
    output.write((char *) numbers, sizeof(numbers));
    output.close();
    replace_zeroes("f.dat");
}
