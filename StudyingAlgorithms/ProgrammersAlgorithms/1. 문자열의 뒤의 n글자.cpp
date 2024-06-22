#include "../header/pch.h"


#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#if QuestionNumber == 1


char* solution(const char* my_string, int n)
{
    int len = 0;

    while (my_string[len] != '\0')
    {
        len++;
    }

    if (n > len) n = len;

    char* answer = (char*)malloc(n + 1);

    for (int i = 0; i < n; i++)
    {
        answer[i] = my_string[len - n + i];
    }

    answer[n] = '\0';

    return answer;
}

int main()
{
    const char* mychar1 = "ProgrammerS123";
    int n = 11;
    char* result = solution(mychar1, n);
    printf("%s\n", result);

    free(result);

    const char* mychar2 = "He110W0r1d";
    n = 5;
    result = solution(mychar2, n);

    printf("%s\n", result);

    free(result);

	return 0;
}

#endif
#endif
#endif


