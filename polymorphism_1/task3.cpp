#include <cmath>

class Calculator {
    protected:
    double x;
    public:
    Calculator() {
        x = 0;
    }
    double add(double y) {
       return x+=y; 
    }

    double sub(double y) {
        return x-=y;
    }

    double mul(double y) {
        return x*=y;
    }

    double div(double y) {
        return x/=y;
    }

    double sqrt() {
        x = std::sqrt(x);
        return x;
    }

    double sin() {
        x = std::sin(x);
        return x;
    }
};

class MemCalculator : Calculator {
    double mem;
    public:
    MemCalculator() : Calculator(), mem(0) {}
    void write() {
        mem = x;
    }
    void read() {
        x = mem;
    }
    double addFromMem() {
        return x+=mem;
    }
};