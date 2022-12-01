#include <iostream>
#include <random>

int main() {
    int rows, columns;
    std::cin >> rows;
    std::cin >> columns;

    int matrix[rows][columns];
    int minElement = INT32_MAX;
    int minElementColumn = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int element;
            std::cin >> element;
            matrix[i][j] = element;

            if (element < minElement) {
                minElement = element;
                minElementColumn = j;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][minElementColumn] < 0) {
            matrix[i][minElementColumn] = 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}