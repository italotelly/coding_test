#include <iostream>

using namespace std;

// 한수
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 1000보다 작거나 같은 한수 전부 체크
	int ary[1000] = { 0 };
	int chk[1000] = {0};

	int num = 0;

	cin >> num;

	for (int i = 0; i < 1000; i++) {
		ary[i] = i + 1;
	}

	for (int i = 0; i < 1000; i++) {
		if (i < 99) {
			chk[i] = 1;
		}
		else {
			if (((ary[i] / 100) - (ary[i] % 100 / 10)) == ((ary[i] % 100 / 10) - (ary[i] % 10))) {
				chk[i] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < num; i++) {
		if (chk[i]) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}