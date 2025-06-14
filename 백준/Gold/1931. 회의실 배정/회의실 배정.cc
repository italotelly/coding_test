#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> meetings; // {end, start}

	for (int i = 0; i < N; ++i) {
		int start, end;
		cin >> start >> end;
		meetings.push_back({ end, start }); // 종료 시간을 기준으로 정렬
	}

	sort(meetings.begin(), meetings.end()); // end 오름차순, 같으면 start 오름차순

	int count = 0;
	int last_end_time = 0;

	for (auto[end, start] : meetings) {
		if (start >= last_end_time) {
			last_end_time = end;
			count++;
		}
	}

	cout << count << '\n';
	return 0;
}
