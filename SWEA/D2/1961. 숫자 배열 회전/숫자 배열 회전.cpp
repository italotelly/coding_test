#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	vector<vector<int>> v;

	for (int i = 1; i <= T; i++) {

		int N;
		cin >> N;

		v.assign(N, vector<int>(N, 0));

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> v[j][k];
			}
		}

		cout << "#" << i << "\n";

		// 90 180 270
		for (int t = 0; t < N; t++) {

			// 90
			int k = t;
			for (int j = N - 1; j >= 0; j--) {
				cout << v[j][k];
			}
			cout << " ";

			// 180
			int j = N - t - 1;
			for (int k = N - 1; k >= 0; k--) {
				cout << v[j][k];
			}
			cout << " ";

			// 270
			k = N - t - 1;
			for (int j = 0; j < N; j++) {
				cout << v[j][k];
			}
			cout << "\n";
		}
		
	}



	return 0;
}