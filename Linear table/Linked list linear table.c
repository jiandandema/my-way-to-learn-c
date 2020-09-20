#include <stdio.h>

typedef struct LNode *List;

List MakeEmpty();						//*���������������Ա�*//
int Length(List PtrL);					//*�����������Ա��Ⱥ���*// 
List Find(int X, List PtrL);			//*����Ѱ���������Ա�Ԫ�غ���*//
List FindKth(int K, List PtrL);			//*����Ѱ���������Ա�ڼ����ĺ���*//	
List Insert(int X, int i, List PtrL);	//*���������������Ա���*//
List Delet(int i, List PtrL);			//*����ɾ���������Ա���*//

typedef List Position;

struct LNode
{
	int Date;
	List Next;
};

void main()
{
	struct LNode *stu;
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
	while(p->Date != X && p)
	{
		p = p->Next;
	}
	
	if(p)
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
		for(i = 0;i < K; i++)
		{
			p = p->Next; 
		}

		return p;
	}
}

bool Insert(List L, int X, Position P){
	Position temp, pre;
	for(pre = L; pre&&pre != P&&pre->Next != P; pre = pre->Next) ;
	if(pre == NULL){
		return false;
		printf("your position is out of range!\n");
	}
	else{
		temp = (Positon)malloc(sizeof(struct LNode));
		temp->Data = X;
		pre->Next = temp;
		temp->Next = P;
		return true;
	}
}

bool Delete(List L, Position P){
	Position pre;
	for(pre = L; pre&&pre != P&&pre->Next != P; pre=pre->Next) ;
	if(pre == NULL || P == NULL){
		return false;
		printf("your Position is out of range!\n");
	}
	else{
		pre->Next = P->Next;
		free(P);
		return true;
	}
}
