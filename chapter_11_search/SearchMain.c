#include <stdio.h>
//#include "RecursiveBinarySearch.c" // 보간 탐색
#include "BinarySearchTree.h"
#include "BinarySearchTree.c"
#include "BinaryTree.c"
void ShowIntData(int data)
{
    printf("%d ", data);
}

void testSearch()
{
    /* 보간 탐색
    int arr[] = {1, 3, 5, 7, 8, 10};
    int idx;

    // 보간 탐색(기본)
    idx = RecursiveBinarySearch(arr, 0, sizeof(arr)/sizeof(int), 5);

    // 수식 대입
    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 5);
    if (idx == -1)
        printf("5의 데이터 탐색 실패!");
    else
        printf("5의 데이터는 %d번째에 있습니다.\n", idx+1);

    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
    if (idx == -1)
        printf("2의 데이터 탐색 실패!");
    else
        printf("2의 데이터는 %d번째에 있습니다.\n", idx+1);
    */

    /*
     * 이진 탐색트리
    BTreeNode * bstRoot;
    BTreeNode * sNode;    // search node

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    sNode = BSTSearch(bstRoot, 1);
    if(sNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));


    sNode = BSTSearch(bstRoot, 6);
    if(sNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

    sNode = BSTSearch(bstRoot, 7);
    if(sNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));
    */

    BTreeNode * bstRoot;
    BTreeNode * sNode;    // search node

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 7);

    InorderTraverse(bstRoot, ShowIntData); printf("\n");
    sNode = BSTRemove(&bstRoot, 3);
    free(sNode);

    InorderTraverse(bstRoot, ShowIntData); printf("\n");
    sNode = BSTRemove(&bstRoot, 8);
    free(sNode);

    InorderTraverse(bstRoot, ShowIntData); printf("\n");
    sNode = BSTRemove(&bstRoot, 1);
    free(sNode);

    InorderTraverse(bstRoot, ShowIntData); printf("\n");
    sNode = BSTRemove(&bstRoot, 6);
    free(sNode);

    InorderTraverse(bstRoot, ShowIntData); printf("\n");
}