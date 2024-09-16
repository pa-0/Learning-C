#include <stdio.h>
#include <math.h>

void getQuadraticSolutions(int A, int B, int C, double* x1, double* x2) {
    double delta = (B*B) - (4 * A * C);

    if (delta < 0) {
        *x1 = NAN;
        *x2 = NAN;
        return;
    }

    double x1_value = ((B * -1) + sqrt(delta)) / (2 * A);
    double x2_value = ((B * -1) - sqrt(delta)) / (2 * A);

    *x1 = x1_value;
    *x2 = x2_value;
}

int main() {
    int A, B, C;
    double x1, x2;

    printf("Enter the value of A: ");
    scanf("%d", &A);

    printf("Enter the value of B: ");
    scanf("%d", &B);

    printf("Enter the value of C: ");
    scanf("%d", &C);

    getQuadraticSolutions(A, B, C, &x1, &x2);

    if (x1 != x1 && x2 != x2) {
        printf("No real solutions.\n");
        return 0;
    }

    if (x1 == x2) {
        printf("Only one valid solution: %f.\n", x1);
        return 0;
    }

    printf("Solution one is: %f.\n", x1);
    printf("Solution two is: %f.\n", x2);

    return 0;
}