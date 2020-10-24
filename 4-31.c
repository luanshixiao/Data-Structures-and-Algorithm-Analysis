#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeBalancedTree(int H);
SearchTree MakeBalancedTree1(int Lower, int Upper);

int main()
{
    SearchTree T = MakeBalancedTree(3);
    return 0;
}

SearchTree MakeBalancedTree(int H)
{
    
    return MakeBalancedTree1(1, (int)pow(2, H + 1) - 1);
}

SearchTree MakeBalancedTree1(int Lower, int Upper)
{
    SearchTree T;
    T = NULL;
    if (Lower <= Upper)
    {
        T = malloc(sizeof(*T));
        int Center = (Lower + Upper + 1) / 2;
        T->Element = Center;
        T->Left = MakeBalancedTree1(Lower, Center - 1);
        T->Right = MakeBalancedTree1(Center + 1, Upper);
    }
    return T;
}