#include <iostream>
#include <vector>
using namespace std;

bool visited[100];
vector<int> graph[100];
bool found = false;

void dfs(int node) {
	if (node == 99) {
		found = true;
		return;
	}
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];

		if (visited[next] == false) {
			dfs(next);

			if (found == true) {
				return;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int tc = 1; tc <= 10; ++tc) {
		int t, E;
		cin >> t >> E;

		for (int i = 0; i < 100; ++i) {
			graph[i].clear();
			visited[i] = false;
		}
		found = false;

		for (int i = 0; i < E; ++i) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
		}

		dfs(0);

		cout << "#" << t << " " << (found ? 1 : 0) << "\n";
	}

	return 0;
}
