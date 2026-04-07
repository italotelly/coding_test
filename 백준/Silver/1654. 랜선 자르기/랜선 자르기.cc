#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
int max_num;
int ary[10005];
long long rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> N;

	int a;
	for (int i = 0; i < K; i++)
	{
		cin >> a;
		ary[i] = a;
		max_num = max(max_num, a);
	}

	long long l = 1;
	long long r = max_num;

	while (l <= r) {
		long long mid = (l + r) / 2;

		int cnt = 0;
		for (int i = 0; i < K; i++)
		{
			cnt += (ary[i] / mid);
		}
		if (cnt < N) {
			r = mid - 1;
		}
		else {
			rst = max(rst, mid);
			l = mid + 1;
		}
	}

	cout << rst << "\n";

	return 0;
}