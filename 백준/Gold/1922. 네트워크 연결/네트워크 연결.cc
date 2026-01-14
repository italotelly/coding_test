#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
	int a, b;
	int cost;
};

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

int N, M;
vector<edge> v;
int parent[1005];

int find(int a) {
	if (a == parent[a]) return a;

	return parent[a] = find(parent[a]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;

	parent[t2] = t1;
}

int kruskal() {
	int rst = 0;
	int cnt = 0;

	for (edge e : v)
	{
		int a = e.a;
		int b = e.b;
		int cost = e.cost;
		if (find(a) == find(b)) continue;
		setUnion(a, b);
		rst += cost;
		cnt++;
		if (cnt == N - 1) break;
	}
	return rst;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	sort(v.begin(), v.end(), compare);

	cout << kruskal() << "\n";

	return 0;
}