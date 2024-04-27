#include <stdio.h>

#define PIE 3.14

int main()
{

    float radius;
    float area;

    printf("Enter the radius of the circle: \n");
    scanf("%f", &radius);

    area = PIE * (radius * radius);

    printf("The area of the circle is: %f", area);

    return 0;
}