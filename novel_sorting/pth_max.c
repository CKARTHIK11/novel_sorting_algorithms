#include <stdio.h>

int main() {
    int N,p;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int a[N], b[N];
    int i, count = 0, count0 = 0;

    printf("Enter %d elements:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    printf("enter the required the pth max ");
    scanf("%d",&p);

    int max = 0;
    for (i = 0; i < N; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
   int c[max];
    int mat[max + 1][N + 1];
    mat[0][0] = 0;

    for (int j = 1; j <= N; j++) {
        mat[0][j] = a[j - 1];
    }
    for (int i = 1; i <= max; i++) {
        mat[i][0] = i;
    }
    for (int i = 1; i <= max; i++) {
        for (int j = 1; j <= N; j++) {
            if (mat[i][0] <= mat[0][j]) {
                mat[i][j] = 1;  // Set to 1 if the condition is met
            } else {
                mat[i][j] = 0;  // Set to 0 otherwise
            }
        }
    }

    for (int i = 1; i <= max; i++) {
        int count = 0, count0 = 0;
        for (int j = 1; j <= N; j++) {
            if (mat[i][j] == 1) {
                count++;
            } else {
                count0++;
            }
        }
        if (count >= p) {
            c[i - 1] = 1;
        } else {
            c[i - 1] = 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < max; i++) {
        sum += c[i];
    }
    printf("\n %dth max of given is : %d\n",p, sum);
    return 0;
}