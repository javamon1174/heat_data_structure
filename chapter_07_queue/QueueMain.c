// 순환 큐
//#include "CircularQueue.h"
//#include "CircularQueue.c"

// 연결리스트 기반 큐
//#include "ListBaseQueue.h"
//#include "ListBaseQueue.c"

// 덱(Dequeue)
#include "Deque.h"
#include "Deque.c"

/*
// 순환 큐
void testCQueue()
{
    // Queue의 생성 및 초기화 ///////
    Queue q;
    QueueInit(&q);

    // 데이터 넣기 ///////
    Enqueue(&q, 1);  Enqueue(&q, 2);
    Enqueue(&q, 3);  Enqueue(&q, 4);
    Enqueue(&q, 5);
    Enqueue(&q, 10);  Enqueue(&q, 9);
    Enqueue(&q, 8);  Enqueue(&q, 7);
    Enqueue(&q, 6);

    // 데이터 꺼내기 ///////
    while(!QIsEmpty(&q))
        printf("%d ", Dequeue(&q));
}


// 연결리스트 기반 큐
void testListBaseQueue()
{
    // Queue의 생성 및 초기화 ///////
    Queue q;
    QueueInit(&q);

    // 데이터 넣기 ///////
    Enqueue(&q, 1);  Enqueue(&q, 2);
    Enqueue(&q, 3);  Enqueue(&q, 4);
    Enqueue(&q, 5);

    // 데이터 꺼내기 ///////
    while(!QIsEmpty(&q))
        printf("%d ", Dequeue(&q));

}
*/

// 덱(Dequeue)
void testDequeue()
{
    // Deque의 생성 및 초기화 ///////
    Deque deq;
    DequeInit(&deq);

    // 데이터 넣기 1차 ///////
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    // 데이터 꺼내기 1차 ///////
    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveFirst(&deq));

    printf("\n");

    // 데이터 넣기 2차 ///////
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    // 데이터 꺼내기 2차 ///////
    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveLast(&deq));
}