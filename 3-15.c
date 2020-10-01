#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    int element;
    Position next;
};

void Add(Position P);
Position Find(int x, List A);

int main()
{
    srand((unsigned)time(NULL));
    int size;
    printf("input the size of list: ");
    scanf("%d", &size);
    List A = malloc(sizeof(struct Node));
    A->element = rand() % 100;
    Position curr = A;
    for (int i = 0; i < size - 1; i++)
    {
        Add(curr);
        curr = curr->next;
    }

    printf("what number do you want to find?\n");
    printf("input number: ");
    int x;
    scanf("%d", &x);
    Position xPrevPos = Find(x, A);
    Position xPos = xPrevPos->next;
    Position xNextPos = xPos->next;
    xPrevPos->next = xNextPos;
    xPos->next = A;
    A = xPos;

    return 0;
}

void Add(Position P)
{
    Position tmp = malloc(sizeof(struct Node));
    tmp->element = rand() % 100;
    tmp->next = NULL;
    P->next = tmp;
}

Position Find(int x, List A)
{
    Position prev = NULL;
    Position curr = A;
    while (curr != NULL)
    {
        if (curr->element == x)
            return prev;
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}