#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool isAlphabeticOrder(std::string s) {
    int n = s.length();
    std::string c = s;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i] > c[j]) {
                std::swap(c[i], c[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (c[i] != s[i])
            return false;

    return true;
}

bool checkContainment(std::string *arr, std::string s, int N) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == s) {
            return true;
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::ifstream in("../input.txt");
    if (!in.is_open())
        return 0;

    std::string line;
    getline(in, line);
    int N = std::stoi(line);

    std::string text;
    while (getline(in, line)) {
        text += line + " ";
    }
    in.close();

    text.erase(std::remove_if(text.begin(), text.end(), ispunct), text.end());

    std::istringstream iss(text);
    std::string s;
    int n = 0;
    while (getline(iss, s, ' ')) {
        n++;
    }
    std::string arr[n];
    n = 0;
    std::istringstream iss2(text);
    while (getline(iss2, s, ' ')) {
        arr[n] = s;
        n++;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].length() < arr[j].length()) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    std::ofstream out;
    out.open("../output.txt");
    int counter = N;
    std::string current[n];
    if (out.is_open()) {
        for (int i = 0; i < n; i++) {
            if (isAlphabeticOrder(arr[i]) && !checkContainment(current, arr[i], n)) {
                current[i] = arr[i];
                out << arr[i] << std::endl;
                counter--;
                if (counter == 0) {
                    break;
                }
            }
        }
    }
    out.close();
}