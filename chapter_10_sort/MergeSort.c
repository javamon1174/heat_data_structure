#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int sIdx = left;
    int fIdx = left;
    int rIdx = mid+1;
    int i;

    int * sortArr = (int*)malloc(sizeof(int)*(right+1)); // 임시 배열 동적 할당

    // O(log2n)
    while(fIdx<=mid && rIdx<=right) // 배열의 앞 또는 뒷 부분 데이터 저장
    {
        if(arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];

        sIdx++;
    }

    if(fIdx > mid) // 배열의 앞부분이 옴겨 졌다면 mid ~ right 데이터 저장
    {
        for(i=rIdx; i<=right; i++, sIdx++) // 뒷부분 저장
            sortArr[sIdx] = arr[i];
    }
    else // 배열의 뒷부분이 옴겨 졌다면 left ~ mid 데이터 저장
    {
        for(i=fIdx; i<=mid; i++, sIdx++) // 앞 부분 저장
            sortArr[sIdx] = arr[i];
    }

    // 임시배열에서 원래의 배열로 데이터 이동 - O(n)
    for(i=left; i<=right; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    // 시간복잡도 : O(nlog2n)
    int mid;

    if(left < right) // 재귀 탈출 조건
    {
        // 중간 지점을 계산한다.
        mid = (left+right) / 2;

        // 둘로 나눠서 각각을 정렬한다.
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        // 정렬된 두 배열을 병합한다.
        MergeTwoArea(arr, left, mid, right);
    }
}