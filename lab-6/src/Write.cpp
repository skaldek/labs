#include <Write.h>
#include <fstream>

namespace lab {
    void write(int matrix[100][100], int n) {
        std::ofstream out;
        out.open("../output.txt");
        if (out.is_open()) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out << matrix[i][j] << " ";
                }
                out << std::endl;
            }
        }
        out.close();
    }
}