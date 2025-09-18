#include <iomanip>
#include <iostream>
#include <ostream>
#include <random>
#include <vector>
#include <fstream>

template<typename GeneratorType>
void generate_pic(std::vector<std::vector<int>>& field, GeneratorType& gen) {
    std::uniform_int_distribution<int> distrib(0,1);
    for (auto& row: field) {
        for (auto& point : row) {
            point = distrib(gen);
        }
    }
}

void draw_pic(std::vector<std::vector<int>> const & field, std::ostream& out) {
    for (auto& row: field) {
        for (auto& point : row) {
            if (point == 1) out << "*";
            else out << " ";
        }
        out << "\n";
    }

}

int main() {
    std::minstd_rand minstd;
    std::mt19937 mt;
    std::ranlux48 ranlux;
    std::knuth_b knuth;
    std::random_device rd;

    std::vector<std::vector<int>> field(100, std::vector<int>(100));
    std::ofstream picture = std::ofstream("pictures/mt.txt");
    generate_pic(field, mt);
    draw_pic(field, picture);
    picture.close();

    picture.open("pictures/minstd.txt");
    generate_pic(field, minstd);
    draw_pic(field, picture);
    picture.close();

    picture.open("pictures/ranlux.txt");
    generate_pic(field, ranlux);
    draw_pic(field, picture);
    picture.close();

    picture.open("pictures/rd.txt");
    generate_pic(field, rd);
    draw_pic(field, picture);
    picture.close();


    picture.open("pictures/knuth.txt");
    generate_pic(field, knuth);
    draw_pic(field, picture);
    picture.close();

}