#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v[50005];
int depth[50005];
int parent[50005];
bool visited[50005];

void dfs(int num, int d) {
	visited[num] = 1;
	depth[num] = d;

	for (int i = 0; i < v[num].size(); i++)
	{
		if (!visited[v[num][i]]) {
			parent[v[num][i]] = num;
			dfs(v[num][i], d + 1);
		}
	}

	return;
}

int lca(int a, int b) {
	while (parent[a] != parent[b]) {
		if (depth[a] < depth[b]) {
			b = parent[b];
		}
		else {
			a = parent[a];
		}
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
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

	cin >> M;
	dfs(1, 0);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}