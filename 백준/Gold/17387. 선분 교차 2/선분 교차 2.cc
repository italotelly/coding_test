#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll v = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (v > 0) return 1;
	if (v < 0) return -1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	ll ab1 = ccw(x1, y1, x2, y2, x3, y3);
	ll ab2 = ccw(x1, y1, x2, y2, x4, y4);
	ll cd1 = ccw(x3, y3, x4, y4, x1, y1);
	ll cd2 = ccw(x3, y3, x4, y4, x2, y2);

	if (ab1 * ab2 == 0 && cd1 * cd2 == 0) {
		if (min(x1, x2) <= max(x3, x4) &&
			min(x3, x4) <= max(x1, x2) &&
			min(y1, y2) <= max(y3, y4) &&
			min(y3, y4) <= max(y1, y2))
			cout << 1;
		else
			cout << 0;
	}
	else {
		cout << (ab1 * ab2 <= 0 && cd1 * cd2 <= 0);
	}
}
