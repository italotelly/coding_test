#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
char MAP[105][105];
int temp_MAP[105][105];
int r_cnt;
int g_cnt;
int b_cnt;


bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void bfs(int y, int x, char a) {
	temp_MAP[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x });

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (!inRange(ny, nx)) continue;
			if (temp_MAP[ny][nx]) continue;
			
			if (a == 'K') {
				if (MAP[ny][nx] == 'R' || MAP[ny][nx] == 'G') {
					temp_MAP[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
			else {
				if (MAP[ny][nx] == a) {
					temp_MAP[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
		}

	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp_MAP[i][j] == 0) {
				if (MAP[i][j] == 'R') {
					bfs(i, j, 'R');
					r_cnt++;
				}
				else if (MAP[i][j] == 'G') {
					bfs(i, j, 'G');
					g_cnt++;
				}
				else if (MAP[i][j] == 'B') {
					bfs(i, j, 'B');
					b_cnt++;
				}
			}
		}
	}

	cout << r_cnt + g_cnt + b_cnt << " ";

	memset(temp_MAP, 0, sizeof(temp_MAP));
	r_cnt = 0;
	g_cnt = 0;
	b_cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp_MAP[i][j] == 0) {
				if (MAP[i][j] == 'R' || MAP[i][j] == 'G') {
					bfs(i, j, 'K');
					r_cnt++;
				}
				else if (MAP[i][j] == 'B') {
					bfs(i, j, 'B');
					b_cnt++;
				}
			}
		}
	}

	cout << r_cnt + b_cnt << " ";

	return 0;
}