#include <stdio.h>
#include <stdlib.h>

// 연결 리스트 이해
//#include "LinkedRead.c"

// 04-3 예제 실습
#include "Point.h"
#include "Point.c"
#include "DLinkedList2.h"
#include "DLinkedList2.c"


// 연결 리스트 구현
/*
#include "DLinkedList.h"
#include "DLinkedList.c"

int WhoIsPrecede(LData d1, LData d2) // 리스트 정렬 기준
{
    if (d1 < d2) // 순차
        return 0;
    else
        return 1;
}

int testList2(void)
{
    // 연결 리스트 이해
//    LinkedRead();

    // 연결 리스트 구현
    // List의 생성 및 초기화 /////////////////////////////
    List list;
    int data;
    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede);

    // 5개의 데이터 저장 /////////////////////////////
    LInsert(&list, 11);  LInsert(&list, 11);
    LInsert(&list, 22);  LInsert(&list, 22);
    LInsert(&list, 33);

    // 저장된 데이터의 전체 출력 /////////////////////////
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data))    // 첫 번째 데이터 조회
    {
        printf("%d ", data);

        while(LNext(&list, &data))    // 두 번째 이후의 데이터 조회
            printf("%d ", data);
    }

    printf("\n\n");

    // 숫자 22을 검색하여 모두 삭제 //////////////////////////
    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);

        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }

    // 삭제 후 남아있는 데이터 전체 출력 ////////////////////////
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    return 0;
}
*/
///*

int Precede(LData d1, LData d2) // 리스트 정렬 기준
{
    if (d1->xpos < d2->xpos) // x 순차
        return 0;
    else if (d1->xpos == d2->xpos)
    {
        if (d1->ypos < d2->ypos) // y 순차
            return 0;
        else
            return 1;
    }
    else
        return 1;
}

void pointListMain2(void) // 04-3 예제 실습
{
    List list;
    Point compPos;
    Point * ppos;

    ListInit(&list);
    SetSortRule(&list, Precede);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 1, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 1, 1);
    LInsert(&list, ppos);


    printf("현재 저장된 데이터 수 : %d\n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    printf("\n\n");

    // xpos가 2인 데이터 삭제
    compPos.xpos = 2;
    compPos.ypos = 0;

    if(LFirst(&list, &ppos))
    {
        if(PointComp(ppos, &compPos) == 1)
        {
            ppos = LRemove(&list);
            free(ppos);
        }

        while(LNext(&list, &ppos))
            if(PointComp(ppos, &compPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
    }

    printf("현재 저장된 데이터 수 : %d\n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
}
//*/