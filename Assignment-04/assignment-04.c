#include <stdio.h>

#define PI 3.14

int main() {
    float radius;
    float area;

    printf("Enter the radius of your circle: ");
    scanf("%f", &radius);

    area = PI * (radius * radius);

    printf("The area of your circle is %f\n", area);

    return 0;
}