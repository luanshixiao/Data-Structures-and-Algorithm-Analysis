#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define custom true

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    int exp;
    int coe;
    Position Next;
};

Position Header(void);
List Generation(bool state);
void Insert(Position P);
void Print(List list);
List MultiplyPolynomial(List A, List B);

int main()
{

    printf("polynomial A: ");
    List A = Generation(custom);
    printf("polynomial B: ");
    List B = Generation(custom);

    Print(MultiplyPolynomial(A, B));

    return 0;
}

Position Header(void)
{
    Position voidUnit = malloc(sizeof(struct Node));
    voidUnit->exp = 0;
    voidUnit->coe = 0;
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

List Generation(bool state)
{
    List list = Header();
    Position cur = list;
    if (state == custom)
    {
        do
        {
            Position newNode = malloc(sizeof(struct Node));
            scanf("%d", &newNode->exp);
            scanf("%d", &newNode->coe);
            newNode->Next = NULL;
            cur->Next = newNode;
            cur = cur->Next;
        } while (getchar() != '\n');
        return list;
    }
    else
    {
        printf("input the highest exponent of polynomial: ");
        int i;
        scanf("%d", &i);
        while (i-- >= 0)
        {
            Position newNode = malloc(sizeof(struct Node));
            newNode->coe = rand() % 10;
            newNode->exp = i;
            newNode->Next = NULL;
            cur->Next = newNode;
            cur = cur->Next;
        }
        return list;
    }
}

void Insert(Position P)
{
    if (P->Next == NULL)
        P->Next = Header();
    else
    {
        Position tmp = Header();
        tmp->Next = P->Next;
        P->Next = tmp;
    }
}

void Print(List list)
{
    Position P;
    for (P = First(list); P != NULL; P = P->Next)
        printf("%d %d\t", P->exp, P->coe);
    printf("\n");
}

List MultiplyPolynomial(List A, List B)
{
    Position curlA = First(A);
    Position curlB = First(B);

    List C = Header();
    Insert(C);
    Position curl = First(C);

    int ABexp;
    int ABcoe;

    while (curlA != NULL)
    {
        curl = First(C);
        curlB = First(B);
        while (curlB != NULL)
        {
            ABexp = curlA->exp + curlB->exp;
            ABcoe = curlA->coe * curlB->coe;

            while (curl->exp > ABexp)
            {
                if (curl->Next == NULL || curl->Next->exp < ABexp)
                {
                    Insert(curl);
                    curl->Next->exp = ABexp;
                    curl->Next->coe += ABcoe;
                }
                curl = curl->Next;
            }
            if (curl->exp == 0)
            {
                curl->exp = ABexp;
                curl->coe = ABcoe;
            }

            curlB = curlB->Next;
        }

        curlA = curlA->Next;
    }

    return C;
}