#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(int *array) {
    int i;
    for (i = 0; i < n-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[i]);
}

void set_0(int *array) {
    int i;
    for (i = 0; i < n-1; i++) {
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
*/
void knap_sack_recursive(int *ret, int curr_item, int *curr_knap_sack) {
    if (curr_item >= n) {
        // TODO return the knapsack
    }
    int new_ks[n]
    cp_array(curr_knap_sack, new_ks, n);
    new_ks[curr_item] = 1;
    new_ks_weight = countup_sack_value(new_ks);
    if (new_ks_weight > w) {
        knap_sack_recursive(
    }


    

}
/*
(return_val, current_item, current_knap_sack)
if current_item == n:
    return_val = current_knap_sack
    return;

potential_knap_sack = current_knap_sack + current item
if potential_knap_sack.weight > w:
    knap_sack_recursive(return_val, current_item+1, current_knap_sack)
else:
    max (
        ksr(return_val, current_item+1, current_knap_sack),
        ksr(return_val, current_item+1, curr_ks + curr_item)
    )
return the knapsack with the best value
*/

int* weights; // weights of each item
int* values; // values of each item
int w = 20; // max weight in knap sack
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
        value[i] = b;
    }
    printf("weights\n");
    print_array(weights, n);
    printf("value\n");
    print_array(value, n);
    int ret[n];
    knap_sack_recursive(ret, weights, value, w, n);


    return 0;
}

