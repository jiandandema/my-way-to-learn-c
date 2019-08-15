#include <stdio.h>
#include <stdlib.h>

typedef struct SNode *Stack;

struct SNode
{
    int Data;
    struct SNode *Next;
};

Stack CreateStack();
int IsEmpty(Stack S);
void Push(Stack S, int item);
int Pop(Stack S);

Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(Stack S)
{
    return (S->Next == NULL);
}

void Push(Stack S, int item)
{
    Stack PtrQ;
    PtrQ = (Stack)malloc(sizeof(struct SNode));
    PtrQ->Data = item;
    PtrQ->Next = S->Next;
    S->Next = PtrQ;
}

int Pop(Stack S)
{
    Stack FirstCell;
    int TopData;
    if(IsEmpty(S))
    {
        printf("堆栈空!\n");
        return NULL;
    }
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopData = FirstCell->Data;
        free(FirstCell);
        return TopData;
    }
}
