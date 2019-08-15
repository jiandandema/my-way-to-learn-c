#include <stdio.h>
#include <stdlib.h>

typedef struct SNode *Stack;

struct SNode
{
	int Data[MAXSIZE];
	int top;	
};

Stack *CreateStack(int maxszie);
void Push(Stack Ptrs,int item); 
int Pop(Stack PtrS);

Stack *CreateStack(int maxsize)
{
    struct SNode
    {
        int Data[maxsize];
        int top;
    };
    Stack S = malloc(sizeof(struct SNode));
    return S;
}

void Push(Stack Ptrs,int item)
{
    if(Ptrs->top == MAXSIZE - 1)
    {
        printf("堆栈已满!\n");
        return;
    }
    else
    {
        Ptrs->Data[++(Ptrs->top)] = item;
    }
}

int Pop(Stack Ptrs)
{
    if(Ptrs->top == -1)
    {
        printf("堆栈空!\n");
        return ERROR;
    }
    else
    {
        return Ptrs->Data[(Ptrs->top)--];
    }
}
