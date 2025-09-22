#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a, b;

int flag;
int cnt;

struct edge
{
	int num;
	int cost;
};

vector<edge> v[105];
int visited[105];

void bfs(int st) {
	queue<edge> q;
	q.push({ st, 0 });
	visited[st] = 1;

	while (!q.empty()) {
		edge now = q.front();
		q.pop();
		if (now.num == b) {
			flag = 1;
			cnt = now.cost;
			return;
		}
		for (int i = 0; i < v[now.num].size(); i++)
		{
			if (visited[v[now.num][i].num] == 1)
				continue;
			visited[v[now.num][i].num] = 1;
			q.push({ v[now.num][i].num, now.cost + 1 });
		}
	}
}

int main() {

	cin >> n;	
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		v[start].push_back({ end, 0 });
		v[end].push_back({ start, 0 });
	}

	bfs(a);

	if (flag) {
		cout << cnt << "\n";
	}
	else {
		cout << "-1\n";
	}

	return 0;
}