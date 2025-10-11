#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        // just simple input check
        printf("Invalid number.\n");
        return 1;
    }

    // allocate dynamic memory for array
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        return 1;
    }

    // read values
    long long sum = 0; // using long long cause maybe large sum
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // not checking scanf here, keep simple
        sum += arr[i];
    }

    // average
    double avg = (double)sum / n;
    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", avg);

    free(arr); // always free
    return 0;
}