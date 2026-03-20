#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int a, b, c;
	int n;
};
int compare(info x, info y) {
	if (x.a == y.a) {
		if (x.b == y.b) {
			return x.c > y.c;
		}
		return x.b > y.b;
	}
	return x.a > y.a;
}

int N, K;
vector<info> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ b, c, d, a });
	}

	sort(v.begin(), v.end(), compare);

	if (N == 1) {
		cout << "1\n";
		return 0;
	}

	int st = 1;
	int rank = 1;
	int same_rank = 1;

	while (v[st].n != K) {
		if (v[st - 1].a == v[st].a && v[st - 1].b == v[st].b && v[st - 1].c == v[st].c) {
			same_rank++;
		}
		else {
			rank += same_rank;
			same_rank = 1;
		}
		st++;
	}
	// 이전꺼랑 비교
	if (v[st - 1].a == v[st].a && v[st - 1].b == v[st].b && v[st - 1].c == v[st].c) {
		cout << rank << "\n";
	}
	else {
		rank += same_rank;
		cout << rank << "\n";
	}

	return 0;
}