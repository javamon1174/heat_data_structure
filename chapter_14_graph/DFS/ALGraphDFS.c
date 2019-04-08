#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ALGraphDFS.h"
#include "ArrayBaseStack.h"

#include "DLinkedList.c"
#include "ArrayBaseStack.c"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph * pg, int nv)
{
    pg->adjList = (List *)malloc(sizeof(List)*nv);

    pg->numV = nv;
    pg->numE = 0;
    pg->visitInfo = (int *) malloc(sizeof(int) * pg->numV); // 배열 할당
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV); // 배열 초기화

    for (int i = 0; i < nv; ++i) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede); // 정렬기준 할당
    }
}

void GraphDestroy(ALGraph * pg)
{
    if (pg->adjList != NULL)
        free(pg->adjList);

    if (pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);  // fromV의 연결리스트에 정점 toV의 정보 추가
    LInsert(&(pg->adjList[toV]), fromV); // toV의 연결리스트에 정점 FromV의 정보 추가
    pg->numE += 1;
}

int VisitVertex(ALGraph * pg, int visitV)
{
    if (pg->visitInfo[visitV] == 0) // 첫 방문
    {
        pg->visitInfo[visitV] = 1;
        printf("%c ", visitV + 65);

        return TRUE;
    }
    return FALSE;
}

// 깊이 우선 탐색 로직
void DFShowGraphVertex(ALGraph * pg, int startV)
{
    Stack stack;
    int visitV = startV;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV); // 첫번째 정점 방문
    SPush(&stack, visitV);

    while (LFirst(&(pg->adjList[visitV]), &nextV)) // 두번째 부터
    {
        int visitFlag = FALSE;

        if(VisitVertex(pg, nextV) == TRUE) // 다음 정점이 있는지
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
            {
                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }
        if (visitFlag == FALSE)
        {
            if(SIsEmpty(&stack) == TRUE)
                break;
            else
                visitV = SPop(&stack);
        }
    }

    memset(pg->visitInfo, 0, sizeof(int) * pg->numV); // 다음 방문을 위한 배열 초기화
}

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg)
{
    int i;
    int vx;

    for(i=0; i<pg->numV; i++)
    {
        printf("%c와 연결된 정점: ", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx))
        {
            printf("%c ", vx + 65);

            while(LNext(&(pg->adjList[i]), &vx))
                printf("%c ", vx + 65);
        }
        printf("\n");
    }
}

int WhoIsPrecede(int data1, int data2) // 연결리스트 정렬 기준
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}