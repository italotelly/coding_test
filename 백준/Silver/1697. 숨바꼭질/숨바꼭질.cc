#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct edge
{
	int num;
	int cost;
};

int N, K;
const int MAXX = 100000;

int bfs(int num) {
	queue<edge> q;
	vector<int> visited(MAXX + 1, 0);
	q.push({ num, 0 });
	visited[num] = 1;

	while (!q.empty()) {
		edge now = q.front();
		q.pop();

		if (now.num == K) {
			return now.cost;
		}

		if (now.num > K) {
			int nxt = now.num - 1;
			if (nxt >= 0 && !visited[nxt]) {
				visited[nxt] = 1;
				q.push({ nxt, now.cost + 1 });
			}
			continue;
		}

		// now.num <= K 인 경우 세 방향 푸시
		int a = now.num - 1;
		int b = now.num + 1;
		int c = now.num * 2;

		if (a >= 0 && !visited[a]) {
			visited[a] = 1;
			q.push({ a, now.cost + 1 });
		}
		if (b <= MAXX && !visited[b]) {
			visited[b] = 1;
			q.push({ b, now.cost + 1 });
		}
		if (c <= MAXX && !visited[c]) {
			visited[c] = 1;
			q.push({ c, now.cost + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	if (N == K) {
		cout << "0\n";
		return 0;
	}
	else if (N > K) {
		cout << N - K << "\n";
		return 0;
	}

	int rst = bfs(N);
	cout << rst << "\n";

	return 0;
}
