#include <iostream>

using namespace std;

int main() {
	
	int N;
	cin >> N;

	int sum = 0;

	while (N>0) {
		sum += (N % 10);
		N /= 10;
	}

	cout << sum;

	return 0;
}