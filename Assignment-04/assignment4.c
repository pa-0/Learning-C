#include <stdio.h>
//define a value for PIE
#define PIE 3.14

void main()
{
  //initialize variable
  float radius;
  float area;

  //get user input and store it
  printf("Enter the radius of your circle : ");
  scanf("%f", &radius);

  area = PIE * radius * radius;

  printf("The Area Of The Circle Is : %.2f", area);


}
