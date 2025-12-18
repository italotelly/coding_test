#include <iostream>

using namespace std;

int A, B, C;
int sum;
int arr[10];

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C;
	sum = A * B * C;

	int temp_sum = sum;
	while (temp_sum > 0) {
		arr[temp_sum % 10]++;
		temp_sum /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}