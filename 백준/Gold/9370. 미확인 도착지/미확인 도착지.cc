#include <iostream>
#include <vector>
#include <queue>
#include <set>

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

int T;
int n, m, t;
int s, g, h;
vector<edge> v[2005];
int distst[2005];
int distg[2005];
int disth[2005];
vector<int> goal;
int dist_hg;

set<int> rst;

void init() {
	for (int i = 1; i <= n; i++)
	{
		v[i].clear();
		distst[i] = 21e8;
		distg[i] = 21e8;
		disth[i] = 21e8;
	}
	goal.clear();
	dist_hg = 0;
	rst.clear();
}

void dijkstra_st(int st) {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ st, 0 });
	distst[st] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > distst[now.num]) continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int nxt_num = v[now.num][i].num;
			int nxt_cost = now.cost + v[now.num][i].cost;

			if (nxt_cost < distst[nxt_num]) {
				distst[nxt_num] = nxt_cost;
				pq.push({ nxt_num, nxt_cost });
			}
		}
	}
}

void dijkstra_g(int st) {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ st, 0 });
	distg[st] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > distg[now.num]) continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int nxt_num = v[now.num][i].num;
			int nxt_cost = now.cost + v[now.num][i].cost;

			if (nxt_cost < distg[nxt_num]) {
				distg[nxt_num] = nxt_cost;
				pq.push({ nxt_num, nxt_cost });
			}
		}
	}
}

void dijkstra_h(int st) {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ st, 0 });
	disth[st] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (now.cost > disth[now.num]) continue;

		for (int i = 0; i < v[now.num].size(); i++)
		{
			int nxt_num = v[now.num][i].num;
			int nxt_cost = now.cost + v[now.num][i].cost;

			if (nxt_cost < disth[nxt_num]) {
				disth[nxt_num] = nxt_cost;
				pq.push({ nxt_num, nxt_cost });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		init();
		for (int i = 0; i < m; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;
			if ((a == g && b == h) || (b == g && a == h)) {
				dist_hg = d;
			}
			v[a].push_back({ b, d });
			v[b].push_back({ a, d });
		}
		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			goal.push_back(x);
		}
		dijkstra_st(s);
		dijkstra_g(g);
		dijkstra_h(h);

		int c = distg[s];
		int d = disth[s];
		for (int i = 0; i < goal.size(); i++)
		{
			int a = distg[goal[i]];
			int b = disth[goal[i]];
			int sum = 0;

			if (c != 21e8 && b != 21e8 && dist_hg != 0) {
				sum = c + b + dist_hg;
				if (sum == distst[goal[i]]) rst.insert(goal[i]);
			}

			if (d != 21e8 && a != 21e8 && dist_hg != 0) {
				sum = d + a + dist_hg;
				if (sum == distst[goal[i]]) rst.insert(goal[i]);
			}
		}

		for (auto it : rst)
		{
			cout << it << " ";
		}
		cout << "\n";
	}

	return 0;
}