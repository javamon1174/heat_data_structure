#include "Table.h"

void TBLInit(Table * pt, HashFunc * f)
{
    // 슬롯 초기화
    for (int i = 0; i < MAX_TBL; ++i) {
        ListInit(&(pt->tbl[i]));
    }

    pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v)
{
    int idx = pt->hf(k);
    Slot nSlot = {k , v};

    if (TBLSearch(pt, k))
    {
        printf("exists key.");
        return ;
    }
    else
    {
        LInsert(&(pt->tbl[idx]), nSlot);
    }
}

Value TBLDelete(Table * pt, Key k)
{
    int idx = pt->hf(k);
    Slot cSlot;

    if (LFirst(&(pt->tbl[idx]), &cSlot))
    {
        if (cSlot.key == k)
        {
            LRemove(&(pt->tbl[idx]));
            return cSlot.val;
        }
        else
        {
            while (LNext(&(pt->tbl[idx]), &cSlot))
            {
                if (cSlot.key == k)
                {
                    LRemove(&(pt->tbl[idx]));
                    return cSlot.val;
                }
            }
        }
    }

    return FALSE; // NULL => FALSE Value가 포인터 형(주소 값)이어야 한다는 제약을 없앰
}

Value TBLSearch(Table * pt, Key k)
{
    int idx = pt->hf(k);
    Slot cSlot;

    if (LFirst(&(pt->tbl[idx]), &cSlot))
    {
        if (cSlot.key == k)
        {
            return cSlot.val;
        }
        else
        {
            while (LNext(&(pt->tbl[idx]), &cSlot))
            {
                if (cSlot.key == k)
                {
                    return cSlot.val;
                }
            }
        }
    }

    return FALSE;
}
