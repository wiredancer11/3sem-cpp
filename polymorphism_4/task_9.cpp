#include <string>
#include <fstream>
#include <iostream>

void save(std::string filename, double numbers[]) {
    std::ofstream output = std::ofstream(filename, std::ios::binary);
    output.write((char *) numbers, sizeof(double) * 15);
    output.close();
}

void load(std::string filename, double numbers[]) {
    std::ifstream input = std::ifstream(filename, std::ios::binary); 
    input.read((char *) numbers, sizeof(double) * 15);
    input.close();
    
}

int main() {
    double numbers[15] = {1, 2, 3, 5, 2.5,
         6, 7, 4, 3, 3, 3, 3, 3,4, 2.1};
    double a[15];
    save("g.dat", numbers);
    load("g.dat", a);
    for (int i = 0; i < 15; i++) {
        std::cout << a[i] << " ";
    }
}