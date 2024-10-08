#include <stdio.h>
#include "lib.c"

void show_results(int test_id, int expected, int got) {
    printf(" === test: %d === \n", test_id);
    if (expected == got) {
        ;
    } else {
        printf("Incorrect!\nExpected: %d\nGot: %d\n", expected, got);
    }
    printf(" === === \n");
}

void test_coin_change0() {
    int amount = 0;
    int change = coin_change(amount);
    int expected = 0;
    show_results(0, expected, change);
}

void test_coin_change1() {
    int amount = 1;
    int change = coin_change(amount);
    int expected = 1;
    show_results(1, expected, change);
}

void test_coin_change2() {
    int amount = 14;
    int change = coin_change(amount);
    int expected = 14;
    show_results(2, expected, change);
}

void test_coin_change3() {
    int amount = 30;
    int change = coin_change(amount);
    int expected = 2;
    show_results(3, expected, change);
}

void test_coin_change4() {
    int amount = 45;
    int change = coin_change(amount);
    int expected = 3;
    show_results(4, expected, change);
}

void test_coin_change5() {
    int amount = 51;
    int change = coin_change(amount);
    int expected = 3;
    show_results(5, expected, change);
}


void test_coin_change_dynamic6() {
    int amount = 0;
    int change = coin_change_dynamic(amount);
    int expected = 0;
    show_results(6, expected, change);
}

void test_coin_change_dynamic7() {
    int amount = 1;
    int change = coin_change_dynamic(amount);
    int expected = 1;
    show_results(7, expected, change);
}

void test_coin_change_dynamic8() {
    int amount = 14;
    int change = coin_change_dynamic(amount);
    int expected = 14;
    show_results(8, expected, change);
}


void test_coin_change_dynamic9() {
    int amount = 30;
    int change = coin_change_dynamic(amount);
    int expected = 2;
    show_results(9, expected, change);
}

void test_coin_change_dynamic10() {
    int amount = 45;
    int change = coin_change_dynamic(amount);
    int expected = 3;
    show_results(10, expected, change);
}

void test_coin_change_dynamic11() {
    int amount = 51;
    int change = coin_change_dynamic(amount);
    int expected = 3;
    show_results(11, expected, change);
}

int main() {
    test_coin_change0();
    test_coin_change1();
    test_coin_change2();
    test_coin_change3();
    test_coin_change4();
    test_coin_change5();
    test_coin_change_dynamic6();
    test_coin_change_dynamic7();
    test_coin_change_dynamic8();
    test_coin_change_dynamic9();
    test_coin_change_dynamic10();
    test_coin_change_dynamic11();
    return 0;
}