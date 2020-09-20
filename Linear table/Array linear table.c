#include <stdio.h>

typedef struct LNode *List;

List MakeEmpty();						//*声明建立数组线性表*// 
int Find(int X, List PtrL);				//*声明寻找数组线性表元素函数*//
List Insert(int X, int i, List PtrL);	//*声明插入数组线性表函数*//
List Delet(int i, List PtrL);			//*声明删除数组线性表函数*//
void print(List p);						//*打印函数*// 
 


struct LNode
{
	int Date[100];
	int Last;
};

void main()
{
	List p;
	int i, k;
	
	p = MakeEmpty();
	for(i = 0; i <= 9; i++)
		p->Date[i] = i + 1;
	p->Last = 9;
	
	printf("this is original list\n");
	print(p);
	
	printf("this is element 5's location\n");
	k = Find(5, p);
	printf("%d\n", k);
	
	printf("insert 7 in the %dth\n", k);
	Insert(7, k, p);
	print(p);
	
	printf("delet the %dth element in the list\n", k);
	Delet(k, p);
	print(p);
 }
 
List MakeEmpty()
{
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;
	
	return PtrL;
}

int Find(int X, List PtrL)
{
	int i = 0;
	while(PtrL->Date[i] != X && i <= PtrL->Last)//*&&i <= PtrL->Last*//
	{
		i++;
	}
	
	if(i > PtrL->Last)
	{
		printf("there is no %d in the list\n", X);
		return -1;
	}
	else
	{
		return i;
	}
	
}

List Insert(int X, int i, List PtrL)
{
	int j;
	if(PtrL->Last == 100  - 1)
	{
		printf("表满\n");
		return;
	}
	if(i < 1 || i > PtrL->Last + 2)
	{
		printf("i must between 1 and %d", PtrL->Last);
		return;
	}
	
	for(j = PtrL->Last; j>= i-1; j--)
	{
		PtrL->Date[j+1] = PtrL->Date[j];
	}
	PtrL->Date[i-1] = X;
	PtrL->Last++;
	
	return;
}

List Delet(int i, List PtrL)
{
	int j;
	if(i < 1 && i > PtrL->Last + 1)
	{
		printf("there is not %d element", i);
	}
	else
	{
		for(j = i; j <= PtrL->Last; j++)
		{
			PtrL->Date[j-1] = PtrL->Date[j];
		}
		PtrL->Last--;
	}
	
	return;
}

void print(List p)
{
	int i;
	for(i = 0; i <= p->Last; i++)
		printf("%d\n", p->Date[i]);
	printf("this is the length of the list\n");
	printf("%d\n\n\n\n", p->Last);
}
