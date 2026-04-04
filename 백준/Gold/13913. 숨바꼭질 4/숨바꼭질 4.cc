#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
int parent[100005];
vector<int> rst;

struct edge
{
	int pos, cost;
};

int bfs() {
	queue<edge> q;
	q.push({ N, 0 });
	parent[N] = N;

	while (!q.empty()) {
		edge now = q.front();
		q.pop();

		if (now.pos == K) {
			return now.cost;
		}
		if (now.pos > K) {
			if (now.pos > 0 && parent[now.pos - 1] == -1) {
				parent[now.pos - 1] = now.pos;
				q.push({ now.pos - 1, now.cost + 1 });
			}
			continue;
		}
		// K - 1
		if (now.pos > 0 && parent[now.pos - 1] == -1) {
			parent[now.pos - 1] = now.pos;
			q.push({ now.pos - 1, now.cost + 1 });
		}
		// K + 1
		if (parent[now.pos + 1] == -1) {
			parent[now.pos + 1] = now.pos;
			q.push({ now.pos + 1, now.cost + 1 });
		}
		// K * 2
		if (now.pos * 2 < 100005 && parent[now.pos * 2] == -1) {
			parent[now.pos * 2] = now.pos;
			q.push({ now.pos * 2, now.cost + 1 });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	if (N == K) {
		cout << 0 << "\n";
		cout << N << "\n";
		return 0;
	}
	else if (N > K) {
		cout << N - K << "\n";
		for (int i = N; i >= K; i--)
		{
			cout << i << " ";
		}
		cout << "\n";
		return 0;
	}

	memset(parent, -1, sizeof(parent));

	cout << bfs() << "\n";

	auto it = K;
	rst.push_back(K);
	while (it != N) {
		rst.push_back(parent[it]);
		it = parent[it];
	}

	for (int i = rst.size() - 1; i >= 0; i--)
	{
		cout << rst[i] << " ";
	}
	cout << "\n";

	return 0;
}