#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

// 포인트 리스트 예제
void pointListMain(void)
{
    List list;
    Point compPos;
    Point * ppos;

    ListInit(&list);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 1, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 1, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
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

// 리스트 라이브러리 활용 예제
void qUseListLib()
{
    List list;
    int data;
    int sum = 0;

    ListInit(&list);
    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);
    LInsert(&list, 9);

    if(LFirst(&list, &data))
    {
        sum += data;

        while(LNext(&list, &data))
            sum += data;
    }

    printf("총합 : %d\n", sum); // 총합 출력

    if(LFirst(&list, &data))
    {
        if (data % 2 == 0 || data % 3 == 0)
            LRemove(&list);

        while(LNext(&list, &data))
            if (data % 2 == 0 || data % 3 == 0)
                LRemove(&list);
    }

    printf("2과 3의 배수 삭제 후 남은 수 : "); // 총합 출력

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
}

// 리스트 예제
void testList(void)
{
    /*** ArrayList의 생성 및 초기화 ***/
    List list;
    int data;
    ListInit(&list);

    /*** 5개의 데이터 저장 ***/
    LInsert(&list, 11);  LInsert(&list, 11);
    LInsert(&list, 22);  LInsert(&list, 22);
    LInsert(&list, 33);

    /*** 저장된 데이터의 전체 출력 ***/
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data))    // 첫 번째 데이터 조회
    {
        printf("%d ", data);

        while(LNext(&list, &data))    // 두 번째 이후의 데이터 조회
            printf("%d ", data);
    }
    printf("\n\n");

    /*** 숫자 22을 탐색하여 모두 삭제 ***/
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

    /*** 삭제 후 저장된 데이터 전체 출력 ***/
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
}

// 구현한 리스트 활용 예제
void makeListArraySample()
{
    testList();
}