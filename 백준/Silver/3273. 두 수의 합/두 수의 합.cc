#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
int rst;

vector<int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	if (v.size() == 1) {
		cout << rst << "\n";
		return 0;
	}

	sort(v.begin(), v.end());

	int st = 0;
	int en = v.size() - 1;

	cin >> x;

	while (st < en) {
		if (v[st] + v[en] == x) {
			rst++;
			st++;
			en--;
		}
		else if (v[st] + v[en] < x) st++;
		else en--;
	}

	cout << rst << "\n";

	return 0;
}