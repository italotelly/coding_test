#include <iostream>

using namespace std;

int main(void)
{
    int X,Y;
    cin>>X>>Y;
    while(X>1000||X==0||X<-1000||Y>1000||Y==0||Y<-1000)
    {
        cout << "X,Y 수 범위 오류 다시 입력 바람!"<<endl;
        cin>>X>>Y;
    }
    if(X>0&&Y>0)
        cout << "1"<<endl;
    else if(X<0&&Y>0)
        cout << "2"<<endl;
    else if(X<0&&Y<0)
        cout << "3"<<endl;
    else if(X>0&&Y<0)
        cout << "4"<<endl;
}
