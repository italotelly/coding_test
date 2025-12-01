#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct pos
{
	int water;
	int cloud;
};

int N, M;
pos MAP[55][55];
int d[105];
int s[105];

vector<pair<int, int>> v;

int rst;

int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

bool inRange(int y, int x) {
	if (y < 1 || x < 1 || y > N || x > N) {
		return false;
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> MAP[i][j].water;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> d[i] >> s[i];
	}

	for (int i = 0; i < M; i++)
	{

		/*for (int o = 1; o <= N; o++)
		{
			for (int p = 1; p <= N; p++)
			{
				cout << MAP[o][p].water << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

		if (i == 0) {
			// 초기 구름 생성
			v.push_back({ N, 1 });
			v.push_back({ N, 2 });
			v.push_back({ N - 1, 1 });
			v.push_back({ N - 1, 2 });
		}
		// 이동(vector y, x 값 최신화) 후 비 1씩 내리기
		for (int j = 0; j < v.size(); j++)
		{
			int ny = v[j].first + dy[d[i]] * s[i];
			int nx = v[j].second + dx[d[i]] * s[i];

			if (ny <= 0) {
				ny = N - (abs(ny) % N);
			}
			else if (ny > N) {
				ny = ny % N;
				if (ny == 0) {
					ny = N;
				}
			}
			if (nx <= 0) {
				nx = N - (abs(nx) % N);
			}
			else if (nx > N) {
				nx = nx % N;
				if (nx == 0) {
					nx = N;
				}
			}
			v[j].first = ny;
			v[j].second = nx;
			MAP[ny][nx].water++;
			MAP[ny][nx].cloud = 1;
		}
		// 물복사 마법 시전
		for (int j = 0; j < v.size(); j++)
		{
			int sum = 0;
			for (int k = 2; k <= 8; k += 2)
			{
				int ny = v[j].first + dy[k];
				int nx = v[j].second + dx[k];

				if (!inRange(ny, nx)) continue;

				if (MAP[ny][nx].water > 0) {
					sum++;
				}
			}
			MAP[v[j].first][v[j].second].water += sum;
		}
		v.clear();
		for (int a = 1; a <= N; a++)
		{
			for (int b = 1; b <= N; b++)
			{
				// 구름이 사라진 칸
				if (MAP[a][b].cloud == 1) {
					MAP[a][b].cloud = 0;
				}
				// 구름 생성
				else if (MAP[a][b].water >= 2) {
					v.push_back({ a, b });
					MAP[a][b].water -= 2;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			rst += MAP[i][j].water;
		}
	}

	cout << rst << "\n";

	return 0;
}