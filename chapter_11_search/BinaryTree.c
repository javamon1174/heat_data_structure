#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void)
{
    BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));

    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode * bt)
{
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->left != NULL)
        free(main->left);

    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->right != NULL)
        free(main->right);

    main->right = sub;
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

// 삭제 연관 함수
BTreeNode * RemoveLeftSubTree(BTreeNode * bt) // 메모리 해제는 호출부에서 담당
{
    BTreeNode *dNode;

    if (bt != NULL)
    {
        dNode = bt->left;
        bt->left = NULL;
    }

    return dNode;

}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
    BTreeNode *dNode;

    if (bt != NULL)
    {
        dNode = bt->right;
        bt->right = NULL;
    }

    return dNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    main->left = sub;
}
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    main->right = sub;
}
