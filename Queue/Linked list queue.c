#include <stdio.h>
#include<stdlib.h>

struct Node
{
	int Data;
	struct Node *Next;
};

struct QNode
{
	struct Node *front;
	struct Node *rear;
};

typedef struct QNode *Queue;

Queue PtrQ;

int DeleteQ(Queue PtrQ);
void AddQ(Queue PtrQ, int Element);

int DeleteQ(Queue PtrQ)
{
    struct Node *FrontCell;
    int FrontElement;
    if(PtrQ->front == NULL)
    {
        printf("队列空!\n");
        return ERROR;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear)
    {
        PtrQ->front = PtrQ->rear = NULL;
    }
    else
    {
        PtrQ->front = PtrQ->front->Next;
    }
    FrontElement = FrontCell->Data;
    free(FrontCell);
    return FrontElement;
}

void AddQ(Queue PtrQ, int Element)
{
    struct Node *Elementpint;
    Elementpoint = malloc(sizeof(struct Node));
    Elementpoint->Data = Element;
    Elementpoint->Next = NULL;
    if(PtrQ->front == NULL)
    {
        PtrQ->front = Elementpoint;
        PtrQ->rear = Elementpoint;
    }
    else
    {
        PtrQ->rear->Next = Elementpoint;
        PtrQ->rear = Elementpoint;
    }
}
