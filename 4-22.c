#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

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

Position DoubleRotateWithLeft(Position K3)
{
    Position K1, K2;
    K1 = K3->Left;
    K2 = K1->Right;

    K1->Right = K2->Left;
    K3->Left = K2->Right;
    K2->Left = K1;
    K2->Right = K3;

    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K3->Height = Max(Height(K3->Left), Height(K3->Right)) + 1;
    K2->Height = Max(K1->Height, K3->Height) + 1;

    return K3;
}

Position DoubleRotateWithRight(Position K1)
{
    Position K2, K3;
    K3 = K1->Right;
    K2 = K3->Left;

    K1->Right = K2->Left;
    K3->Left = K2->Right;
    K2->Left = K1;
    K2->Right = K3;

    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K3->Height = Max(Height(K3->Left), Height(K3->Right)) + 1;
    K2->Height = Max(K1->Height, K3->Height) + 1;

    return K2;
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