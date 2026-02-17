#include <iostream>

using namespace std;

int H, W, N, M;
int a, b;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> H >> W >> N >> M;

	int st = 0;
	while (st <= H) {
		st++;
		if (st > H) break;
		a++;
		st += N;
	}
	st = 0;
	while (st <= W) {
		st++;
		if (st > W) break;
		b++;
		st += M;
	}

	cout << a * b << "\n";

	return 0;
}