#include <iostream>

using namespace std;

int main(void)
{
	int N, N1;
	int count = 0;
	while (cin >> N)
	{
		N1 = N;
		if ((N / 10 + N % 10) / 10 >= 1) {
			N = (N % 10 * 10) + (N / 10 + N % 10)%10;
		}
		else N = (N % 10 * 10) + (N / 10 + N % 10);
		count = 1;
		while (N1 != N) {
			if ((N / 10 + N % 10) / 10 >= 1) {
				N = (N % 10 * 10) + (N / 10 + N % 10) % 10;
			}
			else N = (N % 10 * 10) + (N / 10 + N % 10);
			count++;
		}
		cout << count << endl;
	}
}
