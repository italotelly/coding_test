#include <iostream>

using namespace std;

// 알고리즘 수업 - 알고리즘의 수행 시간 6

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long n;
    cin >> n;

    cout << n * (n - 1) * (n - 2) / 6 << "\n3";
    return 0; // 정상종료
}