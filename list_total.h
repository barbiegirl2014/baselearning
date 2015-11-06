#ifndef LIST_TOTAL_H
#define LIST_TOTAL_H

typedef struct ListNode_
{
    int key;
    struct ListNode_ *next;
    
}ListNode;

enum
{
    TRUE,
    FALSE,
};

typedef struct Stack_
{
    ListNode *top;
    int size;
}Stack;

#endif