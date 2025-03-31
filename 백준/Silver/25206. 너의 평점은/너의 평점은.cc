#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 너의 평점은
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 전공 평점 3.3이상
    // 전공 평점을 계산해주는 프로그램 작성

    vector<string> total;
    vector<string> credit;
    vector<string> grade;
    vector<double> grade_level;
    for (int i = 0; i < 20; i++)
    {
        string a;
        getline(cin, a);
        total.push_back(a);
    }
    // credit과 grade vector 완성성
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < total[i].size(); j++)
        {
            if (total[i][j] == ' ')
            {
                string b = total[i].substr(j + 1, 3);
                credit.push_back(b);
                j += 4;
                string c = total[i].substr(j + 1, 2);
                grade.push_back(c);
                if (grade[i] == "A+")
                {
                    grade_level.push_back(4.5);
                }
                else if (grade[i] == "A0")
                {
                    grade_level.push_back(4.0);
                }
                else if (grade[i] == "B+")
                {
                    grade_level.push_back(3.5);
                }
                else if (grade[i] == "B0")
                {
                    grade_level.push_back(3.0);
                }
                else if (grade[i] == "C+")
                {
                    grade_level.push_back(2.5);
                }
                else if (grade[i] == "C0")
                {
                    grade_level.push_back(2.0);
                }
                else if (grade[i] == "D+")
                {
                    grade_level.push_back(1.5);
                }
                else if (grade[i] == "D0")
                {
                    grade_level.push_back(1.0);
                }
                else if (grade[i] == "P")
                {
                    grade_level.push_back(4.0);
                }
                else if (grade[i] == "F")
                {
                    grade_level.push_back(0.0);
                }
                break;
            }
        }
    }

    double sum = 0;
    double total_credit = 0;
    for (int i = 0; i < 20; i++)
    {
        // p인 경우 pass
        if (grade[i] == "P")
        {
            continue;
        }
        else
        {
            total_credit += stod(credit[i]);
            sum += (stod(credit[i]) * grade_level[i]);
        }
    }
    cout << (sum / total_credit);
    return 0; // 정상종료
}