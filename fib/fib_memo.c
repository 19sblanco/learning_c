#include <stdio.h>
#include "lib.c"
#include <stdlib.h>


long fib_helper(int n, long* memo) {
    if (n <= 1) { 
        return n; 
    }
    if (memo[n] != 0) { 
        return memo[n]; 
    }
    else {
        memo[n] = fib_helper(n-1, memo) + fib_helper(n-2, memo);
        return memo[n];
    }
}

long fib(int n) {
    long* memo = (long*)calloc(n+1, sizeof(long));
    return fib_helper(n, memo);
} 

int main() {
    int input = 50;
    long ans = fib(input);
    printf("%ld\n", ans);

    return 0;
}