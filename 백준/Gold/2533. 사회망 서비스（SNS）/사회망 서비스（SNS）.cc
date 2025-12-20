#include <iostream>
#include <queue>

using namespace std;

int N;
vector<int> v[1000005];
int indegree[1000005];
int early[1000005];
int removed[1000005];

int rst;

void bfs() {

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 1) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			if (removed[v[now][i]] || indegree[v[now][i]] == 0) continue;

			if (early[now] == 0) {
				if (early[v[now][i]] == 0) {
					early[v[now][i]] = 1;
					rst++;
					removed[now] = 1;
					indegree[now]--;
					indegree[v[now][i]]--;
				}
				else {
					removed[now] = 1;
					indegree[now]--;
					indegree[v[now][i]]--;
				}
			}
			else {
				removed[now] = 1;
				indegree[now]--;
				indegree[v[now][i]]--;
			}
			if (indegree[v[now][i]] == 1) {
				q.push(v[now][i]);
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
		indegree[a]++;
		indegree[b]++;
	}

	bfs();

	cout << rst << "\n";

	return 0;
}