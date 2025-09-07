
#include <fstream>
#include <string>
void append(std::string input_filename, std::string output_filename) {
    std::ifstream input = std::ifstream(input_filename);
    std::ofstream output = std::ofstream(output_filename, std::ios::app);

    std::string line;
    while (std::getline(input, line)) {
        output << line << "\n";
    }
    input.close();
    output.close();
}

int main() {
    append("g.txt", "f.txt");
}