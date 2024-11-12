#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 17
#if QuestionNumber == 1
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
	string tempString = to_string(a) + to_string(b);
	int tempNum1 = stoi(tempString);
	tempString = to_string(b) + to_string(a);
	int tempNum2 = stoi(tempString);
	return tempNum1 >= tempNum2 ? tempNum1 : tempNum2;
}
int main()
{
	cout << solution(9, 91) << '\n';
	cout << solution(89, 8) << '\n';
	return 0;
}

#endif

#if QuestionNumber == 2

#endif
#endif
#endif
