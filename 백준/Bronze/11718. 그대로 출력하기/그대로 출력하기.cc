#include <iostream>
#include <string>

using namespace std;

// 그대로 출력하기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string S;

    for (int i = 0; i < 100; i++)
    {
        getline(cin, S);
        if (S == "")
        {
            break;
        }
        cout << S << "\n";
    }
    return 0; // 정상종료
}