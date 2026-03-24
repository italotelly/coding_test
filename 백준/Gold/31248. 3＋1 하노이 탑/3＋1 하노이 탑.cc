#include <iostream>
#include <string>

using namespace std;

int N;
int cnt = 0;
string rst;

void move(char from, char to) {
	rst += from;
	rst += ' ';
	rst += to;
	rst += '\n';
	cnt++;
}

void hanoi3(int n, char from, char to, char aux) {
	if (n == 0) return;
	hanoi3(n - 1, from, aux, to);
	move(from, to);
	hanoi3(n - 1, aux, to, from);
}

void hanoi4(int n, char from, char to, char rest1, char rest2) {
	if (n == 0) return;

	if (n == 1) {
		move(from, to);
		return;
	}

	if (n == 2) {
		move(from, rest2);
		move(from, to);
		move(rest2, to);
		return;
	}

	hanoi3(n - 2, from, rest1, rest2);

	move(from, rest2);
	move(from, to);
	move(rest2, to);

	hanoi4(n - 2, rest1, to, from, rest2);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	hanoi4(N, 'A', 'D', 'B', 'C');

	cout << cnt << "\n";
	cout << rst;

	return 0;
}