#include "BST.h"

//Binary Search Tree (이진 탐색 트리)

int main()
{
	BSTNode* Tree = CreateNode(123);
	BSTNode* Node = NULL;

	InsertNode(Tree, CreateNode(22));
	InsertNode(Tree, CreateNode(9918));
	InsertNode(Tree, CreateNode(424));
	InsertNode(Tree, CreateNode(17));
	InsertNode(Tree, CreateNode(3));

	InsertNode(Tree, CreateNode(98));
	InsertNode(Tree, CreateNode(34));

	InsertNode(Tree, CreateNode(760));
	InsertNode(Tree, CreateNode(317));
	InsertNode(Tree, CreateNode(1));

	//트리출력
	InorderPrintTree(Tree);
	printf("\n");

	//특정 노드 삭제
	printf("Removing 98...\n");

	Node = RemoveNode(Tree, NULL, 98);
	DestroyNode(Node);

	InorderPrintTree(Tree);
	printf("\n");

	//새 노드삽입
	printf("Inserting 111...\n");

	InsertNode(Tree, CreateNode(111));
	InorderPrintTree(Tree);
	printf("\n");

	//트리소멸
	DestroyTree(Tree);

	return 0;
}