#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 5
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#if QuestionNumber == 1

int* solution(int num_list[], size_t num_list_len) {
    int* answer = (int*)malloc((num_list_len + 1) * sizeof(int));

    for (int i = 0; i < num_list_len; i++)
    {
        answer[i] = num_list[i];
    }

    if (num_list[num_list_len - 1] > num_list[num_list_len - 2])
        answer[num_list_len] = num_list[num_list_len - 1] - num_list[num_list_len - 2];
    else
        answer[num_list_len] = num_list[num_list_len - 1] * 2;
    return answer;
}

int main()
{
    int numlist[] = {2, 1, 6};

    int* result = solution(numlist, __crt_countof(numlist));

    for (int i = 0; i < __crt_countof(numlist) + 1; i++)
    {
        std::cout << result[i] << '\t';
    }

    std::cout << '\n';

    free(result);

    int numlist2[] = { 5, 2, 1, 7, 5 };

    result = solution(numlist2, __crt_countof(numlist2));

    for (int i = 0; i < __crt_countof(numlist2) + 1; i++)
    {
        std::cout << result[i] << '\t';
    }

    std::cout << '\n';

    free(result);
    return 0;
}

#endif


#endif
#endif


