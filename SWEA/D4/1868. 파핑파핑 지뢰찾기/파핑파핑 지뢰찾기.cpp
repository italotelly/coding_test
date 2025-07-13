#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T, N;
char board[300][300];
int cnt[300][300];      // 각 칸 주변 지뢰 개수
bool visited[300][300];

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

bool inRange(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		int cx = cur.first;
		int cy = cur.second;

		if (cnt[cx][cy] != 0) continue;

		for (int d = 0; d < 8; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (inRange(nx, ny) && !visited[nx][ny] && board[nx][ny] == '.') {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int solve() {
	memset(visited, false, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));

	// 1. 주변 지뢰 개수 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '.') {
				for (int d = 0; d < 8; d++) {
					int ni = i + dx[d], nj = j + dy[d];
					if (inRange(ni, nj) && board[ni][nj] == '*') {
						cnt[i][j]++;
					}
				}
			}
		}
	}

	int click = 0;

	// 2. 주변 지뢰 수가 0인 곳부터 BFS
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '.' && cnt[i][j] == 0 && !visited[i][j]) {
				bfs(i, j);
				click++;
			}
		}
	}

	// 3. 남은 . 하나하나 클릭
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '.' && !visited[i][j]) {
				click++;
			}
		}
	}

	return click;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> board[i];
		}

		int res = solve();
		cout << "#" << t << " " << res << "\n";
	}

	return 0;
}
