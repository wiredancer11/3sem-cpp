#include <fstream> 
#include <cmath>

int main() {
    double x = 0;
    std::ofstream file = std::ofstream("f.txt");
    file << "x  sin(x)\n";
    for (int i = 0; i <= 10; i++) {
        file << x << '\t' << std::sin(x) << "\n";
        x += 0.1;
    }
    file.close();
}