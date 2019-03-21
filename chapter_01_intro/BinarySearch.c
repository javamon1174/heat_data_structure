// 이진 검색

int BSearch(int ar[], int len, int target)
{
    int first = 0;
    int last = len - 1;
    int mid = 0;


    // 시간 복잡도 : log n => O(log n) => order of log n
    while(first <= last) { // 증감 연산자 필요!
        mid = (last + first)/2; // 배열의 중간 인덱스 지정

        if (ar[mid] == target) { // 탐색 성공!
            return mid;
        }
        else {
            if (ar[mid] > target) { // 찾고자 하는 값 보다 클 경우
                last = mid-1; // 1을 감소하는 이유 : mid는 이미 한번 접근 했기때문 => 찾는 값이 없을 경우 무한반복 탈출을 위해
            }
            else { // 찾고자 하는 값 보다 작을 경우
                first = mid+1;
            }
        }
    }

    return -1; // 탐색 실패!
}

void testBSearch()
{
    int arr[] = {1, 2, 3, 7, 9, 12, 21, 23, 27};
    int idx;


    idx = BSearch(arr, sizeof(arr)/ sizeof(int), 9);

    if (idx != -1)
    {
        printf("9의 인덱스 : %d\n", idx);
    }
    else
    {
        printf("탐색 실패!\n");
    }

    idx = BSearch(arr, sizeof(arr)/ sizeof(int), 23);

    if (idx != -1)
    {
        printf("23의 인덱스 : %d\n", idx);
    }
    else
    {
        printf("탐색 실패!\n");
    }

    idx = BSearch(arr, sizeof(arr)/ sizeof(int), 13);

    if (idx != -1)
    {
        printf("13의 인덱스 : %d\n", idx);
    }
    else
    {
        printf("13의 인덱스 탐색 실패!\n");
    }
}