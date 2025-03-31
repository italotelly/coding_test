#include <iostream>

using namespace std;

int main(void)
{
    int a,n;
    a = 0;
    cin>>n;
    while(n<1||n>10000)
    {
        cout << "1<=n<=10000" << endl;
        cin>>n;
    }
    for(int i = 1; i <= n ; i++)
    {
        a = a+i;
    }
    cout << a;
}
