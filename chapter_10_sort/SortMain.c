//#include "BubbleSort.c" // 버블정렬
//#include "SelectionSort.c" // 선택정렬
//#include "InsertionSort.c" // 삽입정렬
//#include "HeapSort.c" // 힙정렬
//#include "MergeSort.c" // 합병 정렬
//#include "QuickSort.c" // 퀵 정렬
#include "RadixSort.c" // 퀵 정렬


void testSort()
{
    /*
    int len = 5;
    int arr[5] = {4, 2, 5, 1, 3};
    int i;

    // 버블 정렬
    BubbleSort(arr, sizeof(arr)/sizeof(int));

    // 선택 정렬
    SelectionSort(arr, sizeof(arr)/sizeof(int));

    // 삽입 정렬
    InsertionSort(arr, sizeof(arr)/sizeof(int));


    // 힙 정렬
    HeapSort(arr, sizeof(arr)/sizeof(int));

    // 병합 정렬
    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    // 퀵 정렬
//    int len = 15;
//    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
//    QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    printf("정렬된 데이터 : ");
    for (i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    */

    // 기수 정렬
    int arr2[7] = {13, 212, 14, 7141, 10987, 6, 15}; // 가장 긴 데이터 길이 5
    int len2 = sizeof(arr2) / sizeof(int);

    RadixSort(arr2, len2, 5);

    printf("기수 정렬된 데이터 : ");
    for (int i = 0; i < len2; ++i) {
        printf("%d ", arr2[i]);
    }
}