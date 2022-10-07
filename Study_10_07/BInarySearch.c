#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Score.h"

//이진탐색을 구현한 함수
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

//두 값의 크기 비교함수
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

	//정렬함수(오름차)
	qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

	while (1)
	{
		printf("검색할 점수를 입력하세요(음수를 입력시 종료) : ");
		scanf("%lf", &findScore);

		if (findScore < 0) { return 0; }

		/*구현한 이진탐색을 바탕으로 점수찾기*/
		{ 
			found = BinarySearch(DataSet, Length, findScore);

			if (found == NULL) { printf("\n해당하는 점수를 가진 학생이 존재하지 않습니다.\n\n"); }
			else { printf("\nfound! Number : %d,\tScore : %lf\n\n", found->number, found->score); }
		}


		/*
		* 위대하신 STL님께서는 이진탐색 알고리즘을 친히 함수로 등록해 주시었고
		* 그로인해 프로그래머의 손가락이 좀더 쉴수 있게 되었다.
		*/


		/*STL의 이진탐색함수 bsearch를 이용한 점수찾기*/
		{ 
			target.score = findScore;
			target.number = 0;

			found = bsearch((void*)&target, (void*)DataSet, Length, sizeof(Score), CompareScore);

			if (found == NULL) { printf("\n해당하는 점수를 가진 학생이 존재하지 않습니다.\n\n"); }
			else { printf("\nfound! Number : %d,\tScore : %lf\n\n", found->number, found->score); }
		}
	}

	return 0;
}