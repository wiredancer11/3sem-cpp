#include <iomanip>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <cmath>

void print_sin_table(std::ostream& stream, double step) {
    for (double i = 0; i < 20; i=i+step) {
        stream << std::setprecision(4) << "sin(" << i << ")\t" << std::sin(i) << "\n";
    }
}

void make_sin_files() {
    std::ofstream output;
    std::ostringstream stringstream;
    std::string filename;
    for (int i = 1; i <= 10; i++) {
        stringstream.clear();
        stringstream.str("");
        stringstream.seekp(0);
        
        stringstream <<std::setprecision(2)<< "./sin/sin_" << i/10.0;
        filename = stringstream.str();
        
        std::cout << filename << "\n";
        output.open(filename);
        print_sin_table(output, i/10.0);
        output.close();
    }
}
int main() {
    make_sin_files();
}

