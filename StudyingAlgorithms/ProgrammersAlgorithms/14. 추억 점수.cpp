#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 14

#if QuestionNumber == 1
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    map<string, int> nameScore;

    for (int i = 0; i < name.size(); i++)
    {
        nameScore[name[i]] = yearning[i];
    }

    vector<int> answer;

    for (auto& friendsMemory : photo)
    {
        int temp = 0;
        for (auto& friendsName : friendsMemory)
        {
            if (nameScore.find(friendsName) != nameScore.end())
            {
                temp += nameScore[friendsName];
            }
        }
        answer.push_back(temp);
    }

    return answer;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> name = solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { {"may", "kein", "kain", "radi"} , {"may", "kein", "brin", "deny"} , {"kon", "kain", "may", "coni"} });

    for (auto& i : name)
    {
        cout << i << '\n';
    }
    name.clear();
    cout << '\n';

    name = solution({ "kali", "mari", "don" }, { 11, 1, 55 }, { {"kali", "mari", "don"} , {"pony", "tom", "teddy"} , {"con", "mona", "don"} });

    for (auto& i : name)
    {
        cout << i << '\n';
    }
    name.clear();
    cout << '\n';

    name = solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { {"may"} , {"kein", "deny", "may"} , {"kon", "coni"} });
    for (auto& i : name)
    {
        cout << i << '\n';
    }
    name.clear();
    cout << '\n';
    return 0;
}

#endif

#if QuestionNumber == 2

#endif
#endif
#endif


