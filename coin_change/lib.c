/*
Given an amount to make change for (cents in our case)
find the fewest number of coins that will make change for that

We will use these denominations
    * 1, 15, 25
We won't use USA money denominations because then we wouldn't have
to use brute force recursion and dynamic programming.

If you wanna know why it essentially boils down to the fact that
in the USA money denomination (1, 5, 10, 25) each larger coin is a 
multiple of one of the smaller coins. This means anytime we can use
a larger coin, its fine to do so. But with our coin denominations for
this problem (1, 15, 25), notice that 15 and 25 are not multiples of 
one another. This means that there are times when we can use a 25 but
actually wouldn't want to. For example when the remaining amount is 30,
we can either use (15, 15) or (25, 1, 1, 1, 1, 1). Obviously the first
option is better. Because of this unpredictability we'll just have to
try out all solutions.
*/
int coin_change(int amount) {
    if (amount == 0) {
        return 0;
    }
    else if (amount < 0) {
        return -1;
    }

    int denominations[3] = {1, 15, 25};
    int best_so_far = -1;
    for (int i = 0; i < 3; i++) {
        int coin = denominations[i];
        int new_amount = amount - coin;
        int best = coin_change(new_amount);
        if (best < best_so_far) {
            best_so_far = best;
        }
    }

    return best_so_far + 1;
}