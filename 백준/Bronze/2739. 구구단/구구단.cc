#include <iostream>

using namespace std;

int main(void)
{
    int a;
    cin>>a;
    while(a<1||a>9){
        cout << "N은 1보다 크거나 같고, 9보다 작거나 같다." <<endl;
        cin>>a;
    }
    for(int i=1;i<10;i++){
        cout << a << " * " << i <<" = "<<i*a<<endl;
    }
}