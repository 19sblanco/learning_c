#include <stdio.h>

#define bit0 (1 << 0)
#define bit1 (1 << 1) 
#define bit2 (1 << 2)
#define bit3 (1 << 3)
#define bit7 (1 << 7)
#define bit30 (1 << 30)
#define bit31 (1 << 31)


void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf(" (%u)\n", num);
}

unsigned int mark_as_visited(unsigned int n, unsigned int position) {
    n &= ~(1 << position);
    return n;
}

/*
(complete) create 2 functions:
    1. a function that can set any bit to 0 
    2. a function to create a number that has all 1's till a position x

have a way to visit an unvisited city
*/

unsigned int set_available_cities(unsigned int n) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        ret |= (1 << i);
    }
    return ret;
}


void visit_each_city(int n, unsigned int available_cities) {
    for (int i = 0; i < n; i++) {
        if ((available_cities >> i) & 1) {
            unsigned int new_available_cities = mark_as_visited(available_cities, i);
            printBinary(new_available_cities);
        }
    }

}

int main() {
    int n = 8;
    int available_cities = set_available_cities(n);
    printBinary(available_cities);
    visit_each_city(n, available_cities);

    return 0;
}