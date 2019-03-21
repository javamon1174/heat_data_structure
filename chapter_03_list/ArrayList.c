
void ListInit(List * plist)
{
    plist->numOfData = 0;
    plist->curPosition = -1;
}
void LInsert(List * plist, LData data)
{
    if(plist->numOfData > LIST_LEN)
    {
        puts("용량 초과.");
        return;
    }
    plist->arr[plist->numOfData] = data;
    plist->numOfData += 1;
}

int LFirst(List * plist, LData * pdata)
{
    if (plist->numOfData == 0)
        return FALSE;

    plist->curPosition = 0;
    *pdata = plist->arr[0];

    return TRUE;
}
int LNext(List * plist, LData * pdata)
{
    if (plist->numOfData == plist->curPosition+1)
        return FALSE;

    plist->curPosition += 1;
    *pdata = plist->arr[plist->curPosition];

    return TRUE;
}

LData LRemove(List * plist)
{
    int pos = plist->curPosition;
    int cnt = plist->numOfData;

    LData rData = plist->arr[pos];

    for (int i = pos; i < cnt; ++i) { // 삭제 이후 데이터 왼쪽으로 이동
        plist->arr[i] = plist->arr[i+1];
    }


    plist->curPosition -= 1; // 참조값을 이전 데이터로 이동
    plist->numOfData -= 1;

    return rData;
}

int LCount(List * plist)
{
    return plist->numOfData;
}