#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 10
#include <string>
#include <vector>

using namespace std;

#if QuestionNumber == 1

int solution(int n)
{
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % 2 == 0)
		{
			if (i % 2 == 0)
				answer += i * i;
		}
		else
		{
			if (i % 2 == 1)
				answer += i;
		}
	}

	return answer;
}

int main()
{
	cout << solution(7) << '\n' << solution(10) << '\n';
	return 0;
}

#endif

#if QuestionNumber == 2

#endif
#endif
#endif


