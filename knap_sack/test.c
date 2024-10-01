#include <stdio.h>
#include "lib.h"


int test_equal(int n, int *a, int *b) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void ks_test0() {
    printf("=== test 0 ===\n");
    int n = 1;
    int w = 0;
    int weights[n];
    int values[n];
    set_0(n, weights);
    set_0(n, values);
    weights[0] = 1;
    values[0] = 1;

    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, weights, values, n, w);
    
    int expected_sack[1] = {0};
    int expected_value = 0;
    if (test_equal(n, expected_sack, ret_sack) && expected_value == max_value) {
        printf("Correct!\n");
    } else {
        printf("Incorrect :(");
    }
    printf("=== ===\n");
}

void ks_test1() {
    printf("=== test 1 ===\n");
    int n = 3;
    int w = 4;
    int weights[3] = {2, 2, 3};
    int values[3] = {2, 2, 3};

    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, weights, values, n, w);
    
    int expected_sack[3] = {1, 1, 0};
    int expected_value = 4;
    if (test_equal(n, expected_sack, ret_sack) && expected_value == max_value) {
        printf("Correct!\n");
    } else {
        printf("Incorrect :(");
    }
    printf("=== ===\n");
    
}

void ks_test2() {
    printf("=== test 2 ===\n");
    int n = 4;
    int w = 4;
    int weights[4] = {1, 1, 1, 1};
    int values[4] = {1, 1, 1, 1};

    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, weights, values, n, w);
    
    int expected_sack[4] = {1, 1, 1, 1};
    int expected_value = 4;
    if (test_equal(n, expected_sack, ret_sack) && expected_value == max_value) {
        printf("Correct!\n");
    } else {
        printf("Incorrect :(");
    }
    printf("=== ===\n");
}

void ks_test3() {
    printf("=== test 3 ===\n");
    int n = 10;
    int w = 100;
    int weights[10] = {100, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int values[10] = {100, 1, 1, 1, 1, 1, 1, 1, 1, 1};


    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, weights, values, n, w);
    
    int expected_sack[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int expected_value = 100;
    if (test_equal(n, expected_sack, ret_sack) && expected_value == max_value) {
        printf("Correct!\n");
    } else {
        printf("Incorrect :(");
    }
    printf("=== ===\n");
}

void ks_test4() {
    printf("=== test 4 ===\n");
    int n = 10;
    int w = 99;
    int weights[10] = {100, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int values[10] = {100, 1, 1, 1, 1, 1, 1, 1, 1, 1};


    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, weights, values, n, w);
    
    int expected_sack[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int expected_value = 9;
    if (test_equal(n, expected_sack, ret_sack) && expected_value == max_value) {
        printf("Correct!\n");
    } else {
        printf("Incorrect :(");
    }
    printf("=== ===\n");
}

void ks_dymanic_test0() {
    printf("===  ks_dymanic_test0 ===\n");

    

    printf("=== ===\n");

}


int main() {
    ks_test0();
    ks_test1();
    ks_test2();
    ks_test3();
    ks_test4();

    return 0;
}