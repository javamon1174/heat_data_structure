#include <stdio.h>
#include <stdlib.h>

// 이진 탐색트리
#include "BinarySearchTree.h"
#include "BinarySearchTree.c"
#include "BinaryTree.h"
#include "BinaryTree.c"

// 리밸런싱
#include "AVLRebalance.h"
//#include "AVLRebalance.c"

void testSearch2()
{
    /* AVL 트리 삽입 과정에서의 리밸런싱 기능에 대한 완성
     * Page 492~493 보완 내용
     * 본 서의 리밸런싱 기준 : BSInsert  마지막 부분에서 루트 노드를 기준으로 리밸런싱 필요성을 판단하고 진행한다.
     * 3
     * 2 4
     * 1 5
     * 위와 같은 구조일 때 6을 추가해도 밸런싱이 이루어 지지 않아 재귀적으로 BSInsert 함수를 구성해야 한다. => 생략
     *
     */
    BTreeNode * avlRoot;
    BTreeNode * clNode;		// current left node
    BTreeNode * crNode;		// current right node
    BSTMakeAndInit(&avlRoot);

    BSTInsert(&avlRoot, 1);
    BSTInsert(&avlRoot, 2);
    BSTInsert(&avlRoot, 3);
    BSTInsert(&avlRoot, 4);
    BSTInsert(&avlRoot, 5);
    BSTInsert(&avlRoot, 6);
    BSTInsert(&avlRoot, 7);
    BSTInsert(&avlRoot, 8);
    BSTInsert(&avlRoot, 9);

    printf("루트 노드: %d \n", GetData(avlRoot));

    clNode = GetLeftSubTree(avlRoot);
    crNode = GetRightSubTree(avlRoot);
    printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));
}