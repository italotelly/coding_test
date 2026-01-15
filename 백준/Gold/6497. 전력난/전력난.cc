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

int m, n;
vector<edge> v;
int parent[200005];
int sum;

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
	int edge_cnt = 0;

	for (edge e : v) {
		int a = e.a;
		int b = e.b;
		int cost = e.cost;

		if (find(a) == find(b)) continue;
		setUnion(a, b);
		rst += cost;
		edge_cnt++;
		if (edge_cnt == m - 1) break;
	}
	return rst;
}

void init() {
	v.clear();
	sum = 0;
}

int main() {

	while (true) {
		init();
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		int a, b, c;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> c;
			v.push_back({ a, b, c });
			sum += c;
		}
		for (int i = 0; i < m; i++)
		{
			parent[i] = i;
		}
		sort(v.begin(), v.end(), compare);
		cout << sum - kruskal() << "\n";
	}
	return 0;
}