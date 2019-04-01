void SelectionSort(int arr[], int n)
{
    // 시간 복잡도 : O(n**2)

    int max;
    int tmp;
    int i, j;

    for (i = 0; i < n-1; ++i) {
        max = i;

        for (j = i+1; j < n; ++j) { // i의 다음값 부터
            if (arr[j] < arr[max]) // 비교 횟수
            {
                max = j;
            }
        }

        tmp = arr[i];
        arr[i] = arr[max];
        arr[max] = tmp;
    }
}