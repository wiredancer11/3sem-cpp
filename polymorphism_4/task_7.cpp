#include <fstream>
#include <string>
#include <sstream>

void print_sums(std::string input_file, std::string output_file) {
    std::ifstream input = std::ifstream(input_file);
    std::ofstream output = std::ofstream(output_file);
    
    std::istringstream line_stream = std::istringstream();

    std::string line;

    int n;
    int sum;
    
    while(std::getline(input, line)) {
        line_stream.str(line);
        sum = 0;
        while(line_stream >> n) {
            sum += n;
        }
        output << sum << "\n";
        line_stream.clear();
    }

}

int main() {
    print_sums("numbers.txt", "sums.txt"); 
}