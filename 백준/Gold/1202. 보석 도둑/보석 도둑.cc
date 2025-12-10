#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> jewel[300001];
long long bag[300001];
long long rst;
int N, K;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> jewel[i].first >> jewel[i].second;
	}

	for (int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}

	sort(jewel, jewel + N);
	sort(bag, bag + K);

	priority_queue<int> pq;
	int j = 0;

	for (int i = 0; i < K; i++)
	{
		while (j < N && jewel[j].first <= bag[i]) {
			pq.push(jewel[j].second);
			j++;
		}

		if (!pq.empty()) {
			rst += pq.top();
			pq.pop();
		}
	}

	cout << rst << "\n";

	return 0;
}