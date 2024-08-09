#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 8

#if QuestionNumber == 1
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
	return flag ? (a + b) : (a - b);
}


int main()
{
	cout << solution(-4, 7, true) << '\n';
	cout << solution(-4, 7, false);


	return 0;
}

#endif

#if QuestionNumber == 2
#endif
#endif
#endif


