#ifndef LIB_H
#define LIB_H

void print_array(int n, int *array);
void set_0(int n, int *array);
void cp_array(int n, int *original, int *cp);
int countup_sack_value(int n, int *knap_sack, int *values);
int countup_sack_weight(int n, int *knap_sack, int *weights);
int max(int a, int b);
int knap_sack_recursive(int *ret_sack, int curr_item, int *curr_knap_sack, int *weights, int *values, int w, int n);

#endif