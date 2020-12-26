#include <unistd.h>
void main()
{
char str[12]="Hello World";
write(1, str, sizeof(str)); // printf is too main-stream
}
