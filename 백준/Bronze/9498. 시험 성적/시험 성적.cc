#include <iostream>

using namespace std;

int main(void)
{
    int score;
    cin>>score;
    while(score>100||score<0){
        cout<<"시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수입니다!"<<endl;
        cin>>score;}
    if(89<score)
        cout << "A";
    else if(79<score)
        cout << "B";
    else if(69<score)
        cout << "C";
    else if(59<score)
        cout << "D";
    else cout << "F";
}