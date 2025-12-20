#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, int> m;

int T;
int k;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> k;

		char a;
		int b;

		priority_queue<int, vector<int>, greater<>> pq2;
		priority_queue<int> pq1;
		m.clear();

		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;

			if (a == 'I') {
				pq1.push(b);
				pq2.push(b);
				m[b]++;
			}
			else {
				if (b == 1) {
					while (!pq1.empty() && m[pq1.top()] == 0) {
						pq1.pop();
					}
					if (pq1.empty()) continue;
					m[pq1.top()]--;
					pq1.pop();
				}
				else {
					while (!pq2.empty() && m[pq2.top()] == 0) {
						pq2.pop();
					}
					if (pq2.empty()) continue;
					m[pq2.top()]--;
					pq2.pop();
				}
			}
		}
		while (!pq1.empty() && m[pq1.top()] == 0) {
			pq1.pop();
		}
		while (!pq2.empty() && m[pq2.top()] == 0) {
			pq2.pop();
		}

		if (pq1.empty() && pq2.empty()) cout << "EMPTY\n";
		else {
			cout << pq1.top() << " " << pq2.top() << "\n";
		}
	}

	return 0;
}