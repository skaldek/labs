#include <Calculate.h>
#include <cmath>

namespace lab {
    bool isPrime(int x) {
        if (x < 2)
            return false;
        for (int d = 2; d <= sqrt(x); d++) {
            if (x % d == 0)
                return false;
        }
        return true;
    }

    void calculate(int matrix[100][100], int n) {
        bool flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int counter = 0;
                for (int c = 0; c < n; c++) {
                    if (matrix[i][c] == matrix[j][c] && i != j) {
                        counter++;
                    }
                }
                if (counter == n) {
                    flag = true;
                }
            }
        }

        if (flag) {
            int max = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] > max && lab::isPrime(matrix[i][j])) {
                        max = matrix[i][j];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                int min = 1e9;
                for (int j = 0; j < n; j++) {
                    if (matrix[j][i] < min) {
                        min = matrix[j][i];
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (matrix[j][i] == min) {
                        matrix[j][i] = max;
                    }
                }
            }
        }
    }

}