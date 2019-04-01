void BubbleSort(int arr[], int n)
{
    // 시간 복잡도 : O(n**2)
    int cnt = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < (n-i)-1; ++j) { // (n-i)-1 => 비교 횟수(n-1)
            cnt++;
            if (arr[j] > arr[j+1]) // 앞뒤 비교
            {
                // 스왑
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    printf("BubbleSort Count : %d\n", cnt);
}
