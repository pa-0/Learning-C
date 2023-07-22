#include <unistd.h>
#include <dlfcn.h>
#include <string.h>

ssize_t write(int fd, const void *buf, size_t count) {
    ssize_t (*good_write)(int fd, const void *buf, size_t count);
    ssize_t write_result;

    good_write = dlsym(RTLD_NEXT, "write");

    if (strcmp((char *)buf, "Hello, world!\n") == 0) {
        write_result = write(fd, "Goodbye, cruel world!\n", 22);
    } else {
        write_result = write(fd, buf, count);
    }

    return write_result;
}
