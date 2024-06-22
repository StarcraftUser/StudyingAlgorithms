#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 4
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#if QuestionNumber == 1

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(int n, const char* control)
{
    int answer = n;
    int i = 0;

    while (control[i] != '\0')
    {
        if (control[i] == 'w') ++answer;
        else if (control[i] == 's') --answer;
        else if (control[i] == 'd') answer += 10;
        else if (control[i] == 'a') answer -= 10;
        i++;
    }

    return answer;
}

int main()
{
    std::cout << solution(0, "wsdawsdassw");
    return 0;
}

#endif


#if QuestionNumber == 2


#endif
#endif
#endif


