#include <iostream>
#include <algorithm>

using namespace std;

int N;

int max_a, max_b, max_c;
int min_a, min_b, min_c;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	cin >> max_a >> max_b >> max_c;

	min_a = max_a;
	min_b = max_b;
	min_c = max_c;

	for (int i = 1; i < N; i++)
	{
		int temp_max_a = 0;
		int temp_max_b = 0;
		int temp_max_c = 0;
		int temp_min_a = 0;
		int temp_min_b = 0;
		int temp_min_c = 0;

		temp_max_a += max(max_a, max_b);
		temp_max_b += max(max_a, max(max_b, max_c));
		temp_max_c += max(max_b, max_c);

		temp_min_a += min(min_a, min_b);
		temp_min_b += min(min_a, min(min_b, min_c));
		temp_min_c += min(min_b, min_c);
	
		int a, b, c;
		cin >> a >> b >> c;

		temp_max_a += a;
		temp_max_b += b;
		temp_max_c += c;

		temp_min_a += a;
		temp_min_b += b;
		temp_min_c += c;

		max_a = temp_max_a;
		max_b = temp_max_b;
		max_c = temp_max_c;

		min_a = temp_min_a;
		min_b = temp_min_b;
		min_c = temp_min_c;
	}

	cout << max(max_a, max(max_b, max_c)) << " ";
	cout << min(min_a, min(min_b, min_c)) << "\n";

	return 0;
}