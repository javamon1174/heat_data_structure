#include <stdlib.h>
#include "SimpleHeap.h"

void HeapInit(Heap * ph)
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx) // 부모 노드 인덱스
{
    return (int) idx/2;
}

int GetLChildIDX(int idx) // 왼쪽 자식 노드 인덱스
{
    return (int)idx*2;
}

int GetRChildIDX(int idx) // 오른쪽 자식 노드 인덱스
{
    return (int) (idx*2) + 1;
}

// 두개의 자식 중 우선순위가 높은 자식의 인덱스 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
    if(GetLChildIDX(idx) > ph->numOfData)    // 자식 노드가 없다면
        return 0;

    else if(GetLChildIDX(idx) == ph->numOfData)    // 왼쪽 자식 노드가 마지막 노드라면
        return GetLChildIDX(idx);

    else // 자식노드가 둘다 존재 한다면
    {
        // 왼쪽 자식 노드와 오른쪽 자식 노드의 우선순위를 비교
        if(ph->heapArr[GetLChildIDX(idx)].pr
           > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph->numOfData+1;
    HeapElem newElem = {pr, data};

    while (idx != 1)
    {
        if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) // 현재 우선순위가 부모의 우선순위보다 높다면.
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }

    ph->heapArr[idx] = newElem;
    ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
    HData data = ph->heapArr[1].data;
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1; // 루트노드의 인덱스
    int childIdx;

    while (childIdx = GetHiPriChildIDX(ph, parentIdx)) // 내 위치 찾기
    {
        if(lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 비교
            break;

        // 부모-자식 스왑 => 부모 노드보다 우선순위가 높으니 한 레벨 올림
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx; // 마지막 노드가 저장될 위치 정보를 한 레벨 내림
    }

    ph->heapArr[parentIdx] = lastElem; // 마지막 노드 최종 저장
    ph->numOfData -= 1;

    return data;
}

