#include <iostream>

using namespace std;

int T, N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;


	while (T--) {
		cin >> N;
		int a = N + 1;
		int b = N % 100;

		if (a % b == 0) cout << "Good\n";
		else cout << "Bye\n";
	}

	return 0;
}