#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct info
{
	int a, b, c;
};
vector<pair<int, pair<int, int>>> v;
int parent[100005];

int N;
info planet[100005];

int find(int tar) {
	if (tar == parent[tar]) return tar;
	return parent[tar] = find(parent[tar]);
}
void set_union(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;
	
	parent[t2] = t1;
}
int kruskal() {
	int rst = 0;
	int s_cnt = 0;

	for (auto &e : v)
	{
		int a = e.second.first;
		int b = e.second.second;
		int cost = e.first;

		if (find(a) == find(b)) continue;
		set_union(a, b);

		rst += cost;
		s_cnt++;

		if (s_cnt == N - 1) return rst;
	}
	return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		planet[i].a = A;
		planet[i].b = B;
		planet[i].c = C;
	}
	for (int i = 0; i < N; i++)	parent[i] = i;
	
	vector<pair<int, int>> X, Y, Z;
	X.reserve(N), Y.reserve(N), Z.reserve(N);

	for (int i = 0; i < N; i++)
	{
		X.push_back({ planet[i].a, i });
		Y.push_back({ planet[i].b, i });
		Z.push_back({ planet[i].c, i });
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());
	
	v.reserve(3 * (N - 1));

	for (int i = 0; i < N - 1; i++)
	{
		int u = X[i].second, w = X[i + 1].second;
		v.push_back({ abs(X[i + 1].first - X[i].first), {u, w} });

		 u = Y[i].second, w = Y[i + 1].second;
		v.push_back({ abs(Y[i + 1].first - Y[i].first), {u, w} });

		u = Z[i].second, w = Z[i + 1].second;
		v.push_back({ abs(Z[i + 1].first - Z[i].first), {u, w} });
	}

	sort(v.begin(), v.end());
	cout << kruskal() << "\n";

	return 0;
}