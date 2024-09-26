#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.c"


int* weights; // weights of each item
int* values; // values of each item
int w = 100; // max weight in knap sack
int n = 10; // number of total items to choose from

int main() {
    srand(time(NULL)); // set random seed
    int weights_array[n];
    int values_array[n];
    weights = weights_array;
    values = values_array;
    int max = 50;
    int min = 1;
    for (int i = 0; i < n; i++) {
        int a = rand() % (max - min + 1) + min;
        weights[i] = a;
        int b = rand() % (max - min + 1) + min;
        values[i] = b;
    }
    printf("weights\n");
    print_array(weights);
    printf("value\n");
    print_array(values);
    int starting_knap_sack[n];
    set_0(starting_knap_sack);
    int ret_sack[n];
    int max_value = knap_sack_recursive(ret_sack, 0, starting_knap_sack);
    printf("max_value: %d\n", max_value);
    printf("knap_sack: ");
    print_array(ret_sack);

    return 0;
}

