#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int N, M;
int MAP[55][55];

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int visited[15];

int rst = 2100000000;

void calc(){
    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int min_num = 2100000000;
        for (int j = 0; j < chicken.size(); j++)
        {
            if(visited[j] == 1){
                int dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                min_num = min(min_num, dist);
            }       
        }
        sum += min_num;
    }
    rst = min(rst, sum);
}

void dfs(int lev, int st_idx){
    if(lev == M){
        calc();
        return;
    }

    for (int i = st_idx; i < chicken.size(); i++)
    {
        if(visited[i] == 1) continue;
        visited[i] = 1;
        dfs(lev + 1, i + 1);
        visited[i] = 0;
    }
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> MAP[i][j];
            if(MAP[i][j] == 1){
                house.push_back({i, j});
            }
            else if(MAP[i][j] == 2){
                chicken.push_back({i, j});
            }
        }  
    }

    dfs(0, 0);

    cout << rst << "\n";

    return 0;
}