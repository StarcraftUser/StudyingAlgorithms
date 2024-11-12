#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 16
#if QuestionNumber == 1
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
	int numAB = stoi(to_string(a) + to_string(b));
	int temp = 2 * a * b;
	return numAB > temp ? numAB : temp;
}

int main()
{
	cout << solution(2, 91) << '\n';
	cout << solution(91, 2) << '\n';
	return 0;
}

#endif

#if QuestionNumber == 2

#endif
#endif
#endif


