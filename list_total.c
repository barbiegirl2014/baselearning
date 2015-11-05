#include <stdio.h>
#include <stdlib.h>
#include "list_total.h"

ListNode *create_list(int length)
{
    ListNode *head = NULL, *p = NULL, *q = NULL;
    int i = 0;
    if(!length) return NULL;

    for(i = 0; i < length; i++)
    {
        p = (ListNode *)calloc(1,sizeof(ListNode));
        if(!p) return NULL;
        p->next = q;
        p->key = i;
        q = p;        
    }
    return p;
}

void print_list(ListNode *head)
{
    ListNode *p = head;

    while(p)
    {
        printf("node:%d!\n",p->key);
        p = p->next;
    }
}

void reverse_list(ListNode **head)
{
    ListNode *p = NULL, *q = NULL, *r = NULL;

    if(!head) return;

    p = *head;
    q = p->next;    
    while(q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    (*head)->next = NULL;
    *head = p;
}

void print_the_last_kth_node(ListNode *head, int k)
{
    ListNode *front = head, *behind =head;
    int index = k;
    printf("print the last %dth node\n",index);
    if(k <= 0) 
    {
        printf("invalid value of 'k':%d(too small)\n",k);
        return;
    }
    while(k > 0 && front != NULL)
    {
        front = front->next;
        k--;
    }
    if(k > 0)
    {
        printf("invalid value of 'k':%d(too big)\n",index);
        return;
    }
    while(front != NULL)
    {
        front = front->next;
        behind = behind->next;
    }
    printf("the last %dth node is %d\n",index,behind->key);
}

/* testing program */
int main(void)
{
    ListNode *head = NULL;

    if((head = create_list(10)) == NULL) fprintf(stderr,"failed to create list!\n");
#if 0
    fprintf(stdout,"the list before reverse:\n");
    print_list(head);
    reverse_list(&head);
    fprintf(stdout,"the list after reverse:\n");
    print_list(head);
#endif

    print_list(head);
    print_the_last_kth_node(head,1);
    print_the_last_kth_node(head,10);
    print_the_last_kth_node(head,11);
    print_the_last_kth_node(head,5);
    return 0;
}