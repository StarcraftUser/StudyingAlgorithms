#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 3
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#if QuestionNumber == 1

int* solution(int start_num, int end_num)
{
	int len, start = 0;
	if (start_num < end_num)
	{
		len = end_num - start_num + 1;
		start = start_num;
	}
	else
	{
		len = start_num - end_num + 1;
		start = end_num;
	}
	int* answer = (int*)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++)
	{
		answer[i] = start++;
	}

	return answer;
}


int main()
{
	int num[] = { 3, 10 };
	int* result = solution(num[0], num[1]);
	
	for (int i = 0; i < num[1] - num[0] + 1; i++)
	{
		printf("%d,\t", result[i]);

	}

	free(result);

	return 0;
}

#endif


#if QuestionNumber == 2

int* solution(int start, int end)
{
	int* answer = (int*)malloc((end - start + 1) * sizeof(int));
	int* ptr = answer;
	for (int num = start; num <= end; num++) *ptr++ = num;
	return answer;
}


int main()
{
	int num[] = { 3, 10 };
	int* result = solution(num[0], num[1]);

	for (int i = 0; i < num[1] - num[0] + 1; i++)
	{
		printf("%d,\t", result[i]);

	}

	free(result);

	return 0;
}

#endif
#endif
#endif


