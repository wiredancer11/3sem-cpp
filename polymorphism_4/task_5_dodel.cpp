#include <fstream>
#include <iostream>
#include <map>

void count_ascii(std::string filename) {
    int char_arr[128] = {0};
    char c;
    std::ifstream input = std::ifstream(filename);
    while (input.get(c)) {
        char_arr[(int) c] += 1;
    }
    input.close();
    for (int i = 32; i < 128;i++) {
        if (char_arr[i] != 0) {
            std::cout << (char) i << ": " << char_arr[i]  << std::endl;
        }
    }
}

void count_all(std::string filename) {
    std::map<char, int> char_count;
    char c;
    std::ifstream input = std::ifstream(filename);
    while (input.get(c)) {
        if (char_count.count(c) > 0) {
            char_count.at(c)++;
        } else {
            char_count.insert({c, 1});
        }
    }
    input.close();
    for (auto pair : char_count) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
   count_all("f.txt"); 
}