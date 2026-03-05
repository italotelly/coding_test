#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct pos
{
	int x, y;
};
pos gods[1005];
vector<pair<double, pair<int, int>>> v;
int parent[1005];

int N, M;

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
double kruskal() {
	double sum = 0;
	int s_cnt = 0;

	for (auto &e : v) {
		int a = e.second.first;
		int b = e.second.second;
		double cost = e.first;

		if (find(a) == find(b)) continue;
		set_union(a, b);

		sum += cost;
		s_cnt++;

	}
	return sum;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		gods[i].x = a;
		gods[i].y = b;
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		set_union(a, b);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double dist = sqrt(pow(gods[i].x - gods[j].x, 2) + pow(gods[i].y - gods[j].y, 2));
			v.push_back({ dist, {i, j} });
		}
	}
	sort(v.begin(), v.end());

	cout.precision(2);
	cout << fixed << kruskal() << "\n";

	return 0;
}