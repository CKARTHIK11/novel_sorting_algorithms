#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void max(int n, int *arr, char *maxStr) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    sprintf(maxStr, "%d", max);
}

int countDigits(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    return count;
}

void addLeadingZeros(int *arr, int n, int count) {
    for (int i = 0; i < n; i++) {
        char tempStr[20];
        sprintf(tempStr, "%0*d", count, arr[i]);
        printf("%s ", tempStr);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    char maxStr[20];
    max(n, arr, maxStr);

    int count = countDigits(maxStr);
    printf("Maximum value: %s\n", maxStr);
    printf("Number of digits in maxStr: %d\n", count);

    printf("Array with leading zeros:\n");
    addLeadingZeros(arr, n, count);

    return 0;
}
