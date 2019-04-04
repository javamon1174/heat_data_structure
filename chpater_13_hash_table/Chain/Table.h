#ifndef __TABLE_H_
#define __TABLE_H_

#include "Slot.h"
#include "DLinkedList.h"

#define MAX_TBL     100

typedef int HashFunc(Key k);

typedef struct _table
{
    List tbl[MAX_TBL];
    HashFunc * hf;
} Table;

void TBLInit(Table * pt, HashFunc * f);
void TBLInsert(Table * pt, Key k, Value val);
Value TBLDelete(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);

#endif