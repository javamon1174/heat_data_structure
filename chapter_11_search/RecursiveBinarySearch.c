// 상식적인 보간 탐색
int RecursiveBinarySearch(int ar[], int first, int last, int target)
{
    if (first > last)
        return -1;

    int mid = (first+last) / 2;

    if (ar[mid] == target)
        return mid;
    else if (target > ar[mid])
        return RecursiveBinarySearch(ar, mid+1, last, target);
    else
        return RecursiveBinarySearch(ar, first, mid-1, target);
}

// 수식을 적용한 보간 탐색
int ISearch(int ar[], int first, int last, int target)
{
    if(ar[first] > target || ar[last] < target) // 범위 제한(정렬된 데이터이기에 해당 조건 가능)
        return -1;

    // 이진 탐색과의 차이점을 반영한 문장
    int mid = ((double)(target-ar[first]) / (ar[last]-ar[first]) *
           (last-first)) + first;

    if (ar[mid] == target)
        return mid;
    else if (target > ar[mid])
        return RecursiveBinarySearch(ar, mid+1, last, target);
    else
        return RecursiveBinarySearch(ar, first, mid-1, target);
}

