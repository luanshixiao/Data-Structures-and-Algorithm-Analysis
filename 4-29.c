#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TreeNode;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
    int Height;
};

int RandInt(int Lower, int Upper);
SearchTree MakeRandomTree1(int Lower, int Upper);
SearchTree MakeRandomTree(int N);

int main()
{
    srand((unsigned)time(NULL));
    printf("input N: ");
    int N;
    scanf("%d", &N);
    SearchTree T = MakeRandomTree(N);
    return 0;
}

int RandInt(int Lower, int Upper)
{
    return Lower + rand() % (Upper - Lower + 1);
}

SearchTree MakeRandomTree1(int Lower, int Upper)
{
    SearchTree T;
    int RandomValue;

    T = NULL;
    if (Lower <= Upper)
    {
        T = malloc(sizeof(struct TreeNode));
        if (T != NULL)
        {
            T->Element = RandomValue = RandInt(Lower, Upper);
            T->Left = MakeRandomTree1(Lower, RandomValue - 1);
            T->Right = MakeRandomTree1(RandomValue + 1, Upper);
        }
        else
            printf("ERROR");
    }
    return T;
}

SearchTree MakeRandomTree(int N)
{
    return MakeRandomTree1(1, N);
}