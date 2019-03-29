// 간단한 힙
//#include "SimpleHeap.h"
//#include "SimpleHeap.c"

// 사용할만한 힙
#include "UsefulHeap.h"
#include "UsefulHeap.c"
#include "string.h"

//int DataPriorityComp(char ch1, char ch2)
//{
//    return ch2-ch1;
//	return ch1-ch2;
//}

// 문제 09-1
int DataPriorityComp(char *ch1, char *ch2)
{
    return strlen(ch2)-strlen(ch1);
    return ch2-ch1;
//	return ch1-ch2;
}


/*
void testSimpleHeap(void)
{
    Heap heap;
    HeapInit(&heap);

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c \n", HDelete(&heap));

    while(!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));

}
*/

// 사용할만한 힙
void testUseHeap(void)
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, "AA");
    HInsert(&heap, "BBB");
    HInsert(&heap, "CCCC");
    HInsert(&heap, "D");

    while(!HIsEmpty(&heap))
        printf("%s \n", HDelete(&heap));
}