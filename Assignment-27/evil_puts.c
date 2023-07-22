#include <string.h>
#include <unistd.h>
#include <dlfcn.h>

int puts(const char *message) {
    int (*new_puts)(const char *message);
    int result;
    new_puts = dlsym(RTLD_NEXT, "puts");

    if(strcmp(message, "Hello, world!") == 0) {
        result = new_puts("Goodbye, cruel world!");
    } else {
        result = new_puts(message);
    }

    return result;
}
