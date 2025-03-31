#include <iostream>
#include <map>
#include <iterator>
#include <cmath>

using namespace std;

// 통계학
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    map<int, int> m;
    map<int, int>::iterator iter;

    int num;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        sum += num;
        m[num]++;
    }

    // 산술평균
    double mean = round((double)sum / (double)N);
    if (mean == 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << mean << "\n";
    }
    // 중앙값
    int median = (N + 1) / 2;
    int count = 0;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        count += iter->second;
        if (count >= median)
        {
            median = iter->first;
            break;
        }
    }
    cout << median << "\n";
    // 최빈값
    int often = 0;
    int often_num = 0;
    int least = 0;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        if (often < iter->second)
        {
            often = iter->second;
            often_num = iter->first;
            least = 0;
        }
        else if (often == iter->second && least == 0)
        {
            often_num = iter->first;
            least = 1;
        }
    }
    cout << often_num << "\n";
    // 범위
    cout << prev(m.end())->first - m.begin()->first;

    return 0; // 정상종료
}