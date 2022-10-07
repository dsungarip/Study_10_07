#include "BST.h"

BSTNode* CreateNode(ElementType NewData)
{
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	
	NewNode->Data = NewData;
	NewNode->Left = NULL;
	NewNode->Right = NULL;

	return NewNode;
}

void DestroyNode(BSTNode* Node) { free(Node); }

void DestroyTree(BSTNode* Tree)
{
	if (Tree->Right != NULL) { DestroyTree(Tree->Right); }
	if (Tree->Left != NULL) { DestroyTree(Tree->Left); }

	Tree->Left = NULL;
	Tree->Right = NULL;

	DestroyNode(Tree);
}

BSTNode* SearchNode(BSTNode* Tree, ElementType Target)
{
	if (Tree == NULL) { return NULL; }
	
	if (Tree->Data == Target) { return Tree; }
	else if (Tree->Data > Target) { return SearchNode(Tree->Left, Target); }
	else { return SearchNode(Tree->Right, Target); }
}

BSTNode* SearchMinNode(BSTNode* Tree)
{
	if (Tree == NULL) { return NULL; }
	
	if (Tree->Left == NULL) { return Tree; }
	else { return SearchMinNode(Tree->Left); }
}

void InsertNode(BSTNode* Tree, BSTNode* Child)
{

	if (Tree->Data < Child->Data)
	{
		if (Tree->Right == NULL) { Tree->Right = Child; }
		else { InsertNode(Tree->Right, Child); }
	}
	else if (Tree->Data > Child->Data)
	{
		if (Tree->Left == NULL) { Tree->Left = Child; }
		else { InsertNode(Tree->Left, Child); }
	}
}

BSTNode* RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
	if (Tree == NULL) { return NULL; }

	BSTNode* Removed = NULL;

	if (Tree->Data > Target) { Removed = RemoveNode(Tree->Left, Tree, Target); }
	else if (Tree->Data < Target) { Removed = RemoveNode(Tree->Right, Tree, Target); }
	else /*목표값일경우*/
	{
		Removed = Tree;

		//자식이 없을때
		if (Tree->Left == NULL && Tree->Right == NULL)
		{
			if (Parent->Left == Tree) { Parent->Left = NULL; }
			else { Parent->Right == NULL; }
		}
		else
		{
			/*자식이 양쪽 다 있을때*/
			if (Tree->Left != NULL && Tree->Right != NULL)
			{
				//현재노드의 오른쪽 노드부터 최소값 노드를 찾아 제거후 현재의 노드에 덮어씌운다.
				BSTNode* MinNode = SearchMinNode(Tree->Right);
				MinNode = RemoveNode(Tree, NULL, MinNode->Data);
				Tree->Data = MinNode->Data;
			}
			/*자식이 하나일 때*/
			else
			{
				BSTNode* Temp = NULL;
				if (Tree->Left != NULL) { Temp = Tree->Left; }
				else { Temp = Tree->Right; }

				if (Parent->Left == Tree) { Parent->Left = Temp; }
				else { Parent->Right = Temp; }
			}
		}
	}
	return Removed;
}

void InorderPrintTree(BSTNode* Node)
{
	if (Node == NULL) { return NULL; }

	//왼쪽하위트리 출력
	InorderPrintTree(Node->Left);

	//루트노드 출력
	printf("%d ", Node->Data);

	//오른쪽 하위트리 출력
	InorderPrintTree(Node->Right);
}