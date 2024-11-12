#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 19
#if QuestionNumber == 1
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
	int size = 1;

	map<string, int> NameScore;
	map<int, string> ScoreName;

	for (string& name : players)
	{
		NameScore.emplace(name, size);
		ScoreName.emplace(size, name);
		size++;
	}

	for (auto& call : callings)
	{
		int numCall = NameScore[call];
		int frontNum = numCall - 1;
		string frontName = "\0";
		if (frontNum >= 1)
		{
			frontName = ScoreName[frontNum];

			NameScore[frontName]++;
			NameScore[call]--;

			ScoreName[frontNum] = call;
			ScoreName[numCall] = frontName;
		}
	}

	vector<string> answer;
	for (auto& iter : ScoreName)
	{
		answer.push_back(iter.second);
	}
	return answer;
}

int main()
{
	vector<string> temp = solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

	for (string& name : temp)
	{
		cout << name << "\n";
	}
	return 0;
}

#endif

#if QuestionNumber == 2

#endif
#endif
#endif
