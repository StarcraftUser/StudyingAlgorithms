#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 18
/*
- 참고 사이트 -
https://velog.io/@namkun/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-lv2-%EB%8D%A7%EC%B9%A0%ED%95%98%EA%B8%B0
*/
#if QuestionNumber == 1
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
	int answer = 0;
	int max = 0;

	for (int& i : section)
	{
		if (i < max) continue;

		answer++;
		max = i + m;
	}

	return answer;
}

int main()
{
	cout << solution(8, 4, {2, 3, 6}) << '\n';
	cout << solution(5, 4, { 1, 3 }) << '\n';
	cout << solution(4, 1, { 1, 2, 3, 4 }) << '\n';
	return 0;
}

#endif

#if QuestionNumber == 2

#endif
#endif
#endif
