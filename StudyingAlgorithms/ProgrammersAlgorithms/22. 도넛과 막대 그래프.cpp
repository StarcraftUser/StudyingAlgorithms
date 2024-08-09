#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 22
/*
- 참고 사이트 -
https://velog.io/@pi1199/%EB%8F%84%EB%84%9B%EA%B3%BC-%EB%A7%89%EB%8C%80-%EA%B7%B8%EB%9E%98%ED%94%84-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-C
*/

#if QuestionNumber == 1
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define BigNum 1000001

int indegree[BigNum];
int outdegree[BigNum];
vector<vector<int>> graph(BigNum);
int t8 = 0, t1 = 0, t0 = 0;

void BFScheck(int start)
{
	queue<int> q;
	q.push(start);
	bool isvisted = false;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == start && isvisted)
		{
			t0++;
			return;
		}

		if (graph[now].size() >= 2)
		{
			t8++;
			return;
		}

		for (int i = 0; i < graph[now].size(); i++)
		{
			q.push(graph[now][i]);
		}
		isvisted = true;
	}
	t1++;
	return;
}

vector<int> solution(vector<vector<int>> edges)
{
	vector<int> answer;
	for (int i = 0; i < edges.size(); i++)
	{
		indegree[edges[i][1]]++;
		outdegree[edges[i][0]]++;
		graph[edges[i][0]].push_back(edges[i][1]);
	}

	for (int i = 1; i < BigNum; i++)
	{
		if (indegree[i] == 0 && outdegree[i] >= 2)
		{
			answer.push_back(i);
		}
	}

	vector<int> start = graph[answer[0]];
	for (int i = 0; i < start.size(); i++)
	{
		BFScheck(start[i]);
	}
	answer.push_back(t0);
	answer.push_back(t1);
	answer.push_back(t8);

	return answer;
}

int main()
{
	vector<int> answer = solution({ {2, 3}, {4, 3}, {1, 1}, {2, 1} });
	for (auto i : answer)
		cout << i << '\t';
	cout << "\n";
	answer = solution({ {4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8} });

	for (auto i : answer)
		cout << i << '\t';

	return 0;
}
#endif

#if QuestionNumber == 2

#endif
#endif
#endif
