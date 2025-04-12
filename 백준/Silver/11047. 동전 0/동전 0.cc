#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;

    vector<int> coin;

    cin >> N >> K;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        coin.push_back(num);
    }

    int i = 1;
    int cnt = 0;
    while (K != 0 && i <= N)
    {
        while (K >= coin[N - i])
        {
            K = K - coin[N - i];
            cnt++;
        }
        i++;
    }

    cout << cnt;

    return 0;
}