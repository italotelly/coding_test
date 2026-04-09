#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[55];
int B[55];
int rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + N, greater<int>());

	for (int i = 0; i < N; i++)
	{
		rst += (A[i] * B[i]);
	}
	cout << rst << "\n";

	return 0;
}