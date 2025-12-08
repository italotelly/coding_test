#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<int> v[1005];
vector<int> indegree;

vector<int> rst;

void bfs() {
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (!indegree[i])
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		rst.push_back(now);
		q.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			if (indegree[v[now][i]]) indegree[v[now][i]]--;
			if (!indegree[v[now][i]]) q.push(v[now][i]);
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	indegree.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;

		vector<int> v1;
		for (int j = 0; j < a; j++)
		{
			int b;
			cin >> b;
			v1.push_back({ b });
		}
		for (int j = 0; j < v1.size() - 1; j++)
		{
			v[v1[j]].push_back(v1[j + 1]);
			indegree[v1[j + 1]]++;
		}
	}

	bfs();
	if (rst.size() == N) {
		for (int i = 0; i < N; i++)
		{
			cout << rst[i] << " ";
		}
		cout << "\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}