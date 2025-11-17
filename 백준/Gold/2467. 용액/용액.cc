#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	vector<long long> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int st = 0;
	int en = N - 1;
	long long sum = 0;
	long long min_num = abs(v[st] + v[en]);
	int min_st = st;
	int min_en = en;

	while (st < en) {
		sum = v[st] + v[en];
		if (abs(min_num) > abs(sum)) {
			min_num = sum;
			min_st = st;
			min_en = en;
		}

		if (sum == 0) {
			cout << v[st] << " " << v[en] << "\n";
			return 0;
		}
		else if (sum > 0) {
			en--;
		}
		else
			st++;
	}
	cout << v[min_st] << " " << v[min_en] << "\n";

	return 0;
}