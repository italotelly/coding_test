#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;
int rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int a;
	for (int i = 0; i < N; i++){
		cin >> a;
		pq.push(a);
	}

	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		rst += (a + b);
		pq.push(a + b);
	}

	cout << rst << "\n";

	return 0;
}