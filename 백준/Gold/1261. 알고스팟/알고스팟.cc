#include <iostream>
#include <queue>
#include <string>

using namespace std;

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

int N, M;
int MAP[105][105];
int dist[105][105];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (y < 1 || x < 1 || y > N || x > M) {
		return false;
	}
	return true;
}

void dijkstra() {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ 1,1,0 });
	dist[1][1] = 0; 

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > dist[now.y][now.x]) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (!inRange(ny, nx)) continue;

			int nxt_cost = now.cost;
			if (MAP[ny][nx] == 1) nxt_cost++;

			if (nxt_cost < dist[ny][nx]) {
				dist[ny][nx] = nxt_cost;
				pq.push({ ny, nx, nxt_cost });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	string s;
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			MAP[i][j + 1] = (s[j] - '0');
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dist[i][j] = 21e8;
		}
	}

	dijkstra();

	cout << dist[N][M] << "\n";

	return 0;
}