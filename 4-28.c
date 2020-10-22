#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef struct TreeNode *BinaryTree;

struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
    int Height;
};

int CountNodes(BinaryTree T);
int CountLeaves(BinaryTree T);
int CountFull(BinaryTree T);

int main()
{
    return 0;
}

int CountNodes(BinaryTree T)
{
    if (T == NULL)
        return 0;
    return 1 + CountNodes(T->Left) + CountNodes(T->Right);
}

int CountLeaves(BinaryTree T)
{
    if (T == NULL)
        return 0;
    else if (T->Left == NULL && T->Right == NULL)
        return 1;
    return CountLeaves(T->Left) + CountLeaves(T->Right);
}

int CountFull(BinaryTree T)
{
    if (T == NULL)
        return 0;
    return (T->Left != NULL && T->Right != NULL) + CountFull(T->Left) + CountFull(T->Right);
}