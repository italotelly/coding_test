#include <iostream>
#include <queue>

using namespace std;

int N, M;
int ary[1010][1010];
int visited[1010];
int cnt = 1;

void bfs(int st) {
	queue<int> q;
	q.push(st);
	visited[st] = cnt;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (visited[i])
				continue;
			if (ary[now][i] == 0)
				continue;
			q.push(i);
			visited[i] = cnt;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		ary[from][to] = 1;
		ary[to][from] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i])
			continue;
		bfs(i);
		cnt++;
	}

	cout << cnt - 1 << "\n";

	return 0;
}