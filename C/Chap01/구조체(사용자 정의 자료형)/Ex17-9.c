//자기 참조 구조체로 list만들기
#include <stdio.h>

struct list
{
    int num;
   struct list* next;
};

int main()
{
    //LinkedList
    struct list a = {10,0}, b = {20,0}, c = {30,0};
    struct list* head = &a, *current;
    //struct list* head;
    //struct list* current;

    a.next = &b;
    b.next = &c;

    printf("head->num : %d\n", head->num);
    printf("head->next->num : %d\n", head->next->num);

    printf("list all : ");
    current = head;
    while (current != NULL){
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");

    return 0;
}
