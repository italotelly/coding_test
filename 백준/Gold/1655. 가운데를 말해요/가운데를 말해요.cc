#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <queue>

using namespace std;

int N;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<>> min_heap;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;

		max_heap.push(x);

		if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
			int a = max_heap.top();
			max_heap.pop();
			int b = min_heap.top();
			min_heap.pop();

			max_heap.push(b);
			min_heap.push(a);
		}

		if (max_heap.size()== min_heap.size() + 2) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		}


		cout << max_heap.top() << "\n";
	}

	return 0;
}