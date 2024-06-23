#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 6


#if QuestionNumber == 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    
    int even_number = 0, odd_number = 0;

    //int answer = 0;

    int even_ten = 1, odd_ten = 1;

    while (num_list_len--)
    {
        if (num_list[num_list_len] % 2 == 0)
        {
            even_number += num_list[num_list_len] * even_ten;
            even_ten *= 10;
        }
        else
        {
            odd_number += num_list[num_list_len] * odd_ten;
            odd_ten *= 10;
        }
    }

    return even_number + odd_number;
}

int main()
{
    int myint[] = { 5, 7, 8, 3 };

    std::cout << solution(myint, __crt_countof(myint));

    return 0;
}

#endif

#if QuestionNumber == 2

#include <string>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> num_list)
{
    string even_number, odd_number;

    for (int i = 0; i < num_list.size(); i++)
    {
        if (num_list[i] % 2 == 0)
        {
            even_number += std::to_string(num_list[i]);
        }
        else
        {
            odd_number += std::to_string(num_list[i]);
        }
    }

    int answer = std::stoi(even_number) + std::stoi(odd_number);
    return answer;
}

int main()
{
    vector<int> myint = { 3, 4, 5, 2, 1 };

    std::cout << solution(myint);

    return 0;
}

#endif
#endif
#endif


