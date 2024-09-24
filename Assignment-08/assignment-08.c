#include <stdio.h>

int main(void) {
  int number; 

  printf("Enter a number between '1' and '500': ");
  scanf("%d", &number);

  if (number < 1 || number > 500) {
    printf("Your number is not in any of our ranges.\n");
    return 0;
  }

  if (number <= 100) {
    printf("Your number is between '1' and '100'.\n");
    return 0;
  }

  if (number <= 200) {
    printf("Your number is between '101' and '200'.\n");
    return 0;
  }

  if (number <= 300) {
    printf("Your number is between '201' and '300'.\n");
    return 0;
  }

  if (number <= 400) {
    printf("Your number is between '301' and '400'.\n");
    return 0;
  }

  if (number <= 500) {
    printf("Your number is between '401' and '500'.\n");
    return 0;
  }


  return 0;
}
