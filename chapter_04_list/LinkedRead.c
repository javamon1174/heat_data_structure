#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int LinkedRead(void)
{
    Node * head = NULL;    // NULL 포인터 초기화
    Node * tail = NULL;
    Node * cur = NULL;

    Node * newNode = NULL;

    int readData;

    while(1)
    {
        printf("자연수 입력: ");
        scanf("%d", &readData);
        if(readData < 1)
            break;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
//            tail = newNode; // 역순
        }
        else
        {
            //순차
            tail->next = newNode;

            // 역순
//            newNode->next = head;
//            head = newNode;
        }

        tail = newNode; // 순차
    }
    printf("\n");

    printf("입력 받은 데이터의 전체출력! \n");
    if(head == NULL)
    {
        printf("저장된 자연수가 존재하지 않습니다. \n");
    }
    else
    {
        cur = head;
        printf("%d  ", cur->data);   // 첫 번째 데이터 출력

        while(cur->next != NULL)    // 두 번째 이후의 데이터 출력
        {
            cur = cur->next;
            printf("%d  ", cur->data);
        }
    }
    printf("\n");

    if(head == NULL)
    {
        return 0;    // 해제할 노드가 존재하지 않는다.
    }
    else
    {
        Node * delNode = head;
        Node * delNextNode = head->next;

        printf("%d을(를) 삭제합니다. \n", head->data);
        free(delNode);   // 첫 번째 노드의 삭제

        while(delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("%d을(를) 삭제합니다. \n", delNode->data);
            free(delNode);    // 두 번째 이후의 노드 삭제
        }
    }

    return 0;
}