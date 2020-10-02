#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct StackMin;
typedef struct StackMin *PtrToStack;
typedef PtrToStack Stack;

struct StackMin
{
    int topOfStackS;
    int stackS[10];
    int topOfStackM;
    int stackM[10];
};

void Push(Stack a);
void Pop(Stack a);
int FindMin(Stack a);

int main()
{
    srand((unsigned)time(NULL));
    Stack a = malloc(sizeof(struct StackMin));
    a->topOfStackS = -1;
    a->topOfStackM = -1;
    for (int i = 0; i < 10; i++)
    {
        Push(a);
        printf("%d\t", a->stackS[a->topOfStackS]);
    }
    printf("\nThe min of Stack is: %d\n", FindMin(a));
    for (int i = 0; i < 10; i++)
    {
        Pop(a);
        printf("The min of the Stack is: %d\n", FindMin(a));
    }

    return 0;
}

void Push(Stack a)
{
    a->stackS[++a->topOfStackS] = rand() % 100;
    if (a->stackS[a->topOfStackS] < a->stackM[a->topOfStackM] || a->topOfStackM == -1)
        a->stackM[++a->topOfStackM] = a->stackS[a->topOfStackS];
}

void Pop(Stack a)
{
    printf("%d\t", a->stackS[a->topOfStackS]);
    if (a->stackS[a->topOfStackS] == a->stackM[a->topOfStackM])
        a->topOfStackM--;
    a->topOfStackS--;
}

int FindMin(Stack a)
{
    if (a->topOfStackM > -1)
    {
        int min = a->stackM[a->topOfStackM];
        return min;
    }
    return -1;
}