#include "../header/pch.h"

#if TypesOfAlgorithmSites == 0
#if AlgorithmNumber == 15
/*
- 참고 사이트 -
https://velog.io/@superscman/PCCE-%EA%B8%B0%EC%B6%9C%EB%AC%B8%EC%A0%9C-9%EB%B2%88-%EC%9D%B4%EC%9B%83%ED%95%9C-%EC%B9%B8-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4%EC%9E%90%EB%B0%94
*/
#if QuestionNumber == 1
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {

    int boardnum = board.size();

    int count = 0;
    int dh[] = {0, 1, -1, 0};
    int dw[] = {1, 0, 0, -1};

    for (int i = 0; i < __crt_countof(dh); i++)
    {
        int h_check = h + dh[i];
        int w_check = w + dw[i];

        if (0 <= h_check && h_check < boardnum && 0 <= w_check && w_check < boardnum)
        {
            if (board[h][w] == board[h_check][w_check])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solution({ {"blue", "red", "orange", "red"} , {"red", "red", "blue", "orange" }, { "blue", "orange", "red", "red" }, { "orange", "orange", "red", "blue" } }, 1, 1) << '\n';

    cout << solution({ {"yellow", "green", "blue"} , {"blue", "green", "yellow"} , {"yellow", "blue", "blue" } }, 0, 1) << '\n';

    return 0;
}

#endif

#if QuestionNumber == 2

#endif
#endif
#endif


