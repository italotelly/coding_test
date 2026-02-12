#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
bool ori1[100005];
bool ori2[100005];
bool chan[100005];
int rst = -1;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	string s;
	cin >> s;
	for (int i = 0; i < N; i++)
	{
		ori1[i] = s[i] - '0';
		ori2[i] = s[i] - '0';
	}

	cin >> s;
	for (int i = 0; i < N; i++)
	{
		chan[i] = s[i] - '0';
	}

	// 0번 전구를 안켰을 때
	int cnt1 = 0;
	bool flag1 = 0;
	for (int i = 1; i < N - 1; i++)
	{
		if (ori1[i - 1] != chan[i - 1]) {
			ori1[i - 1] = !ori1[i - 1];
			ori1[i] = !ori1[i];
			ori1[i + 1] = !ori1[i + 1];
			cnt1++;
		}
	}
	if (ori1[N - 2] != chan[N - 2]) {
		ori1[N - 2] = !ori1[N - 2];
		ori1[N - 1] = !ori1[N - 1];
		cnt1++;
	}
	if (ori1[N - 1] == chan[N - 1]) flag1 = true;

	// 0번 전구를 켰을 때
	int cnt2 = 1;
	bool flag2 = 0;
	ori2[0] = !ori2[0];
	ori2[1] = !ori2[1];
	for (int i = 1; i < N - 1; i++)
	{
		if (ori2[i - 1] != chan[i - 1]) {
			ori2[i - 1] = !ori2[i - 1];
			ori2[i] = !ori2[i];
			ori2[i + 1] = !ori2[i + 1];
			cnt2++;
		}
	}
	if (ori2[N - 2] != chan[N - 2]) {
		ori2[N - 2] = !ori2[N - 2];
		ori2[N - 1] = !ori2[N - 1];
		cnt2++;
	}
	if (ori2[N - 1] == chan[N - 1]) flag2 = true;

	if (flag1 && flag2) {
		rst = min(cnt1, cnt2);
	}
	else if (flag1) {
		rst = cnt1;
	}
	else if (flag2) {
		rst = cnt2;
	}
	cout << rst << "\n";

	return 0;
}