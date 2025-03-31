#include <iostream>

using namespace std;

// 블랙잭

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 카드 합이 21을 넘지 않는 한도 내에서 합을 최대한 크게 만드는 게임
    // 새로운 규칙, N장의 카드를 숫자가 보이도록 바닥에 놓고, 딜러는 숫자 M을 크게 외친다
    // N장의 카드 중에서 3장의 카드를 고르고 합이 M을 넘지 않으면서 M과 가깝게

    int N, M;

    cin >> N >> M;

    int ary[N];

    for (int i = 0; i < N; i++)
    {
        cin >> ary[i];
    }

    // M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합
    // MC3

    int sum = 0;

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if ((ary[i] + ary[j] + ary[k] <= M) && (ary[i] + ary[j] + ary[k] > sum))
                {
                    sum = ary[i] + ary[j] + ary[k];
                }
            }
        }
    }

    cout << sum;

    return 0; // 정상종료
}