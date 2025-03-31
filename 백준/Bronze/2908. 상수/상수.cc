#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 상수
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string num1, num2;

    cin >> num1 >> num2;
    char temp1, temp2;

    temp1 = num1[0];
    num1[0] = num1[2];
    num1[2] = temp1;

    temp2 = num2[0];
    num2[0] = num2[2];
    num2[2] = temp2;

    if (stoi(num1) > stoi(num2))
    {
        cout << num1;
    }
    else
    {
        cout << num2;
    }
    return 0; // 정상종료
}