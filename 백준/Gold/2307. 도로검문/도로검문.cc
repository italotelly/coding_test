#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

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
vector<edge> v[1005];
int dist[1005];
int parent[1005];

int min_t;

void dijkstra_path() {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > dist[now.num]) continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int nxt_num = v[now.num][i].num;
			int nxt_cost = now.cost + v[now.num][i].cost;

			if (nxt_cost < dist[nxt_num]) {
				pq.push({ nxt_num, nxt_cost });
				dist[nxt_num] = nxt_cost;
				parent[nxt_num] = now.num;
			}
		}
	}
}

void dijkstra(int a, int b) {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > dist[now.num]) continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int nxt_num = v[now.num][i].num;
			int nxt_cost = now.cost + v[now.num][i].cost;

			if((now.num == a && nxt_num == b) || (now.num == b && nxt_num == a)) continue;

			if (nxt_cost < dist[nxt_num]) {
				pq.push({ nxt_num, nxt_cost });
				dist[nxt_num] = nxt_cost;
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}

	dijkstra_path();
	min_t = dist[N];
	if (min_t == 21e8) {
		cout << "-1\n";
		return 0;
	}
	
	int now = N;
	int max_t = -1;
	while (now != 1) {
		for (int i = 1; i <= N; i++)
		{
			dist[i] = 21e8;
		}
		int a = now;
		int b = parent[now];

		dijkstra(a, b);

		max_t = max(max_t, dist[N]);
		now = parent[now];
	}

	if (max_t == 21e8) {
		cout << "-1\n";
		return 0;
	}
	cout << max_t - min_t << "\n";

	return 0;
}