#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N;
vector<int> v;
int op[4];             // +, -, *, /
int max_val = INT_MIN; // 최대값 초기화
int min_val = INT_MAX; // 최소값 초기화

void dfs(int idx, int result)
{
    if (idx == N)
    {
        max_val = max(max_val, result);
        min_val = min(min_val, result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;

            if (i == 0)
                dfs(idx + 1, result + v[idx]);
            else if (i == 1)
                dfs(idx + 1, result - v[idx]);
            else if (i == 2)
                dfs(idx + 1, result * v[idx]);
            else if (i == 3)
                dfs(idx + 1, result / v[idx]);

            op[i]++; // 백트래킹
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }

    dfs(1, v[0]);

    cout << max_val << "\n"
         << min_val;

    return 0;
}