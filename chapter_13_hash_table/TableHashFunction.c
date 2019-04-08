#include <stdio.h>

typedef struct _empInfo
{
    int empNum;
    int age;
} EmpInfo;

int GetHashValue(int empNum)
{
    return empNum % 100;
}

void TableHashFunction()
{
    EmpInfo empInfoArr[100];
    /* 100명이 넘을 경우 고려 X
     * 사번은 넓은 범위의 키, 해쉬값은 좁은 범위의 키로 활용된다.
     * 해쉬값을 구하는 함수를 해쉬 함수라 한다.
     * 해쉬 함수에서 가장 중요한건 고루 분포되는 데이터 저장, 해쉬 값 충돌의 해결이다.
     */

    EmpInfo emp1 = {20120003, 42};
    EmpInfo emp2 = {20130012, 33};
    EmpInfo emp3 = {20170049, 27};

    EmpInfo r1, r2, r3;

    empInfoArr[GetHashValue(emp1.empNum)] = emp1;
    empInfoArr[GetHashValue(emp2.empNum)] = emp2;
    empInfoArr[GetHashValue(emp3.empNum)] = emp3;

    r1 = empInfoArr[GetHashValue(20120003)]; // 사번으로 조회
    r2 = empInfoArr[GetHashValue(20130012)];
    r3 = empInfoArr[GetHashValue(20170049)];

    printf("사번 : %d, 나이 : %d\n", r1.empNum, r1.age);
    printf("사번 : %d, 나이 : %d\n", r2.empNum, r2.age);
    printf("사번 : %d, 나이 : %d\n", r3.empNum, r3.age);
}