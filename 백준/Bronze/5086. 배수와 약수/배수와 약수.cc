#include <iostream>

using namespace std;

// 배수와 약수
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // factor 약수, multiple 배수, neither 둘다 아니다

    int a, b;

    while (true)
    {
        cin >> a >> b;
        if ((a == 0) && (b == 0))
        {
            break;
        }
        // 첫 번째 숫자가 두 번째 숫자의 약수이다.
        if (b % a == 0)
        {
            cout << "factor\n";
        }
        // 첫 번째 숫자가 두 번째 숫자의 배수이다.
        else if (a % b == 0)
        {
            cout << "multiple\n";
        }
        // 둘다 아니다.
        else
        {
            cout << "neither\n";
        }
    }

    return 0; // 정상종료
}