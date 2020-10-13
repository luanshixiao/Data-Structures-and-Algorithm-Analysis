#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
int Retrive(Position P);

struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
};

int main()
{
    // P83 Fig 4-23
    SearchTree A = malloc(sizeof(struct TreeNode));
    A->Element = 2;
    A->Left = malloc(sizeof(struct TreeNode));
    A->Left->Element = 1;
    A->Left->Left = A->Left->Right = NULL;
    A->Right = malloc(sizeof(struct TreeNode));
    A->Right->Element = 4;
    A->Right->Left = malloc(sizeof(struct TreeNode));
    A->Right->Left->Element = 3;
    A->Right->Left->Left = NULL;
    A->Right->Left->Right = NULL;
    A->Right->Right = NULL;

    SearchTree B = Delete(4, A);

    return 0;
}

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(int X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}

Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (T->Right == NULL)
        return T;
    else
        return FindMin(T->Right);
}

SearchTree Insert(int X, SearchTree T)
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            printf("ERROR!\n");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
    }

    return T;
}

SearchTree Delete(int X, SearchTree T)
{
    Position TmpCell;

    if (T == NULL)
    {
        printf("Element not found\n");
    }
    else if (X < T->Element)
    {
        T->Left = Delete(X, T->Left);
    }
    else if (X > T->Element)
    {
        T->Right = Delete(X, T->Right);
    }
    else if (T->Left && T->Right)
    {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(TmpCell->Element, T->Right);
    }
    else
    {
        TmpCell = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }

    return T;
}