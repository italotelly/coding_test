#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N;

vector<int> node[10005];
int parent[10005][20];
int depth[10005];
int indeg[10005];
int max_height = 20;

void init() {
	for (int i = 1; i <= N; i++)
	{
		node[i].clear();
		depth[i] = 0;
		indeg[i] = 0;
		for (int j = 0; j < 20; j++)
		{
			parent[i][j] = 0;
		}
	}
}

void dfs(int cur, int par) {
	parent[cur][0] = par;
	for (int nxt : node[cur])
	{
		if (nxt == par) continue;
		depth[nxt] = depth[cur] + 1;
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

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> N;
		init();
		for (int i = 0; i < N - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			node[a].push_back(b);
			node[b].push_back(a);
			indeg[b]++;
		}
		int A, B;
		cin >> A >> B;

		// 루트 정하기
		int root = 1;
		for (int i = 1; i <= N; i++)
		{
			if (indeg[i] == 0) {
				root = i;
				break;
			}
		}
		depth[root] = 0;
		// depth 구하기
		dfs(root, root);

		for (int j = 1; j < max_height; j++)
		{
			for (int i = 1; i <= N; i++)
			{
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
			}
		}
		cout << lca(A, B) << "\n";
	}

	return 0;
}