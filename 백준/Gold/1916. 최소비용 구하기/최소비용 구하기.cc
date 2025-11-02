#include <iostream>
#include <queue>

using namespace std;

struct edge
{
	int num;
	int cost;
};

struct compare
{
	bool operator()(edge a, edge b) {
		return a.cost > b.cost;
	}
};

int N, M;
int dist[1005];
vector<edge> v[1005];

void dijkstra(int st_idx) {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ st_idx, 0 });
	dist[st_idx] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > dist[now.num])
			continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int next_cost = now.cost + v[now.num][i].cost;
			int next_num = v[now.num][i].num;

			if (next_cost < dist[next_num]) {
				dist[next_num] = next_cost;
				pq.push({ next_num, next_cost });
			}
		}
	}
	return;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}

	for (int i = 0; i < 1005; i++)
	{
		dist[i] = 21e8;
	}

	int st, en;
	cin >> st >> en;

	dijkstra(st);

	cout << dist[en] << "\n";

	return 0;
}