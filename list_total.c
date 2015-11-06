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

ListNode *create_list_odd(int length)
{
    ListNode *head = NULL, *p = NULL, *q = NULL;
    int i = 0;
    if(!length) return NULL;

    for(i = 0; i < length; i++)
    {
        p = (ListNode *)calloc(1,sizeof(ListNode));
        if(!p) return NULL;
        p->next = q;
        p->key = 2*i+1;
        q = p;        
    }
    return p;
}

ListNode *create_list_even(int length)
{
    ListNode *head = NULL, *p = NULL, *q = NULL;
    int i = 0;
    if(!length) return NULL;

    for(i = 0; i < length; i++)
    {
        p = (ListNode *)calloc(1,sizeof(ListNode));
        if(!p) return NULL;
        p->next = q;
        p->key = 2*i;
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

int list_is_loop(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            break;
        }
    }

    if(fast == NULL || fast->next == NULL)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

ListNode *merge_list(ListNode *head1, ListNode *head2)
{
    ListNode *mergehead, *p , *q, *pre, *post;
    if(!head1 && !head2)
    {
        return NULL;
    }
    if(!head1 && head2)
    {
        return head2;
    }
    if(head1 && !head2)
    {
        return head1;
    }

    if(head1->key > head2->key)
    {
        mergehead = head2;
        q = head1;
    }
    else
    {
        mergehead = head1;
        q = head2;
    }
    p = mergehead;

    while(p != NULL && q != NULL)
    {
        if(p->key > q->key)
        {
            pre->next = q;
            post = q->next;
            q->next = p;
            q = post;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    if(!p)
    {
        pre->next = q;
    }

    return mergehead;
}

ListNode *find_the_mid_node(ListNode *head)
{
    
}
Stack *init_stack()
{
    Stack *ps = calloc(1,sizeof(Stack));
    return ps;
}

int is_stack_empty(Stack *ps)
{
    if(ps->size) return FALSE;
    return TRUE;
}

ListNode *get_top_node(Stack *ps)
{
    return ps->top;
}

void push_stack(Stack *ps, ListNode *node)
{
    node->next = get_top_node(ps);
    ps->top = node;
    ps->size++;
    printf("push node:%d\n",node->key);
}

void pop_stack(Stack *ps)
{
    if(ps->size == 0) 
    {
        printf("the stack is already empty!\n");
        return;
    }
    printf("pop node:%d\n",ps->top->key);
    ps->top=ps->top->next;
    ps->size--;
    
}
void print_list_reversely(ListNode *head)
{
    Stack *ps = init_stack();
    ListNode *p = head, *q;
    if(!ps || !p) return;

    while( p != NULL)
    {
        q = p->next;
        push_stack(ps, p);
        p = q;
    }

    while(ps->size)
    {
        pop_stack(ps);
    }
    
}
/* testing program */
int main(void)
{
    ListNode *head = NULL;
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *merge = NULL;
    if((head = create_list(10)) == NULL) fprintf(stderr,"failed to create list!\n");
#if 0/* reverse the list */
    fprintf(stdout,"the list before reverse:\n");
    print_list(head);
    reverse_list(&head);
    fprintf(stdout,"the list after reverse:\n");
    print_list(head);
#endif

#if 0/* printf the last kth node */
    print_list(head);
    print_the_last_kth_node(head,1);
    print_the_last_kth_node(head,10);
    print_the_last_kth_node(head,11);
    print_the_last_kth_node(head,5);
#endif

#if 0/* merge the two ordered list */
    if((head1 = create_list_even(3)) == NULL) fprintf(stderr,"failed to create list!\n");
    if((head2 = create_list_odd(5)) == NULL) fprintf(stderr,"failed to create list!\n");
    printf("the even list:\n");
    reverse_list(&head1);
    print_list(head1);
    printf("the odd list:\n");
    reverse_list(&head2);
    print_list(head2);
    merge = merge_list(head1, head2);
    printf("the merge list:\n");
    print_list(merge);
#endif    
    fprintf(stdout,"the origin list:\n");
    print_list(head);
    print_list_reversely(head);
    return 0;
}