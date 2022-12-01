#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A > B && B > C) {
        cout << A - B - C;
    } else if (B > A && B % C == 0) {
        cout << B / C + B - A;
    } else {
        cout << A + B + C;
    }
}
