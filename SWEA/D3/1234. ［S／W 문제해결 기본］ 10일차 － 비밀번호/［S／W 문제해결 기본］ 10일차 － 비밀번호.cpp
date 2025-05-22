#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int len;

	for (int i = 1; i <= 10; i++) {
		vector<char> v;

		cin >> len;

		v.resize(len, 0);

		for (int j = 0; j < len; j++) {
			cin >> v[j];
		}

		for (int j = 0; j < len; j++) {
			while (v[j] == v[j + 1]) {
				v.erase(v.begin()+j, v.begin() + j + 2);
				len -= 2;
				j--;
			}
		}

		cout << "#" << i << " ";
		for (int j = 0; j < len; j++) {
			cout << v[j];
		}
		cout << "\n";
	}


	return 0;
}