#include <iostream>
#include <vector>

using namespace std;

int ary[100000];
vector<int> v;

int dp(int a, int b)
{
    if (ary[b] != 0 && ary[a] != 0)
    {
        return ary[b] - ary[a - 1];
    }

    ary[0] = 0;
    ary[1] = v[0];

    for (int i = 2; i <= b; i++)
    {
        ary[i] = ary[i - 1] + v[i - 1];
    }

    return ary[b] - ary[a - 1];
}

// 누적합
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << dp(a, b) << "\n";
    }

    return 0; // 정상종료
}