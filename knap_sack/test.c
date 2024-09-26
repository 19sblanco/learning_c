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

    int starting_knap_sack[n];
    set_0(n, starting_knap_sack);
    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, 0, starting_knap_sack, weights, values, w, n);
    
    int expected_sack[1] = {0};
    int expected_value = 0;
    if (test_equal(n, expected_sack, ret_sack) && expected_value == max_value) {
        printf("Correct!\n");
    } else {
        printf("Incorrect :(");
    }
    printf("=== ===\n");
}




int main() {

    return 0;
}