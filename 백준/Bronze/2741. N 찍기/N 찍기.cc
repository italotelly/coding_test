#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin>>N;
    while(N<1||N>100000)
    {
        cout << "N은 100,000보다 작거나 같은 자연수이다. \n";
        cin>>N;
    }
    for(int i = 0; i<N;i++)
    {
        cout << i+1 <<"\n";
    }
}
