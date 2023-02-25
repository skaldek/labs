#include <iostream>
#include <cmath>

class Cube {
private:
    int m_a;
public:
    Cube(int a) {
        m_a = a;
    }

    bool setSideLength(int a) {
        if (a <= 0) {
            std::cout << "Error in length of the side" << std::endl;
            return false;
        }
        m_a = a;
    }

    float getDiagonalLength() {
        return m_a * sqrt(3);
    }
};

int main() {
    Cube cube = Cube(10);
    cube.setSideLength(-10);
    std::cout << cube.getDiagonalLength();
}
