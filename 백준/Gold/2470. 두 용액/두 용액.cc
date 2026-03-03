#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int N;
vector<ll> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ll a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	int l = 0;
	int r = N - 1;
	int rst1, rst2;
	ll rst = 1e18;
	ll sum = 0;

	while (l < r) {
		sum = v[l] + v[r];

		if (sum == 0) {
			rst = 0;
			rst1 = v[l];
			rst2 = v[r];
			break;
		}
		if (abs(sum) < rst) {
			rst1 = v[l];
			rst2 = v[r];
			rst = abs(sum);
		}
		if (sum < 0) l++;
		else r--;
	}

	cout << rst1 << " " << rst2 << "\n";

	return 0;
}