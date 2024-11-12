#include "../../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 11

#if QuestionNumber == 1
/*
- ���� ����Ʈ -
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

	/* 1�ʺ��� ������ ���� �ð����� ü�� ���� �ʱ�ȭ */
	for (int i = 1; i <= endTime; i++)
	{
		
		if (attackInfo.find(i) != attackInfo.end())
		{ // ������ �ִٸ�
			curHealth -= attackInfo[i];
			successiveTime = 0;
		}
		else
		{ // ������ ���ٸ�
			curHealth += bandage[1]; // ȸ��
			successiveTime++;

			if (successiveTime == bandage[0])
			{
				curHealth += bandage[2]; // �߰� ȸ��
				successiveTime = 0;
			}
			if (curHealth > health)
			{
				curHealth = health;
			}
		}

		if (curHealth <= 0)
		{ // �̹� ���� ��ġ�� ü���� �ٴڳ��ٸ� ����
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
- ���� ����Ʈ -
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

	// ������ ���� �ð��� ���ط��� �����ϴ� attackTime ���� �ʱ�ȭ�մϴ�.
	for (int i = 0; i < attacks.size(); i++)
	{
		size_t sad;
		attackTime[attacks[i][0]] = attacks[i][1];

		//���� ��
		// ������ ���� �ð��� �����մϴ�.
		//if (i == (attacks.size() - 1))
		//{
		//	lastTime = attacks[i][0];
		//}

	}

	//���� ��
	// ���� : attacks.size()�� unsigned __int64 �����ε� ���� 0�϶�, -1�� ���ָ� �����ص尡 �߻���
	// ������ ���� �ð��� �����մϴ�.
	if (attackTime.rbegin() != attackTime.rend())
		lastTime = attackTime.rbegin()->first;

	answer = health;

	// 0���� ������ ���� �ð����� �ùķ��̼��� �����մϴ�.
	for (int i = 0; i <= lastTime; i++)
	{
		if (attackTime[i] != 0)
		{
			answer -= attackTime[i];
			count = 0;

			// ���� ü���� 0 ���ϸ� ���� ����
			if (answer <= 0)
			{
				answer = -1;
				break;
			}
		}
		else
		{
			// ������ ������ ���� ���, �ش� ���� ����� ����մϴ�.
			if (answer <= health && count < bandage[0])
			{
				answer += bandage[1];
				count++;

				// �������� ����� ����ϸ� �߰� ȸ������ �����մϴ�.
				if (count >= bandage[0])
				{
					answer += bandage[2];
					count = 0;
				}
			}
		}

		// ���� ü���� �ִ� ü���� �Ѿ�� �ִ� ü������ �����մϴ�.
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


