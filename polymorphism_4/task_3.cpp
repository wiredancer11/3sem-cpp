#include <fstream>
#include <string>
void copy(std::string input_filename, std::string output_filename) {
    std::ifstream input = std::ifstream(input_filename);
    std::ofstream output = std::ofstream(output_filename);

    std::string line;
    while (std::getline(input, line)) {
        output << line << "\n";
    }
    input.close();
    output.close();
}

int main() {
    copy("g.txt", "f.txt");
}