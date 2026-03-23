#include <iostream>

using namespace std;
using ll = long long;

int T;
ll N, K;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N >> K;

		if (K >= 61) {
			cout << "0\n";
			continue;
		}

		ll p = 1ll << K;
		if (p > N) {
			cout << "0\n";
			continue;
		}
		cout << ((N / p) + 1) / 2 << "\n";
	}

	return 0;
}