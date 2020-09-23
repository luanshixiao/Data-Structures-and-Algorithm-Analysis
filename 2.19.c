#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rec(int a[], int N);

int main()
{
    int N;
    scanf("%d", &N);
    int *a = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        a[i] = rand();
    printf("The main element is %d\n", rec(a, N));

    return 0;
}

int rec(int a[], int N)
{
    int *b = malloc((N / 2 + N % 2) * sizeof(int));
    int j = 0;
    for (int i = 0; i < N / 2 * 2; i += 2)
    {
        if (a[i] == a[i + 1])
            b[j++] = a[i];
    }
    if (N % 2 != 0)
    {
        if (j == 0)
            return a[N - 1];
        b[j++] = a[N - 1];
    }
    else
    {
        if (j == 0)
            return -1;
    }
    return rec(b, j);
}