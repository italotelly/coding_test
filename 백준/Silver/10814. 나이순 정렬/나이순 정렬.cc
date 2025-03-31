#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 나이순 정렬

struct age_name
{
    int x;
    string y;
    int z;
};

bool compare(age_name a, age_name b)
{
    if (a.x == b.x)
    {
        return a.z < b.z;
    }
    else
    {
        return a.x < b.x;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    age_name id[N];
    for (int i = 0; i < N; i++)
    {
        cin >> id[i].x >> id[i].y;
        id[i].z = i; // 가입한 순서
    }

    sort(id, id + N, compare);

    for (int i = 0; i < N; i++)
    {
        cout << id[i].x << " " << id[i].y << "\n";
    }

    return 0;
}