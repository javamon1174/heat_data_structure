// 순차 검색

int LSearch(int ar[], int len, int target)
{
    int i;
    // 시간 복잡도
    // 최선 : 1
    // 평균 : (3/4)*n
    // 최악 : n => O(n) => order of n
    for(i=0; i < len; i++) {
        if (ar[i] == target) { // 해당 알고리즘의 연산 횟수가 적은 것이 좋은 알고리즘!
            return i; // 찾은 대상의 인덱스 값 반환
        }
    }

    return -1;
}

void testLSearch() // 순차 탐색
{

    int arr[] = {1, 2, 3, 4, 5};
    int idx;

    idx = LSearch(arr, sizeof(arr)/sizeof(int), 4);

    if (idx != -1) {
        printf("찾은 인덱스 : %d \n", idx);
    }
    else {
        printf("탐색 실패 \n");
    }

    idx = LSearch(arr, sizeof(arr)/sizeof(int), 7);

    if (idx != -1) {
        printf("찾은 인덱스 : %d \n", idx);
    }
    else {
        printf("탐색 실패 \n");
    }
}