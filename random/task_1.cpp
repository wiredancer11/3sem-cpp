#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <random>
#include <vector>
#include <fstream>

template<typename GeneratorType>
void generate_ints(std::vector<int>& numbers_count, GeneratorType& generator) {
    std::uniform_int_distribution<int> distrib(0, 100);
    for (int i = 0; i < 1000000; i++) {
        numbers_count[distrib(generator)]++;
    }
}

double get_avg_freq(std::vector<int> const & numbers_count) {
    double sum = 0;
    for (auto el: numbers_count) {
        sum += el;
    }
    return sum / numbers_count.size();
}

double get_dispersion(std::vector<int> const & numbers_count, double avg_freq) {
    double sum = 0;
    for (auto el: numbers_count) {
        sum += pow(avg_freq - el, 2);
    }
    return sum / 100;
}

void draw_diagram(std::vector<int> const & numbers_count, std::ostream& out) {
    double avg_freq = get_avg_freq(numbers_count);
    double dispersion = get_dispersion(numbers_count, avg_freq);
    out << "Average frequency: " << avg_freq << "\n";
    out << "Dispersion: " << dispersion << "\n";
    for (int i = 0; i < numbers_count.size(); i++) {
        out<< std::setw(3) << i << " | ";
        for (int j = 0; j < numbers_count[i] / 500; j++) {
            out << "*";
        }
        out << " " << numbers_count[i] << "\n";
    }
}



int main() {
    std::minstd_rand minstd;
    std::mt19937 mt;
    std::ranlux48 ranlux;
    std::knuth_b knuth;
    std::random_device rd;

    std::vector<int> numbers_count(101, 0);
    std::ofstream diagram = std::ofstream("diagrams/mt.txt");
    generate_ints(numbers_count, mt);
    draw_diagram(numbers_count, diagram);
    diagram.close();

    diagram.open("diagrams/minstd.txt");
    numbers_count = std::vector<int>(101, 0);
    generate_ints(numbers_count, minstd);
    draw_diagram(numbers_count, diagram);
    diagram.close();

    diagram.open("diagrams/ranlux.txt");
    numbers_count = std::vector<int>(101, 0);
    generate_ints(numbers_count, ranlux);
    draw_diagram(numbers_count, diagram);
    diagram.close();

    diagram.open("diagrams/rd.txt");
    numbers_count = std::vector<int>(101, 0);
    generate_ints(numbers_count, rd);
    draw_diagram(numbers_count, diagram);
    diagram.close();


    diagram.open("diagrams/knuth.txt");
    numbers_count = std::vector<int>(101, 0);
    generate_ints(numbers_count, knuth);
    draw_diagram(numbers_count, diagram);
    diagram.close();
}