#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct favorite
{
	int num;
	int a, b, c, d;
};

struct info
{
	int fav_num;
	int empty_num;
	int y, x;
};

int N;
int MAP[25][25];
vector<favorite> students;
vector<info> v;

int rst;

bool inRange(int y, int x) {
	if (y < 1 || x < 1 || y > N || x > N) {
		return false;
	}
	return true;
}

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool compare(info a, info b) {
	if (a.fav_num == b.fav_num) {
		if (a.empty_num == b.empty_num) {
			if (a.y == b.y) {
				return a.x < b.x;
			}
			return a.y < b.y;
		}
		return a.empty_num > b.empty_num;
	}
	return a.fav_num > b.fav_num;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		students.push_back({ a, b, c, d, e });
	}

	for (int i = 0; i < N * N; i++)
	{
		v.clear();
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (MAP[j][k] == 0) {
					// 좋아하는 학생 수 chk
					// 비어있는 칸 chk
					int num_a = 0;
					int num_b = 0;
					for (int l = 0; l < 4; l++)
					{
						int ny = j + dy[l];
						int nx = k + dx[l];

						if (!inRange(ny, nx)) continue;


						if (MAP[ny][nx] == 0) {
							num_b++;
						}
						else {
							if (MAP[ny][nx] == students[i].a) {
								num_a++;
							}
							else if (MAP[ny][nx] == students[i].b) {
								num_a++;
							}
							else if (MAP[ny][nx] == students[i].c) {
								num_a++;
							}
							else if (MAP[ny][nx] == students[i].d) {
								num_a++;
							}
						}
					}
					v.push_back({ num_a, num_b, j, k });
				}
			}
		}
		sort(v.begin(), v.end(), compare);
		MAP[v[0].y][v[0].x] = students[i].num;
	}

	for (int i = 0; i < N * N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (MAP[j][k] == students[i].num) {
					int sum = 0;
					for (int l = 0; l < 4; l++)
					{
						int ny = j + dy[l];
						int nx = k + dx[l];

						if (!inRange(ny, nx)) continue;

						if (MAP[ny][nx] == students[i].a) {
							sum++;
						}
						else if (MAP[ny][nx] == students[i].b) {
							sum++;
						}
						else if (MAP[ny][nx] == students[i].c) {
							sum++;
						}
						else if (MAP[ny][nx] == students[i].d) {
							sum++;
						}
					}
					if (sum != 0) {
						rst += pow(10, sum - 1);
					}
				}
			}
		}
	}

	cout << rst << "\n";

	return 0;
}