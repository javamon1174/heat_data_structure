// 이진트리 - 삽입, 삭제, 조회
//#include "BinaryTree.h"
//#include "BinaryTree.c"

// 수식트리 구현
#include "ExpressionTree.h"
#include "ExpressionTree.c"

//#include "ListBaseStack.h"
//#include "ListBaseStack.c"

/*
// 이진트리 - 삽입, 삭제, 조회
void ShowIntData(BTData data);
void testBinaryTree()
{
    BTreeNode * bt1 = MakeBTreeNode();
    BTreeNode * bt2 = MakeBTreeNode();
    BTreeNode * bt3 = MakeBTreeNode();
    BTreeNode * bt4 = MakeBTreeNode();
    BTreeNode * bt5 = MakeBTreeNode();
    BTreeNode * bt6 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);

    PreorderTraverse(bt1, ShowIntData); // 함수 포인터를 활용한 행위 전달
    printf("\n");
    InorderTraverse(bt1, ShowIntData);
    printf("\n");

    PostorderTraverse(bt1, ShowIntData);
    printf("\n");

    DeleteTree(bt1); // 트리 모두 삭제
}
void ShowIntData(BTData data) // 샘플 행위
{
    printf("%d ", data);
}
*/

// 수식트리 구현
void testExpressionTree()
{
    char exp[] = "12+7*";
    BTreeNode * eTree = MakeExpTree(exp);

    printf("전위 표기법의 수식: ");
    ShowPrefixTypeExp(eTree); printf("\n");

    printf("중위 표기법의 수식: ");
    ShowInfixTypeExp(eTree); printf("\n");

    printf("후위 표기법의 수식: ");
    ShowPostfixTypeExp(eTree); printf("\n");

    printf("연산의 결과: %d \n", EvaluateExpTree(eTree));
}