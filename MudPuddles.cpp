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
bool grid[1030][1030];
bool visited[1030][1030];
int main()
{
    int r, c, n, curR, curC, curD = 0;
    cin >> c >> r >> n;
    r += 510;
    c += 510;
    for(int i = 0; i < n; i ++)
    {
        cin >> curC >> curR;
        grid[curR + 510][curC + 510] = true;
    }
    nextInLine.push({510, 510, 0});
    while(!nextInLine.empty())
    {
        curR = nextInLine.front().r;
        curC = nextInLine.front().c;
        curD = nextInLine.front().d;
        nextInLine.pop();
        if(curR < 0 || curR > 1020 || curC < 0 || curC > 1020) continue;
        if(visited[curR][curC]) continue;
        if(grid[curR][curC]) continue;
        visited[curR][curC] = true;
        if(curR == r && curC == c) break;
        nextInLine.push({curR + 1, curC, curD + 1});
        nextInLine.push({curR - 1, curC, curD + 1});
        nextInLine.push({curR, curC + 1, curD + 1});
        nextInLine.push({curR, curC - 1, curD + 1});
    }
    cout << curD << "\n";
}
