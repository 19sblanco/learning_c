#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"


int main() {
    srand(time(NULL)); // set random seed
    int w = 100; // max weight in knap sack
    int n = 10; // number of total items to choose from
    int weights[n]; // weights of each item
    int values[n]; // values of each item
    int max = 50;
    int min = 1;
    for (int i = 0; i < n; i++) {
        int a = rand() % (max - min + 1) + min;
        weights[i] = a;
        int b = rand() % (max - min + 1) + min;
        values[i] = b;
    }
    printf("weights\n");
    print_array(n, weights);
    printf("value\n");
    print_array(n, values);
    int starting_knap_sack[n];
    set_0(n, starting_knap_sack);
    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, 0, starting_knap_sack, weights, values, w, n);
    printf("max_value: %d\n", max_value);
    printf("knap_sack: ");
    print_array(n, ret_sack);

    return 0;
}

