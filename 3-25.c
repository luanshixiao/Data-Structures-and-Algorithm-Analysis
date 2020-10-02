#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct QueueRecord
{
    Position front;
    Position rear;
    List a;
};
struct Node
{
    int n;
    Position next;
};

Queue CreatQueue(void);
void Enqueue(int x, Queue q);
void Dequeue(Queue q);
void PrintQueue(Queue q);

int main()
{
    srand((unsigned)time(NULL));
    printf("Enqueue: ");
    int enSize;
    scanf("%d", &enSize);
    Queue q = CreatQueue();
    q->a->n = rand() % 100;
    for (int i = 0; i < enSize - 1; i++)
        Enqueue(rand() % 100, q);
    PrintQueue(q);
    printf("\n");
    printf("Dequeue: ");
    int deSize;
    scanf("%d", &deSize);
    for (int i = 0; i < deSize; i++)
        Dequeue(q);
    return 0;
}

Queue CreatQueue(void)
{
    Queue q = malloc(sizeof(struct QueueRecord));
    q->a = malloc(sizeof(struct Node));
    q->a->next = NULL;
    q->front = q->a;
    q->rear = q->a;
    return q;
}

void Enqueue(int x, Queue q)
{
    Position tmp = malloc(sizeof(struct Node));
    tmp->n = x;
    tmp->next = NULL;
    q->rear->next = tmp;
    q->rear = tmp;
}

void Dequeue(Queue q)
{
    printf("%d\t", q->front->n);
    Position tmp = q->front;
    q->front = q->a = q->front->next;
    free(tmp);
}

void PrintQueue(Queue q)
{
    Position curr = q->front;
    while (curr != NULL)
    {
        printf("%d\t", curr->n);
        curr = curr->next;
    }
}