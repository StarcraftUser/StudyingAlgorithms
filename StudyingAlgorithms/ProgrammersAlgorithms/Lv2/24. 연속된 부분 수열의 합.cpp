#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 24
/*
- 참고 사이트 -
https://velog.io/@imuu2256/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-LV.2-%EC%97%B0%EC%86%8D%EB%90%9C-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4%EC%9D%98-%ED%95%A9

https://velog.io/@wodnr0710/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-LV.2-%EC%97%B0%EC%86%8D%EB%90%9C-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4%EC%9D%98-%ED%95%A9

*/

#if QuestionNumber == 1
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
	vector<int> answer = { 0, static_cast<int>(sequence.size()) - 1 };
	int start = 0;
	int end = 0;
	int sum = 0;
	sum += sequence[start];

	while (start < sequence.size() && end < sequence.size())
	{

		if (sum < k)
		{
			end++;
			if (end >= sequence.size()) break;
			sum += sequence[end];
		}
		else if (sum > k)
		{
			sum -= sequence[start];
			start++;

		}
		else
		{
			if (answer[1] - answer[0] > end - start ||
				(answer[1] - answer[0] == end - start && start < answer[0]))
			{
				answer[0] = start;
				answer[1] = end;
			}
			sum -= sequence[start];
			start++;
		}
	}
	return answer;
}

#endif

#if QuestionNumber == 2
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	int n = sequence.size();
	int max_sum = 0;
	int end = 0;
	int interval = n;
	vector<int> res;  // 결과를 저장할 벡터

	// start는 0부터 n-1까지 순회
	for (int start = 0; start < n; ++start) {
		// max_sum이 k보다 작고 end가 n을 넘지 않으면, end를 증가시키며 max_sum을 구함
		while (max_sum < k && end < n) {
			max_sum += sequence[end];
			++end;
		}

		// max_sum이 k일 경우에만 결과 업데이트
		if (max_sum == k && (end - 1 - start) < interval) {
			res = { start, end - 1 };  // 결과 저장
			interval = end - 1 - start;  // 구간 길이 갱신
		}

		// start를 1 증가시키기 전에 sequence[start]를 빼서 max_sum을 업데이트
		max_sum -= sequence[start];
	}

	return res;
}


#endif

#if QuestionNumber == 3
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;
	sequence.push_back(0);  // 마지막에 0을 추가

	deque<int> q;  // 큐 역할을 할 deque
	int sum = 0;
	int start = 0, end = 0;
	int result = sequence.size();  // 최소 길이 구하기 위해 큰 값으로 초기화

	// sequence의 각 원소를 탐색
	for (int i = 0; i < sequence.size(); ++i)
	{
		// sum이 k보다 클 경우, 큐에서 값을 하나씩 빼면서 sum을 감소
		while (sum > k)
		{
			int temp = q.front();
			q.pop_front();
			sum -= temp;
			start++;
		}

		// sum이 k와 같고, 구간의 길이가 더 짧으면 answer를 업데이트
		if (sum == k && (end - start) < result)
		{
			answer = { start, end };
			result = end - start;
		}

		// 현재 값을 큐에 추가하고 sum을 갱신
		q.push_back(sequence[i]);
		sum += sequence[i];
		end = i;	// end 포인터를 현재 위치로 갱신
	}

	return answer;
}


#endif


int main()
{
	vector<int> answer = solution({ 1, 2, 3, 4, 5 }, 7);
	for (auto i : answer)
		cout << i << '\t';
	cout << "\n";
	answer = solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);

	for (auto i : answer)
		cout << i << '\t';
	cout << "\n";

	answer = solution({ 2, 2, 2, 2, 2 }, 6);

	for (auto i : answer)
		cout << i << '\t';
	cout << "\n";
	return 0;
}
#endif
#endif
