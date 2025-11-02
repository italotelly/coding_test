#include <iostream>
#include <queue>

using namespace std;

struct edge
{
	int num;
	int cost;
};

struct compare
{
	bool operator()(edge a, edge b) {
		return a.cost > b.cost;
	}
};

int N, K;

int dist[100005];

void dijkstra() {
	priority_queue<edge, vector<edge>, compare> pq;
	pq.push({ N, 0 });
	dist[N] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (dist[now.num] < now.cost)
			continue;

		if (now.num > K) {
			if (now.cost + (now.num - K) < dist[K]) {
				dist[K] = now.cost + (now.num - K);
			}
		}
		else if (now.num < K) {
			if (now.num == 0) {
				if (now.cost + 1 < dist[now.num + 1]) {
					dist[now.num + 1] = now.cost + 1;
					pq.push({ now.num + 1, now.cost + 1 });
				}
			}
			else {
				if (now.cost + 1 < dist[now.num - 1]) {
					dist[now.num - 1] = now.cost + 1;
					pq.push({ now.num - 1, now.cost + 1 });
				}
				if (now.cost + 1 < dist[now.num + 1]) {
					dist[now.num + 1] = now.cost + 1;
					pq.push({ now.num + 1, now.cost + 1 });
				}
				if (now.num * 2 < 100005) {
					if (now.cost < dist[now.num * 2]) {
						dist[now.num * 2] = now.cost;
						pq.push({ now.num * 2, now.cost });
					}
				}
			}
		}
	}

	return;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	if (N == K) {
		cout << "0\n";
		return 0;
	}
	else if (N > K) {
		cout << N - K << "\n";
		return 0;
	}

	for (int i = 0; i < 100005; i++)
	{
		dist[i] = 21e8;
	}

	dijkstra();

	cout << dist[K] << "\n";

	return 0;
}