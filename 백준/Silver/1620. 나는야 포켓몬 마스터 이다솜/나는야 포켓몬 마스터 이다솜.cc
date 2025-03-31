#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// 나는야 포켓몬 마스터 이다솜

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> name_to_num;
    vector<string> num_to_name(N + 1); // 인덱스를 1부터 사용하기 위해 크기 N+1

    string pokemon;
    for (int i = 1; i <= N; i++) // 1부터 시작
    {
        cin >> pokemon;
        name_to_num[pokemon] = i; // 이름 → 번호 저장
        num_to_name[i] = pokemon; // 번호 → 이름 저장
    }

    string input;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        if (isdigit(input[0])) // 숫자로 시작하면 숫자로 변환 후 출력
        {
            int num = stoi(input);
            cout << num_to_name[num] << "\n";
        }
        else // 아니면 문자열이므로 맵에서 찾기
        {
            cout << name_to_num[input] << "\n";
        }
    }

    return 0;
}