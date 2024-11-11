#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 23
/*
- 참고 사이트 -
https://cherishvert.tistory.com/71
*/

#if QuestionNumber == 1
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct
{
	int x, y;
}box;

box moveDir[4] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
map<char, int> MovingIndexMap = { { 'N', 0 }, { 'S', 1 }, { 'W', 2 }, { 'E', 3 } };

vector<int> solution(vector<string> park, vector<string> routes)
{
	pair<int, int> MovingLoc;

	int H = park.size();
	int W = park[0].size();

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (park[i][j] == 'S')
			{
				MovingLoc = { i, j };
				break;
			}
		}
	}


	for (const auto& route : routes)
	{
		char index = MovingIndexMap[route[0]];
		int n = route[2] - 48;

		int nx = MovingLoc.first;
		int ny = MovingLoc.second;

		while (n--)
		{
			nx += moveDir[index].x;
			ny += moveDir[index].y;

			if ((nx < 0 || H <= nx || ny < 0 || W <= ny) || park[nx][ny] == 'X')
				break;
		}

		if (n < 0) MovingLoc = { nx, ny };
	}

	return { MovingLoc.first, MovingLoc.second };
}

int main()
{
	vector<int> answer = solution({ "SOO","OOO","OOO" }, { "E 2","S 2","W 1" });
	for (auto i : answer)
		cout << i << '\t';
	cout << "\n";
	answer = solution({ "SOO","OXX","OOO" }, { "E 2","S 2","W 1" });

	for (auto i : answer)
		cout << i << '\t';
	cout << "\n";

	answer = solution({ "OSO","OOO","OXO","OOO" }, { "E 2","S 3","W 1" });

	for (auto i : answer)
		cout << i << '\t';
	cout << "\n";
	return 0;
}
#endif

#if QuestionNumber == 2

#endif
#endif
#endif
