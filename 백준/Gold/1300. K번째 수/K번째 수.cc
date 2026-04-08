#include <iostream>
#include <algorithm>

using namespace std;

int N, k;
int rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> k;

	int l = 1;
	int r = k;

	while (l <= r) {
		int mid = (l + r) / 2;

		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			sum += min(N, mid / i);
		}
		
		if (sum >= k) {
			rst = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << rst << "\n";

	return 0;
}