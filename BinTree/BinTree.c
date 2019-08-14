#include <stdio.h>

#define BinTree int
#define MAXSIZE 10
#define Null -1

struct TreeNode{
	int Element;
	char left;
	char right;
}T[MAXSIZE];

BinTree BuildBinTree();
BinTree PositionFind(int X, BinTree BST);
BinTree PositionIterFind(int X, BinTree BST);
BinTree PositionFindMax(BinTree BST);
BinTree PositionFindMin(BinTree BST);

BinTree BuildBinTree(){
	int N ,i, check[N], Root;
	char cl, cr;
	printf("pls input your BinTree's number of element!\n");
	scanf("%d\n", &N);
	if(N){
		for(i=0; i<N; i++){
			scanf("%d %c %c\n", &T[i].Element, &cl, &cr);
			check[i] = 0;
		}
		for(i=0; i<N; i++){
			if(cl != '-'){
				T[i].left = cl - '0';
				check[T[i].left] = 1;

			}
			else T[i].left = Null;
			if(cr != '-'){
				T[i].right = cr - '0';
				check[T[i].right] = 1;

			}
			else T[i].right = Null;
		}

		for(i=1; i<N; i++){	
			if(!check[i]) break;
		}
		
		Root = i;
		return Root;
	}
}

BinTree PositionFind(int X, BinTree BST){
	if(BST == Null) return Null;
	if(X>T[BST].Element)
		return PositionFind(X, T[BST].right);
	else if(X<T[BST].Element)
		return PositionFind(X, T[BST].left);
	else
		return BST;
}

BinTree PositionIterFind(int X, BinTree BST){
	while(BST != Null){
		if(X>T[BST].Element)
			BST = T[BST].right;
		else if(X<T[BST].Element)
			BST = T[BST].left;
		else
			return BST;
	}
	return Null;
}

BinTree PositionFindMax(BinTree BST){
	if(BST != Null){
		while(T[BST].right){
			BST = T[BST].right;
		}
	}
	return BST;
}

BinTree PositionFindMin(BinTree BST){
	if(BST == Null) return Null;
	else if(T[BST].left != Null)
		return BST;
	else
		return PositionFindMin(T[BST].left);
}
