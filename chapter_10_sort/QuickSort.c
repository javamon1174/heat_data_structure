#include <stdlib.h>

void Swap(int arr[], int idx1, int idx2)
{
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int getMidValue(int arr[], int left, int right) // 3개의 값 중 버블정렬을 통해 중간값 리턴
{
    // O(3)
    int pivot[3] = {left, (left+right)/2, right};  // 9 5 1

    // 버블 정렬 2회차 까지만
    if (pivot[0] > pivot[1]) // 5 9 1
        Swap(pivot, 0, 1);

    if (pivot[1] > pivot[2]) // 5 1 9
        Swap(pivot, 1, 2);

    if (pivot[0] > pivot[1]) // 1 5 9
        Swap(pivot, 0, 1);

    return pivot[1]; // return 5
}

int Partition(int arr[], int left, int right)
{
//    int pivot = arr[left]; // 피벗 초기화 => 가장 왼쪽 데이터

    int pIdx = getMidValue(arr, left, right); // 10-1 문제
    int pivot = arr[pIdx]; // 10-1 문제

    int low = left+1;
    int high = right;

    Swap(arr, left, pIdx); // 피벗을 가장 왼쪽으로 이동 // 10-1 문제
    printf("피벗 : %d\n", pivot); // 피벗 출력 // 10-1 문제

    while(low <= high)    // 교차되지 않을 때까지 반복
    {
        while(pivot >= arr[low] && low <= right)  // 인덱스 비교 추가
            low++;

        while(pivot <= arr[high] && high >= (left+1)) // 피벗과 중첩 -> 피벗 제외 조건 추가
            high--;

        /* 피벗과의 중첩 및 중복값이 고려되지 않은 조건
        while (pivot > arr[low]) // 피벗보다 큰 값 나올 때 까지 low 우측으로 이동
            low++;

        while (pivot < arr[high]) // 피벗보다 작은 값 나올 때 까지 high 좌측으로 이동
            high--;
        */

        if(low <= high)    // 교차되지 않은 상태라면 Swap 실행
            Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
    }

    Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
    return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
    // O(nlog2n)
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}