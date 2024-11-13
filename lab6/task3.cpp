#include <iostream>
#include <stdexcept>
using namespace std;

class Celsius;

class Fahrenheit {
private:
    float temperature;
public:
    Fahrenheit() : temperature(-459.67) {}
    Fahrenheit(float temp) {
        if (temp < -459.67) throw invalid_argument("Temperature cannot be below absolute zero.");
        temperature = temp;
    }

    void assign(float temp) {
        if (temp < -459.67) throw invalid_argument("Temperature cannot be below absolute zero.");
        temperature = temp;
    }

    void display() const {
       cout << "The temperature is " << temperature << " Fahrenheit." <<endl;
    }

    operator Celsius();
};

class Celsius {
private:
    float temperature;
public:
    Celsius() : temperature(-273.15) {}
    Celsius(float temp) {
        if (temp < -273.15) throw invalid_argument("Temperature cannot be below absolute zero.");
        temperature = temp;
    }

    void assign(float temp) {
        if (temp < -273.15) throw invalid_argument("Temperature cannot be below absolute zero.");
        temperature = temp;
    }

    void display() const {
        cout << "The temperature is " << temperature << " Celsius." <<endl;
    }

    operator Fahrenheit() {
        return Fahrenheit((temperature * 9 / 5) + 32);
    }
};

Fahrenheit::operator Celsius() {
    return Celsius((temperature - 32) * 5 / 9);
}

int main() {
    Celsius c1(95);
    c1.display();

    Fahrenheit f1 = c1;
    f1.display();

    f1.assign(60);
    f1.display();

    Celsius c2 = f1;
    c2.display();

    return 0;
}
