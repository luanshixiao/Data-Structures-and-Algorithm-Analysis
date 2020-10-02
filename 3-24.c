#include <stdio.h>

long long int Fibonacci(int N);

int main()
{
    int N;
    scanf("%d", &N);
    printf("Fibonacci(%d) = %lld\n", N, Fibonacci(N));
    return 0;
}

long long int Fibonacci(int N)
{
    if (N == 1)
        return 0;
    else if (N == 2)
        return 1;
    return Fibonacci(N - 1) + Fibonacci(N - 2);
}