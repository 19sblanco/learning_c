#include <stdio.h>
#include "lib.c"


long fib(int n) {
    if (n < 0) {
        return -1; // meaning an error
    } else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    long arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n+1; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
} 


int main() {
    int input = 50;
    long ans = fib(input);
    printf("%ld\n", ans);

    return 0;
}