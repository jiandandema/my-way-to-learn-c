#include <stdio.h>

typedef struct LNode *List;

List MakeEmpty();						//*���������������Ա�*//
int Length(List PtrL);					//*�����������Ա��Ⱥ���*// 
List Find(int X, List PtrL);			//*����Ѱ���������Ա�Ԫ�غ���*//
List FindKth(int K, List PtrL);			//*����Ѱ���������Ա�ڼ����ĺ���*//	
List Insert(int X, int i, List PtrL);	//*���������������Ա���*//
List Delet(int i, List PtrL);			//*����ɾ���������Ա���*//



struct LNode
{
	int Date;
	Last Next;
};

void main()
{
	struct LNode *stu;
	
	stu->Date
 }
 
List MakeEmpty()
{
	List p;
	p = (List)malloc(sizeof(struct LNode));
	p->Next = NULL;
	
	return p;
} 

int Length(List PtrL)
{
	int n = 0;
	List p = PtrL;
	while(p)
	{
		n++;
		p = p->Next;
	}
	
	return n;
}

List Find(int X, List PtrL)
{
	List p =PtrL;
	while(p->Date != X && p->Next != NULL)
	{
		p = p->Next;
	}
	
	if(p->Next == NULL)
	{
		printf("there is no %d in the list\n", X);
		return NULL;
	}
	else
	{
		return p;
	}
}

List FindKth(int K, List PtrL);
{
	int i = 1;
	List p = PtrL;
	if(K > Length(PtrL) || K < 1)
	{
		printf("%d is out range\n", X)
		return NULL;
	}
	else
	{
		for(;i < K; i++)
		{
			p = p->Next; 
		}

		return p;
	}
}
