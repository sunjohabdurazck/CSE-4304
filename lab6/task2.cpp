#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class Coordinate {
private:
    float x;
    float y;

public:
    Coordinate() : x(0), y(0) {}
    Coordinate(float x_val, float y_val) : x(x_val), y(y_val) {}

    void display() const {
        cout << "Coordinate: (" << x << ", " << y << ")" << endl;
    }

    float distance(const Coordinate& other) const {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    float getDistance() const {
        return sqrt(x * x + y * y);
    }

    void move_x(float val) {
        x += val;
    }

    void move_y(float val) {
        y += val;
    }

    void move(float x_val, float y_val) {
        x += x_val;
        y += y_val;
    }


    bool operator>(const Coordinate& other) const { return getDistance() > other.getDistance(); }
    bool operator<(const Coordinate& other) const { return getDistance() < other.getDistance(); }
    bool operator>=(const Coordinate& other) const { return getDistance() >= other.getDistance(); }
    bool operator<=(const Coordinate& other) const { return getDistance() <= other.getDistance(); }
    bool operator==(const Coordinate& other) const { return getDistance() == other.getDistance(); }
    bool operator!=(const Coordinate& other) const { return getDistance() != other.getDistance(); }
};



void randomAssignment(Coordinate c[], int size) {
    for (int i = 0; i < size; ++i) {
        c[i] = Coordinate(rand() % 100, rand() % 100);
    }
}

void highest(const Coordinate c[], int size) {
    Coordinate maxCoord = c[0];
    for (int i = 1; i < size; ++i) {
        if (c[i] > maxCoord) {
            maxCoord = c[i];
        }
    }
    maxCoord.display();
}

void lowest(const Coordinate c[], int size) {
    Coordinate minCoord = c[0];
    for (int i = 1; i < size; ++i) {
        if (c[i] < minCoord) {
            minCoord = c[i];
        }
    }
    minCoord.display();
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Coordinate coord[10];
    randomAssignment(coord, 10);
    cout << "Coordinate with highest distance:" <<endl;
    highest(coord, 10);
    cout << "Coordinate with lowest distance:" << endl;
    lowest(coord, 10);
    return 0;
}
