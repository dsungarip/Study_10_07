#include "BST.h"

//Binary Search Tree (���� Ž�� Ʈ��)

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

	//Ʈ�����
	InorderPrintTree(Tree);
	printf("\n");

	//Ư�� ��� ����
	printf("Removing 98...\n");

	Node = RemoveNode(Tree, NULL, 98);
	DestroyNode(Node);

	InorderPrintTree(Tree);
	printf("\n");

	//�� ������
	printf("Inserting 111...\n");

	InsertNode(Tree, CreateNode(111));
	InorderPrintTree(Tree);
	printf("\n");

	//Ʈ���Ҹ�
	DestroyTree(Tree);

	return 0;
}