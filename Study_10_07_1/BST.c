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
	else /*��ǥ���ϰ��*/
	{
		Removed = Tree;

		//�ڽ��� ������
		if (Tree->Left == NULL && Tree->Right == NULL)
		{
			if (Parent->Left == Tree) { Parent->Left = NULL; }
			else { Parent->Right == NULL; }
		}
		else
		{
			/*�ڽ��� ���� �� ������*/
			if (Tree->Left != NULL && Tree->Right != NULL)
			{
				//�������� ������ ������ �ּҰ� ��带 ã�� ������ ������ ��忡 ������.
				BSTNode* MinNode = SearchMinNode(Tree->Right);
				MinNode = RemoveNode(Tree, NULL, MinNode->Data);
				Tree->Data = MinNode->Data;
			}
			/*�ڽ��� �ϳ��� ��*/
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

	//��������Ʈ�� ���
	InorderPrintTree(Node->Left);

	//��Ʈ��� ���
	printf("%d ", Node->Data);

	//������ ����Ʈ�� ���
	InorderPrintTree(Node->Right);
}