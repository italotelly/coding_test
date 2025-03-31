#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    int N;
    cin>>N;
    while(N<1||N>100)
    {
        cout << "1 <= N <= 100\n";
        cin>>N;
    }
    int K = N;
    for(int i = 1; i <= N; i++)
    {
        cout << setw(K);
        for(int j = 0; j < i; j++)
        {
        cout << "*";
    }
        cout <<"\n";
        K--;
    }
}