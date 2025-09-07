#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input = std::ifstream("g.txt");
    std::string name;
    int math;
    int phys;
    std::getline(input, name);
    while (input >> name) {
        input >> math;
        input >> phys;
        std::cout << name << " " << math+phys << "\n";
    }
    input.close();
}