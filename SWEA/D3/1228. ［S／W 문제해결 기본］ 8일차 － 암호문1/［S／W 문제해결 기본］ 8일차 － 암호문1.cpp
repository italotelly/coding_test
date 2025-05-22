#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int len_enc;
	int len_order;
	vector<int> v;

	char order;
	int x, y, s;

	for (int i = 1; i <= 10; i++) {

		cin >> len_enc;
		v.resize(len_enc, 0);

		for (int j = 0; j < len_enc; j++) {
			cin >> v[j];
		}

		cin >> len_order;
		for (int j = 0; j < len_order; j++) {
			cin >> order;
			cin >> x >> y;
			for (int k = 0; k < y; k++) {
				cin >> s;
				v.insert(v.begin() + x + k, s);
			}
		}


		// 출력
		cout << "#" << i << " ";
		for (int j = 0; j < 10; j++) {
			cout << v[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}