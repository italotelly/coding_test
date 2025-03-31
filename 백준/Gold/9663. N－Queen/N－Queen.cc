#include <iostream>

using namespace std;

int N;
int answer = 0;
bool col[15], diag1[30], diag2[30]; // 세로, 대각선 (최대 크기 설정)

void solve(int row)
{
    if (row == N)
    { // N개의 퀸을 모두 배치하면 해를 찾음
        answer++;
        return;
    }

    for (int c = 0; c < N; c++)
    { // 각 열에 퀸 배치 시도
        if (!col[c] && !diag1[row + c] && !diag2[row - c + N - 1])
        {
            col[c] = diag1[row + c] = diag2[row - c + N - 1] = true;
            solve(row + 1);
            col[c] = diag1[row + c] = diag2[row - c + N - 1] = false; // 백트래킹
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    solve(0);
    cout << answer << '\n';

    return 0;
}
