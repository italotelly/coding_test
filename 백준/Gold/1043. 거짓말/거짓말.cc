#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int parent[55];
vector<int> know;
vector<vector<int>> party(50);

int rst;

int find(int tar) {
	if (tar == parent[tar]) return tar;

	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;

	parent[t2] = t1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	int x;
	for (int i = 0; i < k; i++)
	{
		cin >> x;
		know.push_back(x);
	}

	int p, num, prev;
	for (int i = 0; i < m; i++)
	{
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			if (j >= 1) {
				prev = num;
				cin >> num;
				setUnion(prev, num);
			}
			else {
				cin >> num;
			}
			party[i].push_back(num);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int flag = 0;
		for (int j = 0; j < party[i].size(); j++)
		{
			for (int k = 0; k < know.size(); k++)
			{
				if (find(party[i][j]) == find(know[k])) {
					flag = 1;
					break;
				}
			}
		}
		if (!flag) rst++;
	}

	cout << rst << "\n";

	return 0;
}