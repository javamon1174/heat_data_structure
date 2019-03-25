#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "InfixCalculator.h"

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int let;

    char * cpy = (char *)malloc(len+1); // 복사할 공간 생성

    strcpy(cpy, exp);

    ConvToRPNExp(cpy);  // 중위식을 후위식으로 변환
    let = EvalRPNExp(cpy); // 후위식 계산

    free(cpy);

    return let;
}
