#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;

struct pos
{
	int y, x;
	int cost;
};
struct compare
{
	bool operator()(pos a, pos b) {
		return a.cost > b.cost;
	}
};
int circuit[505][505];
vector<pos> v[505][505];
int dist[505][505];

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y > N || x > M) {
		return false;
	}
	return true;
}
int dy[] = { -1, -1, 0, 0 };
int dx[] = { -1, 0, -1, 0 };



void dijkstra() {
	priority_queue<pos, vector<pos>, compare> pq;
	pq.push({ 0, 0, 0 });
	dist[0][0] = 0;

	while (!pq.empty()) {
		pos cur = pq.top();
		pq.pop();

		if (cur.cost > dist[cur.y][cur.x]) continue;

		for (int i = 0; i < v[cur.y][cur.x].size(); i++)
		{
			int ny = v[cur.y][cur.x][i].y;
			int nx = v[cur.y][cur.x][i].x;
			int nxt_cost = cur.cost + v[cur.y][cur.x][i].cost;

			if (!inRange(ny, nx)) continue;

			if (nxt_cost < dist[ny][nx]) {
				dist[ny][nx] = nxt_cost;
				pq.push({ ny, nx, nxt_cost });
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			circuit[i][j] = s[j];
		}
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			dist[i][j] = 21e8;
			if (i == 0 && j == 0) {
				if (circuit[0][0] == '\\') v[i][j].push_back({ 1, 1, 0 });
				else if(circuit[0][0] == '/') v[i][j].push_back({ 1, 1, 1 });
				continue;
			}
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (!inRange(ny, nx))  continue;

				if (k == 0) {
					if (circuit[ny][nx] == '\\') v[i][j].push_back({ i - 1, j - 1, 0 });
					else v[i][j].push_back({ i - 1, j - 1, 1 });
				}
				else if (k == 1) {
					if (circuit[ny][nx] == '/') v[i][j].push_back({ i - 1, j + 1, 0 });
					else v[i][j].push_back({ i - 1, j + 1, 1 });
				}
				else if (k == 2) {
					if (circuit[ny][nx] == '/') v[i][j].push_back({ i + 1, j - 1, 0 });
					else v[i][j].push_back({ i + 1, j - 1, 1 });
				}
				else {
					if (circuit[ny][nx] == '\\') v[i][j].push_back({ i + 1, j + 1, 0 });
					else v[i][j].push_back({ i + 1, j + 1, 1 });
				}
			}
		}
	}

	dijkstra();

	if (dist[N][M] == 21e8) {
		cout << "NO SOLUTION\n";
		return 0;
	}
	cout << dist[N][M] << "\n";

	return 0;
}