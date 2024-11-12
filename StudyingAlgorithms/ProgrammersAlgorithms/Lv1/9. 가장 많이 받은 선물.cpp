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
	istringstream is; //문자열을 입력 스트림으로 다룰 수 있게 해주는 변수
	is.str(str); //istringstream 객체를 생성하고, str 문자열을 사용하여 초기화합니다.
	//is 객체는 str 문자열을 입력 스트림으로 간주하고 이를 처리할 수 있게 됩니다.
	vector<string>ans;
	string sttt;
	while (getline(is, sttt, ' '))//객체에서 문자열을 공백(' ')을 기준으로 분리하여 각 단어를 ans 벡터에 저장합니다.
	{
		ans.push_back(sttt);
	}
	graph[FM[ans[0]]][FM[ans[1]]] += 1; // 선물을 주었을 때
	graph[FM[ans[1]]][FM[ans[0]]] -= 1; // 선물을 받았을 때
	giftScore[FM[ans[0]]] += 1; // 선물을 주었을 때
	giftScore[FM[ans[1]]] -= 1; // 선물을 받았을 때
}

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;
	giftScore = vector<int>(friends.size(), 0); //giftScore 초기화, friends.size() 크기의 배열을 만들고 0으로 초기화
	for (int i = 0; i < friends.size(); i++)
	{
		FM.insert({ friends[i],i });
	}
	graph = vector<vector<int>>(friends.size(), vector<int>(friends.size(), 0));
	for (int i = 0; i < gifts.size(); i++)
	{
		splitFunc(gifts[i]);// 이름을 분리하고 선물 주고 받는 정보를 기록하는 함수
	}

	for (int i = 0; i < friends.size(); i++)
	{
		int nowGift = 0;
		for (int j = 0; j < friends.size(); j++)
		{
			if (graph[i][j] > 0) // 보낸 선물이 많을 때
			{
				nowGift += 1;
			}
			else if (graph[i][j] == 0)
			{
				if (giftScore[i] > giftScore[j]) // 선물지수가 클 때
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
		nameToIdx[friends[i]] = i; //map에 이름과 인덱스를 입력
	}

	for (int i = 0; i < gifts.size(); i++)
	{
		string giveName = "";
		string temp = "";
		for (int j = 0; j < gifts[i].length(); j++)// 이름을 분리
		{
			if (gifts[i][j] == ' ')
			{
				giveName = temp;
				temp = "";
				continue;
			}
			temp += gifts[i][j];
		}
		//선물 주고받는 정보를 갱신
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
			if (giftArr[i][j] > giftArr[j][i]) // 보낸 선물양 비교
			{
				giftTemp++;
			}
			else if (giftArr[i][j] == giftArr[j][i]) //선물 보낸 양이 같을 때
			{
				if (give[friends[i]] - receive[friends[i]] > give[friends[j]] - receive[friends[j]]) //선물 지수 비교
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


