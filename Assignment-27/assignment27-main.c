#include <unistd.h>
void main()
{
char str[13]="Hello, World!";
write(1, str, sizeof(str)); // printf is too main-stream
}
