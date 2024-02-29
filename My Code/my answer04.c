/* 
Prompt the user to input the length of a radius and then print the area of the user's circle to the terminal.

Extra credit: Use the `#define` feature of C to assign the value `3.14` to `PIE`.
*/


/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

int main() {

/* 
Prompt the user to input the length of a radius and then print the area of the user's circle to the terminal.

Extra credit: Use the `#define` feature of C to assign the value `3.14` to `PIE`.
*/



float radius = 0;
printf("Enter length of radius: ");
scanf("%f",&radius);


 float area;
  area = 3.14 * (radius * radius);
  printf("\nthe area is: %f",area);
    return 0;
}
