#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 12

#if QuestionNumber == 1

#include <string>
#include <vector>

using namespace std;

int solution(int number, int n, int m)
{
    if (number % n == 0 && number % m == 0) return true;
    else return false;
}

int main()
{
    cout << solution(60, 3, 2) << '\n';
    cout << solution(55, 10, 5) << '\n';
    return 0;
}

#endif

#if QuestionNumber == 2

int main()
{
    return 0;
}
#endif
#endif
#endif


