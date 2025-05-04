#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [S/W 문제해결 기본] 1일차 - View
int main()
{
    for (int i = 0; i < 10; i++)
    {
        int N;
        cin >> N;
        int sum = 0;
        vector<int> v(N);
        for (int j = 0; j < N; j++)
        {
            cin >> v[j];
        }
        int j = 2;
        while (j < N - 2)
        {
            if (v[j] > 0)
            {
                int max1 = max(v[j - 1], v[j - 2]);
                int max2 = max(v[j + 1], v[j + 2]);
                int max3 = max(max1, max2);
                if (v[j] > max3)
                {
                    sum = sum + v[j] - max3;
                }
            }
            j++;
        }
        cout << "#" << i + 1 << " " << sum << "\n";
    }
    return 0;
}