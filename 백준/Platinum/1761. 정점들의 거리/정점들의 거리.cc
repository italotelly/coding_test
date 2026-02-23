#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge
{
	int num;
	int cost;
};

vector<edge> node[40005];
int parent[40005][20];
int dist_root[40005];
int depth[40005];
int max_height = 20;

int N, M;

void lca_init(int root_idx) {
	depth[root_idx] = 0;
	dist_root[root_idx] = 0;
	for (int i = 0; i < max_height; i++)
	{
		parent[root_idx][i] = root_idx;
	}
}

void dfs(int cur, int par) {
	parent[cur][0] = par;
	for (auto &e : node[cur]) {
		int nxt = e.num;
		int w = e.cost;

		if (nxt == par) continue;

		depth[nxt] = depth[cur] + 1;
		dist_root[nxt] = dist_root[cur] + w;

		dfs(nxt, cur);
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);

	int diff = depth[b] - depth[a];
	for (int i = max_height - 1; i >= 0; i--)
	{
		if (diff & (1 << i)) b = parent[b][i];
	}
	if (a == b) return a;
	for (int i = max_height - 1; i >= 0; i--)
	{
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b, c });
		node[b].push_back({ a, c });
	}

	int root = 1;
	lca_init(root);
	dfs(root, root);

	for (int j = 1; j < max_height; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}

	cin >> M;

	while (M--) {
		int a, b;
		cin >> a >> b;
		int rst = lca(a, b);
		cout << dist_root[a] + dist_root[b] - 2 * dist_root[rst] << "\n";
	}
	return 0;
}