#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode
{
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;
	ElementType Data;
} BSTNode;

BSTNode* CreateNode(ElementType NewData);
void DestroyNode(BSTNode* Node);
void DestroyTree(BSTNode* Tree);

BSTNode* SearchNode(BSTNode* Tree, ElementType Target);
BSTNode* SearchMinNode(BSTNode* Tree);
void InsertNode(BSTNode* Tree, BSTNode* Child);
BSTNode* RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target);
void InorderPrintTree(BSTNode* Node);