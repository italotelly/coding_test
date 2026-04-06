#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

priority_queue<int> plus_pq;
priority_queue<int> minus_pq;

int N, M;
int rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (N == 1) {
			cout << abs(a) << "\n";
			return 0;
		}
		if (a > 0) plus_pq.push(a);
		else minus_pq.push(-a);
	}

	// 양수만 있을 때
	if (minus_pq.empty()) {
		rst += plus_pq.top();
		int cnt = M;
		while (!plus_pq.empty() && cnt--) plus_pq.pop();
		while (!plus_pq.empty()) {
			cnt = M;
			rst += (plus_pq.top() * 2);
			while (!plus_pq.empty() && cnt--) plus_pq.pop();
		}
		cout << rst << "\n";
		return 0;
	}
	// 음수만 있을 때
	else if (plus_pq.empty()) {
		rst += minus_pq.top();
		int cnt = M;
		while (!minus_pq.empty() && cnt--) minus_pq.pop();
		while (!minus_pq.empty()) {
			cnt = M;
			rst += (minus_pq.top() * 2);
			while (!minus_pq.empty() && cnt--) minus_pq.pop();
		}
		cout << rst << "\n";
		return 0;
	}
	// 양 음수 다 있을 때
	if (plus_pq.top() > minus_pq.top()) {
		rst += plus_pq.top();
		int cnt = M;
		while (!plus_pq.empty() && cnt--) plus_pq.pop();
		while (!plus_pq.empty()) {
			cnt = M;
			rst += (plus_pq.top() * 2);
			while (!plus_pq.empty() && cnt--) plus_pq.pop();
		}
		while (!minus_pq.empty()) {
			cnt = M;
			rst += (minus_pq.top() * 2);
			while (!minus_pq.empty() && cnt--) minus_pq.pop();
		}
		cout << rst << "\n";
	}
	else {
		rst += minus_pq.top();
		int cnt = M;
		while (!minus_pq.empty() && cnt--) minus_pq.pop();
		while (!plus_pq.empty()) {
			cnt = M;
			rst += (plus_pq.top() * 2);
			while (!plus_pq.empty() && cnt--) plus_pq.pop();
		}
		while (!minus_pq.empty()) {
			cnt = M;
			rst += (minus_pq.top() * 2);
			while (!minus_pq.empty() && cnt--) minus_pq.pop();
		}
		cout << rst << "\n";
	}

	return 0;
}