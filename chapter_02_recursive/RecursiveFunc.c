#include <stdint.h>

// 재귀 함수 기본 구조
void Recursive(int num)
{
    if (num > 0)
    {
        printf("-%d번째 실행!\n", num);
        Recursive(num-1);
    }
}

// 팩토리얼 예제
int Factorial(int n)
{
    if(n <= 0)
    {
        return 1; // 곱셈에 따라 마지막 값 1로 설정
    }
    else
    {
        return n * Factorial(n-1); // n 곱셈 누적
    }
}

// 피보나치 수열 예제
// 공식 : n = n-1 + n-2
int Fibo(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return Fibo(n-1)+Fibo(n-2); // 0+1, 1+1, 1+2, 2+3, 3+5 ..
    }

}
// 이진 탐색 알고리즘 예제
int BSearchRecur(int ar[], int first, int last, int target)
{
    if (first > last) return -1; // 찾는 값이 없을 경우 탈출

    int mid = (last + first) / 2;

    if (ar[mid] == target)
    {
        return mid;
    }
    else if (ar[mid] > target) // 찾는 값이 mid의 값 보다 작은 경우 : last 탐색 범위 절반 감소
    {
        return BSearchRecur(ar, first, mid-1, target); // -1 : mid는 이미 참조, 재귀 탈출 조건
    }
    else // 찾는 값이 mid의 값 보다 큰 경우 : first 탐색범위 절반 감소
    {
        return BSearchRecur(ar, mid+1, last, target); // +1 : mid는 이미 참조, 재귀 탈출 조건
    }
}

// 하노이 탑 예제
void HanoiTowerMove(int num, char from, char by, char to) // A, B, C
{
    if (num == 1)
    {
        printf("원반 1을 %c에서 %c로 이동\n", from, to);
    }
    else
    {
        HanoiTowerMove(num-1, from, to, by); // A에 있는 원반을 C를 거쳐서 B로 이동
        printf("원반 %d을 %c에서 %c로 이동\n", num, from, to);
        HanoiTowerMove(num-1, by, from, to); // B에 있는 원반을 A를 거쳐서 C로 이동
    }
}

void testRecursive(void)
{
    /*
    // 재귀 함수 기본 구조
    Recursive(3);

    // 팩토리얼 예제
    int f, e;

    e = 1;
    f = Factorial(e);
    printf("%d! = %d\n", e, f);

    e = 2;
    f = Factorial(e);
    printf("%d! = %d\n", e, f);

    e = 3;
    f = Factorial(e);
    printf("%d! = %d\n", e, f);

    e = 4;
    f = Factorial(e);
    printf("%d! = %d\n", e, f);

    e = 9;
    f = Factorial(e);
    printf("%d! = %d\n", e, f);


    // 피보나치 수열 예제
    for (int i = 1; i < 15; ++i) {
        printf("%d ", Fibo(i));
    }

    // 이진 탐색 알고리즘 예제
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int), 3);
    printf("3 index of %d\n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int), 5);
    printf("5 index of %d\n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int), 6);
    printf("6 index of %d\n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int), 8);
    printf("8 index of %d\n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int), 13);
    if (idx == -1)
    {
        printf("13 not found!\n");
    }
    else
    {
        printf("13 index of %d\n", idx);
    }
    */

    // 하노이 탑 예제
    HanoiTowerMove(4, 'A', 'B', 'C');
}