#include <stdio.h>
#include "lib.c"

void show_results(int test_id, int expected, int got) {
    printf(" === test: %d === \n", test_id);
    if (expected == got) {
        ;
    } else {
        printf("Incorrect!\nExpected: %d\nGot: %d", expected, got);
    }
    printf(" === === \n");
}

void test_coin_change0() {
    int amount = 0;
    int change = coin_change(amount);
    int expected = 0;
    show_results(0, expected, change);
}


int main() {
    test_coin_change0();

    return 0;
}