#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 진법 변환2
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 10 진법 수 N, 이 수를 B 진법으로 바꿔 출력하는 프로그램
    int B;
    int N;

    cin >> N >> B;

    // 아스키 코드
    // 대문자 A 65. 소문자 a 97, 0은 48
    vector<char> sum;
    int quotient = 0;
    int remainder = 0;
    while ((N / B) != 0)
    {
        remainder = N % B;
        quotient = N / B;
        if (remainder >= 0 && remainder <= 9)
        {
            sum.push_back(remainder + 48);
        }
        else
        {
            sum.push_back(remainder + 55);
        }
        N = quotient;
    }
    // 마지막 값 삽입
    remainder = N % B;
    quotient = N / B;
    if (remainder >= 0 && remainder <= 9)
    {
        sum.push_back(remainder + 48);
    }
    else
    {
        sum.push_back(remainder + 55);
    }

    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[sum.size() - i - 1];
    }

    return 0; // 정상종료
}