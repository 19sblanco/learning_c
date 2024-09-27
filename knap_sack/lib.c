#include <stdio.h>
#include "lib.h"

void prepare_memo(int n, int w, int **memo) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w; j++) {
            memo[i][j] = 0;
        }
    }
}

void print_array(int n, int *array) {
    int i;
    for (i = 0; i < n-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[i]);
}

void set_0(int n, int *array) {
    int i;
    for (i = 0; i < n; i++) {
        array[i] = 0;
    }
}

void cp_array(int n, int *original, int *cp) {
    for (int i = 0; i < n; i++) {
        cp[i] = original[i];
    }
}

int countup_sack_value(int n, int *knap_sack, int *values) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (knap_sack[i] == 1) {
            total += values[i];
        }
    }
    return total;
}

int countup_sack_weight(int n, int *knap_sack, int *weights) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (knap_sack[i] == 1) {
            total += weights[i];
        }
    }
    return total;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

/*
given a sack of items with each item having a weight
and a value, find the most value that you can put
in your knap sack without exceeding its weight limit w.
Then return an array of each item (index) in the knap sack

curr_item is the index representing the current item
*curr_knap_sack is a pointer to an array where 1 represents
    an item in the knap sack and 0 represents an item not in the knapsack
*/
int knap_sack_recursive(int *ret_sack, int curr_item, int *curr_knap_sack, int *weights, int *values, int w, int n) {
    // base case
    // stop early
    int weight = countup_sack_weight(n, curr_knap_sack, weights);
    if (weight > w) { 
        return -1;
    }
    // check end
    if (curr_item == n) {
        cp_array(n, curr_knap_sack, ret_sack);
        int value = countup_sack_value(n, curr_knap_sack, values);
        return value;
    }
    // recursive step
    int ret1[n];
    int ret2[n];

    // add item to sack
    int add_curr_item[n];
    cp_array(n, curr_knap_sack, add_curr_item);
    add_curr_item[curr_item] = 1;
    int val1 = knap_sack_recursive(ret1, curr_item + 1, add_curr_item, weights, values, w, n);

    // don't add item to sack
    int dont_add[n];
    cp_array(n, curr_knap_sack, dont_add);
    int val2 = knap_sack_recursive(ret2, curr_item + 1, dont_add, weights, values, w, n);

    // return max(val1, val2);
    int best = max(val1, val2);
    if (best == val1) {
        cp_array(n, ret1, ret_sack);
        return val1;
    } else {
        cp_array(n, ret2, ret_sack);
        return val2;
    }
}

/*
knap sack using dynamic programming
*/
int knap_sack_dynamic(int *weights, int *values, int w, int n) {
    int memo[n][w]; // items, capacity
    prepare_memo(n, w, memo);
    int value = knap_sack_dynamic_helper(weights, values, w, n, memo, w, ?);
    return value;

}

int knap_sack_dynamic_helper(int *weights, int *values, int w, int n, int **memo, int capacity, int curr_item) {

}