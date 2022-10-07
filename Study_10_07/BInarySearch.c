#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Score.h"

//����Ž���� ������ �Լ�
Score* BinarySearch(Score ScoreList[], int Size, double Target)
{
	int Left, Right, Mid;
	int count = 0;

	Left = 0;
	Right = Size - 1;

	while (Left <= Right)
	{
		count++;
		Mid = (Left + Right) / 2;
		
		if (Target == ScoreList[Mid].score) 
		{ 
			printf("count : %d\n", count);
			return &(ScoreList[Mid]); 
		}
		else if (Target > ScoreList[Mid].score) { Left = Mid + 1; }
		else { Right = Mid - 1; }
	}
	return NULL;
}

//�� ���� ũ�� ���Լ�
int CompareScore(const void* _elem1, const void* _elem2)
{
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if (elem1->score > elem2->score) { return 1; }
	else if (elem1->score < elem2->score) { return -1; }
	else { return 0; }
}

int main()
{
	int Length = sizeof DataSet / sizeof DataSet[0];
	Score* found = NULL;
	Score target;
	double findScore = 0;

	//�����Լ�(������)
	qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

	while (1)
	{
		printf("�˻��� ������ �Է��ϼ���(������ �Է½� ����) : ");
		scanf("%lf", &findScore);

		if (findScore < 0) { return 0; }

		/*������ ����Ž���� �������� ����ã��*/
		{ 
			found = BinarySearch(DataSet, Length, findScore);

			if (found == NULL) { printf("\n�ش��ϴ� ������ ���� �л��� �������� �ʽ��ϴ�.\n\n"); }
			else { printf("\nfound! Number : %d,\tScore : %lf\n\n", found->number, found->score); }
		}


		/*
		* �����Ͻ� STL�Բ����� ����Ž�� �˰����� ģ�� �Լ��� ����� �ֽþ���
		* �׷����� ���α׷����� �հ����� ���� ���� �ְ� �Ǿ���.
		*/


		/*STL�� ����Ž���Լ� bsearch�� �̿��� ����ã��*/
		{ 
			target.score = findScore;
			target.number = 0;

			found = bsearch((void*)&target, (void*)DataSet, Length, sizeof(Score), CompareScore);

			if (found == NULL) { printf("\n�ش��ϴ� ������ ���� �л��� �������� �ʽ��ϴ�.\n\n"); }
			else { printf("\nfound! Number : %d,\tScore : %lf\n\n", found->number, found->score); }
		}
	}

	return 0;
}