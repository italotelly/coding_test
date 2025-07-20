#include <iostream>
#include <vector>
using namespace std;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void flip(vector<vector<int>>& board, int x, int y, int color, int N) {
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		vector<pair<int, int>> path;

		while (nx >= 0 && ny >= 0 && nx < N && ny < N && board[nx][ny] != 0 && board[nx][ny] != color) {
			path.push_back(make_pair(nx, ny));
			nx += dx[dir];
			ny += dy[dir];
		}

		if (nx >= 0 && ny >= 0 && nx < N && ny < N && board[nx][ny] == color) {
			for (size_t i = 0; i < path.size(); ++i) {
				int fx = path[i].first;
				int fy = path[i].second;
				board[fx][fy] = color;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> board(N, vector<int>(N, 0));

		// 초기 세팅
		int mid = N / 2;
		board[mid - 1][mid - 1] = 2;
		board[mid][mid] = 2;
		board[mid - 1][mid] = 1;
		board[mid][mid - 1] = 1;

		for (int i = 0; i < M; i++) {
			int y, x, color;
			cin >> y >> x >> color;
			x--; y--;  // 0-indexed
			board[x][y] = color;
			flip(board, x, y, color, N);
		}

		int black = 0, white = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (board[i][j] == 1) black++;
				else if (board[i][j] == 2) white++;
			}
		}

		cout << "#" << t << " " << black << " " << white << "\n";
	}

	return 0;
}
