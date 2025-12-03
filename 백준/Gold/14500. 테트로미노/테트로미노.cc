#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int MAP[505][505];
int visited[505][505];
int rst;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	return true;
}

void dfs(int y, int x, int lev, int sum) {
	if (lev == 3) {
		rst = max(rst, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!inRange(ny, nx)) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = 1;
		dfs(ny, nx, lev + 1, sum + MAP[ny][nx]);
		visited[ny][nx] = 0;
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 1;
			dfs(i, j, 0, MAP[i][j]);
			visited[i][j] = 0;
		}
	}

	// edge case 추가
	// case 1.
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			rst = max(rst, MAP[i][j] + MAP[i][j + 1] + MAP[i][j + 2] + MAP[i + 1][j + 1]);
		}
	}
	// case 2.
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			rst = max(rst, MAP[i + 1][j] + MAP[i + 1][j + 1] + MAP[i + 1][j + 2] + MAP[i][j + 1]);
		}
	}
	// case 3.
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			rst = max(rst, MAP[i + 1][j] + MAP[i][j + 1] + MAP[i + 1][j + 1] + MAP[i + 2][j + 1]);
		}
	}
	// case 4.
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			rst = max(rst, MAP[i][j] + MAP[i + 1][j] + MAP[i + 2][j] + MAP[i + 1][j + 1]);
		}
	}
	cout << rst << "\n";

	return 0;
}