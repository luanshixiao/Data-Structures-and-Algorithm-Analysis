#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    int N;
    Position Next;
};

void Add(Position P);
void Print(List L);
List ReverseList(List L);

int main()
{
    srand((unsigned)time(NULL));

    int size;
    printf("input the size of list: ");
    scanf("%d", &size);
    List A = malloc(sizeof(struct Node));
    Position curr = A;
    curr->N = rand() % 100;
    curr->Next = NULL;
    for (int i = 0; i < size - 1; i++)
    {
        Add(curr);
        curr = curr->Next;
        curr->N = rand() % 100;
    }

    Print(A);
    Print(ReverseList(A));

    return 0;
}

void Add(Position P)
{
    Position tmp = malloc(sizeof(struct Node));
    if (P->Next == NULL)
    {
        tmp->Next = NULL;
        P->Next = tmp;
    }
    else
    {
        tmp->Next = P->Next;
    }
}

void Print(List L)
{
    while (L != NULL)
    {
        printf("%d\t", L->N);
        L = L->Next;
    }
    printf("\n");
}

List ReverseList(List L)
{
    Position PreviousPos, CurrentPos, NextPos;

    PreviousPos = NULL;
    CurrentPos = L;
    NextPos = L->Next;

    while (NextPos != NULL)
    {
        CurrentPos->Next = PreviousPos;

        PreviousPos = CurrentPos;
        CurrentPos = NextPos;
        NextPos = NextPos->Next;
    }
    CurrentPos->Next = PreviousPos;

    return CurrentPos;
}