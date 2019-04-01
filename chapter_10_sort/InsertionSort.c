void InsertionSort(int arr[], int n)
{
    // 시간 복잡도 : O(n**2)

    int i,j;
    int data;

    for (i = 0; i < n; ++i) {
        data = arr[i];

        for (j = i-1; j >= 0; j--) { // 끝 데이터부터
            if (arr[j] > data)
                arr[j+1] = arr[j]; // 오른쪽으로 한칸 밀기
            else
                break;
        }
        arr[j+1] = data;
    }
}