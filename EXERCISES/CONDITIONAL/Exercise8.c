/*
 Write a C program to find the largest of three numbers.
Test Data : 12 25 52
Expected Output :
1st Number = 12,        2nd Number = 25,        3rd Number = 52
The 3rd Number is the greatest among the three
*/

#include <stdio.h>

int main(){

    int num1, num2, num3;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    printf("\nEnter the third number: ");
    scanf("%d", &num3);

    printf("\nFirst number = %d,      Second number = %d,     Third number = %d\n", num1, num2, num3);

    if(num1 > num2 && num3 < num1){
        printf("The First number is the greatest among the three");
    }
    else if(num2 > num1 && num1 > num3){
        printf("The Second number is the greatest among the three");
    }
    else{
        printf("The Third number is the greatest among the three");
    }

    return 0;
}