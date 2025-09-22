#include <mutex>
#include <vector>
#include <iostream>
#include <random>
#include <cstdlib>
#include <chrono>
#include <thread>

int object;
bool flag = false;
bool work1 = true, work2 = false;
std::vector<int> v1, v2;

std::mutex m;

void factory() {
    while(work1) {
        if (flag) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        } else {
            object = rand() % 100000;
            v1.push_back(object);
            flag = true;
        }
    }
}


void consumer() {
    while(work2) {
        if (!flag) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        } else {
            v2.push_back(object);
            flag = false;
        }
    }
}

void check_all() {
    std::thread t1(factory);
    std::thread t2(factory);

    std::thread t3(consumer);
    std::thread t4(consumer);
    std::thread t5(consumer);
    work1 = true;
    work2 = true;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    work1 = false;
    work2 = false;
    
    for (auto el : v1) {std::cout << el << ", ";}
    std::cout << "\nlel\n";
    for (auto el : v2) {std::cout << el << ", ";}


    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

}

void factory_m() {
    while(work1) {
        m.lock();
        if (flag) {
            m.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        } else {
            object = rand() % 100000;
            v1.push_back(object);
            flag = true;
            m.unlock();
        }
    }
}

void consumer_m() {
    while(work2) {
        m.lock();
        if (!flag) {
            m.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        } else {
            v2.push_back(object);
            flag = false;
            m.unlock();
        }
    }
}

void check_all_m() {
    std::thread t1(factory_m);
    std::thread t2(factory_m);

    std::thread t3(consumer_m);
    std::thread t4(consumer_m);
    std::thread t5(consumer_m);
    work1 = true;
    work2 = true;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    work1 = false;
    work2 = false;
    
    for (auto el : v1) {std::cout << el << ", ";}
    std::cout << "\n\n";
    for (auto el : v2) {std::cout << el << ", ";}


    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

}

int main(){
    check_all();
}