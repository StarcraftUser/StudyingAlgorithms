#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 11

#if QuestionNumber == 1
/*
- 참고 사이트 -
https://velog.io/@topqr123q/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-PCCP-%EA%B8%B0%EC%B6%9C%EB%AC%B8%EC%A0%9C-1%EB%B2%88%EB%B6%95%EB%8C%80-%EA%B0%90%EA%B8%B0
*/

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
	map<int, int> attackInfo;
	int endTime = 0;
	int curHealth = 0;
	int successiveTime = 0;

	curHealth = health;

	for (auto& attack : attacks)
	{
		attackInfo[attack[0]] = attack[1];
		endTime = attack[0];
	}

	/* 1초부터 마지막 공격 시각까지 체력 정보 초기화 */
	for (int i = 1; i <= endTime; i++)
	{
		
		if (attackInfo.find(i) != attackInfo.end())
		{ // 공격이 있다면
			curHealth -= attackInfo[i];
			successiveTime = 0;
		}
		else
		{ // 공격이 없다면
			curHealth += bandage[1]; // 회복
			successiveTime++;

			if (successiveTime == bandage[0])
			{
				curHealth += bandage[2]; // 추가 회복
				successiveTime = 0;
			}
			if (curHealth > health)
			{
				curHealth = health;
			}
		}

		if (curHealth <= 0)
		{ // 이번 턴을 마치고 체력이 바닥났다면 종료
			return -1;
		}
	}
	return curHealth;
}

int main()
{
	cout << solution({ 5, 1, 5 }, 30, { {2, 10}, {9, 15}, {10, 5}, {11, 5} }) << '\n';
	cout << solution({ 3, 2, 7 }, 20, { {1, 15}, {5, 16}, {8, 6} }) << '\n';
	cout << solution({ 4, 2, 7 }, 20, { {1, 15}, {5, 16}, {8, 6} }) << '\n';
	cout << solution({ 1, 1, 1 }, 5, { {1, 2}, {3, 2} }) << '\n';
	return 0;
}

#endif

#if QuestionNumber == 2

/*
- 참고 사이트 -
https://unialgames.tistory.com/entry/programmerslessons150370
*/

#include <string>
#include <vector>
#include <map>
using namespace std;


int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
	map<int, int> attackTime;
	int answer = 0;
	int lastTime = 0;
	int count = 0;

	// 몬스터의 공격 시간과 피해량을 저장하는 attackTime 맵을 초기화합니다.
	for (int i = 0; i < attacks.size(); i++)
	{
		size_t sad;
		attackTime[attacks[i][0]] = attacks[i][1];

		//변경 전
		// 마지막 공격 시간을 저장합니다.
		//if (i == (attacks.size() - 1))
		//{
		//	lastTime = attacks[i][0];
		//}

	}

	//변경 후
	// 이유 : attacks.size()는 unsigned __int64 형식인데 값이 0일때, -1을 해주면 오버해드가 발생함
	// 마지막 공격 시간을 저장합니다.
	if (attackTime.rbegin() != attackTime.rend())
		lastTime = attackTime.rbegin()->first;

	answer = health;

	// 0부터 마지막 공격 시간까지 시뮬레이션을 진행합니다.
	for (int i = 0; i <= lastTime; i++)
	{
		if (attackTime[i] != 0)
		{
			answer -= attackTime[i];
			count = 0;

			// 현재 체력이 0 이하면 게임 종료
			if (answer <= 0)
			{
				answer = -1;
				break;
			}
		}
		else
		{
			// 몬스터의 공격이 없는 경우, 붕대 감기 기술을 사용합니다.
			if (answer <= health && count < bandage[0])
			{
				answer += bandage[1];
				count++;

				// 연속으로 기술을 사용하면 추가 회복량을 적용합니다.
				if (count >= bandage[0])
				{
					answer += bandage[2];
					count = 0;
				}
			}
		}

		// 현재 체력이 최대 체력을 넘어가면 최대 체력으로 설정합니다.
		if (answer >= health)
		{
			answer = health;
		}
	}

	return answer;
}

int main()
{
	cout << solution({ 5, 1, 5 }, 30, { {2, 10}, {9, 15}, {10, 5}, {11, 5} }) << '\n';
	cout << solution({ 3, 2, 7 }, 20, { {1, 15}, {5, 16}, {8, 6} }) << '\n';
	cout << solution({ 4, 2, 7 }, 20, { {1, 15}, {5, 16}, {8, 6} }) << '\n';
	cout << solution({ 1, 1, 1 }, 5, { {1, 2}, {3, 2} }) << '\n';
	return 0;
}
#endif
#endif
#endif


