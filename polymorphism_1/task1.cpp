struct DivCounter {
    int counterTwo;
    int counterThree;
    int counterFive;
    void consider(int n);
    DivCounter();
};

void DivCounter::consider(int n) {
    if (n % 2) counterTwo++;
    if (n % 3) counterThree++;
    if (n % 5) counterFive++;
}

DivCounter::DivCounter() : counterFive(0), counterThree(0), counterTwo(0){}

struct DivCounter2 : DivCounter {
    int counterSeven;
    void consider(int n);
    DivCounter2();
};

void DivCounter2::consider(int n) {
    DivCounter::consider(n);
    if (n % 7) counterSeven++;
}

DivCounter2::DivCounter2() : DivCounter(), counterSeven(0) {}

