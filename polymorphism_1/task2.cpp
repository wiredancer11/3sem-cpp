struct Inequality {
    double a;
    double b;
    Inequality(double a, double b) {
        if (a >= b) {
            this->a = a;
            this->b = b;
        } else {
            this->b = a;
            this->a = b;
        }
    }

    double consider(double x) {
        double new_a;
        double new_b;
        double min;
        
        if (x >= a) {
            new_a = x;
            new_b = a;
            min = b;
        } else if (x >= b) {
            new_a = a;
            new_b = x;
            min = b;
        } else {
            new_a = a;
            new_b = b;
            min = x;
        }
        a = new_a;
        b = new_b;
        return min;
    }

};

struct TernaryInequality : Inequality{
    double c;
    TernaryInequality(double a, double b, double c) : Inequality(a,b) {
        double new_a, new_b, new_c;
        if (c >= a) {
            new_a = c;
            new_b = a;
            new_c = b;
        } else if (c >=b) {
            new_a = a;
            new_b = c;
            new_c = b;
        } else {
            new_a = a;
            new_b = b;
            new_c = c;
        }
        this->a = new_a;
        this->b = new_b;
        this->c = new_c;
    }

    double consider(double x) {
        double min;
        if (x > c) {
            min = c;
            c = Inequality::consider(x);
            return c;
        }
        return x;
    }
};