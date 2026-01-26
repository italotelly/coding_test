#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
vector<int> v;
vector<ll> tree;
vector<pair<int, int>> temp_v;
vector<int> rank_list;
ll rst;

void update(int idx, int s, int e, int pos, int val) {
	if (s == e) {
		tree[idx] = val;
		return;
	}
	int mid = (s + e) / 2;
	if(pos <= mid) update(idx * 2, s, mid, pos, val);
	else update(idx * 2 + 1, mid + 1, e, pos, val);

	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll get(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 0;
	if (ts <= s && e <= te) return tree[idx];

	int mid = (s + e) / 2;
	ll a = get(idx * 2, s, mid, ts, te);
	ll b = get(idx * 2 + 1, mid + 1, e, ts, te);

	return a + b;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	v.resize(N + 1);
	temp_v.resize(N + 1);
	rank_list.resize(N + 1);
	tree.resize(N * 4 + 5);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
		temp_v[i].first = v[i];
		temp_v[i].second = i;
	}
	sort(temp_v.begin(), temp_v.end());

	for (int i = 1; i <= N; i++)
	{
		rank_list[temp_v[i].second] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		if (rank_list[i] != N) rst += get(1, 1, N, rank_list[i] + 1, N);
		update(1, 1, N, rank_list[i], 1);
	}
	cout << rst << "\n";
	return 0;
}