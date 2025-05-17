#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 진기의 최고급 붕어빵
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    int N, M, K;
    int bread, impossible, people;
    vector<int> v;
    for (int i = 1; i <= tc; i++)
    {
        v.clear();
        cin >> N >> M >> K;
        v.resize(N);
        bread = 0;
        impossible = 0;
        people = 0;

        // 손님 도착 시간
        for (int j = 0; j < N; j++)
        {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        for (int j = 1; j <= v[N - 1]; j++)
        {
            // 1번째 조건
            // M은 v[0]보다 같거나 작아야 함
            if (M > v[0])
            {
                impossible = 1;
                break;
            }
            // 2번째 조건
            // 이후부터 M초가 지날 때 마다 붕어빵 K개 추가
            if (j % M == 0)
            {
                bread += K;
            }
            // 3번째 조건
            // 각 초에 해당하는 사람이 들어올 때 붕어빵 --
            if (j == v[people])
            {
                if (bread == 0)
                {
                    impossible = 1;
                    break;
                }
                bread--;
                people++;
            }
        }
        // 출력
        cout << "#" << i << " ";
        if (impossible)
        {
            cout << "Impossible\n";
        }
        else
        {
            cout << "Possible\n";
        }
    }
    return 0;
}
