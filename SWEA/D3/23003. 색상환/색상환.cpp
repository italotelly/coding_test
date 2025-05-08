#include <iostream>
#include <string>
 
using namespace std;
 
string ary[6] = {"red", "orange", "yellow", "green", "blue", "purple"};
 
// »ö»óÈ¯
int main()
{
    int T;
 
    cin >> T;
 
    string s, t;
 
    for (int i = 0; i < T; i++)
    {
        cin >> s >> t;
 
        if (s == t)
        {
            cout << "E\n";
        }
        else
        {
            for (int j = 0; j < 6; j++)
            {
                if (s == ary[j])
                {
                    int a = j + 1;
                    int b = j - 1;
                    int c = j + 3;
                    if (a >= 6)
                    {
                        a = 0;
                    }
                    if (b < 0)
                    {
                        b = 5;
                    }
                    if (c >= 6)
                    {
                        c -= 6;
                    }
                    if (ary[a] == t)
                    {
                        cout << "A\n";
                    }
                    else if (ary[b] == t)
                    {
                        cout << "A\n";
                    }
                    else if (ary[c] == t)
                    {
                        cout << "C\n";
                    }
                    else
                    {
                        cout << "X\n";
                    }
                    break;
                }
            }
        }
    }
    return 0;
}