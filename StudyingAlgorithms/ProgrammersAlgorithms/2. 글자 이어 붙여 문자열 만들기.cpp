#include "../header/pch.h"

#if AlgorithmNumber == 2
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#if QuestionNumber == 1

// index_list_len은 배열 index_list의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int index_list[], size_t index_list_len)
{
    char* answer = (char*)malloc(index_list_len + 1);

    for (int i = 0; i < index_list_len; i++)
    {
        answer[i] = my_string[index_list[i]];
    }

    answer[index_list_len] = '\0';

    return answer;
}


int main()
{
    const char* mychar1 = "cvsgiorszzzmrpaqpe";
    int n[] = { 16, 6, 5, 3, 12, 14, 11, 11, 17, 12, 7 };
    char* result = solution(mychar1, n, __crt_countof(n));
    printf("%s\n", result);

    free(result);

    const char* mychar2 = "zpiaz";
    int m[] = { 1, 2, 0, 0, 3 };
    result = solution(mychar2, m, __crt_countof(m));

    printf("%s\n", result);

    free(result);

    return 0;
}

#endif
#endif


