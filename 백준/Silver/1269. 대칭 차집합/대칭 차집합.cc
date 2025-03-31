#include <iostream>
#include <unordered_set>
#include <iterator>

using namespace std;

// 대칭 차집합
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;

    cin >> a >> b;
    unordered_set<int> A;
    unordered_set<int> B;
    unordered_set<int>::iterator itera = A.begin();
    unordered_set<int>::iterator iterb = B.begin();

    int num = 0;
    for (int i = 0; i < a; i++)
    {
        cin >> num;
        A.insert(num);
    }

    for (int i = 0; i < b; i++)
    {
        cin >> num;
        B.insert(num);
    }

    int cnta = a;
    int cntb = b;
    for (itera = A.begin(); itera != A.end(); itera++)
    {
        if (B.find(*itera) != B.end())
        {
            cnta--;
        }
    }
    for (iterb = B.begin(); iterb != B.end(); iterb++)
    {
        if (A.find(*iterb) != A.end())
        {
            cntb--;
        }
    }

    cout << cnta + cntb;

    return 0;
}