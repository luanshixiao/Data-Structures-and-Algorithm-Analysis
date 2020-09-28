#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    Position Prev;
    int N;
    Position Next;
};

List Header(void);
void Add(Position P);
Position Delete(Position P);
void Print(List list, int N);

int main()
{
    int N, M, MM;
    printf("input N: ");
    scanf("%d", &N);
    printf("input M: ");
    scanf("%d", &M);

    List Josephus = Header();
    Position curl = Josephus;
    for (int i = 2; i <= N; i++)
    {
        Add(curl);
        curl->Next->N = i;
        curl = curl->Next;
    }
    curl->Next = Josephus;
    Josephus->Prev = curl;

    curl = Josephus;
    Print(curl, N);
    while (curl->Next != curl)
    {
        MM = M % N;
        if (MM <= N / 2)
        {
            for (int i = 0; i < MM; i++)
                curl = curl->Next;
        }
        else
        {
            for (int i = 0; i < N - MM; i++)
                curl = curl->Prev;
        }
        curl = Delete(curl);
        N--;
        Print(curl, N);
    }
    printf("The winner is %d.\n", curl->N);

    return 0;
}

List Header(void)
{
    List list = malloc(sizeof(struct Node));
    list->Prev = NULL;
    list->N = 1;
    list->Next = NULL;
    return list;
}

void Add(Position P)
{
    Position tmp = malloc(sizeof(struct Node));
    if (P->Next == NULL)
    {
        tmp->Next = NULL;
        P->Next = tmp;
        tmp->Prev = P;
    }
    else
    {
        tmp->Next = P->Next;
        P->Next->Prev = tmp;
        tmp->Prev = P;
        P->Next = tmp;
    }
}

Position Delete(Position P)
{
    Position tmp = P;
    P = P->Next;
    tmp->Prev->Next = tmp->Next;
    tmp->Next->Prev = tmp->Prev;
    free(tmp);

    return P;
}

void Print(List list, int N)
{
    Position P = list;
    for (int i = 0; i < N; i++)
    {
        printf("%d\t", P->N);
        P = P->Next;
    }
    printf("\n");
}