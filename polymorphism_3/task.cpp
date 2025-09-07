struct Real ;
struct Integer ;
struct Complex;
struct Number {
    virtual ~Number() {}
    virtual Number* operator+(const Number&) const = 0;
    virtual Number* operator+ (const Integer&) const = 0;
    virtual Number* operator+(const Real&) const = 0;
};

struct Integer : Number {
    int n;
    Number* operator+(const Number &x) const {
        return x + *this;
    }

    Number* operator+(const Integer &x) const {
        Integer* result = new Integer();
        result->n = n+x.n;
        return result; 
    } 

    Number* operator+(const Real &x) const;

    Number* operator+(const Complex &x) const;
};

struct Real : Number {
    double a;
    Number* operator+(const Number &x) const {
        return x + *this;
    }

    Number* operator+(const Integer &x) const {
        Real* result = new Real();
        result->a = a + x.n;
        return result; 
    } 

    Number* operator+(const Real &x) const{
        Real* result = new Real();
        result->a = a+x.a;
        return result;
    }

    Number* operator+(const Complex &x) const;
};


struct Complex : Number {
    double re;
    double im;
    Number* operator+(const Number &x) const {
        return x + *this;
    }

    Number* operator+(const Integer &x) const {
        Complex* result = new Complex();
        result->re = re + x.n;
        result->im = im;
        return result; 
    } 

    Number* operator+(const Real &x) const{
        Complex* result = new Complex();
        result->re = re + x.a;
        return result;
    }

    Number* operator+(const Complex &x) const {
        Complex* result = new Complex();
        result->re = re + x.re;
        result->im = im + x.im;
        return result;
    }
};

Number* Integer::operator+(const Real & x) const {
    Real* result = new Real();
    result->a = n + x.a;
    return result;
}

Number* Integer::operator+(const Complex &x) const {
    Complex* result = new Complex();
    result->re = n + x.re;
    result->im = x.im;
    return result;
}

Number* Real::operator+(const Complex &x) const {
    Complex* result = new Complex();
    result->re = a + x.re;
    result->im = x.im;
    return result;
}