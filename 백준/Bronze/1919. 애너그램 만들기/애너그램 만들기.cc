#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2;

int bucket1[26];
int bucket2[26];

int rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++)
	{
		bucket1[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		bucket2[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (bucket1[i] > bucket2[i]) rst += (bucket1[i] - bucket2[i]);
		else if (bucket1[i] < bucket2[i]) rst += (bucket2[i] - bucket1[i]);
	}

	cout << rst << "\n";

	return 0;
}