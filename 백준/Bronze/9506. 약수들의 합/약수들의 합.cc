#include <iostream>
#include <vector>

using namespace std;

// 약수들의 합
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    vector<int> v;

    while (true)
    {

        int sum = 0;
        cin >> n;
        v.clear();
        if (n == -1)
        {
            break;
        }

        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
                sum += i;
            }
        }
        if (sum == n)
        {
            cout << n << " = 1";
            for (int i = 1; i < v.size(); i++)
            {
                cout << " + " << v[i];
            }
            cout << "\n";
        }
        else
        {
            cout << n << " is NOT perfect.\n";
        }
    }

    return 0; // 정상종료
}