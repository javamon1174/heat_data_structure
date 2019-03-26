#include <stdlib.h>

void DequeInit(Deque * pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq)
{
    if (pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;

}

void DQAddFirst(Deque * pdeq, Data data) // 리스트 머리에 추가
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;

    if (DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;

    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data) // 리스트 꼬리에 추가
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pdeq->tail;

    if (DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("No data.");
        exit(-1);
    }

    Node *rNode = pdeq->head;
    Data rData = rNode->data;

    pdeq->head = pdeq->head->next; // 헤드 노드의 다음 노드를 헤드 노드로 대체

    free(rNode);

    if (pdeq->head == NULL) // 남은 데이터가 없을 경우
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL; // 머리 노드 prev 초기화(헤드 노드의 prev가 방금 삭제 됬기 때문)

    return rData;
}

Data DQRemoveLast(Deque * pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("No data.");
        exit(-1);
    }

    Node *rNode = pdeq->tail;
    Data rData = rNode->data;

    pdeq->tail = pdeq->tail->prev; // 꼬리 앞에 노드를 꼬리 노드로 대체

    free(rNode);

    if (pdeq->tail == NULL) // 남은 데이터가 없을 경우
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL; // 꼬리 노드 next 초기화

    return rData;
}

Data DQGetFirst(Deque * pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("No data.");
        exit(-1);
    }

    return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("No data.");
        exit(-1);
    }

    return pdeq->tail->data;
}