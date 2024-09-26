void print_array(int *array) {
    int i;
    for (i = 0; i < n-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[i]);
}

void set_0(int *array) {
    int i;
    for (i = 0; i < n; i++) {
        array[i] = 0;
    }
}

void cp_array(int *original, int *cp) {
    for (int i = 0; i < n; i++) {
        cp[i] = original[i];
    }
}

int countup_sack_value(int *knap_sack) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (knap_sack[i] == 1) {
            total += values[i];
        }
    }
    return total;
}

int countup_sack_weight(int *knap_sack) {
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
int knap_sack_recursive(int *ret_sack, int curr_item, int *curr_knap_sack) {
    // base case
    if (curr_item == n) {
        cp_array(curr_knap_sack, ret_sack);
        int weight = countup_sack_weight(curr_knap_sack);
        if (weight > w) { 
            return -1;
        } else {
            int value = countup_sack_value(curr_knap_sack);
            return value;
        }
    }
    // recursive step
    int ret1[n];
    int ret2[n];

    // add item to sack
    int add_curr_item[n];
    cp_array(curr_knap_sack, add_curr_item);
    add_curr_item[curr_item] = 1;
    int val1 = knap_sack_recursive(ret1, curr_item + 1, add_curr_item);

    // don't add item to sack
    int dont_add[n];
    cp_array(curr_knap_sack, dont_add);
    int val2 = knap_sack_recursive(ret2, curr_item + 1, dont_add);

    // return max(val1, val2);
    int best = max(val1, val2);
    if (best == val1) {
        cp_array(ret1, ret_sack);
        return val1;
    } else {
        cp_array(ret2, ret_sack);
        return val2;
    }
}