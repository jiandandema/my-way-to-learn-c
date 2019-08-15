#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct QSNode *Queue;

struct QSNode
{
    int Element[MAXSIZE];
    int front;
    int rear;
};

Queue CreatQueue();
int IsEmpty(Queue Node);
void Add(Queue Node, int K);
int Delet(Queue Node);

Queue CreatQueue()
{
    Queue Node;

    Node = (Queue)malloc(sizeof(struct QSNode));

    return Node;
}

int IsEmpty(Queue Node)
{
    if(Node->front == Node->rear) return 1;
    else return 0;
}

void Add(Queue Node, int K)
{
    if((Node->rear+1)%MAXSIZE == Node->front)
    {
        printf("队列满!\n");
        return NULL;
    }
    else
    {
        Node->rear = (Node->rear + 1)%MAXSIZE;
        Node->Element[Node->rear] = K;
    }

}

int Delete(Queue Node)
{
    int K;
    if(IsEmpty(Node))
    {
        printf("队列空!\n");
        return;
    }
    else
    {
        K = Node->Element[Node->front];
        return K;
        Node->front = (Node->front + 1)%MAXSIZE;
    }
    
}
