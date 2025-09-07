#include <string>
#include <fstream>
void sort(std::string in_name, std::string out_name) {
    bool *numbers = new bool[1000000] {false};
    std::ifstream input = std::ifstream(in_name);
    std::ofstream output = std::ofstream(out_name);
    int n;
    while (input >> n) {
        numbers[n-1] = true;
    }
    for (int i =0; i < 1000000;i++) {
        if (numbers[i]) output << i+1 << " ";
    }
}

int main() {
    sort("f.txt", "g.txt");
}