#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A, lis;
int N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		A.push_back(t);
	}

	for (int i = 0; i < A.size(); i++)
	{
		auto it = lower_bound(lis.begin(), lis.end(), A[i]);

		if (it == lis.end()) lis.push_back(A[i]);
		else *it = A[i];
	}

	cout << lis.size();

	return 0;
}