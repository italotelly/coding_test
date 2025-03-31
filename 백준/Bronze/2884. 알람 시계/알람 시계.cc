#include <iostream>

using namespace std;

int main(void)
{
    int H,M;
    cin>>H>>M;
    while(H<0||H>23||M<0||M>59)
    {
        cout<<"시간 범위 초과 다시 입력 바람!"<<endl;
        cin>>H>>M;
    }
    if(M>44)
        cout <<H<<" "<< M - 45 << endl;
    else if(H==0)
        cout << 23<<" " << M+15;
    else cout << H-1 <<" " << M+15;
}
