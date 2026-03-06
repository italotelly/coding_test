#include <iostream>
#include <queue>

using namespace std;

int N, L;
int arr[5000005];
deque<pair<int, int>> dq;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (!dq.empty()) {
			if (dq.front().second < i - L + 1) dq.pop_front();
		}
		while (!dq.empty() && dq.back().first > arr[i]) dq.pop_back();
		dq.push_back({ arr[i], i });
		cout << dq.front().first << " ";
	}

	return 0;
}