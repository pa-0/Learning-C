#include <stdio.h>
#include <math.h>

// calculate the roots of a quadratic polynomial ax^2+bx+c
// positive root is first, negative root second in the roots array
void quadraticFormula(double roots[2], int a, int b, int c) {
    double discriminant = sqrt(pow(b, 2) - 4*a*c);

    // negative b plus or minus the square root of b-squared minus 4ac all over 2a
    roots[0] = (-b + discriminant) / (2*a);
    roots[1] = (-b - discriminant) / (2*a);
}

int isRoot(x,a,b,c) {
    return a*x*x+b*x+c == 0;
}

int main() {
    int a,b,c;
    double roots[2];

    // prompt the user for input
    printf("Enter the value of variable 'A': ");
    scanf("%d", &a);
    printf("Enter the value of variable 'B': ");
    scanf("%d", &b);
    printf("Enter the value of variable 'C': ");
    scanf("%d", &c);

    // compute the roots
    quadraticFormula(roots,a,b,c);

    // test the output and print
    if (isRoot(roots[0],a,b,c) == 1) {
        printf("The solution using the '+' operator is: %f\n", roots[0]);
    } else {
        printf("The solution using the '+' operator is: %f, but you might want to double-check that...\n", roots[0]);
    }
    
    if (isRoot(roots[1],a,b,c) == 1) {
        printf("The solution using the '-' operator is: %f\n", roots[1]);
    } else {
        printf("The solution using the '-' operator is: %f, but you might want to double-check that...\n", roots[1]);
    }
    
    return 0;
}