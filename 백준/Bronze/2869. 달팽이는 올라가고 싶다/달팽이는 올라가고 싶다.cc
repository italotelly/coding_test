#include <iostream>

using namespace std;

// 달팽이는 올라가고 싶다
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B, V;

    cin >> A >> B >> V;

    int day = 0;
    int formal_day = 0;
    int height = 0;
    int oneday_height = 0;
    oneday_height = A - B;
    // formal한 day 계산
    formal_day = V / oneday_height;
    if ((V % oneday_height) > 0)
    {
        formal_day++;
    }
    height = formal_day * oneday_height;
    day = formal_day;

    // 전날 주간이 V보다 크다면 day--
    while ((height - (oneday_height - B)) >= V)
    {
        height = height - (oneday_height);
        day--;
    }

    cout << day;

    return 0; // 정상종료
}