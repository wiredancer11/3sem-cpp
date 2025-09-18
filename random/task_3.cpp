#include <iostream>
#include <ostream>
#include <random>
#include <vector>
#include <fstream>
#include "my_gen.h"

template<typename GeneratorType>
void generate_pic(std::vector<std::vector<int>>& field, GeneratorType& gen) {
    std::uniform_int_distribution<int> distrib(0,99);
    for (int i = 0; i < 200; i++) {
        field[distrib(gen)][distrib(gen)] = 1;
    }
}

void generate_pic_with_func(std::vector<std::vector<int>>& field, int (*gen)(int, int)) {
    for (int i = 0; i < 200; i++) {
        field[gen(0, 99)][gen(0,99)] = 1;
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

    std::vector<std::vector<int>> field(100, std::vector<int>(100, 0));
    std::ofstream picture = std::ofstream("pictures/mt.txt");
    generate_pic(field, mt);
    draw_pic(field, picture);
    picture.close();

    field = std::vector<std::vector<int>>(100, std::vector<int>(100, 0));
    picture.open("pictures/minstd.txt");
    generate_pic(field, minstd);
    draw_pic(field, picture);
    picture.close();

    field = std::vector<std::vector<int>>(100, std::vector<int>(100, 0));
    picture.open("pictures/ranlux.txt");
    generate_pic(field, ranlux);
    draw_pic(field, picture);
    picture.close();

    field = std::vector<std::vector<int>>(100, std::vector<int>(100, 0));
    picture.open("pictures/rd.txt");
    generate_pic(field, rd);
    draw_pic(field, picture);
    picture.close();


    field = std::vector<std::vector<int>>(100, std::vector<int>(100, 0));
    picture.open("pictures/knuth.txt");
    generate_pic(field, knuth);
    draw_pic(field, picture);
    picture.close();

    field = std::vector<std::vector<int>>(100, std::vector<int>(100, 0));
    picture.open("pictures/c_rand.txt");
    generate_pic_with_func(field, gen_rand);
    draw_pic(field, picture);
    picture.close();

    field = std::vector<std::vector<int>>(100, std::vector<int>(100, 0));
    picture.open("pictures/c_rand_mod.txt");
    generate_pic_with_func(field, gen_rand_mod);
    draw_pic(field, picture);
    picture.close();
}