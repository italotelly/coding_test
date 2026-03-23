#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> v;
int cnt;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (a >= b) cnt++;
		else v.push_back(b - a);
	}

	if (cnt >= K) {
		cout << "0\n";
		return 0;
	}
	sort(v.begin(), v.end());

	cout << v[K - cnt - 1] << "\n";

	return 0;
}