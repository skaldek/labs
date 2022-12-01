#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    bool flag = false;
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        int b = 0;
        for (int j = i + 1; j > 0; j /= 10) {
            b += j % 10;
        }
        if (b == 14) {
            flag = true;
            break;
        }
    }
    int r_arr[n];
    if (flag) {
        for (int i = n; i > 0; i--) {
            r_arr[n - i] = i;
        }
    } else {
        copy(arr, arr + n, r_arr);
    }
    for (int i = 0; i < n; i++) {
        cout << r_arr[i] << endl;
    }
}
