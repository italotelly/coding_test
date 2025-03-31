#include <iostream>
#include <algorithm>

using namespace std;

// 좌표 정렬하기

struct coordinate
{
    int x;
    int y;
};

bool compare(coordinate a, coordinate b)
{
    if (a.x == b.x)
    {                     // x좌표가 같으면
        return a.y < b.y; // b의 y좌표가 더 크도록 정렬
    }
    else
    {                     // x좌표가 다르면
        return a.x < b.x; // b의 x좌표가 더 크도록 정렬 (=x좌표가 증가하는 순으로)
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    coordinate arr[100001];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr + N, compare);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }

    return 0;
}