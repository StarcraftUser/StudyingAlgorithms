#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 9
#include <string>
#include <vector>
#include <map>
#if QuestionNumber == 1

#include <sstream>
using namespace std;

map<string, int> FM;
vector<vector<int>>graph;
vector<int>giftScore;

void splitFunc(string str)
{
	istringstream is; //���ڿ��� �Է� ��Ʈ������ �ٷ� �� �ְ� ���ִ� ����
	is.str(str); //istringstream ��ü�� �����ϰ�, str ���ڿ��� ����Ͽ� �ʱ�ȭ�մϴ�.
	//is ��ü�� str ���ڿ��� �Է� ��Ʈ������ �����ϰ� �̸� ó���� �� �ְ� �˴ϴ�.
	vector<string>ans;
	string sttt;
	while (getline(is, sttt, ' '))//��ü���� ���ڿ��� ����(' ')�� �������� �и��Ͽ� �� �ܾ ans ���Ϳ� �����մϴ�.
	{
		ans.push_back(sttt);
	}
	graph[FM[ans[0]]][FM[ans[1]]] += 1; // ������ �־��� ��
	graph[FM[ans[1]]][FM[ans[0]]] -= 1; // ������ �޾��� ��
	giftScore[FM[ans[0]]] += 1; // ������ �־��� ��
	giftScore[FM[ans[1]]] -= 1; // ������ �޾��� ��
}

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;
	giftScore = vector<int>(friends.size(), 0); //giftScore �ʱ�ȭ, friends.size() ũ���� �迭�� ����� 0���� �ʱ�ȭ
	for (int i = 0; i < friends.size(); i++)
	{
		FM.insert({ friends[i],i });
	}
	graph = vector<vector<int>>(friends.size(), vector<int>(friends.size(), 0));
	for (int i = 0; i < gifts.size(); i++)
	{
		splitFunc(gifts[i]);// �̸��� �и��ϰ� ���� �ְ� �޴� ������ ����ϴ� �Լ�
	}

	for (int i = 0; i < friends.size(); i++)
	{
		int nowGift = 0;
		for (int j = 0; j < friends.size(); j++)
		{
			if (graph[i][j] > 0) // ���� ������ ���� ��
			{
				nowGift += 1;
			}
			else if (graph[i][j] == 0)
			{
				if (giftScore[i] > giftScore[j]) // ���������� Ŭ ��
				{
					nowGift += 1;
				}
			}
		}

		answer = max(answer, nowGift);
	}
	return answer;
}
int main()
{
	vector<string> friends = { "muzi", "ryan", "frodo", "neo" };

	vector<string> gifts = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };

	cout << solution(friends, gifts);

	return 0;
}

#endif

#if QuestionNumber == 2

using namespace std;

map<string, int> nameToIdx;
int giftArr[51][51];
map<string, int> give;
map<string, int> receive;


int solution(vector<string> friends, vector<string> gifts)
{
	int answer = 0;

	for (int i = 0; i < friends.size(); i++)
	{
		nameToIdx[friends[i]] = i; //map�� �̸��� �ε����� �Է�
	}

	for (int i = 0; i < gifts.size(); i++)
	{
		string giveName = "";
		string temp = "";
		for (int j = 0; j < gifts[i].length(); j++)// �̸��� �и�
		{
			if (gifts[i][j] == ' ')
			{
				giveName = temp;
				temp = "";
				continue;
			}
			temp += gifts[i][j];
		}
		//���� �ְ�޴� ������ ����
		giftArr[nameToIdx[giveName]][nameToIdx[temp]]++;
		give[giveName]++;
		receive[temp]++;
	}

	int cur = friends.size();

	for (int i = 0; i < cur; i++)
	{
		int giftTemp = 0;
		for (int j = 0; j < cur; j++)
		{
			if (giftArr[i][j] > giftArr[j][i]) // ���� ������ ��
			{
				giftTemp++;
			}
			else if (giftArr[i][j] == giftArr[j][i]) //���� ���� ���� ���� ��
			{
				if (give[friends[i]] - receive[friends[i]] > give[friends[j]] - receive[friends[j]]) //���� ���� ��
				{
					giftTemp++;
				}
			}
		}
		answer = max(answer, giftTemp);
	}

	return answer;
}

int main()
{
	vector<string> friends = { "muzi", "ryan", "frodo", "neo" };

	vector<string> gifts = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };

	cout << solution(friends, gifts);

	return 0;
}
#endif
#endif
#endif


