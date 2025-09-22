#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int MAP[105][105];
int dist[105][105];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	return true;
}

struct Edge
{
	int y, x;
	int cost;
};

struct compare
{
	bool operator() (Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

void dijkstra(int y, int x) {
	priority_queue<Edge, vector<Edge>, compare> pq;
	pq.push({ y, x, 0 });
	dist[y][x] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		// 가지치기
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

			int nextCost = now.cost + 1;

			if (nextCost < dist[ny][nx]) {
				dist[ny][nx] = nextCost;
				pq.push({ ny, nx, nextCost });
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			MAP[i][j] = s[j] - '0';
			dist[i][j] = 21e8;
		}
	}

	dijkstra(0, 0);

	cout << dist[N - 1][M - 1] + 1<< "\n";

	return 0;
}