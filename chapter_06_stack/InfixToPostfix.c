#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

#include "InfixToPostfix.h"

int GetOpPrec(char op) // 연산자 우선 순위
{
    switch (op)
    {
        case '*':
        case '/':
            return 5;

        case '+':
        case '-':
            return 3;

        case '(':
//        case ')': 괄호는 메세징 역할만 수행
            return 1;
    }

    return -1;
}

int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec)
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else
        return 0; // 우선순위 동일
}

// Reverse Polish Notation
void ConvToRPNExp(char exp[]) // 중위 -> 후위 표기법
{
    Stack stack;
    int expLen = strlen(exp);
    char * convExp = (char *)malloc(sizeof(expLen+1));

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);

    for(i=0; i<expLen; i++)
    {
        tok = exp[i];
        if (isdigit(tok)) // 피연산자일 경우
        {
            convExp[idx++] = tok;
        }
        else // 연산자일 경우
        {
            switch (tok)
            {
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')': // 괄호는 메세징 역할만
                    while (1)
                    {
                        popOp = SPop(&stack);
                        if(popOp == '(')
                            break;
                        convExp[idx++] = popOp;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) // 우선순위 비교
                        convExp[idx++] = SPop(&stack);

                    SPush(&stack, tok);
                    break;
            }

        }
    }

    while (!SIsEmpty(&stack)) // 스택에 남아있는 모든 연산자를 이동
        convExp[idx++] = SPop(&stack);

    strcpy(exp, convExp); // 복사 후 소멸
    free(convExp);
}