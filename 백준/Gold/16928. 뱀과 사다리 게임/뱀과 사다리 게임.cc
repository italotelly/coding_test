#include <iostream>
#include <queue>

using namespace std;

struct edge
{
	int num, cost;
};

int N, M;
int MAP[105];
int visited[105];

int rst;

void bfs(int st) {
	queue<edge> q;
	q.push({ st, 0 });
	visited[st] = 1;

	while (!q.empty()) {
		edge now = q.front();
		q.pop();

		if (now.num == 100) {
			rst = now.cost;
			return;
		}
		if (visited[now.num + 1] == 0) {
			visited[now.num + 1] = 1;
			if (MAP[now.num + 1] && visited[MAP[now.num + 1]] == 0) {
				visited[MAP[now.num + 1]] = 1;
				q.push({ MAP[now.num + 1], now.cost + 1 });
			}
			else if(MAP[now.num + 1] == 0){
				q.push({ now.num + 1, now.cost + 1 });
			}
		}
		if (visited[now.num + 2] == 0) {
			visited[now.num + 2] = 1;
			if (MAP[now.num + 2] && visited[MAP[now.num + 2]] == 0) {
				visited[MAP[now.num + 2]] = 1;
				q.push({ MAP[now.num + 2], now.cost + 1 });
			}
			else if (MAP[now.num + 2] == 0) {
				q.push({ now.num + 2, now.cost + 1 });
			}
		}
		if (visited[now.num + 3] == 0) {
			visited[now.num + 3] = 1;
			if (MAP[now.num + 3] && visited[MAP[now.num + 3]] == 0) {
				visited[MAP[now.num + 3]] = 1;
				q.push({ MAP[now.num + 3], now.cost + 1 });
			}
			else if (MAP[now.num + 3] == 0) {
				q.push({ now.num + 3, now.cost + 1 });
			}
		}
		if (visited[now.num + 4] == 0) {
			visited[now.num + 4] = 1;
			if (MAP[now.num + 4] && visited[MAP[now.num + 4]] == 0) {
				visited[MAP[now.num + 4]] = 1;
				q.push({ MAP[now.num + 4], now.cost + 1 });
			}
			else if (MAP[now.num + 4] == 0) {
				q.push({ now.num + 4, now.cost + 1 });
			}
		}
		if (visited[now.num + 5] == 0) {
			visited[now.num + 5] = 1;
			if (MAP[now.num + 5] && visited[MAP[now.num + 5]] == 0) {
				visited[MAP[now.num + 5]] = 1;
				q.push({ MAP[now.num + 5], now.cost + 1 });
			}
			else if (MAP[now.num + 5] == 0) {
				q.push({ now.num + 5, now.cost + 1 });
			}
		}
		if (visited[now.num + 6] == 0) {
			visited[now.num + 6] = 1;
			if (MAP[now.num + 6] && visited[MAP[now.num + 6]] == 0) {
				visited[MAP[now.num + 6]] = 1;
				q.push({ MAP[now.num + 6], now.cost + 1 });
			}
			else if (MAP[now.num + 6] == 0) {
				q.push({ now.num + 6, now.cost + 1 });
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		MAP[a] = b;
	}
	for (int i = 0; i < M; i++)
	{
		int c, d;
		cin >> c >> d;
		MAP[c] = d;
	}

	bfs(1);

	cout << rst << "\n";

	return 0;
}