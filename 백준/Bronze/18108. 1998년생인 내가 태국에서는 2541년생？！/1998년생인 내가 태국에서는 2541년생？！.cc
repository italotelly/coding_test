#include <iostream>

using namespace std;

int main()
{

    int y;

    cin >> y;

    if (y < 1000 || y > 3000)
        return 0;

    cout << y - 543;

    return 0;
}