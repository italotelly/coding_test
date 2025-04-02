#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 수열
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    vector<int> v;

    cin >> N >> K;
    int num;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    int sum = 0;
    int max_num = numeric_limits<int>::min();

    for (int i = 0; i < K; i++)
    {
        sum += v[i];
    }
    max_num = sum;

    for (int i = 0; i < N - K; i++)
    {
        sum -= v[i];
        sum += v[K + i];
        max_num = max(max_num, sum);
    }

    cout << max_num;

    return 0;
}
