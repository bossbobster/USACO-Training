#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct st
{
    short r, c, dir;
    bool smell;
    int d;
};

short board[1010][1010];
bool visited[1010][1010][4][2];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
queue<st> nextInLine;
int main()
{
    short n, m, curR, curC, curDir;
    int curD;
    bool curS;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> board[i][j];
    nextInLine.push({0, 0, 0, 0, 0});
    nextInLine.push({0, 0, 1, 0, 0});
    while(!nextInLine.empty())
    {
        curR = nextInLine.front().r;
        curC = nextInLine.front().c;
        curDir = nextInLine.front().dir;
        curD = nextInLine.front().d;
        curS = nextInLine.front().smell;
        nextInLine.pop();
        if(curR < 0 || curR >= n || curC < 0 || curC >= m) continue;
        if(board[curR][curC] == 0) continue;
        if(board[curR][curC] == 3 && !curS) continue;
        if(visited[curR][curC][curDir][curS]) continue;
        if(curR == n - 1 && curC == m - 1)
        {
            cout << curD << "\n";
            return 0;
        }
        visited[curR][curC][curDir][curS] = true;
        if(board[curR][curC] == 2) curS = true;
        if(board[curR][curC] == 4)
        {
            if(curR + dr[curDir] < 0 || curR + dr[curDir] >= n || curC + dc[curDir] < 0 || curC + dc[curDir] >= m || board[curR + dr[curDir]][curC + dc[curDir]] == 0 || (board[curR + dr[curDir]][curC + dc[curDir]] == 3 && !curS))
            {
                nextInLine.push({static_cast<short>(curR + 1), curC, 0, 0, curD + 1});
                nextInLine.push({static_cast<short>(curR - 1), curC, 2, 0, curD + 1});
                nextInLine.push({curR, static_cast<short>(curC + 1), 1, 0, curD + 1});
                nextInLine.push({curR, static_cast<short>(curC - 1), 3, 0, curD + 1});
            }
            else
                nextInLine.push({static_cast<short>(curR + dr[curDir]), static_cast<short>(curC + dc[curDir]), curDir, 0, curD + 1});
        }
        else
        {
            nextInLine.push({static_cast<short>(curR + 1), curC, 0, curS, curD + 1});
            nextInLine.push({static_cast<short>(curR - 1), curC, 2, curS, curD + 1});
            nextInLine.push({curR, static_cast<short>(curC + 1), 1, curS, curD + 1});
            nextInLine.push({curR, static_cast<short>(curC - 1), 3, curS, curD + 1});
        }
    }
    cout << -1 << "\n";
}
