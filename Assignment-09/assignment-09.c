#include <stdio.h>

void capitalize(char *string) {
  if (*string >= 97 && *string <= 122) {
    *string -= 32;
  }
}

int main(int argc, char *argv[]) {
  
  if (argc != 3) {
    printf("Usage: ./09 firstname lastname\n");
    return 1;
  }

  capitalize(argv[1]);
  capitalize(argv[2]);

  printf("Hello, %s %s.\n", argv[1], argv[2]);
    
  return 0;
}
