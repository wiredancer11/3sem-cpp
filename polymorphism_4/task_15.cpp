#include <string>
#include <fstream>

void write_sums(std::string in_filename, std::string out_filename) {
    std::ifstream in = std::ifstream(in_filename);
    std::ofstream out = std::ofstream(out_filename);

    int number;
    int sum = 0;
    while (in >> number) {
        if (number >= 1000) continue;
        if (number + sum < 1000) {
            sum += number;
        } else if (number + sum >= 1000) {
            out << sum << " ";
            sum = number;
        }
    }
    out << sum;

}

int main() {
    write_sums("input.txt", "output.txt");
}