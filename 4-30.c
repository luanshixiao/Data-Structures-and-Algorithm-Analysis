#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
    int Height;
};

SearchTree GenTree(int Height,int *LastNode);
SearchTree MinAvlTree(int H);

int main()
{
    SearchTree T = MinAvlTree(3);
    return 0;
}

SearchTree GenTree(int Height,int *LastNode)
{
    SearchTree T;

    if(Height>=0)
    {
        T = malloc(sizeof(*T));
        T->Left = GenTree(Height - 1, LastNode);
        T->Element = ++*LastNode;
        T->Right = GenTree(Height - 2, LastNode);
        return T;
    }
    else
        return NULL;
}

SearchTree MinAvlTree(int H)
{
    int LastNodeAssigned = 0;
    return GenTree(H, &LastNodeAssigned);
}