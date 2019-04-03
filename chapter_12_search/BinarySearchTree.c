#include <stdlib.h>
#include "AVLRebalance.c"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode *pNode = NULL; // 부모
    BTreeNode *cNode = *pRoot; // 자식
    BTreeNode *nNode = NULL; // 새 노드

    while (cNode != NULL) // 저장될 위치 탐색
    {
        if (data == GetData(cNode)) // 키 충돌
            return ;

        pNode = cNode;

        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    nNode = MakeBTreeNode(); // 노드 생성 및 데이터 저장
    SetData(nNode, data);

    if (pNode != NULL)
    {
        if (GetData(pNode) > data) // 데이터 비교 후 자식노드로 추가
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else // 루트 노드로 추가
    {
        *pRoot = nNode;
    }

    *pRoot = Rebalance(pRoot);
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst;
    BSTData cData;

    while(cNode != NULL)
    {
        cData = GetData(cNode);

        if(target == cData) // 찾음!
            return cNode;
        else if(target < cData) // 찾는 값이 현재 값보다 작으면
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return NULL;
}

// 노드 삭제
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
    // 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.

    BTreeNode * pVRoot = MakeBTreeNode();    // 가상 루트 노드;

    BTreeNode * pNode = pVRoot;    // parent node
    BTreeNode * cNode = *pRoot;    // current node
    BTreeNode * dNode;    // delete node

    // 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 서브 노드가 되게 한다.
    ChangeRightSubTree(pVRoot, *pRoot);

    // 삭제 대상을 저장한 노드 탐색
    while(cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;

        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    if(cNode == NULL)    // 삭제 대상이 존재하지 않는다면,
        return NULL;

    dNode = cNode;    // 삭제 대상을 dNode가 가리키게 한다.

    // 첫 번째 경우: 삭제할 노드가 단말 노드인 경우
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }

        // 두 번째 경우: 하나의 자식 노드를 갖는 경우
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode * dcNode;    // delete node의 자식 노드

        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);

        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }

        // 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
    else
    {
        BTreeNode * mNode = GetRightSubTree(dNode);    // mininum node
        BTreeNode * mpNode = dNode;    // mininum node의 부모 노드
        int delData;

        // 삭제할 노드를 대체할 노드를 찾는다.
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        // 대체할 노드에 저장된 값을 삭제할 노드에 대입한다.
        delData = GetData(dNode);    // 대입 전 데이터 백업
        SetData(dNode, GetData(mNode));

        // 대체할 노드의 부모 노드와 자식 노드를 연결한다.
        if(GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

        dNode = mNode;
        SetData(dNode, delData);    // 백업 데이터 복원
    }

    // 삭제된 노드가 루트 노드인 경우에 대한 처리
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);

    free(pVRoot);

    *pRoot = Rebalance(pRoot);

    return dNode;
}
