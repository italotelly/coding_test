#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v[100005];
int parent[100005][21];
int depth[100005];
bool visited[100005];
int max_height;

void dfs(int num, int d) {
	visited[num] = 1;
	depth[num] = d;

	for (int i = 0; i < v[num].size(); i++)
	{
		int nxt = v[num][i];
		if (!visited[nxt]) {
			parent[nxt][0] = num;
			dfs(nxt, d + 1);
		}
	}
}

void set_parent() {
	for (int i = 1; i < max_height; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (parent[j][i - 1] != 0) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
			}
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);

	for (int i = max_height - 1; i >= 0; i--)
	{
		int diff = depth[b] - depth[a];
		if (diff >= (1 << i)) b = parent[b][i];
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
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int temp = N;
	while (temp > 0) {
		max_height++;
		temp = temp >> 1;
	}
	dfs(1, 0);
	set_parent();

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << "\n";
	}

	return 0;
}