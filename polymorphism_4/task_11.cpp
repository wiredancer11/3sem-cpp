#include <fstream>
#include <string>
#include <vector>
void change_to_sum(std::string filename) {
    std::ifstream input = std::ifstream(filename, std::ios::binary);
    std::ofstream output;
    double sum = 0;
    double a;
    std::vector<double> sums;
    while(input.read((char *) &a, sizeof(double))) {
        sum += a;
        sums.push_back(sum);
    }
    input.close();
    output.open(filename, std::ios::binary);
    output.write((char *) sums.data(), sizeof(double) * sums.size());
    output.close();
}



int main() {
    change_to_sum("f.dat");
}