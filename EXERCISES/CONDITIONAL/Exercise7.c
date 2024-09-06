/*
Write a C program to accept the height of a person in centimeters and categorize the person according to their height.
Test Data : 135
Expected Output :
The person is Dwarf.
*/

#include <stdio.h>

int main(){

    int height;

    printf("Enter your height in cm: ");
    scanf("%d", &height);

    if(height < 150){
        printf("The person is a Dwarf.");
    }
    else if(height >= 150 && height < 170){
        printf("The person is Short.");
    }
    else if(height >= 190 && height <= 200){
        printf("The person is Very Tall.");
    }
    else if(height >= 180 && height <= 190){
        printf("The person is Tall.");
    }
    else if(height >= 170 && height <= 180){
        printf("The person is Average.");
    }
    else if(height > 200){
        printf("The person is a Giant.");
    }

    return 0;
}