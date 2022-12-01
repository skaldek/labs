#include <Read.h>
#include <string>
#include <fstream>
#include <sstream>

namespace lab {
    void read(int matrix[100][100], int &n) {
        std::string line;
        std::ifstream in("../input.txt");
//        if (!in.is_open())
//            return 0;
        getline(in, line);
        n = std::stoi(line);
        int lineM = 0;
        int columnM = 0;
        while (getline(in, line)) {
            std::istringstream iss(line);
            std::string s;
            while (getline(iss, s, ' ')) {
                matrix[lineM][columnM] = std::stoi(s);
                columnM++;
            }
            lineM++;
            columnM = 0;
        }
        in.close();
    }
}