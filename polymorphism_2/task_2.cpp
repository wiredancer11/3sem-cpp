#include <iostream>
#include <new>
#include <cmath>

class Expression {
    public:
    virtual void print() =0;

    virtual double calculate(double x) = 0;

    virtual Expression* getDerivative() = 0;

    virtual Expression* copy() = 0;

    virtual ~Expression() {}
};

class Constant : public Expression {
    double c;

    public:
    Constant(double c) : c(c) {}

    double calculate(double x) {
        return c;
    }

    void print() {
        std::cout << c;
    }

    Expression* copy() {
        return new Constant(c);
    }

    Expression* getDerivative() {
        return new Constant(0);
    }
};

class Variable : public Expression {
    public:
    double calculate(double x) {
        return x;
    }

    void print() {
        std::cout << "x";
    }

    Expression* copy() {
        return new Variable();
    }

    Expression* getDerivative() {
        return new Constant(1);
    }
};

class Sum : public Expression {
    private:
    Expression* expr1;
    Expression* expr2;
    public:
    Sum() {}
    Sum(Expression* expr1, Expression* expr2) : expr1(expr1), expr2(expr2){}

    double calculate(double x) {
        return expr1->calculate(x) + expr2->calculate(x);
    }

    void print() {
        std::cout << "(";
        expr1->print();
        std::cout << ")";

        std::cout << " + ";

        std::cout << "(";
        expr2->print();
        std::cout << ")";
    }

    Expression* getDerivative() {
        return new Sum(expr1->getDerivative(), expr2->getDerivative());
    }

    Expression* copy() {
        return new Sum(expr1->copy(), expr2->copy());
    }

    ~Sum() {
        delete expr1;
        delete expr2;
    }
};

class Sub : public Expression {
    private:
    Expression* expr1;
    Expression* expr2;
    public:
    Sub() {}
    Sub(Expression* expr1, Expression* expr2) : expr1(expr1), expr2(expr2){}

    double calculate(double x) {
        return expr1->calculate(x) - expr2->calculate(x);
    }

    void print() {
        std::cout << "(";
        expr1->print();
        std::cout << ")";

        std::cout << " - ";

        std::cout << "(";
        expr2->print();
        std::cout << ")";
    }

    Expression* getDerivative() {
        return new Sub(expr1->getDerivative(), expr2->getDerivative());
    }

    Expression* copy() {
        return new Sub(expr1->copy(), expr2->copy());
    }

    ~Sub() {
        delete expr1;
        delete expr2;
    }
};

class Mul : public Expression {
    private:
    Expression* expr1;
    Expression* expr2;
    public:
    Mul() {}
    Mul(Expression* expr1, Expression* expr2) : expr1(expr1), expr2(expr2){}

    double calculate(double x) {
        return expr1->calculate(x) * expr2->calculate(x);
    }

    void print() {
        std::cout << "(";
        expr1->print();
        std::cout << ")";

        std::cout << " * ";

        std::cout << "(";
        expr2->print();
        std::cout << ")";
    }

    Expression* getDerivative() {
        Expression* mul1 = new Mul(expr1->getDerivative(), expr2->copy());
        Expression* mul2 = new Mul(expr1->copy(), expr2->getDerivative());
        return new Sum(mul1, mul2);
    }

    Expression* copy() {
        return new Mul(expr1->copy(), expr2->copy());
    }
    ~Mul() {
        delete expr1;
        delete expr2;
    }

};

class Div : public Expression {

    private:
    Expression* expr1;
    Expression* expr2;
    public:
    Div() {}
    Div(Expression* expr1, Expression* expr2) : expr1(expr1), expr2(expr2){}

    double calculate(double x) {
        return expr1->calculate(x) / expr2->calculate(x);
    }

    void print() {
        std::cout << "(";
        expr1->print();
        std::cout << ")";

        std::cout << " / ";

        std::cout << "(";
        expr2->print();
        std::cout << ")";
    }

    Expression* getDerivative() {
        Expression* mul1 = new Mul(expr1->getDerivative(), expr2->copy());
        Expression* mul2 = new Mul(expr1->copy(), expr2->getDerivative());
        Expression* sub = new Sub(mul1, mul2);
        Expression* square = new Mul(expr2->copy(), expr2->copy());
        return new Div(sub, square);
    }

    Expression* copy() {
        return new Div(expr1->copy(), expr2->copy());
    }
    ~Div() {
        delete expr1;
        delete expr2;
    }
};

class Sin : public Expression {
    private:
    Expression* expr;
    public:
    Sin() {}
    Sin(Expression* expr) : expr(expr){}

    double calculate(double x) {
        return std::sin(expr->calculate(x));
    }

    void print() {
        std::cout << "sin(";
        expr->print();
        std::cout << ")";

    }

    Expression* getDerivative();


    Expression* copy() {
        return new Sin(expr->copy());
    }
    ~Sin() {
        delete expr;
        
    }

};


class Cos: public Expression {
    private:
    Expression* expr;
    public:
    Cos() {}
    Cos(Expression* expr) : expr(expr){}

    double calculate(double x) {
        return std::cos(expr->calculate(x));
    }

    void print() {
        std::cout << "cos(";
        expr->print();
        std::cout << ")";

    }

    Expression* getDerivative() {
        Expression* sin = new Sin(expr->copy());
        Expression* negSin = new Mul(new Constant(-1), sin); 
        Expression* innerDer = expr->getDerivative();
        return new Mul(negSin, innerDer);
    }

    Expression* copy() {
        return new Cos(expr->copy());
    }
    ~Cos() {
        delete expr;
        
    }

};

Expression* Sin::getDerivative() {
    Expression* cos = new Cos(expr->copy());
    Expression* innerDer = expr->getDerivative();
    return new Mul(cos, innerDer);
}


class Exp : public Expression {
    private:
    Expression* expr;
    public:
    Exp() {}
    Exp(Expression* expr) : expr(expr){}

    double calculate(double x) {
        return std::exp(expr->calculate(x));
    }

    void print() {
        std::cout << "exp(";
        expr->print();
        std::cout << ")";

    }

    Expression* getDerivative() {
        Expression* innerDer = expr->getDerivative();
        return new Mul(copy(), innerDer);
    }

    Expression* copy() {
        return new Exp(expr->copy());
    }
    ~Exp() {
        delete expr;
        
    }

};

class Log : public Expression {
    private:
    Expression* expr;
    public:
    Log() {}
    Log(Expression* expr) : expr(expr){}

    double calculate(double x) {
        return std::log(expr->calculate(x));
    }

    void print() {
        std::cout << "ln(";
        expr->print();
        std::cout << ")";

    }

    Expression* getDerivative() {
        Expression* innerDer = expr->getDerivative();
        return new Div(innerDer, expr->copy());
    }

    Expression* copy() {
        return new Log(expr->copy());
    }

    ~Log() {
        delete expr;
    }

};


int main() {
    Expression* var = new Variable();
    Expression* c = new Constant(2);

    Expression* sum = new Sum(var, c);
    Expression* sin = new Sin(sum);

    sin->print();
    std::cout << std::endl << sin->calculate(-2) << std::endl;

    Expression* derivative = sin->getDerivative();
    derivative->print();
    std::cout << std::endl << derivative->calculate(-2);

    delete sin;
    delete derivative;
}