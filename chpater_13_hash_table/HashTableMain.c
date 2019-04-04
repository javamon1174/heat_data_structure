//#include "UnderstandTable.c"
//#include "TableHashFunction.c"

// 기본 해쉬테이블
//#include "Table.h"
//#include "Person.c"
//#include "Table.c"

// 체이닝
#include "Chain/Table.h"
#include "Chain/Person.c"
#include "Chain/Table.c"
#include "Chain/DLinkedList.c"

int MyHashFunc(int k)
{
    return k % 100;    // 키를 부분적으로만 사용한 별로 좋지 않은 해쉬의 예!!!
}

int FirstHashFunc(int k)
{
    return k % 15;
}

int SecondHashFunc(int k) // 충돌시 이중 해쉬로 보완!
{
    return k % 7;
}

void HashTableMain()
{
//    UnderstandTableMain(); // 배열기반 기초적인 테이블
//    TableHashFunction(); // 기초적인 해쉬 테이블 => 충돌

    /*
     * 하나의 해쉬함수를 활용한 해쉬 테이블
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;

    TBLInit(&myTbl, MyHashFunc);

    // 데이터 입력
    np = MakePersonData(20120003, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(20130012, "KIM", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(20170049, "HAN", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);

    // 데이터 검색
    sp = TBLSearch(&myTbl, 20120003);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 20130012);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 20170049);
    if(sp != NULL)
        ShowPerInfo(sp);

    // 데이터 삭제
    rp = TBLDelete(&myTbl, 20120003);
    if(rp != NULL)
        free(rp);

    rp = TBLDelete(&myTbl, 20130012);
    if(rp != NULL)
        free(rp);

    rp = TBLDelete(&myTbl, 20170049);
    if(rp != NULL)
        free(rp);
    */

    // 닫힌 어드레스 방식의 체이닝
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;

    TBLInit(&myTbl, MyHashFunc);

    // 데이터 입력 ///////
    np = MakePersonData(900254, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900139, "KIM", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);

    np = MakePersonData(900827, "HAN", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);

    // 데이터 탐색 ///////
    sp = TBLSearch(&myTbl, 900254);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900139);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl, 900827);
    if(sp != NULL)
        ShowPerInfo(sp);

    // 데이터 삭제 ///////
    rp = TBLDelete(&myTbl, 900254);
    if(rp != NULL)
        free(rp);

    rp = TBLDelete(&myTbl, 900139);
    if(rp != NULL)
        free(rp);

    rp = TBLDelete(&myTbl, 900827);
    if(rp != NULL)
        free(rp);
}