#include <stdio.h>
#include "UsefulHeap.h"
#include "UsefulHeap.c"

int PriComp(int n1, int n2)
{
    return n2-n1;
}

void HeapSort(int arr[], int n)
{

    Heap heap;
    HeapInit(&heap, PriComp);
    int i;

    // 정렬 대상을 가지고 힙을 구성한다.
    for(i=0; i<n; i++)
        HInsert(&heap, arr[i]);

    // 순서대로 하나씩 꺼내서 정렬을 완성한다.
    for(i=0; i<n; i++)
        arr[i] = HDelete(&heap);
}
