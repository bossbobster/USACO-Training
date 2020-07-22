#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

string grid[310];
queue<pair<int, int>> nextInLine;
int minD[310][310];
bool inside[310][310];
int dr[4] = {-2, 2, 0, 0};
int dc[4] = {0, 0, -2, 2};
int main()
{
    int e1r = -1, e1c = -1, e2r = -1, e2c = -1, n, m, curR, curC, ans = 0;
    cin >> m >> n;
    n = n * 2 + 1;
    m = m * 2 + 1;
    cin.get();
    for(int i = 0; i < n; i ++)
    {
        getline(cin, grid[i]);
        for(int j = 0; j < m; j ++)
            minD[i][j] = 2000000000;
        if(i == 0 || i == n - 1)
        {
            for(int j = 1; j < m - 1; j ++)
                if(grid[i][j] == ' ')
                {
                    if(e1r == -1) { e1r = i; e1c = j; minD[i][j] = 0; }
                    else { e2r = i; e2c = j; minD[i][j] = 0; }
                }
        }
        else
        {
            if(grid[i][0] == ' ')
            {
                if(e1r == -1) { e1r = i; e1c = 0; minD[i][0] = 0;}
                else { e2r = i; e2c = 0; minD[i][0] = 0;}
            }
            if(grid[i][m - 1] == ' ')
            {
                if(e1r == -1) { e1r = i; e1c = m - 1; minD[i][m - 1] = 0; }
                else { e2r = i; e2c = m - 1; minD[i][m - 1] = 0; }
            }
        }
    }
    for(int i = 0; i < 4; i ++)
    {
        nextInLine.push(pair<int, int>(e1r + dr[i] / 2, e1c + dc[i] / 2));
        if(e1r + dr[i] / 2 >= 0 && e1r + dr[i] / 2 < n && e1c + dc[i] / 2 >= 0 && e1c + dc[i] / 2 < m)
            minD[e1r + dr[i] / 2][e1c + dc[i] / 2] = 1;
        nextInLine.push(pair<int, int>(e2r + dr[i] / 2, e2c + dc[i] / 2));
        if(e2r + dr[i] / 2 >= 0 && e2r + dr[i] / 2 < n && e2c + dc[i] / 2 >= 0 && e2c + dc[i] / 2 < m)
            minD[e2r + dr[i] / 2][e2c + dc[i] / 2] = 1;
    }
    while(!nextInLine.empty())
    {
        curR = nextInLine.front().first;
        curC = nextInLine.front().second;
        nextInLine.pop();
        if(curR < 0 || curR >= n || curC < 0 || curC >= m) continue;
        if(curR % 2 == 0 || curC % 2 == 0) continue;
        inside[curR][curC] = false;
        if(grid[curR][curC] != ' ') continue;
        for(int i = 0; i < 4; i ++)
        {
            if((curR > 1 && i == 0) || (curR < n - 2 && i == 1) || (curC > 1 && i == 2) || (curC < m - 2 && i == 3))
                if(grid[curR + dr[i]][curC + dc[i]] == ' ' && !inside[curR + dr[i]][curC + dc[i]] && grid[curR + dr[i] / 2][curC + dc[i] / 2] == ' ')
                    if(minD[curR][curC] + 1 < minD[curR + dr[i]][curC + dc[i]])
                    {
                        minD[curR + dr[i]][curC + dc[i]] = minD[curR][curC] + 1;
                        nextInLine.push(pair<int, int>(curR + dr[i], curC + dc[i]));
                        inside[curR + dr[i]][curC + dc[i]] = true;
                    }
        }
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(minD[i][j] != 2000000000)
                ans = max(ans, minD[i][j]);
    cout << ans << "\n";
}
