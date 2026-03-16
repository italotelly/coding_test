#include <iostream>
#include <string>

using namespace std;

int N;
int pos1;
int pos2;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == "KBS1") {
			pos1 = i;
		}
		else if (s == "KBS2") {
			pos2 = i;
		}
	}

	if (N == 2) {
		cout << "3";
	}
	else if (pos1 < pos2) {
		for (int i = 0; i < pos1; i++)
		{
			cout << "1";
		}
		for (int i = 0; i < pos1; i++)
		{
			cout << "4";
		}
		for (int i = 0; i < pos2; i++)
		{
			cout << "1";
		}
		for (int i = 0; i < pos2 - 1; i++)
		{
			cout << "4";
		}
	}
	else {
		for (int i = 0; i < pos1; i++)
		{
			cout << "1";
		}
		for (int i = 0; i < pos1; i++)
		{
			cout << "4";
		}
		for (int i = 0; i < pos2 + 1; i++)
		{
			cout << "1";
		}
		for (int i = 0; i < pos2; i++)
		{
			cout << "4";
		}
	}

	return 0;
}