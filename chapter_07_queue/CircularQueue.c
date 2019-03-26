#include "CircularQueue.h"

void QueueInit(Queue * pq)
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
    if (pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos) // pos => 위치 값
{
    if (pos == QUE_LEN-1)
        return 0;
    else
        return pos+1;
}

void Enqueue(Queue * pq, Data data)
{
    if (NextPosIdx(pq->rear) == pq->front)
    {
        printf("Queue memory error!!");
    }

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue memory error!!");
    }

    pq->front = NextPosIdx(pq->front);

    return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue memory error!!");
    }

    Data rdata = pq->queArr[NextPosIdx(pq->front)];

    return rdata;
}