#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int N;
vector<vector<int>> v;
vector<bool> visited;
int min_diff = INT_MAX; // 최소 차이 초기화

void calculate()
{
    int start = 0, link = 0;
    vector<int> team_start, team_link;

    // 두 개의 팀으로 나누기
    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            team_start.push_back(i);
        else
            team_link.push_back(i);
    }

    // 능력치 합 계산
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N / 2; j++)
        {
            start += v[team_start[i]][team_start[j]];
            link += v[team_link[i]][team_link[j]];
        }
    }

    // 최소 차이 갱신
    min_diff = min(min_diff, abs(start - link));
}

void dfs(int idx, int cnt)
{
    if (cnt == N / 2)
    { // 팀이 완성되었을 때
        calculate();
        return;
    }

    for (int i = idx; i < N; i++)
    { // 중복 방지: idx부터 시작
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i + 1, cnt + 1);
            visited[i] = false; // 백트래킹
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    v.resize(N, vector<int>(N, 0));
    visited.resize(N, false);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    dfs(0, 0);

    cout << min_diff << '\n';
    return 0;
}
