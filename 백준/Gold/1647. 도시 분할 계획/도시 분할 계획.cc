#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
	int a, b;
	int cost;
};

int N, M;
vector<edge> v;
int parent[100005];
vector<int> rst;
int result;

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

int find(int tar) {
	if (tar == parent[tar])
		return tar;

	return parent[tar] = find((parent[tar]));
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
		return;

	parent[t2] = t1;
}

void kruskal() {
	int selectCount = 0;

	for (edge sel : v) {
		int a = sel.a;
		int b = sel.b;
		int cost = sel.cost;
		if (find(a) == find(b))
			continue;
		setUnion(a, b);
		rst.push_back(cost);
		selectCount++;
		if (selectCount == N - 1)
			break;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int A, B, C;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		v.push_back({ A, B, C });
	}

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	sort(v.begin(), v.end(), compare);

	kruskal();

	sort(rst.begin(), rst.end(), greater<>());

	for (int i = 1; i < rst.size(); i++)
	{
		result += rst[i];
	}

	cout << result << "\n";
	
	return 0;
}