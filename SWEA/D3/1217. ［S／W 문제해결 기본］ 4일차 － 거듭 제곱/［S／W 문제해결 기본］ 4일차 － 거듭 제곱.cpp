#include<iostream>

using namespace std;

int pow_user(int &n, int n1, int m) {
	if (m == 1) {
		return n;
	}
	pow_user(n, n1, m - 1);
	n = n * n1;
	return n;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int TC;
	
	int N, M;
	int calc;

	for (int i = 1; i <= 10; i++) {
		
		cin >> TC >> N >> M;
		calc = pow_user(N, N, M);

		// 출력
		cout << "#" << i << " " << calc << "\n";
	}

	return 0;
}