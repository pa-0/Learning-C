#include <stdio.h>

#define PI 3.14

float areaCircle(float radius) {
    return radius * radius * PI;
}

int main() {
    float r;

    printf("Enter the radius of your circle: ");
    scanf("%f", &r);

    printf("The area of your circle is %f\n", areaCircle(r));

    return 0;
}
