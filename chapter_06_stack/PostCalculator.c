#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for (int i = 0; i < expLen; ++i)
    {
        tok = exp[i];

        if (isdigit(tok)) // 문자가 정수인지 확인
        {
            SPush(&stack, tok - '0'); // 숫자로 변환하여 PUSH!
        }
        else
        {
            op2 = SPop(&stack); // 두번째 피연산자
            op1 = SPop(&stack); // 첫번째 피연산자

            switch (tok) // 각 연산자에 맞게 연산
            {
                case '+':
                    SPush(&stack, op1+op2);
                    break;
                case '-':
                    SPush(&stack, op1-op2);
                    break;
                case '*':
                    SPush(&stack, op1*op2);
                    break;
                case '/':
                    SPush(&stack, op1/op2);
                    break;
            }
        }
    }

    return SPop(&stack);
}
