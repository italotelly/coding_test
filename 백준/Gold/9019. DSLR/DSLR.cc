#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

struct edge
{
	int s;
	string path;
};

int T;
int st, en;
string rst;
int visited[10005];

void bfs() {
	queue<edge> q;
	q.push({ st });
	visited[st] = 1;

	while (!q.empty()) {
		edge now = q.front();
		q.pop();

		if (now.s == en) {
			rst = now.path;
			return;
		}

		// D
		int D1 = (now.s * 2) % 10000;
		if (!visited[D1]) {
			q.push({ D1, now.path + 'D' });
			visited[D1] = 1;
			if (D1 == en) {
				rst = now.path + 'D';
				return;
			}
		}
		// S
		if (now.s == 0) {
			if (!visited[9999]) {
				q.push({ 9999, now.path + 'S' });
				visited[9999] = 1;
				if (9999 == en) {
					rst = now.path + 'S';
					return;
				}
			}
		}
		else {
			int S1 = now.s - 1;
			if (!visited[S1]) {
				q.push({ S1, now.path + 'S' });
				visited[S1] = 1;
				if (S1 == en) {
					rst = now.path + 'S';
					return;
				}
			}
		}
		// L
		int now_temp1 = ((now.s * 10) % 10000) + now.s / 1000;
		if (!visited[now_temp1]) {
			q.push({ now_temp1, now.path + 'L' });
			visited[now_temp1] = 1;
			if (now_temp1 == en) {
				rst = now.path + 'L';
				return;
			}
		}
		// R
		int now_temp2 = (now.s % 10) * 1000 + now.s / 10;
		if (!visited[now_temp2]) {
			q.push({ now_temp2, now.path + 'R' });
			visited[now_temp2] = 1;
			if (now_temp2 == en) {
				rst = now.path + 'R';
				return;
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		memset(visited, 0, sizeof(visited));
		cin >> st >> en;

		bfs();
		cout << rst << "\n";
	}

	return 0;
}