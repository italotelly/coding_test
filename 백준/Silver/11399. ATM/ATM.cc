#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ATM
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += v[i] * (N - i);
    }
    cout << sum;

    return 0;
}