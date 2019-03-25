// testStack
//#include "ArrayBaseStack.h"
//#include "ArrayBaseStack.c"

// testLinkedListStack
//#include "ListBaseStack.h"
//#include "ListBaseStack.c"

// testPostfix
#include "InfixToPostfix.h"
#include "InfixToPostfix.c"
#include "ListBaseStack.c"

// Calculator
#include "PostCalculator.h"
#include "PostCalculator.c"

#include "InfixCalculator.h"
#include "InfixCalculator.c"

/*
void testStack(void)
{
    // Stack의 생성 및 초기화 ///////
    Stack stack;
    StackInit(&stack);

    // 데이터 넣기 ///////
    SPush(&stack, 1);  SPush(&stack, 2);
    SPush(&stack, 3);  SPush(&stack, 4);
    SPush(&stack, 5);

    // 데이터 꺼내기 ///////
    while(!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));
}
*/

void testLinkedListStack()
{
    // Stack의 생성 및 초기화 ///////
    Stack stack;
    StackInit(&stack);

    // 데이터 넣기 ///////
    SPush(&stack, 1);  SPush(&stack, 2);
    SPush(&stack, 3);  SPush(&stack, 4);
    SPush(&stack, 5);

    // 데이터 꺼내기 ///////
    while(!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));
}

void testPostfix()
{
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";

    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);

    printf("%s \n", exp1);
    printf("%s \n", exp2);
    printf("%s \n", exp3);
}

void testCalculator()
{
    char postExp1[] = "42*8+";
    char postExp2[] = "123+*4/";

    printf("%s = %d \n", postExp1, EvalRPNExp(postExp1));
    printf("%s = %d \n", postExp2, EvalRPNExp(postExp2));
}

void testInfixCalculator()
{
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";

    printf("%s = %d \n", exp1, EvalInfixExp(exp1));
    printf("%s = %d \n", exp2, EvalInfixExp(exp2));
    printf("%s = %d \n", exp3, EvalInfixExp(exp3));
}