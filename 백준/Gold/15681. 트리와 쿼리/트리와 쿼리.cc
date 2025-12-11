#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct pos
{
	int num;
	int level;
};

struct v1_pos
{
	int from;
	int to;
	int level;
};

int N, R, Q;
vector<int> v[100001];
vector<v1_pos> v1;
int visited[100001];
int rst[100001];

bool compare(v1_pos a, v1_pos b) {
	if (a.level == b.level) {
		return a.to < b.to;
	}
	return a.level > b.level;
}

void bfs(int st) {
	queue<pos> q;
	q.push({ st, 0 });
	visited[st] = 1;

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		int cnt = 0;
		for (int i = 0; i < v[now.num].size(); i++)
		{
			if (visited[v[now.num][i]]) continue;
			cnt++;
			visited[v[now.num][i]] = 1;
			q.push({ v[now.num][i], now.level + 1 });
			v1.push_back({ now.num, v[now.num][i], now.level + 1 });
		}
		if (cnt == 0) {
			v1.push_back({ now.num, 0, now.level + 1 });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(R);
	sort(v1.begin(), v1.end(), compare);

	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i].to == 0) {
			rst[v1[i].from] = 1;
		}
		else {
			if (rst[v1[i].from] == 0) rst[v1[i].from] = 1;
			rst[v1[i].from] += rst[v1[i].to];
		}
	}

	for (int i = 0; i < Q; i++)
	{
		int c;
		cin >> c;

		cout << rst[c] << "\n";
	}

	return 0;
}