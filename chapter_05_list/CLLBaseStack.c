//#include "CLinkedList.h"
#include "CLLBaseStack.h"
#include "CLinkedList.c"

void StackInit(Stack * pstack)
{
    pstack->plist = (List *) malloc(sizeof(List));
    ListInit(pstack->plist);
}

int SIsEmpty(Stack * pstack)
{
    if (LCount(pstack->plist) == 0)
        return TRUE;
    else
        return FALSE;

}

void SPush(Stack * pstack, Data data)
{
    LInsertFront(pstack->plist, data);
}

Data SPop(Stack * pstack)
{
    Data d;
    LFirst(pstack->plist, &d);
    LRemove(pstack->plist);
    return d;
}

Data SPeek(Stack * pstack)
{
    Data d;
    LFirst(pstack->plist, &d);
    return d;
}