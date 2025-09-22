#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::chrono::time_point now =std::chrono::system_clock::now();
    std::time_t current_time;
    while(true) {
        now = std::chrono::system_clock::now();
        current_time = std::chrono::system_clock::to_time_t(now);
        std::cout << std::put_time(std::localtime(&current_time), "%H:%M:%S") << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}