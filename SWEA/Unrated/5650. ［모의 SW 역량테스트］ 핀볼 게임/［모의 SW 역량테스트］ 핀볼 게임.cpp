#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> board;
vector<pair<int, int>> wormhole[11]; // 웜홀은 6~10번까지 있음

// 상, 하, 좌, 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 블록 반사 규칙
int block_dir[5][4] = {
	{1, 3, 0, 2}, // 블록 1
	{3, 0, 1, 2}, // 블록 2
	{2, 0, 3, 1}, // 블록 3
	{1, 2, 3, 0}, // 블록 4
	{1, 0, 3, 2}  // 블록 5 (벽 역할)
};

bool inRange(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int simulate(int sx, int sy, int dir) {
	int score = 0;
	int x = sx, y = sy;

	while (true) {
		x += dx[dir];
		y += dy[dir];

		if (!inRange(x, y)) {
			dir = block_dir[4][dir]; // 벽에 부딪힘 (5번 블록처럼 처리)
			score++;
			continue;
		}

		int val = board[x][y];

		if ((x == sx && y == sy) || val == -1) break; // 출발지 재도달 또는 블랙홀

		if (val >= 1 && val <= 5) {
			dir = block_dir[val - 1][dir];
			score++;
		}
		else if (val >= 6 && val <= 10) {
			pair<int, int> a = wormhole[val][0];
			pair<int, int> b = wormhole[val][1];
			if (x == a.first && y == a.second) {
				x = b.first;
				y = b.second;
			}
			else {
				x = a.first;
				y = a.second;
			}
		}
	}

	return score;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int test = 1; test <= T; test++) {
		cin >> N;
		board.assign(N, vector<int>(N));
		for (int i = 6; i <= 10; i++) wormhole[i].clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (board[i][j] >= 6 && board[i][j] <= 10) {
					wormhole[board[i][j]].push_back({ i, j });
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) {
					for (int d = 0; d < 4; d++) {
						ans = max(ans, simulate(i, j, d));
					}
				}
			}
		}

		cout << "#" << test << " " << ans << "\n";
	}

	return 0;
}
