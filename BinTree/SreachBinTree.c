#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* BinTree;
typedef BinTree Position;

struct TreeNode{
	int Element;
	BinTree left;
	BinTree right;
};

Position Find(int X, BinTree BST);
Position FintIter(int X, BinTree BST);
Position FindMax(BinTree BST);
Position FindMin(BinTree BSt);
Position Insert(int X, BinTree BST);

Position Insert(int X, BinTree BST){
	if(!BST){
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->Element = X;
		BST->left = BST->right = NULL;
	}
	else{
		if(X > BST->Element)
			BST = Insert(X, BST->right);
		else if(X < BST->Element)
			BST = Insert(X, BST->left);
	}
	return BST;
}

Position Find(int X, BinTree BST){
	if(!BST)
		return NULL;
	else{
		if(X > BST->Element)
			return Find(X, BST->right);
		else if(X < BST->Element)
			return Find(X, BST->left);
		else
			return BST;
	}
}

Position FindIter(int X, BinTree BST){
	if(!BST)
		return NULL;
	else{
		while(BST){
			if(X < BST->Element)
				BST = BST->left;
			else if(X > BST->Element)
				BST = BST->right;
			else
				return BST;
		}
	}
}

Position FindMax(BinTree BST){
	if(!BST)
		return NULL;
	else{
		while(!BST->right){
			BST = BST->right;
		}
		return BST;
	}
}

Position FindMin(BinTree BST){
	if(!BST)
		return NULL;
	else if(!BST->left){
		return BST;
	}
	else
		return FindMin(BST->left);
}
