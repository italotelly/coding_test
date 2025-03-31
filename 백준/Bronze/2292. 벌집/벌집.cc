#include <iostream>

using namespace std;

// 벌집
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    int count = 1;
    int distance = 1;

    cin >> N;

    while (N > count)
    {
        count += 6 * distance;
        distance++;
    }

    cout << distance;

    return 0; // 정상종료
}