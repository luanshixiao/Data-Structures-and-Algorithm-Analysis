#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

Position SingleRotateWithLeft(Position K2);
Position SingleRotateWithRight(Position K1);
Position DoubleRotateWithLeft(Position K3);
Position DoubleRotateWithRight(Position K1);
int Height(Position TreeNode);
int Max(int a, int b);

struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
    int Height;
};

int main()
{
    return 0;
}

Position SingleRotateWithLeft(Position K2)
{
    Position K1 = K2->Left;

    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;

    return K1;
}

Position SingleRotateWithRight(Position K1)
{
    Position K2 = K1->Right;

    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;

    return K2;
}
Position DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

Position DoubleRotateWithRight(Position K1)
{
    K1->Right = SingleRotateWithLeft(K1->Right);
    return SingleRotateWithRight(K1);
}

int Max(int a, int b)
{
    if (a <= b)
        return b;
    else
        return a;
}

int Height(Position TreeNode)
{
    if (TreeNode == NULL)
        return 0;
    return Max(Height(TreeNode->Left), Height(TreeNode->Right)) + 1;
}