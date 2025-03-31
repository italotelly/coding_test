#include <iostream>

using namespace std;

int main(void)
{
    int year;
    cin>>year;
    while(year<1||year>4000){
        cout<<"연도는 1보다 크거나 같고, 4000보다 작거나 같은 자연수입니다!"<<endl;
        cin>>year;
    }
    if(year%4==0)
    {if(year%100!=0||year%400==0)
            cout << "1"<<endl;
     else cout<<"0"<<endl;
    }
     else cout<<"0"<<endl;
}
