#include <iostream>
#include <queue>

using namespace std;

int N, M;
int indegree[32005];
vector<int> v[32005];

void bfs() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0) pq.push(i);

	while (!pq.empty()) {
		int now = pq.top();
		cout << now << " ";
		pq.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			indegree[v[now][i]]--;
			if(indegree[v[now][i]] == 0) pq.push(v[now][i]);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		indegree[b]++;
		v[a].push_back(b);
	}

	bfs();
	cout << "\n";

	return 0;
}