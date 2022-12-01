#include <iostream>

int main() {
    char s[100];
    std::cin >> s;

    int l = strlen(s);
    for (int i = 0; i < l; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            for (int j = i; j < l; j++) {
                s[j] = s[j + 1];
            }
            i--;
            l--;
        }
    }
    std::cout << s;
}
