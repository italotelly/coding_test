#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;

        vector<vector<int>> board(N, vector<int>(N, 0));
        int dx[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
        int dy[4] = {1, 0, -1, 0};

        int x = 0, y = 0, dir = 0;
        for (int i = 1; i <= N * N; ++i)
        {
            board[x][y] = i;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] != 0)
            {
                dir = (dir + 1) % 4; // 방향 전환
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            x = nx;
            y = ny;
        }

        // 출력
        cout << "#" << test_case << "\n";
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
