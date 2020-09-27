#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    int Element;
    Position Next;
};

Position Header(void);
Position Generation(List list, int N, bool state);
Position Add(Position Last, int N);
void Print(List list);
List ListUnion(List L1, List L2);

int main()
{

    srand((unsigned)time(NULL));

    List L1 = Header();
    List L2 = Header();

    printf("List L1: ");
    Generation(L1, 5, true);
    printf("List L2: ");
    Generation(L2, 5, true);
    printf("List L1: ");
    Print(L1);
    printf("List L2: ");
    Print(L2);

    Print(ListUnion(L1, L2));

    return 0;
}

Position Header(void)
{
    Position voidUnit = malloc(sizeof(struct Node));
    voidUnit->Element = 0;
    voidUnit->Next = NULL;
    return voidUnit;
}

Position First(List list)
{
    if (list->Next == NULL)
        printf("Warning!");
    else
        return list->Next;
}

Position Generation(List list, int N, bool state)
{
    Position cur = list;
    if (state == true)
    {
        for (int i = 0; i < N; i++)
        {
            Position new_node = malloc(sizeof(struct Node));
            scanf("%d", &new_node->Element);
            new_node->Next = NULL;
            cur->Next = new_node;
            cur = cur->Next;
        }
        return cur;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            Position new_node = malloc(sizeof(struct Node));
            new_node->Element = rand() % 10;
            new_node->Next = NULL;
            cur->Next = new_node;
            cur = cur->Next;
        }
        return cur;
    }
}

Position Add(Position Last, int N)
{
    if (Last->Next == NULL)
    {
        for (int i = 0; i < N; i++)
        {
            Last->Next = Header();
            Last = Last->Next;
        }
    }
    else
        printf("Warning!\n");

    return Last;
}

void Print(List list)
{
    Position pos;
    for (pos = First(list); pos != NULL; pos = pos->Next)
        printf("%d\t", pos->Element);
    printf("\n");
}

List ListUnion(List L1, List L2)
{
    List result = Header();
    List resultLast = result;
    L1 = First(L1);
    L2 = First(L2);

    while (L1 != NULL && L2 != NULL)
    {
        if (L1->Element < L2->Element)
        {
            resultLast = Add(resultLast, 1);
            resultLast->Element = L1->Element;
            L1 = L1->Next;
        }
        else if (L1->Element > L2->Element)
        {
            resultLast = Add(resultLast, 1);
            resultLast->Element = L2->Element;
            L2 = L2->Next;
        }
        else
        {
            resultLast = Add(resultLast, 1);
            resultLast->Element = L1->Element;
            L1 = L1->Next;
            L2 = L2->Next;
        }
    }
    while (L1 != NULL)
    {
        resultLast = Add(resultLast, 1);
        resultLast->Element = L1->Element;
        L1 = L1->Next;
    }
    while (L2 != NULL)
    {
        resultLast = Add(resultLast, 1);
        resultLast->Element = L2->Element;
        L2 = L2->Next;
    }

    return result;
}