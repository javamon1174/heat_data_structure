#include "CLinkedList.h"

void ListInit(List * plist){
    plist->before = NULL;
    plist->cur = NULL;
    plist->tail = NULL;
    plist->numOfData = 0;
}


void LInsertFront(List * plist, Data data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) // 첫 데이터
    {
        plist->tail = newNode;
        newNode->next = newNode; // 자기 꼬리를 무는 방식
    }
    else
    {
        newNode->next = plist->tail->next; // 첫 노드 주소 값 복사
        plist->tail->next = newNode;
    }

    plist->numOfData += 1;
}

void LInsert(List * plist, Data data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) // 첫 데이터
    {
        plist->tail = newNode;
        newNode->next = newNode; // 자기 꼬리를 무는 방식
    }
    else
    {
        newNode->next = plist->tail->next; // 첫 노드 주소 값 복사
        plist->tail->next = newNode;
        plist->tail = newNode; // Front 와 차이점 => 새로 추가되는 노드를 테일 노드로 지정하냐 안하냐의 차이
    }

    plist->numOfData += 1;
}

int LFirst(List * plist, Data * data)
{
    if (plist->tail == NULL)
        return FALSE;

    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *data = plist->cur->data;

    return TRUE;
}

int LNext(List * plist, Data * data)
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *data = plist->cur->data;

    return TRUE;
}

Data LRemove(List * plist)
{
    Node *curNode = plist->cur;
    Data rdata = curNode->data;

    // 예외
    if (curNode == plist->tail) // 삭제 대상이 꼬리인 경우
    {
        // 예외 삭제할 노드가 마지막일 경우
        if (plist->tail == plist->tail->next)
            plist->tail = NULL; // LFirst 반복문 탈출 조건
        else
            plist->tail = plist->before;

    }

    plist->before->next = curNode->next;
    plist->cur = plist->before;

    free(curNode);
    plist->numOfData -= 1;

    return rdata;
}

int LCount(List * plist)
{
    return plist->numOfData;
}

// 퍼풱트하게 다 직접 구현!