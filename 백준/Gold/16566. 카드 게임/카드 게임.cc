#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> v;
vector<int> parent;

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;

	parent[t1] = t2;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	v.resize(M);
	parent.resize(M + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	for (int i = 0; i <= M; i++)
	{
		parent[i] = i;
	}

	int a;
	for (int i = 0; i < K; i++)
	{
		cin >> a;
		int idx = (upper_bound(v.begin(), v.end(), a) - v.begin());
		int p = find(idx);
		cout << v[p] << "\n";
		setUnion(p, p + 1);
	}

	return 0;
}