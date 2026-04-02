#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct info
{
	int a, b;
	int idx;
	ll c1, c2;
};
bool compare(info a, info b) {
	if (a.c1 == b.c1) return a.c2 > b.c2;
	return a.c1 < b.c1;
}

int N, M;
vector<info> v;
int parent[200005];
vector<int> rst;

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}
void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = parent[t1];
	return;
}
void kruskal() {
	int s_cnt = 0;

	for (auto& e : v) {
		int a = e.a;
		int b = e.b;
		int c = e.idx;

		if (find(a) == find(b)) continue;
		set_union(a, b);
		rst.push_back(c);

		if (s_cnt == N - 1) {
			return;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		ll c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ a, b, i, c, d });
	}
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	sort(v.begin(), v.end(), compare);
	kruskal();

	for (int i = 0; i < rst.size(); i++)
	{
		cout << rst[i] << "\n";
	}
	return 0;
}