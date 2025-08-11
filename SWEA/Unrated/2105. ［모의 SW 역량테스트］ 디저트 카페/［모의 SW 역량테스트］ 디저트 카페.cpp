#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int T;
int N;

int dy[] = { -1, -1, 1, 1 };
int dx[] = { -1,  1,-1, 1 };

int map[25][25];
int visited[25][25];

int st_y, st_x;

int bucket[110];
int cnt;

int rst;

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	memset(bucket, 0, sizeof(bucket));
	cnt = 0;
	rst = 0;
}

bool inRange(int y, int x) {
	return !(y < 0 || x < 0 || y >= N || x >= N);
}

void dfs(int y, int x, int d, int turn) {
	int ny = y + dy[d];
	int nx = x + dx[d];

	if (!inRange(ny, nx)) return;

	if (ny == st_y && nx == st_x) {
		if (turn == 3 && cnt >= 4) {
			if (cnt > rst) rst = cnt;
		}
		return;
	}

	if (visited[ny][nx]) return;
	if (bucket[map[ny][nx]] > 0) return;

	visited[ny][nx] = 1;
	bucket[map[ny][nx]]++;
	cnt++;

	if (d == 0) {
		dfs(ny, nx, 0, turn);
		dfs(ny, nx, 1, turn + 1);
	}
	else if (d == 1) {
		dfs(ny, nx, 1, turn);
		dfs(ny, nx, 3, turn + 1);
	}
	else if (d == 2) {
		dfs(ny, nx, 2, turn);
		dfs(ny, nx, 0, turn + 1);
	}
	else {
		dfs(ny, nx, 3, turn);
		dfs(ny, nx, 2, turn + 1);
	}

	cnt--;
	bucket[map[ny][nx]]--;
	visited[ny][nx] = 0;
}

int main() {
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				memset(visited, 0, sizeof(visited));
				memset(bucket, 0, sizeof(bucket));
				cnt = 0;

				if (j == 0 || j == N - 1 || i == N - 1) continue;

				bucket[map[i][j]] = 1;
				cnt = 1;
				st_y = i; st_x = j;

				dfs(i, j, 3, 0);
				dfs(i, j, 2, 0);

				cnt = 0;
				bucket[map[i][j]] = 0;
			}
		}

		if (rst == 0) rst = -1;
		cout << "#" << tc + 1 << " " << rst << "\n";
	}

	return 0;
}
