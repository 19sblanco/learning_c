void print_arr(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[n]);
}