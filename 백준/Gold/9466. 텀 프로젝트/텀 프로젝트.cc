#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, n;
int student[100005];
int indegree[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}

		// indegree 계산
		for (int i = 1; i <= n; i++) {
			indegree[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			indegree[student[i]]++;
		}

		queue<int> q;

		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		int cntNotTeam = 0;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			cntNotTeam++;

			int next = student[cur];
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}

		cout << cntNotTeam << "\n";
	}

	return 0;
}
