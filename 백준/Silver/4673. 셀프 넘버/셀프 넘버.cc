#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ary[10000] = {0};
	int ary_chk[10000] = { 0 };

	for (int i = 0; i < 10000; i++) {
		ary[i] = i + 1;
		ary_chk[i] = i + 1;
	}

	int sum = 0;
	int temp;

	for (int i = 0; i < 10000; i++) {
			// ary[i] 자리수 파악
			int cnt = 0;
			temp = ary[i];
			while (temp) {
				cnt++;
				temp /= 10;
			}

			temp = ary[i];
			sum = ary[i];
			while (cnt--) {
				sum += (temp % 10);
				temp /= 10;
			}
			if (sum <= 10000) {
				ary_chk[sum - 1] = 0;
			}
	}

	for (int i = 0; i < 10000; i++) {
		if (ary_chk[i] != 0) {
			cout << ary[i] << "\n";
		}
	}
	return 0;
}