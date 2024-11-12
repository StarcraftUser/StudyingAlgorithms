#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 24
/*
- ���� ����Ʈ -
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
	vector<int> res;  // ����� ������ ����

	// start�� 0���� n-1���� ��ȸ
	for (int start = 0; start < n; ++start) {
		// max_sum�� k���� �۰� end�� n�� ���� ������, end�� ������Ű�� max_sum�� ����
		while (max_sum < k && end < n) {
			max_sum += sequence[end];
			++end;
		}

		// max_sum�� k�� ��쿡�� ��� ������Ʈ
		if (max_sum == k && (end - 1 - start) < interval) {
			res = { start, end - 1 };  // ��� ����
			interval = end - 1 - start;  // ���� ���� ����
		}

		// start�� 1 ������Ű�� ���� sequence[start]�� ���� max_sum�� ������Ʈ
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
	sequence.push_back(0);  // �������� 0�� �߰�

	deque<int> q;  // ť ������ �� deque
	int sum = 0;
	int start = 0, end = 0;
	int result = sequence.size();  // �ּ� ���� ���ϱ� ���� ū ������ �ʱ�ȭ

	// sequence�� �� ���Ҹ� Ž��
	for (int i = 0; i < sequence.size(); ++i)
	{
		// sum�� k���� Ŭ ���, ť���� ���� �ϳ��� ���鼭 sum�� ����
		while (sum > k)
		{
			int temp = q.front();
			q.pop_front();
			sum -= temp;
			start++;
		}

		// sum�� k�� ����, ������ ���̰� �� ª���� answer�� ������Ʈ
		if (sum == k && (end - start) < result)
		{
			answer = { start, end };
			result = end - start;
		}

		// ���� ���� ť�� �߰��ϰ� sum�� ����
		q.push_back(sequence[i]);
		sum += sequence[i];
		end = i;	// end �����͸� ���� ��ġ�� ����
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
