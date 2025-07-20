#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	
	int N;
	cin >> N;

	vector<int> v(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cout << v[N / 2];

	return 0;
}