#include <stdio.h>
#include <stdlib.h>

// 원형 연결 리스트 구현
//#include "CLinkedList.h"
//#include "CLinkedList.c"


// 양방향 연결 리스트 구현 + (05-04 문제)양방향 더미 추가
//#include "DBDLinkedList.h"
//#include "DBDLinkedList.c"

// 원형 연결 리스트 스택 구현
#include "CLLBaseStack.h"
#include "CLLBaseStack.c"

// 원형 연결 리스트 스택 구현
void testCLLBaseStack()
{
    // Stack의 생성 및 초기화 ///////
    Stack stack;
    StackInit(&stack);

    // 데이터 넣기 ///////
    SPush(&stack, 1);  SPush(&stack, 2);
    SPush(&stack, 3);  SPush(&stack, 4);
    SPush(&stack, 5);

    // 데이터 꺼내기 ///////
    while(!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));
}


/*
// 원형 연결 리스트 구현
void testList3(void)
{
    // 원형 연결 리스트의 생성 및 초기화 ///////
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    // 리스트에 5개의 데이터를 저장 ///////
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    // 리스트에 저장된 데이터를 연속 3회 출력 ///////
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        for(i=0; i<LCount(&list)*3-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    // 2의 배수를 찾아서 모두 삭제 ///////
    nodeNum = LCount(&list);

    if(nodeNum != 0)
    {
        LFirst(&list, &data);
        if(data%2 == 0)
            LRemove(&list);

        for(i=0; i < nodeNum-1; i++)
        {
            LNext(&list, &data);
            if(data%2 == 0)
                LRemove(&list);
        }
    }

    // 전체 데이터 1회 출력 ///////
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        for(i=0; i<LCount(&list)-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
}


// 양방향 연결 리스트 구현 + (05-04 문제)양방향 더미 추가
int testList4(void)
{
    List list;
    int data;
    ListInit(&list);

    // 8개의 데이터 저장 ///////
    LInsert(&list, 1);  LInsert(&list, 2);
    LInsert(&list, 3);  LInsert(&list, 4);
    LInsert(&list, 5);  LInsert(&list, 6);
    LInsert(&list, 7);  LInsert(&list, 8);

    // 저장된 데이터의 조회 ///////
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);

        printf("\n");
    }

    // 2의 배수 전부 삭제 ///////
    if(LFirst(&list, &data))
    {
        if(data%2 == 0)
            LRemove(&list);

        while(LNext(&list, &data))
        {
            if(data%2 == 0)
                LRemove(&list);
        }
    }

    // 저장된 데이터의 재 조회 ///////
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);

        printf("\n\n");
    }

    return 0;
}
*/