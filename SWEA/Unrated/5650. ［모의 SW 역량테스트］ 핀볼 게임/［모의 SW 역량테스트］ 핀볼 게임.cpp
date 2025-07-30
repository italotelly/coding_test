#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
vector<vector<int>> board;
vector<pair<int, int>> wormhole[11];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int reflect[6][4] = {
	{0,0,0,0},
	{1,3,0,2},
	{3,0,1,2},
	{2,0,3,1},
	{1,2,3,0},
	{1,0,3,2}
};

bool inRange(int y, int x) {
	return (y >= 0 && x >= 0 && y < N && x < N);
}

pair<int, int> warp(int y, int x) {
	int num = board[y][x];
	auto &v = wormhole[num];
	return (v[0] == make_pair(y, x)) ? v[1] : v[0];
}

int simulate(int sy, int sx, int dir) {
	int y = sy, x = sx, d = dir, score = 0;
	while (true) {
		y += dy[d];
		x += dx[d];

		if (!inRange(y, x)) { score++; d ^= 1; continue; }
		if ((y == sy && x == sx) || board[y][x] == -1) break;

		int val = board[y][x];
		if (1 <= val && val <= 5) {
			score++;
			d = reflect[val][d];
		}
		else if (val >= 6) {
			auto nxt = warp(y, x);
			y = nxt.first;
			x = nxt.second;
		}
	}
	return score;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		board.assign(N, vector<int>(N, 0));
		for (int i = 6; i <= 10; i++) wormhole[i].clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (board[i][j] >= 6)
					wormhole[board[i][j]].push_back({ i,j });
			}
		}

		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) {
					for (int d = 0; d < 4; d++) {
						ans = max(ans, simulate(i, j, d));
					}
				}
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}
