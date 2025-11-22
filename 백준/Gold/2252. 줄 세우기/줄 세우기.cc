#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> v;
vector<int> indegree;

void bfs() {
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0) {
			q.push(i);
			cout << i << " ";
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			indegree[v[cur][i]]--;
			if (indegree[v[cur][i]] == 0) {
				cout << v[cur][i] << " ";
				q.push(v[cur][i]);
			}
		}
	}
}

int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	v.resize(N + 1);
	indegree.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		indegree[to]++;
	}

	bfs();
	
	cout << "\n";

	return 0;
}