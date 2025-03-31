#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void cantore(string &can, int start, int length)
{
    if (length < 3)
    {
        return;
    }
    int part = length / 3;
    for (int i = start + part; i < start + 2 * part; i++)
    {
        can[i] = ' ';
    }

    cantore(can, start, part);
    cantore(can, start + 2 * part, part);
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;

    int num, length;
    while (cin >> num)
    {
        length = pow(3, num);
        string s(length, '-');

        cantore(s, 0, length);
        cout << s << "\n";
    }

    return 0;
}