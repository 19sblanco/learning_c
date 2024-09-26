#include "knap_sack.c"


void test_set_0(int n, int *array) {
    int i;
    for (i = 0; i < n; i++) {
        array[i] = 0;
    }
}

int test_equal(int n, int *arr1, int *arr2) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

void ks_test0() {
    printf("=== test 0 ===\n");
    int n = 1;
    int w = 0;
    int test_weights[n];
    int test_values[n];
    test_set_0(n, test_weights);
    test_set_0(n, test_values);
    weights[0] = 1;
    values[0] = 1;

    int starting_knap_sack[n];
    test_set_0(n, starting_knap_sack);
    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, 0, starting_knap_sack);
    
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