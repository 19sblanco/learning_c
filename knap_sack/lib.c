#include <stdio.h>
#include "lib.h"

void prepare_memo(int n, int w, int (*memo)[w]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w; j++) {
            memo[i][j] = 0;
        }
    }
}

void print_memo(int n, int w, int (*memo)[w]) {
    printf("capacity\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w; j++) {
            if (j != w-1) {
                printf("%d, ", memo[i][j]);
            } else {
                printf("%d\n", memo[i][j]);
            }
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
int knap_sack_recursive(int *ret_sack, int *weights, int *values, int n, int w) {

    int starting_knap_sack[n];
    set_0(n, starting_knap_sack);
    int value = knap_sack_recursive_helper(ret_sack, 0, starting_knap_sack, weights, values, w, n);
    return value;
}

int knap_sack_recursive_helper(int *ret_sack, int curr_item, int *curr_knap_sack, int *weights, int *values, int w, int n) {
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
    int val1 = knap_sack_recursive_helper(ret1, curr_item + 1, add_curr_item, weights, values, w, n);

    // don't add item to sack
    int dont_add[n];
    cp_array(n, curr_knap_sack, dont_add);
    int val2 = knap_sack_recursive_helper(ret2, curr_item + 1, dont_add, weights, values, w, n);

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

memo:
    items representation: row (i) index into memo
    capacity representation: col (j) index into memo
*/
int knap_sack_dynamic(int *ret_sack, int *weights, int *values, int n, int w) {
    int memo[n+1][w+1]; // items, capacity
    prepare_memo(n+1, w+1, memo);

    // start @1 bc first row and first col are always 0
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < w+1; j++) {
            int item_weight = weights[i-1];
            int item_value = values[i-1];
            int curr_capacity = j;
            int pick_me_value = 0;
            if (item_weight > curr_capacity) {
                pick_me_value = -1;
            } else {
                int value_before_pick = memo[i-1][j-item_weight];
                pick_me_value = item_value + value_before_pick;
            }
            int dont_value = memo[i-1][j];
            if (pick_me_value > dont_value) {
                memo[i][j] = pick_me_value;
            } else {
                memo[i][j] = dont_value;
            }
        }
    }
    return memo[n][w];
}
