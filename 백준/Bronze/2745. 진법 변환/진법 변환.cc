#include <iostream>
#include <cmath>

using namespace std;

// 진법 변환
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // B 진법 수 N, 이 수를 10 진법으로 바꿔 출력하는 프로그램
    int B;
    string N;

    cin >> N >> B;

    // 아스키 코드
    // 대문자 A 65. 소문자 a 97, 0은 48
    int sum = 0;
    for (int i = 0; i < (N.size()); i++)
    {
        if ((N[i] >= '0') && (N[i] <= '9'))
        {
            sum += ((N[i] - 48) * pow(B, N.size() - i - 1));
        }
        else
        {
            sum += ((N[i] - 55) * pow(B, N.size() - i - 1));
        }
    }

    cout << sum;

    return 0; // 정상종료
}