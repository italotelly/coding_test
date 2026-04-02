#include <iostream>
#include <algorithm>

using namespace std;

int T;
int n, m;
int k, rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> n >> m;
		int a = min(n, m);
		int b = max(n, m);

		if (a == b) {
			k = a;
			rst = 3;
		}
		else if (b <= 2 * a) {
			k = a;
			rst = 7;
		}
		else {
			k = a + 1;
			if (a == 1) {
				rst = 2 * b - 1;
			}
			else
			{
				rst = 7 + 2 * max(0, b - 2 * a - 2);
			}
		}
		cout << k << " " << rst << "\n";
	}

	return 0;
}