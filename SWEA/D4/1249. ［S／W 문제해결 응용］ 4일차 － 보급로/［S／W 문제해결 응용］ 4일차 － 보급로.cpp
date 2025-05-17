#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;
const int dx[4] = {-1, 1, 0, 0}; // 상하좌우
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;

        vector<vector<int>> board(N, vector<int>(N));
        vector<vector<int>> dist(N, vector<int>(N, INF));

        for (int i = 0; i < N; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < N; ++j) {
                board[i][j] = row[j] - '0';
            }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    int cost = dist[x][y] + board[nx][ny];
                    if (cost < dist[nx][ny]) {
                        dist[nx][ny] = cost;
                        q.push({nx, ny});
                    }
                }
            }
        }

        cout << "#" << tc << " " << dist[N - 1][N - 1] << "\n";
    }

    return 0;
}
