#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int ary[100005];
int tree[400005];

void init_seg(int idx, int s, int e) {
	if (s == e) {
		tree[idx] = s;
		return;
	}
	int mid = (s + e) / 2;
	init_seg(idx * 2, s, mid);
	init_seg(idx * 2 + 1, mid + 1, e);

	if (ary[tree[idx * 2]] <= ary[tree[idx * 2 + 1]]) {
		tree[idx] = tree[idx * 2];
	}
	else tree[idx] = tree[idx * 2 + 1];
}

void update_seg(int idx, int s, int e, int pos, int val) {
	if (s == e) {
		ary[s] = val;
		return;
	}
	int mid = (s + e) / 2;
	if(pos <= mid) update_seg(idx * 2, s, mid, pos, val);
	else update_seg(idx * 2 + 1, mid + 1, e, pos, val);

	if (ary[tree[idx * 2]] <= ary[tree[idx * 2 + 1]]) {
		tree[idx] = tree[idx * 2];
	}
	else tree[idx] = tree[idx * 2 + 1];
}

int get_seg(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 0;
	if (ts <= s && e <= te) {
		return tree[idx];
	}
	int mid = (s + e) / 2;
	int a = get_seg(idx * 2, s, mid, ts, te);
	int b = get_seg(idx * 2 + 1, mid + 1, e, ts, te);

	if (ary[a] <= ary[b]) return a;
	else return b;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> ary[i];
	}
	init_seg(1, 1, N);
	ary[0] = 21e8;

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update_seg(1, 1, N, b, c);
		}
		else if (a == 2) {
			cout << get_seg(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}