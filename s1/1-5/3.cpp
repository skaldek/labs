#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    int a[n];
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int product = 1;
    int min = a[0];
    int minIndex = 0;
    for (int i = 0; i < (sizeof a / sizeof(*a)); i++) {
        bool insideRange = (a[i] >= -2) && (a[i] <= 20);
        if (!insideRange) {
            continue;
        }
        product *= a[i];
        if (min <= a[i]) {
            continue;
        }
        min = a[i];
        minIndex = i;
    }

    std::cout << "Произведение: " << product << std::endl;
    std::cout << "Минимальное: " << min << std::endl;
    std::cout << "Его номер: " << minIndex + 1 << std::endl;
}