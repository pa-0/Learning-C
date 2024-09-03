#include <stdlib.h>

// reserving memory for a struct of unknown size

int main() {
    typedef struct {
        int day;
        int month;
        int year;
    } date;

    date *d;
    d = malloc(sizeof(date));

    d->day = 31; d->month = 12; d->year = 1998;

    return 0;
}