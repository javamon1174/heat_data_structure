#include <stdlib.h>

typedef struct _empInfo
{
    int empNum;
    int age;
} EmpInfo;

// 배열기반 기초적인 테이블
void UnderstandTableMain()
{
    EmpInfo empInfoArr[100];
    EmpInfo ei;
    int eNum;

    printf("새로운 사원의 번호와 나이를 입력해주세요.\n");
    scanf("%d %d", &(ei.empNum), &(ei.age));

    empInfoArr[ei.empNum] = ei;

    printf("조회할 사원의 번호를 입력해주세요.\n");

    scanf("%d", &eNum);

    ei = empInfoArr[eNum];

    printf("조회된 사원의 정보입니다.\n");
    printf("사번 : %d  나이 : %d", ei.empNum, ei.age);
}