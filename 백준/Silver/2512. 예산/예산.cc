#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int ary[100005];
int max_num;
int sum;
int rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int a = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a;

		ary[i] = a;
		sum += a;
		max_num = max(max_num, a);
	}
	cin >> M;

	if (sum <= M) {
		cout << max_num << "\n";
		return 0;
	}

	int l = 1;
	int r = max_num;

	while (l <= r) {
		int mid = (l + r) / 2;
		sum = 0;

		for (int i = 0; i < N; i++)
		{
			sum += min(ary[i], mid);
		}

		if (sum > M) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
			rst = max(rst, mid);
		}
	}

	cout << rst << "\n";

	return 0;
}