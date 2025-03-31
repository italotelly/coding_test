#include <iostream>
#include <string>

using namespace std;

// 숫자의 합
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N < 1 || N > 100)
    {
        return 1; // 비정상 종료
    }

    string S;
    cin >> S;

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += ((int)(S[i]) - '0');
    }

    cout << sum;

    return 0; // 정상종료
}