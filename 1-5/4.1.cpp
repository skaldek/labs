#include <iostream>
#define N 10000
int main() {
    int n = 0;
    std::cin >> n;
    int arr[N];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    bool flag = false;
    for (int i = 0; i < n; i++) {
        int sum = 0, m;
        int c = arr[i];
        while (c > 0) {
            m = c % 10;
            sum = sum + m;
            c = c / 10;
        }
        if (sum == 14) {
            flag = true;
            break;
        }
    }
    if (flag) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[i]) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
}
