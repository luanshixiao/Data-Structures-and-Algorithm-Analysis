#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

Position Header(void);
Position First(List list);
Position Add(List list, int N, bool status);
void Print(List list);
void PrintLots(List L, List P);

struct Node
{
    int Element;
    Position Next;
};

int main()
{
    List L = Header();
    List P = Header();

    int N;
    printf("Enter the number of elements in P: ");
    scanf("%d", &N);
    int maxNumber = Add(P, N, true)->Element;
    Add(L, maxNumber, false);
    printf("List L: ");
    Print(L);
    PrintLots(L, P);

    return 0;
}

Position Header(void)
{
    Position header = malloc(sizeof(struct Node));
    header->Element = 0;
    header->Next = NULL;
    return header;
}

Position First(List list)
{
    if (list->Next == NULL)
        printf("Warning!");
    else
        return list->Next;
}

Position Add(List list, int N, bool status)
{
    Position cur = list;
    if (status == true)
    {
        printf("List P: ");
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
            new_node->Element = rand();
            new_node->Next = NULL;
            cur->Next = new_node;
            cur = cur->Next;
        }
        return cur;
    }
}

void Print(List list)
{
    Position pos;
    for (pos = list->Next; pos != NULL; pos = pos->Next)
        printf("%d ", pos->Element);
    printf("\n");
}

void PrintLots(List L, List P)
{
    printf("Answer: ");

    Position Lpos = First(L), Ppos = First(P);
    int cnt = 1;

    while (Ppos != NULL)
    {
        while (cnt < Ppos->Element)
        {
            Lpos = Lpos->Next;
            cnt++;
        }
        printf("%d ", Lpos->Element);
        Ppos = Ppos->Next;
    }
}