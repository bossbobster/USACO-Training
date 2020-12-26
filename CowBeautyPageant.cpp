#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct cow
{
    int row, column, d;
};

bool flood[60][60];
bool visited[60][60];
int dist[60][60];
vector<cow> all[3];
queue<cow> nextInLine;
int total[3][3];
int main()
{
    char ch;
    int n, m, row, column, d, num = 0, ans = 2000000000;
    bool already = false;
    cin >> n >> m;
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
            total[i][j] = 2000000000;
    for(int i = 0; i <= n + 5; i ++)
        for(int j = 0; j <= m + 5; j ++)
        {
            flood[i][j] = false;
            visited[i][j] = false;
        }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> ch;
            if(ch == 'X')
                flood[i][j] = true;
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(!flood[i][j])
                continue;
            nextInLine.push({i, j, 0});
            already = false;
            do
            {
                row = nextInLine.front().row;
                column = nextInLine.front().column;
                if(!flood[row][column] || visited[row][column])
                {
                    nextInLine.pop();
                    continue;
                }
                if(!already)
                {
                    num ++;
                    already = true;
                }
                visited[row][column] = true;
                all[num - 1].push_back({row, column});
                nextInLine.push({row, column + 1, 0});
                nextInLine.push({row, column - 1, 0});
                nextInLine.push({row + 1, column, 0});
                nextInLine.push({row - 1, column, 0});
                nextInLine.pop();
            }while(!nextInLine.empty());
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(flood[i][j]) continue;
            for(int i = 0; i <= n; i ++)
                for(int j = 0; j <= m; j ++)
                {
                    visited[i][j] = false;
                    dist[i][j] = 0;
                }
            nextInLine.push({i, j, 0});
            while(!nextInLine.empty())
            {
                row = nextInLine.front().row;
                column = nextInLine.front().column;
                d = nextInLine.front().d;
                nextInLine.pop();
                if(row <= 0 || row >= n + 1 || column <= 0 || column >= m + 1) continue;
                if(visited[row][column]) continue;
                visited[row][column] = true;
                dist[row][column] = d;
                nextInLine.push({row, column + 1, d + 1});
                nextInLine.push({row, column - 1, d + 1});
                nextInLine.push({row + 1, column, d + 1});
                nextInLine.push({row - 1, column, d + 1});
            }
            int min1 = 2000000000, min2 = 2000000000, min3 = 2000000000;
            for(int i = 0; i < all[0].size(); i ++)
                min1 = min(min1, dist[all[0][i].row][all[0][i].column]);
            for(int i = 0; i < all[1].size(); i ++)
                min2 = min(min2, dist[all[1][i].row][all[1][i].column]);
            for(int i = 0; i < all[2].size(); i ++)
                min3 = min(min3, dist[all[2][i].row][all[2][i].column]);
            ans = min(ans, min1 + min2 + min3 - 2);
        }
    for(int idx1 = 0; idx1 < 2; idx1 ++)
        for(int idx2 = idx1 + 1; idx2 < 3; idx2 ++)
            for(int i = 0; i < all[idx1].size(); i ++)
                for(int j = 0; j < all[idx2].size(); j ++)
                    if(abs(all[idx1][i].row - all[idx2][j].row) + abs(all[idx1][i].column - all[idx2][j].column) < total[idx1][idx2])
                        total[idx1][idx2] = abs(all[idx1][i].row - all[idx2][j].row) + abs(all[idx1][i].column - all[idx2][j].column);
    
    cout << min(min(ans + 2, total[0][1] + total[1][2]), min(total[0][1] + total[0][2], total[0][2] + total[1][2])) - 2 << "\n";
}
