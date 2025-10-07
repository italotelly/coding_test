#include <iostream>
#include <queue>

using namespace std;

int n, m;
int MAP[1005][1005];
int st_y, st_x;

int dist[1005][1005];

struct edge
{
	int y, x;
	int cost;
};

struct compare
{
	bool operator()(edge a, edge b) {
		return a.cost > b.cost;
	}
};

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) {
		return false;
	}
	return true;
}

void dijkstra(int y, int x) {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ y, x, 0 });
	dist[y][x] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > dist[now.y][now.x])
			continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (!inRange(ny, nx))
				continue;
			if (MAP[ny][nx] == 0)
				continue;

			int next_cost = now.cost + 1;

			if (next_cost < dist[ny][nx]) {
				dist[ny][nx] = next_cost;
				pq.push({ny, nx, next_cost});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				st_y = i;
				st_x = j;
			}
			else if (MAP[i][j] == 0) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = 21e8;
			}
		}
	}

	dijkstra(st_y, st_x);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(dist[i][j] == 21e8)
				cout << "-1 ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}