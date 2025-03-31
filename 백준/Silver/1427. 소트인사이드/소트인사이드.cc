#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 소트인사이드

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string N;
    vector<int> a;

    cin >> N;

    for (int i = 0; i < N.size(); i++)
    {
        a.push_back(int(N[i]) - 48);
    }

    sort(a.begin(), a.end(), greater<int>());

    for (int i = 0; i < N.size(); i++)
    {
        cout << a[i];
    }
}