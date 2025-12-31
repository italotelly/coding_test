#include <iostream>
#include <queue>
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

int N, E;
vector<edge> v[805];
int v1, v2;
int dist[805];

long long one_v1;
long long one_v2;
long long v1_v2;
long long v1_N;
long long v2_N;

long long rst;

void dijkstra(int st) {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ st, 0 });

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > dist[now.num]) continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int nxt_cost = v[now.num][i].cost + now.cost;
			int nxt_num = v[now.num][i].num;

			if (nxt_cost < dist[nxt_num]) {
				dist[nxt_num] = nxt_cost;
				pq.push({ nxt_num, nxt_cost });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	cin >> v1 >> v2;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}

	// N이 2인 경우
	if (N == 2) {
		if (v[1].size() == 0) {
			cout << "-1\n";
		}
		else {
			cout << v[1][0].cost << "\n";
		}
		return 0;
	}

	if (v1 == 1) {
		if (v2 == N) {
			dijkstra(1);
			if (dist[N] == 21e8) {
				cout << "-1\n";
			}
			else {
				cout << dist[N] << "\n";
			}
			return 0;
		}
		else {
			dijkstra(1);
			one_v2 = dist[v2];
			for (int i = 1; i <= N; i++)
			{
				dist[i] = 21e8;
			}
			dijkstra(v2);
			v2_N = dist[N];
			
			rst = one_v2 + v2_N;
			if (rst >= 21e8) {
				cout << "-1\n";
			}
			else {
				cout << rst << "\n";
			}
			return 0;
		}
	}

	if (v2 == N) {
		dijkstra(1);
		one_v1 = dist[v1];
		for (int i = 1; i <= N; i++)
		{
			dist[i] = 21e8;
		}
		dijkstra(v1);
		v1_N = dist[N];

		rst = one_v1 + v1_N;
		if (rst >= 21e8) {
			cout << "-1\n";
		}
		else {
			cout << rst << "\n";
		}
		return 0;
	}

	dijkstra(1);
	one_v1 = dist[v1];
	one_v2 = dist[v2];

	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}

	dijkstra(v1);
	v1_v2 = dist[v2];

	for (int i = 1; i <= N; i++)
	{
		dist[i] = 21e8;
	}

	dijkstra(N);
	v1_N = dist[v1];
	v2_N = dist[v2];

	rst = min(one_v1 + v1_v2 + v2_N, one_v2 + v1_v2 + v1_N);

	if (rst >= 21e8) {
		cout << "-1\n";
	}
	else {
		cout << rst << "\n";
	}

	return 0;
}