#include <iostream>

int main() {
    short n;
    std::cin >> n;
    for (int i = 0; i < sizeof(int); i++) {
        std::cout << (int) (*((char *) &n + i)) << " ";
    }
}
