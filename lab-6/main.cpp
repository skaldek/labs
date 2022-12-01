#include <Calculate.h>
#include "Write.h"
#include "Read.h"

int main() {
    int n;
    int matrix[100][100];
    lab::read(matrix, n);

    lab::calculate(matrix, n);

    lab::write(matrix, n);
}
