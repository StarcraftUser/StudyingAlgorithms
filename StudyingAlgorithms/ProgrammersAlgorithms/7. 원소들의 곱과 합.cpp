#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 7

#if QuestionNumber == 1
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
	int multiply = 1, add = 0;

	for (int i = 0; i < num_list.size(); i++)
	{
		multiply *= num_list[i];
		add += num_list[i];
	}

	return (add * add) > multiply;
}

int main()
{
	vector<int> myint = { 3, 4, 5, 2, 1 };

	cout << solution(myint) << '\n';
	vector<int> myint2 = { 5, 7, 8, 3 };
	cout << solution(myint2);


	return 0;
}

#endif

#if QuestionNumber == 2
#include "../bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
using namespace std;

int solution(vector<int> num_list) {
	return accumulate(all(num_list), 1, multiplies<int>()) < pow(accumulate(all(num_list), 0), 2) ? 1 : 0;
}

int main()
{
	vector<int> myint = { 3, 4, 5, 2, 1 };

	cout << solution(myint) << '\n';
	vector<int> myint2 = { 5, 7, 8, 3 };
	cout << solution(myint2);

	return 0;
}

#endif
#endif
#endif


