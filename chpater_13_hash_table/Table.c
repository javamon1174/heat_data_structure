#include "Table.h"

void TBLInit(Table * pt, HashFunc * f)
{
    // 슬롯 초기화
    for (int i = 0; i < MAX_TBL; ++i) {
        (pt->tbl[i]).status = EMPTY;
    }

    pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value val)
{
    int idx = pt->hf(k);

    pt->tbl[idx].key = k;
    pt->tbl[idx].val = val;
    pt->tbl[idx].status = INUSE;
}

Value TBLDelete(Table * pt, Key k)
{
    int idx = pt->hf(k);

    if (pt->tbl[idx].status != INUSE)
        return NULL;
    else
    {
        pt->tbl[idx].status = DELETED;

        return pt->tbl[idx].val;
    }
}

Value TBLSearch(Table * pt, Key k)
{
    int idx = pt->hf(k);

    if (pt->tbl[idx].status != INUSE)
        return NULL;
    else
    {
        return pt->tbl[idx].val;
    }
}
