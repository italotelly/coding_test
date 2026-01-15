#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct edge
{
	int a, b;
	double cost;
};

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

int n;
vector<pair<double, double>> v1;
vector<edge> v;
int parent[105];

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

double kruskal() {
	double rst = 0;
	int edge_cnt = 0;
	
	for (edge e: v) {
		int a = e.a;
		int b = e.b;
		double cost = e.cost;

		if (find(a) == find(b)) continue;
		setUnion(a, b);
		edge_cnt++;
		rst += cost;
		if (edge_cnt == n - 1) break;
	}
	return rst;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	double x, y;
	v1.push_back({ 0, 0 });
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v1.push_back({ x, y });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double temp_cost = sqrt(pow((v1[i].first - v1[j].first), 2) + pow((v1[i].second - v1[j].second), 2));
			v.push_back({ i, j, temp_cost });
		}
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	cout << kruskal() << "\n";

	return 0;
}