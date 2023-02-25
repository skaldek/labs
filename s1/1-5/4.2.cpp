#include <iostream>

int maxNum(int a) {
    std::string s = std::to_string(a);
    int max = INT_MIN;
    for (int i = 0; i < s.length(); i++) {
        int m = s[i] - '0';
        if (m > max) {
            max = m;
        }
    }
    return max;
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (std::to_string(arr[j])[0] < std::to_string(arr[i])[0]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (std::to_string(arr[j])[0] == std::to_string(arr[i])[0] && maxNum(arr[j]) < maxNum(arr[i])) {
                std::swap(arr[i], arr[j]);
            } else if (std::to_string(arr[j])[0] == std::to_string(arr[i])[0] && maxNum(arr[j]) == maxNum(arr[i])) {
                if (arr[j] < arr[i]) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}