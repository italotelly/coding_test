#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
ll MAP[1005][1005];
vector<pair<ll, pair<int, int>>> v;
int parent[1005];

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}
void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;
}
ll kruskal() {
	ll rst = 0;
	int s_cnt = 0;

	for (auto &e : v) {
		int a = e.second.first;
		int b = e.second.second;
		ll cost = e.first;

		if (find(a) == find(b)) continue;
		set_union(a, b);

		rst += cost;
		s_cnt++;
		if (s_cnt == N - 1) return rst;
	}
	return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			v.push_back({MAP[i][j], { i, j }});
		}
	}
	sort(v.begin(), v.end());
	cout << kruskal() << "\n";

	return 0;
}