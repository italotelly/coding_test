#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge
{
	int num;
	int cost;
};

int max_height = 20;
int depth[100005];
int parent[100005][20];
vector<edge> node[100005];
int min_road[100005][20];
int max_road[100005][20];

int N, K;

void init_lca(int root) {
	depth[root] = 0;
	for (int i = 0; i < max_height; i++)
	{
		parent[root][i] = root;
		min_road[root][i] = 21e8;
		max_road[root][i] = -21e8;
	}
	return;
}
void dfs_lca(int cur, int par, int w) {
	if (cur != par) {
		parent[cur][0] = par;
		min_road[cur][0] = w;
		max_road[cur][0] = w;
	}
	for (auto &e : node[cur]) {
		int nxt_num = e.num;
		if (nxt_num == par) continue;
		depth[nxt_num] = depth[cur] + 1;
		dfs_lca(nxt_num, cur, e.cost);
	}
}
pair<int, int> lca(int a, int b) {
	int mn = 21e8;
	int mx = -21e8;
	
	if (depth[a] > depth[b]) swap(a, b);

	int diff = depth[b] - depth[a];
	for (int i = max_height - 1; i >= 0; i--)
	{
		if (diff & (1 << i)) {
			mn = min(mn, min_road[b][i]);
			mx = max(mx, max_road[b][i]);
			b = parent[b][i];
		}
	}
	if (a == b) return {mn, mx};

	for (int i = max_height - 1; i >= 0; i--)
	{
		if (parent[a][i] != parent[b][i]) {
			mn = min(mn, min_road[a][i]);
			mn = min(mn, min_road[b][i]);
			mx = max(mx, max_road[a][i]);
			mx = max(mx, max_road[b][i]);
			
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	// 마지막 부모 도달
	mn = min(mn, min_road[a][0]);
	mn = min(mn, min_road[b][0]);
	mx = max(mx, max_road[a][0]);
	mx = max(mx, max_road[b][0]);

	return { mn, mx };
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		node[A].push_back({ B, C });
		node[B].push_back({ A, C });
	}

	int root = 1;
	init_lca(root);
	dfs_lca(root, root, 0);

	for (int j = 1; j < max_height; j++)
	{
		for (int i = 2; i <= N; i++)
		{
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			
			min_road[i][j] = min(min_road[i][j - 1], min_road[parent[i][j - 1]][j - 1]);
			max_road[i][j] = max(max_road[i][j - 1], max_road[parent[i][j - 1]][j - 1]);
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int D, E;
		cin >> D >> E;
		auto rst = lca(D, E);
		cout << rst.first << " " << rst.second << "\n";
	}

	return 0;
}