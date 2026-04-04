#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, S;

int x[1000005];
int h[1000005];
bool visited[1000005];
vector<int> rst;

void bfs() {
	queue<int> q;
	q.push(S);
	visited[S] = true;
	rst.push_back(S);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int temp1 = now;
		while (temp1 > 1 && (x[temp1 - 1] >= x[now] - h[now])) {
			if (!visited[temp1 - 1]) {
				rst.push_back(temp1 - 1);
				q.push(temp1 - 1);
				visited[temp1 - 1] = true;
			}
			temp1--;
		}
		int temp2 = now;
		while (temp2 < N && (x[temp2 + 1] <= x[now] + h[now])) {
			if (!visited[temp2 + 1]) {
				rst.push_back(temp2 + 1);
				q.push(temp2 + 1);
				visited[temp2 + 1] = true;
			}
			temp2++;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	int a;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		x[i] = a;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		h[i] = a;
	}

	bfs();

	sort(rst.begin(), rst.end());
	for (int i = 0; i < rst.size(); i++)
	{
		cout << rst[i] << " ";
	}
	cout << "\n";

	return 0;
}