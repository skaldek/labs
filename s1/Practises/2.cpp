#include <iostream>
#include <vector>

// Считаем в столбик
std::string sum(std::string A, std::string B) {
    if (A.size() < B.size())
        swap(A, B);

    int j = A.size() - 1;
    for (int i = B.size() - 1; i >= 0; i--, j--)
        A[j] += (B[i] - '0');

    for (int i = A.size() - 1; i > 0; i--) {
        if (A[i] > '9') {
            int d = A[i] - '0';
            A[i - 1] = ((A[i - 1] - '0') + d / 10) + '0';
            A[i] = (d % 10) + '0';
        }
    }
    if (A[0] > '9') {
        std::string k;
        k += A[0];
        A[0] = ((A[0] - '0') % 10) + '0';
        k[0] = ((k[0] - '0') / 10) + '0';
        A = k + A;
    }
    return A;
}

// Тоже
std::string mul(std::string A, std::string B) {
    std::vector<int> result(A.size() + B.size(), 0);
    int c1 = 0, c2;
    for (int i = A.size() - 1; i >= 0; i--) {
        int index = 0;
        int n1 = A[i] - '0';

        c2 = 0;

        for (int j = B.size() - 1; j >= 0; j--) {
            int n2 = B[j] - '0';
            int sum = n1 * n2 + result[c1 + c2] + index;
            index = sum / 10;
            result[c1 + c2] = sum % 10;
            c2++;
        }
        if (index > 0)
            result[c1 + c2] += index;
        c1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    std::string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

int main() {
    std::cout << sum("123", "999999") << std::endl;
    std::cout << mul("123", "999999");
}