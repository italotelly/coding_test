#include <iostream>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

// 문자열 옮기기
int main()
{
    int T;

    cin >> T;

    deque<char> S;
    string s;
    int K;
    long int X;
    while (T--)
    {
        cin >> s >> K;
        S.clear();
        for (int i = 0; i < s.size(); i++)
        {
            S.push_back(s[i]);
        }
        while (K--)
        {
            cin >> X;
            int a;
            if (X > 0)
            {
                a = 2;
            }
            else if (X < 0)
            {
                a = 1;
            }
            else
            {
                a = 0;
            }
            X = abs(X);
            X = X % S.size();
            for (int i = 0; i < X; i++)
            {
                if (a == 2)
                {
                    char temp = S.front();
                    S.pop_front();
                    S.push_back(temp);
                }
                else if (a == 1)
                {
                    char temp = S.back();
                    S.pop_back();
                    S.push_front(temp);
                }
                else
                {
                    break;
                }
            }
        }
        for (int i = 0; i < S.size(); i++)
        {
            cout << S[i];
        }
        cout << "\n";
    }
    return 0;
}