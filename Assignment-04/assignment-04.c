#include <stdio.h>
#define PIE 3.14f

int main(void) {
	float radius;
	printf("Enter the radius of your circle: ");
	scanf("%f", &radius);
	float area = PIE * radius * radius;
	printf("The area of your circle is %f", area);

	return 0;
}
