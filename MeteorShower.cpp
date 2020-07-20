#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

struct coo
{
    int r, c, d;
};
queue<coo> nextInLine;
int grid[310][310];
bool visited[310][310];
int main()
{
    int n, curR, curC, curD = 0;
    bool done = false;
    cin >> n;
    for(int i = 0; i < 310; i ++)
        for(int j = 0; j < 310; j ++)
            grid[i][j] = 2000000000;
    for(int i = 0; i < n; i ++)
    {
        cin >> curC >> curR >> curD;
        grid[curR][curC] = min(curD, grid[curR][curC]);
        if(curR > 0) grid[curR - 1][curC] = min(curD, grid[curR - 1][curC]);
        grid[curR + 1][curC] = min(curD, grid[curR + 1][curC]);
        if(curC > 0) grid[curR][curC - 1] = min(curD, grid[curR][curC - 1]);
        grid[curR][curC + 1] = min(curD, grid[curR][curC + 1]);
    }
    nextInLine.push({0, 0, 0});
    while(!nextInLine.empty())
    {
        curR = nextInLine.front().r;
        curC = nextInLine.front().c;
        curD = nextInLine.front().d;
        if(curR < 0 || curR > 310 || curC < 0 || curC > 310)
        {
            nextInLine.pop();
            continue;
        }
        if(visited[curR][curC])
        {
            nextInLine.pop();
            continue;
        }
        visited[curR][curC] = true;
        if(grid[curR][curC] == 2000000000) { done = true; break; }
        if(curD >= grid[curR][curC])
        {
            nextInLine.pop();
            continue;
        }
        nextInLine.push({curR + 1, curC, curD + 1});
        nextInLine.push({curR - 1, curC, curD + 1});
        nextInLine.push({curR, curC + 1, curD + 1});
        nextInLine.push({curR, curC - 1, curD + 1});
        nextInLine.pop();
    }
    if(done) cout << curD << "\n";
    else cout << -1 << "\n";
}
