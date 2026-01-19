#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct edge
{
	int num;
	ll cost;
};

int N, M;
vector<edge> v[100005];
int parent[100005][21];
int depth[100005];
bool visited[100005];
int max_h;

ll dist_root[100005];

void dfs(int num, int d) {
	visited[num] = 1;
	depth[num] = d;

	for (int i = 0; i < v[num].size(); i++)
	{
		int nxt_num = v[num][i].num;
		ll nxt_cost = dist_root[num] + v[num][i].cost;

		if (!visited[nxt_num]) {
			parent[nxt_num][0] = num;
			dist_root[nxt_num] = nxt_cost;
			dfs(nxt_num, d + 1);
		}
	}
}

void set_parent() {
	for (int i = 1; i < max_h; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (parent[j][i - 1] != 0) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
			}
		}
	}
}

int jump_up(int x, int k) {
	for (int i = max_h - 1; i >= 0; i--)
	{
		if (k >= (1 << i) && k > 0) {
			x = parent[x][i];
			k -= (1 << i);
		}
	}

	return x;
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);

	int diff = depth[b] - depth[a];
	b = jump_up(b, diff);

	if (a == b) return a;

	for (int i = max_h - 1; i >= 0; i--)
	{
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}

ll dist_uv(int u, int v) {
	ll L = lca(u, v);
	return dist_root[u] + dist_root[v] - 2LL * dist_root[L];
}

int kth_on_path(int u, int v, int k) {
	ll L = lca(u, v);

	int up_len = depth[u] - depth[L] + 1;

	if (k <= up_len) {
		return jump_up(u, k - 1);
	}
	else {
		int down_len = depth[v] - depth[L];
		return jump_up(v, up_len + down_len - k);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	int temp = N;
	while (temp > 0) {
		max_h++;
		temp = temp >> 1;
	}

	dfs(1, 0);
	set_parent();

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, u, v, k;
		cin >> a;

		if (a == 1) {
			cin >> u >> v;
			cout << dist_uv(u, v) << "\n";
		}
		else if (a == 2) {
			cin >> u >> v >> k;
			cout << kth_on_path(u, v, k) << "\n";
		}
	}

	return 0;
}