#include <stdio.h>


int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int a[N],b[N];
    int i;

    printf("Enter %d elements:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int max = 0;
    for (i = 0; i < N; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

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
    

    // Print the matrix
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= max; i++)
    {
        int count1=0,count0=0;
        for (int j = 1; j <= N; j++)
        {
            if (mat[i][j]==1)
            {
                count1++;
            }
            else{
                count0++;
            }
            
        }
        if(count1>count0){
            b[i-1]=1;
        }
        else{
            b[i-1]=0;
        }
        
    }

    for (int i = 0; i < max; i++)
    {
        printf("%d ",b[i]);
    }
    int sum=0;
    for (int i = 0; i < max; i++)
    {
       sum += b[i];
    }
    printf("\nmedian of the given array is: %d\n",sum);
    return 0;
}
