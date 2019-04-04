#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person * p)
{
    return p->ssn;
}

void ShowPerInfo(Person * p)
{
    printf("주민등록번호 : %d\n이름       : %s\n주소       : %s\n\n", p->ssn, p->name, p->addr);
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
    Person *newPerson = (Person *)malloc(sizeof(Person));
    newPerson->ssn = ssn;
    strcpy(newPerson->name, name);
    strcpy(newPerson->addr, addr);

    return newPerson;
}