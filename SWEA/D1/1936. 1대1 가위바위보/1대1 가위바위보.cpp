#include <iostream>

using namespace std;

int main() {
	
	int A, B;

	cin >> A >> B;

	if (A == 1 && B == 3) {
		cout << "A";
	}
	else if (A == 3 && B == 1) {
		cout << "B";
	}
	else if (A < B) {
		cout << "B";
	}
	else {
		cout << "A";
	}

	return 0;
}