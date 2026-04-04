#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int MAP[205][205];
bool visited[205][205][35][2];
vector<pair<int, int>> pattern;

struct info
{
	int y, x;
	int p_cnt;
	bool pass;
	int cnt;
};

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return false;
	return true;
}

int bfs() {
	queue<info> q;
	q.push({ 0, 0, 0, 0, 0 });
	visited[0][0][0][0] = true;

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		if (now.y == N - 1 && now.x == M - 1 && now.pass) return now.cnt;

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (!inRange(ny, nx)) continue;
			if (MAP[ny][nx] == 0) {
				if (visited[ny][nx][now.p_cnt][now.pass]) continue;
				visited[ny][nx][now.p_cnt][now.pass] = true;
				q.push({ ny, nx, now.p_cnt, now.pass, now.cnt + 1 });
			}
			else if (MAP[ny][nx] == 2) {
				if (visited[ny][nx][now.p_cnt][1]) continue;
				visited[ny][nx][now.p_cnt][1] = true;
				q.push({ ny, nx, now.p_cnt, true, now.cnt + 1 });
			}
		}
		if (now.p_cnt >= K) continue;
		for (int i = 0; i < pattern.size(); i++)
		{
			int ny = now.y + pattern[i].first;
			int nx = now.x + pattern[i].second;

			if (!inRange(ny, nx)) continue;

			if (MAP[ny][nx] == 0) {
				if (visited[ny][nx][now.p_cnt + 1][now.pass]) continue;
				visited[ny][nx][now.p_cnt + 1][now.pass] = true;
				q.push({ ny, nx, now.p_cnt + 1, now.pass, now.cnt + 1 });
			}
			else if (MAP[ny][nx] == 2) {
				if (visited[ny][nx][now.p_cnt + 1][1]) continue;
				visited[ny][nx][now.p_cnt + 1][1] = true;
				q.push({ ny, nx, now.p_cnt + 1, true, now.cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}
	int a;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> a;
			if ((i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 2) || (i == 2 && j == 3) || (i == 3 && j == 2)) continue;
			if (a) {
				pattern.push_back({ i - 2, j - 2 });
			}
		}
	}

	cout << bfs() << "\n";

	return 0;
}