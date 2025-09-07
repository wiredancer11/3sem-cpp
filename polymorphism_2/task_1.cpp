class Property {
    protected:
    double worth;
    public:
    Property(double worth) : worth(worth) {}
    virtual double calculateTax() = 0;
    virtual ~Property();

};

class Apartment : public Property{
    public:
    Apartment(double worth) : Property(worth) {}
    double calculateTax() {
        return worth / 1000.0; 
    }
    ~Apartment() {}
};

class Car : public Property {
    public:
    Car(double worth) : Property(worth) {}
    double calculateTax() {
        return worth / 200.0;
    }
    ~Car();
};

class CountryHouse : public Property {
    public:
    CountryHouse(double worth) : Property(worth) {}
    double calculateTax() {
        return worth / 500.0;
    }
    ~CountryHouse();
};

int main() {
    Property* properties[7];

    properties[0] = new Apartment(500000);
    properties[1] = new Apartment(515000);
    properties[2] = new Apartment(630000);

    properties[3] = new Car(20000);
    properties[4] = new Car(35000);

    properties[5] = new CountryHouse(1000000);
    properties[6] = new CountryHouse(1500000);

    for (int i = 0; i < 7; i++) {
        delete properties[i];
    }
}