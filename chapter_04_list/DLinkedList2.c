int WhoIsPrecede(LData d1, LData d2) // 리스트 정렬 기준
{
    return 0;
//    if (d1 < d2) // 순차
//        return 0;
//    else
//        return 1;
}

void ListInit(List * plist)
{
    plist->head = (Node*) malloc(sizeof(Node)); // 동적 메모리 할당

    // 더미 지정
    plist->head->next = NULL;
    plist->comp = NULL;

    plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
    Node *newNode = (Node*) malloc(sizeof(Node)); // 동적 메모리 할당
    newNode->data = data;

    newNode->next = plist->head->next; // 새 노드가 다른 노드 지시
    plist->head->next = newNode; // 더미 노드가 새 노드 지시

    (plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    Node * pred = plist->head;
    newNode->data = data;

    while(pred->next != NULL &&
          plist->comp(data, pred->next->data) != 0) // 새 노드가 들어갈 위치 탐색(정렬 조건)
    {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfData)++;
}


void LInsert(List * plist, LData data)
{
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
    if(plist->head->next == NULL)
        return FALSE;

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}


int LNext(List * plist, LData * pdata)
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->before = plist->cur; // 이전 노드에 현재 노드 지시
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List * plist)
{
    if (plist->head->next == NULL)
        return NULL;

    Node *rNode = plist->cur;
    LData rData = rNode->data;

    plist->before->next = rNode->next;
    plist->cur = plist->before; // 현재 지시노드를 삭제 노드의 다음 지시노드로

    free(rNode);
    (plist->numOfData)--;

    return rData;

}

int LCount(List * plist)
{
    return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}



