#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N;
vector<vector<int>> v;
vector<vector<int>> visited;

int a, b, x, y;
int sol;

bool inRange(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}

void dfs(int sec, int cx, int cy) {
	if (visited[cx][cy] <= sec) return;
	visited[cx][cy] = sec;

	if (cx == x && cy == y) {
		sol = min(sol, sec);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = cx + dx[i], ny = cy + dy[i];
		if (!inRange(nx, ny) || v[nx][ny] == 1) continue;

		if (v[nx][ny] == 2) {
			// wait until (sec + 1) % 3 == 0
			int wait = 0;
			if ((sec + 1) % 3 != 0)
				wait = 3 - ((sec + 1) % 3);
			dfs(sec + 1 + wait, nx, ny);
		}
		else {
			dfs(sec + 1, nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		v.assign(N, vector<int>(N));
		visited.assign(N, vector<int>(N, INT_MAX));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> v[i][j];

		cin >> a >> b >> x >> y;

		sol = INT_MAX;
		dfs(0, a, b);

		if (sol == INT_MAX) sol = -1;  // 도달 불가
		cout << "#" << tc << " " << sol << "\n";
	}
	return 0;
}
