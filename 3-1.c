#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

Position Header(void);
void Add(List list, int N);
void Print(List list);
struct Node
{
    int Element;
    Position Next;
};

int main()
{

    List array = Header();
    int N;
    printf("Enter the number of elements to be added: ");
    scanf("%d", &N);
    Add(array, N);
    Print(array);
    return 0;
}

Position Header(void)
{
    Position header = malloc(sizeof(struct Node));
    header->Element = 0;
    header->Next = NULL;
    return header;
}

void Add(List list, int N)
{
    Position cur = list;
    printf("Enter number: ");
    for (int i = 0; i < N; i++)
    {
        Position new_node = malloc(sizeof(struct Node));
        scanf("%d", &new_node->Element);
        new_node->Next = NULL;
        cur->Next = new_node;
        cur = cur->Next;
    }
}

void Print(List list)
{
    Position p;
    for (p = list->Next; p != NULL; p = p->Next)
        printf("%d ", p->Element);
}