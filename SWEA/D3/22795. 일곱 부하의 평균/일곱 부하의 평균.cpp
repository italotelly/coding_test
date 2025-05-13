#include <iostream>
#include <algorithm>

using namespace std;

// 일곱 부하의 평균
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int sum = 0;
        int height;
        int max_h = 0;
        for (int i = 0; i < 6; i++)
        {
            cin >> height;
            sum += height;
            max_h = max(max_h, height);
        }
        while (true)
        {
            max_h++;
            if ((sum + max_h) % 7 == 0)
            {
                break;
            }
        }
        cout << max_h << "\n";
    }

    return 0;
}